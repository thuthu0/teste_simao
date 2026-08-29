#include "lista_universidade.h"
#include "elemento_universidade.h"
#include "universidade.h"
ListaUniversidade::ListaUniversidade() {
	set_nomeUni();
	cabecaUni = NULL;
	atualUni = NULL;
}
ListaUniversidade::~ListaUniversidade() {
	ElemUniversidade* temp = NULL, * depois = NULL;
	for (temp = cabecaUni; temp != NULL; temp = depois) {
		depois = temp->universidadeG_proximo();
		delete temp;
	}
	cabecaUni = NULL;
	atualUni = NULL;
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