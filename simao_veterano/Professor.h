#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_
#include"pessoa.h"
#include"universidade.h"
class Professor : public Pessoa
{
	private:
	 Universidade* trabalho;
	 Derpatamento* localT;
	public:
		Professor(int diaP, int mesP, int anoP, const char* nomeP);
		Professor();
		~Professor();
		void setar_trabalho(Universidade* trab = NULL);
		void onde_trabalho();
		void setar_derpa(Derpatamento* depT = NULL);
		void qual_derpa();
};

#endif _PROFESSOR_H_
