#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_
#include"organiza.h"
#include "Lista_diciplina.h"
class Universidade;
class ElemDiciplina;
class Diciplina;
class Departamento {
	private:
	char nome[30];
	Universidade* uni;
	ListaDiciplina matriz;
	int id;

	public:
		Departamento();
		~Departamento();
		void set_departamento(const char* nomeD = "");
		char *qual_departamento();
		void print_dep();
		Universidade* set_uni(Universidade* uniD = NULL);
		void print_uni();
		void inclue_diciplina(Diciplina* di);
		void print_diciplina();
		void print_reverse();
		ElemDiciplina* busca_diciplina(Diciplina* Di);
		void remove_diciplina(Diciplina* di);
};
#endif