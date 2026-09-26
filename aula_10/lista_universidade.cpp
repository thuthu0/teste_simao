#include "lista_universidade.h"
//#include "elemento_universidade.h"
#include "universidade.h"
ListaUniversidade::ListaUniversidade() {
	set_nomeUni();
	listauniversidade.aterrar();
}
ListaUniversidade::~ListaUniversidade() {
	listauniversidade.destroy();
}
Elemento<Universidade>* ListaUniversidade::get_cabecaUni() {
	if (this == NULL) {
		cout << "cabecaUni nula" << endl;
		return NULL;
	}
	return this->listauniversidade.get_cabeca();
}
Elemento<Universidade>* ListaUniversidade::get_atualUni() {
	if (this == NULL) {
		cout << "atualUni nula" << endl;
		return NULL;
	}
	return this->listauniversidade.get_atual();
}
Universidade* ListaUniversidade::buscaN_universidade(const char* nomeUni) {
	Elemento<Universidade>* temp = NULL;
	if (listauniversidade.get_cabeca() == NULL) {
		cout << "Universidade vazia" << endl;
		return NULL;
	}
	for (temp = listauniversidade.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
		if (!strcmp(temp->get_elem()->qual_uni(),nomeUni))
			return temp->get_elem();
	}
	cout << "nao achado Universidade" << endl;
	system("Pause");
	return NULL;
}
void ListaUniversidade::set_nomeUni(const char* nomeUni) {
	strcpy_s(nome,sizeof(nome),nomeUni);
}
void ListaUniversidade::inclue_universidade(Universidade* uni) {
	Elemento<Universidade>* universidade = new Elemento<Universidade>;
	universidade->set_elem(uni);
	if (uni == NULL) {
		printf("erro universidade com valor nulo");
		return;
	}
	if (listauniversidade.get_cabeca() == NULL) {
		listauniversidade.set_cabeca(universidade);//cabecaUni = universidade;
		listauniversidade.set_atual(universidade);//atualUni = universidade;
	}
	else {
		Elemento<Universidade>* temp = listauniversidade.get_atual();
		listauniversidade.get_atual()->set_proximo(universidade);//atualUni->set_proximo(universidade);
		listauniversidade.set_atual(listauniversidade.get_atual()->get_proximo());//atualUni = atualUni->get_proximo();
		listauniversidade.get_atual()->set_anterior(temp);//atualUni->set_anterior(temp);
	}
}
void ListaUniversidade::print_universidade() {
	Elemento<Universidade>* temp = NULL;
	cout << "as universidades são" << endl;
	for (temp = listauniversidade.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
		cout << temp->get_elem()->qual_uni() << endl;
	}
}
void ListaUniversidade::printR_universidade() {
	Elemento<Universidade>* temp = NULL;
	cout << "as universidades em ordem inversa são" << endl;
	for (temp = listauniversidade.get_atual(); temp != NULL; temp = temp->get_anterior()) {
		cout << temp->get_elem()->qual_uni() << endl;
	}
}
Elemento<Universidade>* ListaUniversidade::busca_universidade(Universidade* uni) {
	Elemento<Universidade>* temp = NULL;
	if (listauniversidade.get_cabeca() == NULL) {
		cout << "Universidade vazia" << endl;
		return NULL;
	}
	for (temp = listauniversidade.get_cabeca(); temp != NULL ; temp = temp->get_proximo()) {
		if (temp->get_elem() == uni)
			return temp;
	}
		return temp;
	cout << "nao achado" << endl;
	return NULL;
}
void ListaUniversidade::remove_universidade(Universidade* uni) {
	Elemento<Universidade>* temp = listauniversidade.get_cabeca(), * universidade = NULL;
	universidade = busca_universidade(uni);
	if (uni == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (universidade == listauniversidade.get_cabeca()) {
		listauniversidade.set_cabeca(listauniversidade.get_cabeca()->get_proximo());//cabecaUni = cabecaUni->get_proximo();
		listauniversidade.get_cabeca()->set_anterior(NULL);//cabecaUni->set_anterior(NULL);
		delete temp;
	}
	else if (universidade == listauniversidade.get_atual()) {
		temp = listauniversidade.get_atual();
		listauniversidade.set_atual(listauniversidade.get_atual()->get_anterior());//atualUni = atualUni->get_anterior();
		listauniversidade.get_atual()->set_anterior(NULL);//atualUni->set_proximo(NULL);
		delete temp;
	}
	else {
		while (temp->get_proximo() != universidade)
			temp = temp->get_proximo();
		temp->set_proximo(temp->get_proximo()->get_proximo());// = temp->next->next;
		temp = temp->get_proximo();
		temp->set_anterior(temp->get_anterior()->get_anterior());// = temp->prev->prev;
		universidade->set_proximo(NULL);// = NULL;
		universidade->set_anterior(NULL);// = NULL;
		delete universidade;
	}
}

void ListaUniversidade::salva_universidade() {
	ofstream SalvaUniversidade("universidades.dat", ios::out);
	if (!SalvaUniversidade) {
		cerr << "nao consegui abrir arquivo universidade" << endl;
		fflush(stdin);
		return;
	}
	Elemento<Universidade>* galuno = NULL;
	galuno = listauniversidade.get_cabeca();
	Universidade* temp = NULL;
	while (galuno != NULL) {
		temp = galuno->get_elem();
		SalvaUniversidade << temp->get_id() << temp->qual_uni() << endl;
		galuno = galuno->get_proximo();

	}
	SalvaUniversidade.close();
}
void ListaUniversidade::registra_universidade() {
	ifstream ResgistraUniversidade("universidades.dat", ios::in);
	if (!ResgistraUniversidade) {
		cerr << "nao consegui regartar arquivo diciplina" << endl;
		fflush(stdin);
	}
	listauniversidade.destroy();
	while (!ResgistraUniversidade.eof()) {
		Universidade* temp = NULL;
		int id;
		char nome[30];
		ResgistraUniversidade >> id >> nome;
		if (0 != strcpy_s(nome, sizeof(nome), "")) {
			temp = new Universidade (-1);
			temp->set_id(id);
			temp->sua_uni(nome);
			inclue_universidade(temp);
		}
	}
	ResgistraUniversidade.close();
}