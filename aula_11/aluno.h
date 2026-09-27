#pragma once
#include "pessoa.h"
class Aluno : public Pessoa {
	protected:
		int RA;
	public:
		Aluno(int diaP, int mesP, int anoP, const char* nomeP, int idO = 0);
		Aluno(int idO = 0);
		~Aluno();
		void set_RA(const int & ra);
		void print_RA();
		int get_RA();
		/*void alunoS_proximo(Aluno* prox = NULL);
		Aluno* alunoG_proximo();
		void  alunoS_anterior(Aluno* ante = NULL);
		Aluno* alunoG_anterior();*/
};