#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_
#include"organiza.h"
class Universidade;
class ListaDiciplina;
class Diciplina;
class Derpatamento {
	private:
	char nome[30];
	ListaDiciplina* atualD;
	ListaDiciplina* cabcaD;
	Universidade* uni;

	public:
		Derpatamento();
		~Derpatamento();
		void set_departamento(const char* nomeD = "");
		char *qual_departamento();
		void print_dep();
		Universidade* set_uni(Universidade* uniD = NULL);
		void print_uni();
		void inclue_diciplina(Diciplina* di);
		void print_diciplina();
		void print_reverse();
		ListaDiciplina* busca_diciplina(Diciplina* Di);
		void remove_diciplina(Diciplina* di);
};
#endif