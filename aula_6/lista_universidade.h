#pragma once
#include "organiza.h"
class ElemUniversidade;
class Universidade;
class ListaUniversidade {
	private:
		char nome[50];
		ElemUniversidade* cabecaUni;
		ElemUniversidade* atualUni;
		int id;
	public:
		ListaUniversidade();
		~ListaUniversidade();
		ElemUniversidade* get_cabecaUni();
		ElemUniversidade* get_atualUni();
		Universidade* buscaN_universidade(const char* nomeUni);
		void set_nomeUni(const char* nomeUni = "");
		void inclue_universidade(Universidade* uni);
		void print_universidade();
		void printR_universidade();
		ElemUniversidade* busca_universidade(Universidade* uni);
		void remove_universidade(Universidade* uni);
};
