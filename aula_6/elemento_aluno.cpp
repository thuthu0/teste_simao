#include "elemento_aluno.h"
#include "aluno.h"
ElemAluno::ElemAluno() {
	nota = -1;
	parcial_1 = -1;
	parcial_2 = -1;
	presença = 0;
	diaLetivo = 300;
	estudante = NULL;
	next = NULL;
	prev = NULL;
}

ElemAluno :: ~ElemAluno() {
	nota = -1;
	parcial_1 = -1;
	parcial_2 = -1;
	presença = 0;
	diaLetivo = 0;
	estudante = NULL;
	next = NULL;
	prev = NULL;
}
void ElemAluno:: colo_aluno(Aluno* Al) {
	if (this == NULL)
		cout << "nó aluno não inicializado" << endl;
	else
		this->estudante = Al;
}
Aluno* ElemAluno::posicao_aluno() {
	if (this == NULL) {
		cout << "nó aluno não inicializado" << endl;
		return NULL;
	}

	return this->estudante;
}
void ElemAluno::alunoS_proximo(ElemAluno* prox) {
	if (this == NULL)
		cout << "nó aluno não inicializado" << endl;

	else
		this->next = prox;
}
ElemAluno* ElemAluno::alunoG_proximo() {
	if (this == NULL) {
		cout << "nó aluno não inicializado" << endl;
		return this;
	}
	return this->next;
}
void ElemAluno::alunoS_anterior(ElemAluno* ante) {
	if (this == NULL)
		cout << "nó aluno não inicializado" << endl;

	else
		this->prev = ante;
}
ElemAluno* ElemAluno::alunoG_anterior() {
	if (this == NULL) {
		cout << "nó aluno não inicializado" << endl;
		return this;
	}
	return this->prev;
}
void ElemAluno::set_primeira_nota(int i) {
	parcial_1 = i;
}
void ElemAluno::set_segunda_nota(int i) {
	parcial_2 = i;
}
void ElemAluno::set_nota_final() {
	nota = (get_primeira_nota() + get_segunda_nota())/2;
}
int ElemAluno::get_primeira_nota() {
	return parcial_1;
}
int ElemAluno::get_segunda_nota() {
	return parcial_2;
}
int ElemAluno::get_nota_final() {
	return nota;
}
void ElemAluno::set_frequencia(int i) {
	presença = i;
}
int ElemAluno::get_presente() {
	return presença;
}
int ElemAluno::get_diaLetivo() {
	return diaLetivo;
}