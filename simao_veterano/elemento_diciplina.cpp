#include "elemento_diciplina.h"
ElemDiciplina::ElemDiciplina() {
	materia = NULL;
	next = NULL;
	prev = NULL;
}
ElemDiciplina::~ElemDiciplina() {
	materia = NULL;
	next = NULL;
	prev = NULL;
}
void ElemDiciplina::colo_diciplina(Diciplina* Di) {
	if (this == NULL)
		cout << "nó diciplina não inicializado" << endl;
	else
		this->materia = Di;
}
Diciplina* ElemDiciplina:: posicao_diciplina() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return NULL;
	}
	return this->materia;
}
void ElemDiciplina::diciplinaS_proximo(ElemDiciplina* prox) {
	if (this == NULL)
		cout << "nó diciplina não inicializado" << endl;

	else
		this->next = prox;
}
ElemDiciplina* ElemDiciplina::diciplinaG_proximo() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return this;
	}
	return this->next;
}
void ElemDiciplina::diciplinaS_anterior(ElemDiciplina* ante) {
	if (this == NULL)
		cout << "nó diciplina não inicializado" << endl;
	else
		this->prev = ante;
}
ElemDiciplina* ElemDiciplina::diciplinaG_anterior() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return this;
	}
	return this->prev;
}