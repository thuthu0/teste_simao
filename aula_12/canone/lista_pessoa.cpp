#include "lista_pessoa.h"

#include "elemento.h"
#include "pessoa.h"


ListaPessoa::ListaPessoa() {
    strcpy_s(nome, sizeof(nome), "");
    listapessoa.aterrar();
}

ListaPessoa::~ListaPessoa() {
    listapessoa.destroy();
}

void ListaPessoa::inclue_pessoa(Pessoa* P) {
    if (P == NULL) {
        cout << "Tentativa de colocar nulidade em Pessoa" << endl;
        return;
    }

    
    Elemento<Pessoa>* pessoa = new Elemento<Pessoa>;
    pessoa->set_elem(P);

 
    if (listapessoa.get_cabeca() == NULL) {
        listapessoa.set_cabeca(pessoa);
        listapessoa.set_atual(pessoa);
        return;
    }

    
    Elemento<Pessoa>* temp = listapessoa.get_cabeca();
    while (temp != NULL &&
        strcmp(temp->get_elem()->get_nome(), P->get_nome()) < 0) {
        temp = temp->get_proximo();
    }

    if (temp == NULL) {
        pessoa->set_anterior(listapessoa.get_atual());
        listapessoa.get_atual()->set_proximo(pessoa);
        listapessoa.set_atual(pessoa);
    }
    else if (temp == listapessoa.get_cabeca()) {
        pessoa->set_proximo(listapessoa.get_cabeca());
        listapessoa.get_cabeca()->set_anterior(pessoa);
        listapessoa.set_cabeca(pessoa);
    }
    else {
        Elemento<Pessoa>* ant = temp->get_anterior();
        ant->set_proximo(pessoa);
        pessoa->set_anterior(ant);
        pessoa->set_proximo(temp);
        temp->set_anterior(pessoa);
    }
}

void ListaPessoa::print_pessoa() {
    if (listapessoa.get_cabeca() == NULL)
        return;
    Elemento<Pessoa>* temp;
    for (temp = listapessoa.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
        temp->get_elem()->print_nome();
    }
}

void ListaPessoa::printR_pessoa() {
    if (listapessoa.get_cabeca() == NULL)
        return;
    Elemento<Pessoa>* temp;
    for (temp = listapessoa.get_atual(); temp != NULL; temp = temp->get_anterior()) {
        temp->get_elem()->print_nome();
    }
}

Elemento<Pessoa>* ListaPessoa::busca_pessoa(Pessoa* P) {
    if (listapessoa.get_cabeca() == NULL) {
        cout << "lista vazia" << endl;
        return NULL;
    }
    Elemento<Pessoa>* temp = NULL;
    for (temp = listapessoa.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
        if (temp->get_elem() == P)
            return temp;
    }
    cout << "nao achado" << endl;
    return NULL;
}

void ListaPessoa::remove_pessoa(Pessoa* P) {
    if (P == NULL) {
        cout << "Tentativa de remover nulidade" << endl;
        return;
    }

    Elemento<Pessoa>* pessoa = busca_pessoa(P);
    if (pessoa == NULL)
        return;

    if (pessoa == listapessoa.get_cabeca()) {
        listapessoa.set_cabeca(pessoa->get_proximo());
        pessoa->set_proximo(NULL);
        if (listapessoa.get_cabeca() != NULL)
            listapessoa.get_cabeca()->set_anterior(NULL);
        else
            listapessoa.set_atual(NULL);
        delete pessoa;
    }
    else if (pessoa == listapessoa.get_atual()) {
        listapessoa.set_atual(pessoa->get_anterior());
        listapessoa.get_atual()->set_proximo(NULL);
        pessoa->set_anterior(NULL);
        delete pessoa;
    }
    else {
        Elemento<Pessoa>* ant = pessoa->get_anterior();
        Elemento<Pessoa>* prox = pessoa->get_proximo();
        ant->set_proximo(prox);
        prox->set_anterior(ant);
        pessoa->set_proximo(NULL);
        pessoa->set_anterior(NULL);
        delete pessoa;
    }
}

void ListaPessoa::salva_pessoa() {
    ofstream SalvaPessoas("pessoas.dat", ios::out);
    if (!SalvaPessoas) {
        cerr << "nao consegui abrir arquivo pessoa" << endl;
        fflush(stdin);
        return;
    }
    Elemento<Pessoa>* gpessoa = listapessoa.get_cabeca();
    Pessoa* temp = NULL;
    while (gpessoa != NULL) {
        temp = gpessoa->get_elem();
        SalvaPessoas << temp->get_id() << temp->get_nome() << endl;
        gpessoa = gpessoa->get_proximo();
    }
    SalvaPessoas.close();
}

void ListaPessoa::registra_pessoa() {
    ifstream RegistraPessoa("pessoas.dat", ios::in);
    if (!RegistraPessoa) {
        cerr << "nao consegui registrar arquivo pessoa" << endl;
        fflush(stdin);
        return;
    }
    listapessoa.destroy();
    while (!RegistraPessoa.eof()) {
        Pessoa* temp = NULL;
        int id;
        char nome[30];
        RegistraPessoa >> id >> nome;
        if (RegistraPessoa.good()) {
            temp = new Pessoa();
            temp->set_nome(nome);
            inclue_pessoa(temp);
        }
    }
    RegistraPessoa.close();
}