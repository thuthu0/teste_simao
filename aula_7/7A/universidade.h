#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_
#include"departamento.h"
#include"organiza.h"
class Universidade {
	private:
		char nome[30];
		vector <Derpatamento*> dep;
	public:
		Universidade();
		~Universidade();
		void sua_uni(const char* nomeU = "");
		char * qual_uni();
		void incluie_dep(Derpatamento* depU = NULL);
		void print_dep();
		/*Derpatamento* aloca_dep(const char* nomeD);
		void desloca_dep();*/
};

#endif