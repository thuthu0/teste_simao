#include "lista_aluno.h"
ListAluno::ListAluno() {
	nota = -1;
	parcial_1 = -1;
	parcial_2 = -1;
	presença = 0;
	diaLetivo = 300;
	estudante = NULL;
	next = NULL;
	prev = NULL;
}

ListAluno :: ~ListAluno() {
	nota = -1;
	parcial_1 = -1;
	parcial_2 = -1;
	presença = 0;
	diaLetivo = 0;
	estudante = NULL;
	next = NULL;
	prev = NULL;
}
void ListAluno:: colo_aluno(Aluno* Al) {
	if (this == NULL)
		cout << "nó aluno não inicializado" << endl;
	else
		this->estudante = Al;
}
Aluno* ListAluno::posicao_aluno() {
	if (this == NULL) {
		cout << "nó aluno não inicializado" << endl;
		return NULL;
	}

	return this->estudante;
}
void ListAluno::alunoS_proximo(ListAluno* prox) {
	if (this == NULL)
		cout << "nó aluno não inicializado" << endl;

	else
		this->next = prox;
}
ListAluno* ListAluno::alunoG_proximo() {
	if (this == NULL) {
		cout << "nó aluno não inicializado" << endl;
		return this;
	}
	return this->next;
}
void ListAluno::alunoS_anterior(ListAluno* ante) {
	if (this == NULL)
		cout << "nó aluno não inicializado" << endl;

	else
		this->prev = ante;
}
ListAluno* ListAluno::alunoG_anterior() {
	if (this == NULL) {
		cout << "nó aluno não inicializado" << endl;
		return this;
	}
	return this->prev;
}
void ListAluno::set_primeira_nota(int i) {
	parcial_1 = i;
}
void ListAluno::set_segunda_nota(int i) {
	parcial_2 = i;
}
void ListAluno::set_nota_final() {
	nota = (get_primeira_nota() + get_segunda_nota())/2;
}
int ListAluno::get_primeira_nota() {
	return parcial_1;
}
int ListAluno::get_segunda_nota() {
	return parcial_2;
}
int ListAluno::get_nota_final() {
	return nota;
}
void ListAluno::set_frequencia(int i) {
	presença = i;
}
int ListAluno::get_presente() {
	return presença;
}
int ListAluno::get_diaLetivo() {
	return diaLetivo;
}