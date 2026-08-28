#pragma once
#include "organiza.h"
class Aluno;
class ElemAluno {
	private:
		Aluno* estudante;
		ElemAluno* next;
		ElemAluno* prev;
		int parcial_1;
		int parcial_2;
		int nota;
		int presença;
		int diaLetivo;
	public:
		ElemAluno();
		~ElemAluno();
		void colo_aluno(Aluno* Al);
		Aluno* posicao_aluno();
		void alunoS_proximo(ElemAluno* prox = NULL);
		ElemAluno* alunoG_proximo();
		void  alunoS_anterior(ElemAluno* ante = NULL);
		ElemAluno* alunoG_anterior();
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
