#include "elemento_departamento.h"
#include "Departamento.h"
ElemDepartamento::ElemDepartamento() {
	next = NULL;
	prev = NULL;
	da = NULL;
	id = rand();
}
ElemDepartamento::~ElemDepartamento() {
	next = NULL;
	prev = NULL;
	da = NULL;
}

void ElemDepartamento::set_departamento(Departamento* dep) {
	if (this == NULL) {
		cout << "nó departamento não inicializado" << endl;
	}
	this->da = dep;
}
Departamento* ElemDepartamento::get_departamento() {
	if (this == NULL) {
		cout << "nó departamento não inicializado" << endl;
		return NULL;
	}
	return this->da;
}
void ElemDepartamento::departamentoS_proximo(ElemDepartamento* prox) {
	if (this == NULL) {
		cout << "nó departamento não inicializado" << endl;
	}
	this->next = prox;
}
ElemDepartamento* ElemDepartamento::departamentoG_proximo() {
	if (this == NULL) {
		cout << "nó departamento não inicializado" << endl;
		return this;
	}
	return this->next;
}
void ElemDepartamento::departamentoS_anterior(ElemDepartamento* ante) {
	if (this == NULL) {
		cout << "nó departamento não inicializado" << endl;
	}
	this->prev = ante;
}
ElemDepartamento* ElemDepartamento::departamentoG_anterior() {
	if (this == NULL) {
		cout << "nó departamento não inicializado" << endl;
		return this;
	}
	return this->prev;
}