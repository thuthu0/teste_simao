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
		int id;
	public:
		Universidade(int idO = 0);
		~Universidade();
		void set_id(int n = 0);
		int get_id();
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