#pragma once
#include "organiza.h"
#include "aluno.h"
//#include "elemento_aluno.h"
#include "lista.h"
class ListAluno {
	private:
	char nome[50];
	Lista<Aluno> listaluno;
	int numero_aluno;
	int capacitade_turma;

	public:
		ListAluno();
		~ListAluno();
		void setup(int cs = 45, const char* ac = "");
		void inclue_aluno(Aluno* Al);
		void print_aluno();
		void printR_aluno();
		Elemento<Aluno>* busca_Aluno(Aluno* Al);
		void remove_aluno(Aluno* Al);
		void salva_aluno();
		void registra_aluno();
};
