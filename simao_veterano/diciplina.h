#pragma once
#include"organiza.h"
class Aluno;
class Derpatamento;
class ListAluno;
class Diciplina {
	private:
		char nome[50];
		char area_conhecimento[50];
		int id;
		Derpatamento* depD;
		ListAluno* cabecaA;
		ListAluno* atualA;
		int numero_aluno;
		int capacitade_turma;
		//Diciplina* next;
		//Diciplina* prev;

	public:
		Diciplina();
		~Diciplina();
		void setup(int cs = 45 , const char* ac = "");
		void set_id(int n);
		void print_id();
		int get_id();
		void set_nome(const char* c);
		void print_nome();
		char* get_nome();
		void set_depDis(Derpatamento* depDi);
		void print_depDis();
		Derpatamento* get_depDis();
		void inclue_aluno(Aluno* Al);
		void print_aluno();
		void printR_aluno();
		ListAluno* busca_Aluno(Aluno* Al);
		void remove_aluno(Aluno* Al);
		/*void diciplinaS_proximo(Diciplina* prox = NULL);
		Diciplina* diciplinaG_proximo();
		void diciplinaS_anterior(Diciplina* ante = NULL);
		Diciplina* diciplinaG_anterior();*/

};