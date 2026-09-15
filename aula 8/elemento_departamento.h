#pragma once
#include"organiza.h"
class Departamento;
class ElemDepartamento {
	private:
		ElemDepartamento* next;
		ElemDepartamento* prev;
		Departamento* da;
		int id;
	public:
		ElemDepartamento(int idO = 0);
		~ElemDepartamento();
		void set_id(int n = 0);
		void set_departamento(Departamento* dep = NULL);
		Departamento* get_departamento();
		void departamentoS_proximo(ElemDepartamento* prox = NULL);
		ElemDepartamento* departamentoG_proximo();
		void departamentoS_anterior(ElemDepartamento* ante = NULL);
		ElemDepartamento* departamentoG_anterior();
};