#pragma once
#include "organiza.h"

class Diciplina;
class ElemDiciplina {
	private:
		Diciplina* materia;
		ElemDiciplina* next;
		ElemDiciplina* prev;
		int id;
	public:
		ElemDiciplina(int idO = 0);
		~ElemDiciplina();
		void set_id(int n = 0);
		void colo_diciplina(Diciplina* Di);
		Diciplina* posicao_diciplina();
		void diciplinaS_proximo(ElemDiciplina* prox = NULL);
		ElemDiciplina* diciplinaG_proximo();
		void diciplinaS_anterior(ElemDiciplina* ante = NULL);
		ElemDiciplina* diciplinaG_anterior();
};
