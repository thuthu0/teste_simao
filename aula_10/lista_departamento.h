#pragma once
#include "organiza.h"
#include"lista.h"
//class ElemDepartamento;
class Departamento;
class ListaDepartamento {
	private:
		char nome[50];
		Lista<Departamento> listadepartamento;
	public:
		ListaDepartamento();
		~ListaDepartamento();
		Elemento<Departamento>* get_cabecaDep();
		Elemento<Departamento>* get_atualDep();
		Departamento* buscaN_departamento(const char* nomeDep);
		void set_nomeD(const char* nomeLdep);
		void inclue_departamento(Departamento* dep);
		void print_departamento();
		void printR_departamento();
		Elemento<Departamento>* busca_departamento(Departamento* dep);
		void remove_departamento(Departamento* dep);
		void salva_departamento();
		void registra_departamento();
};
