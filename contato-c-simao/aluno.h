#pragma once
#include "fufa.h"
class Aluno : public Pessoa {
	private:
		int RA;
		Aluno* next;
		Aluno* prev;
	public:
		Aluno(int diaP, int mesP, int anoP, const char* nomeP);
		Aluno();
		~Aluno();
		void set_RA(const int & ra);
		void print_RA();
		int get_RA();
		void alunoS_proximo(Aluno* prox = NULL);
		Aluno* alunoG_proximo();
		void  alunoS_anterior(Aluno* ante = NULL);
		Aluno* alunoG_anterior();
};