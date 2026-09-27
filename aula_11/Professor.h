#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_
#include"pessoa.h"
#include"universidade.h"
class Professor : public Pessoa
{
	private:
		 Universidade* trabalho;
		Departamento* localT;
		float bolsa_projeto;
		float salario;
	public:
		Professor(int diaP, int mesP, int anoP, const char* nomeP, float sal, float BP,int idO = 0);
		Professor(int idO = 0);
		~Professor();
		void setar_trabalho(Universidade* trab = NULL);
		void onde_trabalho();
		void informa_provedos();
		void setar_derpa(Departamento* depT = NULL);
		void qual_derpa();
};

#endif _PROFESSOR_H_
