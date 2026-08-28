#pragma once
#include "organiza.h"
#include "aluno.h"
#include "elemento_aluno.h"
class ListAluno {
	private:
	char nome[50];
	ElemAluno* cabecaA;
	ElemAluno* atualA;
	int numero_aluno;
	int capacitade_turma;
	public:
	ListAluno();
	~ListAluno();
	void setup(int cs = 45, const char* ac = "");
	void inclue_aluno(Aluno* Al);
	void print_aluno();
	void printR_aluno();
	ElemAluno* busca_Aluno(Aluno* Al);
	void remove_aluno(Aluno* Al);
};
