#pragma once
#include"organiza.h"
#include"lista.h"
class Pessoa;
class ListaPessoa {
	private:
		Lista<Pessoa> listapessoa;
		char nome[60];
	public:
		ListaPessoa();
		~ListaPessoa();
		void inclue_pessoa(Pessoa* P);
		void print_pessoa();
		void printR_pessoa();
		Elemento<Pessoa>* busca_pessoa(Pessoa* P);
		void remove_pessoa(Pessoa* P);
		void salva_pessoa();
		void registra_pessoa();
};