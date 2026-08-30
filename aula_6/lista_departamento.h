#pragma once
#include "organiza.h"
class ElemDepartamento;
class Departamento;
class ListaDepartamento {
	private:
		char nome[50];
		ElemDepartamento* cabecaDep;
		ElemDepartamento* atualDep;
		int id;
	public:
		ListaDepartamento();
		~ListaDepartamento();
		ElemDepartamento* get_cabecaDep();
		ElemDepartamento* get_atualDep();
		Departamento* buscaN_departamento(const char* nomeDep);
		void set_nomeD(const char* nomeLdep);
		void inclue_departamento(Departamento* dep);
		void print_departamento();
		void printR_departamento();
		ElemDepartamento* busca_departamento(Departamento* dep);
		void remove_departamento(Departamento* dep);

};
