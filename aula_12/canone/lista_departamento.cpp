#include"lista_departamento.h"
#include "departamento.h"
ListaDepartamento::ListaDepartamento( ) {
	set_nomeD("");
	listadepartamento.aterrar();
}
ListaDepartamento::~ListaDepartamento() {
	listadepartamento.destroy();
}

Elemento<Departamento>* ListaDepartamento::get_cabecaDep() {
	if (this == NULL) {
		cout << "cabecaDep nula" << endl;
		return NULL;
	}
	return this->listadepartamento.get_cabeca();
}
Elemento<Departamento>* ListaDepartamento::get_atualDep() {
	if (this == NULL) {
		cout << "atualDep nula" << endl;
		return NULL;
	}
	return this->listadepartamento.get_atual();
}
Departamento* ListaDepartamento::buscaN_departamento(const char* nomeDep) {
	Elemento<Departamento>* temp = NULL;
	int achou = 0;
	if (listadepartamento.get_cabeca() == NULL) {
		cout << "Departamento vazia" << endl;
		return NULL;
	}
	for (temp = listadepartamento.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
		if (!strcmp(temp->get_elem()->qual_departamento(), nomeDep))
			return temp->get_elem();
	}
	cout << "nao achado" << endl;
	return NULL;
}
void ListaDepartamento::set_nomeD(const char* nomeD) {
	strcpy_s(nome,sizeof(nome),nomeD);
}
void ListaDepartamento:: inclue_departamento(Departamento* dep) {
	Elemento<Departamento>* departamento = new Elemento<Departamento>;
	departamento->set_elem(dep);
	if (dep == NULL) {
		printf("erro departamento com valor nulo");
		return;
	}
	if (listadepartamento.get_cabeca() == NULL) {
		listadepartamento.set_cabeca(departamento);//cabecaDep = departamento;
		listadepartamento.set_atual(departamento);//atualDep = departamento;
	}
	else {
		Elemento<Departamento>* temp = listadepartamento.get_atual();
		listadepartamento.get_atual()->set_proximo(departamento);//atualDep->set_proximo(departamento);
		listadepartamento.set_atual(listadepartamento.get_atual()->get_proximo());//atualDep = atualDep->get_proximo();
		listadepartamento.get_atual()->set_anterior(temp);//atualDep->set_anterior(temp);
	}
}
void ListaDepartamento::print_departamento() {
	Elemento<Departamento>* temp = NULL;
	cout << "os departamentos da universidade são" << endl;
	for (temp = listadepartamento.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
		cout << temp->get_elem()->qual_departamento() << endl;
	}
}
void ListaDepartamento::printR_departamento() {
	Elemento<Departamento>* temp = NULL;
	cout << "os departamentos da universidade em ordem inversa são" << endl;
	for (temp = listadepartamento.get_atual(); temp != NULL; temp = temp->get_anterior()) {
		cout << temp->get_elem()->qual_departamento()  << endl;
	}
}
Elemento<Departamento>* ListaDepartamento::busca_departamento(Departamento* dep) {
	Elemento<Departamento>* temp = NULL;
	if (listadepartamento.get_cabeca() == NULL) {
		cout << "Departamento vazia" << endl;
		return NULL;
	}
	for (temp = listadepartamento.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
		if (temp->get_elem() == dep)
			return temp;
	}
		
	cout << "nao achado" << endl;
	return NULL;
}
void ListaDepartamento::remove_departamento(Departamento* dep) {
	Elemento<Departamento>* temp = listadepartamento.get_cabeca(), * departamento;
	departamento = busca_departamento(dep);
	if (dep == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (departamento == listadepartamento.get_cabeca()) {
		listadepartamento.set_cabeca(listadepartamento.get_cabeca()->get_proximo());//cabecaDep = cabecaDep->get_proximo();
		listadepartamento.get_cabeca()->set_anterior(NULL);//cabecaDep->set_anterior(NULL);
		delete temp;
	}
	else if (departamento == listadepartamento.get_atual()) {
		temp = listadepartamento.get_atual();
		listadepartamento.set_atual(listadepartamento.get_atual()->get_anterior());//atualDep = atualDep->get_anterior();
		listadepartamento.get_atual()->set_proximo(NULL);//atualDep->set_proximo(NULL);
		delete temp;
	}
	else {
		while (temp->get_proximo() != departamento)
			temp = temp->get_proximo();
		temp->set_proximo(temp->get_proximo()->get_proximo());// = temp->next->next;
		temp = temp->get_proximo();
		temp->set_anterior(temp->get_anterior()->get_anterior());// = temp->prev->prev;
		departamento->set_proximo(NULL);// = NULL;
		departamento->set_anterior(NULL);// = NULL;
		delete departamento;
	}
}

void ListaDepartamento::salva_departamento() {
	ofstream SalvaDepartamento("departamentos.dat", ios::out);
	if (!SalvaDepartamento) {
		cerr << "nao consegui abrir arquivo departamento" << endl;
		fflush(stdin);
		return;
	}
	Elemento<Departamento>* galuno = NULL;
	galuno = listadepartamento.get_cabeca();
	Departamento* temp = NULL;
	while (galuno != NULL) {
		temp = galuno->get_elem();
		SalvaDepartamento << temp->get_id() << temp->qual_departamento() << endl;
		galuno = galuno->get_proximo();

	}
	SalvaDepartamento.close();
}
void ListaDepartamento::registra_departamento() {
	ifstream ResgistraDepartamento("departamentos.dat", ios::in);
	if (!ResgistraDepartamento) {
		cerr << "nao consegui regartar arquivo departamento" << endl;
		fflush(stdin);
	}
	listadepartamento.destroy();
	while (!ResgistraDepartamento.eof()) {
		Departamento* temp = NULL;
		int id;
		char nome[30];
		ResgistraDepartamento >> id >> nome;
		if (0 != strcpy_s(nome, sizeof(nome), "")) {
			temp = new Departamento (-1);
			temp->set_id(id);
			temp->set_departamento(nome);
			inclue_departamento(temp);
		}
	}
	ResgistraDepartamento.close();
}