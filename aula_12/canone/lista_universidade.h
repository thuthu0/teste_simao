#pragma once
#include "organiza.h"
#include "lista.h"
//class ElemUniversidade;
class Universidade;
class ListaUniversidade {
	private:
		char nome[50];
		Lista<Universidade> listauniversidade;
	public:
		ListaUniversidade();
		~ListaUniversidade();
		Elemento<Universidade>* get_cabecaUni();
		Elemento<Universidade>* get_atualUni();
		Universidade* buscaN_universidade(const char* nomeUni);
		void set_nomeUni(const char* nomeUni = "");
		void inclue_universidade(Universidade* uni);
		void print_universidade();
		void printR_universidade();
		Elemento<Universidade>* busca_universidade(Universidade* uni);
		void remove_universidade(Universidade* uni);
		void salva_universidade();
		void registra_universidade();
};
