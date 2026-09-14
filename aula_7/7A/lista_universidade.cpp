#include "lista_universidade.h"
#include "elemento_universidade.h"
#include "universidade.h"
ListaUniversidade::ListaUniversidade() {
	set_nomeUni();
	cabecaUni = NULL;
	atualUni = NULL;
}
ListaUniversidade::~ListaUniversidade() {
	destroy_lista();
	cabecaUni = NULL;
	atualUni = NULL;
}
ElemUniversidade* ListaUniversidade::get_cabecaUni() {
	if (this == NULL) {
		cout << "cabecaUni nula" << endl;
		return NULL;
	}
	return this->cabecaUni;
}
ElemUniversidade* ListaUniversidade::get_atualUni() {
	if (this == NULL) {
		cout << "atualUni nula" << endl;
		return NULL;
	}
	return this->atualUni;
}
Universidade* ListaUniversidade::buscaN_universidade(const char* nomeUni) {
	ElemUniversidade* temp = NULL;
	if (cabecaUni == NULL) {
		cout << "Universidade vazia" << endl;
		return NULL;
	}
	for (temp = cabecaUni; temp != NULL; temp = temp->universidadeG_proximo()) {
		if (!strcmp(temp->get_universidade()->qual_uni(),nomeUni))
			return temp->get_universidade();
	}
	cout << "nao achado Universidade" << endl;
	system("Pause");
	return NULL;
}
void ListaUniversidade::set_nomeUni(const char* nomeUni) {
	strcpy_s(nome,sizeof(nome),nomeUni);
}
void ListaUniversidade::inclue_universidade(Universidade* uni) {
	ElemUniversidade* universidade = new ElemUniversidade;
	universidade->set_universidade(uni);
	if (uni == NULL) {
		printf("erro universidade com valor nulo");
		return;
	}
	if (cabecaUni == NULL) {
		cabecaUni = universidade;
		atualUni = universidade;
	}
	else {
		ElemUniversidade* temp = atualUni;
		atualUni->universidadeS_proximo(universidade);//di;
		atualUni = atualUni->universidadeG_proximo();
		atualUni->universidadeS_anterior(temp);// = temp;
	}
}
void ListaUniversidade::print_universidade() {
	ElemUniversidade* temp = NULL;
	cout << "as universidades são" << endl;
	for (temp = cabecaUni; temp != NULL; temp = temp->universidadeG_proximo()) {
		cout << temp->get_universidade()->qual_uni() << endl;
	}
}
void ListaUniversidade::printR_universidade() {
	ElemUniversidade* temp = NULL;
	cout << "as universidades em ordem inversa são" << endl;
	for (temp = atualUni; temp != NULL; temp = temp->universidadeG_anterior()) {
		cout << temp->get_universidade()->qual_uni() << endl;
	}
}
ElemUniversidade* ListaUniversidade::busca_universidade(Universidade* uni) {
	ElemUniversidade* temp = NULL;
	int achou = 0;
	if (cabecaUni == NULL) {
		cout << "Universidade vazia" << endl;
		return NULL;
	}
	for (temp = cabecaUni; temp != NULL || achou != 0; temp = temp->universidadeG_proximo()) {
		if (temp->get_universidade() == uni)
			achou = 1;
	}
	if (achou == 1)
		return temp;
	cout << "nao achado" << endl;
	return NULL;
}
void ListaUniversidade::remove_universidade(Universidade* uni) {
	ElemUniversidade* temp = cabecaUni, * universidade = NULL;
	universidade = busca_universidade(uni);
	if (uni == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (universidade == cabecaUni) {
		cabecaUni = cabecaUni->universidadeG_proximo();
		cabecaUni->universidadeS_anterior(NULL);// = NULL;
		delete temp;
	}
	else if (universidade == atualUni) {
		temp = atualUni;
		atualUni = atualUni->universidadeG_anterior();
		atualUni->universidadeS_proximo(NULL);// = NULL;
		delete temp;
	}
	else {
		while (temp->universidadeG_proximo() != universidade)
			temp = temp->universidadeG_proximo();
		temp->universidadeS_proximo(temp->universidadeG_proximo()->universidadeG_proximo());// = temp->next->next;
		temp = temp->universidadeG_proximo();
		temp->universidadeS_anterior(temp->universidadeG_anterior()->universidadeG_anterior());// = temp->prev->prev;
		universidade->universidadeS_proximo(NULL);// = NULL;
		universidade->universidadeS_anterior(NULL);// = NULL;
		delete universidade;
	}
}
void ListaUniversidade::destroy_lista() {
	ElemUniversidade* temp = NULL, * depois = NULL;
	for (temp = cabecaUni; temp != NULL; temp = depois) {
		depois = temp->universidadeG_proximo();
		delete temp;
	}
}
void ListaUniversidade::salva_universidade() {
	ofstream SalvaUniversidade("universidades.dat", ios::out);
	if (!SalvaUniversidade) {
		cerr << "nao consegui abrir arquivo universidade" << endl;
		fflush(stdin);
		return;
	}
	ElemUniversidade* galuno = NULL;
	galuno = cabecaUni;
	Universidade* temp = NULL;
	while (galuno != NULL) {
		temp = galuno->get_universidade();
		SalvaUniversidade << temp->get_id() << temp->qual_uni() << endl;
		galuno = galuno->universidadeG_proximo();

	}
	SalvaUniversidade.close();
}
void ListaUniversidade::registra_universidade() {
	ifstream ResgistraUniversidade("universidades.dat", ios::in);
	if (!ResgistraUniversidade) {
		cerr << "nao consegui regartar arquivo diciplina" << endl;
		fflush(stdin);
	}
	destroy_lista();
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