#include "lista_diciplina.h"
ListaDiciplina::ListaDiciplina() {
	materia = NULL;
	next = NULL;
	prev = NULL;
}
ListaDiciplina::~ListaDiciplina() {
	materia = NULL;
	next = NULL;
	prev = NULL;
}
void ListaDiciplina::colo_diciplina(Diciplina* Di) {
	if (this == NULL)
		cout << "nó diciplina não inicializado" << endl;
	else
		this->materia = Di;
}
Diciplina* ListaDiciplina:: posicao_diciplina() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return NULL;
	}
	return this->materia;
}
void ListaDiciplina::diciplinaS_proximo(ListaDiciplina* prox) {
	if (this == NULL)
		cout << "nó diciplina não inicializado" << endl;

	else
		this->next = prox;
}
ListaDiciplina* ListaDiciplina::diciplinaG_proximo() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return this;
	}
	return this->next;
}
void ListaDiciplina::diciplinaS_anterior(ListaDiciplina* ante) {
	if (this == NULL)
		cout << "nó diciplina não inicializado" << endl;
	else
		this->prev = ante;
}
ListaDiciplina* ListaDiciplina::diciplinaG_anterior() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return this;
	}
	return this->prev;
}