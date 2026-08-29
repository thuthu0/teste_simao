#include "elemento_universidade.h"
#include "universidade.h"
ElemUniversidade::ElemUniversidade() {
	next = NULL;
	prev = NULL;
	ua = NULL;
}
ElemUniversidade::~ElemUniversidade() {
	next = NULL;
	prev = NULL;
	ua = NULL;
}
void ElemUniversidade::set_universidade(Universidade* uni) {
	if (this == NULL) {
		cout << "nó universidade não inicializado" << endl;
	}
	this->ua = uni;
}
Universidade* ElemUniversidade::get_universidade() {
	if (this == NULL) {
		cout << "nó universidade não inicializado" << endl;
		return NULL;
	}
	return this->ua;
}
void ElemUniversidade::universidadeS_proximo(ElemUniversidade* uni) {
	if (this == NULL) {
		cout << "nó universidade não inicializado" << endl;
	}
	this->next= uni;
}
ElemUniversidade* ElemUniversidade::universidadeG_proximo() {
	if (this == NULL) {
		cout << "nó universidade não inicializado" << endl;
		return NULL;
	}
	return this->next;
}
void ElemUniversidade::universidadeS_anterior(ElemUniversidade* uni) {
	if (this == NULL) {
		cout << "nó universidade não inicializado" << endl;
	}
	this->prev = uni;
}
ElemUniversidade* ElemUniversidade::universidadeG_anterior() {
	if (this == NULL) {
		cout << "nó universidade não inicializado" << endl;
		return NULL;
	}
	return this->prev;
}
