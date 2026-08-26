#pragma once
#include "organiza.h"
#include "aluno.h"
#include "diciplina.h"
class ListAluno {
	private:
		Aluno* estudante;
		ListAluno* next;
		ListAluno* prev;
		int parcial_1;
		int parcial_2;
		int nota;
		int presença;
		int diaLetivo;
	public:
		ListAluno();
		~ListAluno();
		void colo_aluno(Aluno* Al);
		Aluno* posicao_aluno();
		void alunoS_proximo(ListAluno* prox = NULL);
		ListAluno* alunoG_proximo();
		void  alunoS_anterior(ListAluno* ante = NULL);
		ListAluno* alunoG_anterior();
		void set_primeira_nota(int i);
		void set_segunda_nota(int i);
		void set_nota_final();
		int get_primeira_nota();
		int get_segunda_nota();
		int get_nota_final();
		void set_frequencia(int i);
		int get_presente();
		int get_diaLetivo();
};
