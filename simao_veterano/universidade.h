#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_
#include"departamento.h"
#include "lista_departamento.h"
#include"organiza.h"
class Universidade {
	private:
		char nome[30];
		//vector <Departamento*> dep;
		ListaDepartamento matriz;
	public:
		Universidade();
		~Universidade();
		void sua_uni(const char* nomeU = "");
		char * qual_uni();
		/*void incluie_dep(Departamento* depU = NULL);
		void print_dep();*/
		void inclue_departamento(Departamento* dep);
		void print_departamento();
		void printR_departamento();
		void remove_departamento(Departamento* dep);
		/*Derpatamento* aloca_dep(const char* nomeD);
		void desloca_dep();*/
};

#endif