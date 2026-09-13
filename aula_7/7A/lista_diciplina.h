#pragma once
#include "organiza.h"
#include "diciplina.h"
class ListaDiciplina {
	private:
		Diciplina* materia;
		ListaDiciplina* next;
		ListaDiciplina* prev;
	public:
		ListaDiciplina();
		~ListaDiciplina();
		void colo_diciplina(Diciplina* Di);
		Diciplina* posicao_diciplina();
		void diciplinaS_proximo(ListaDiciplina* prox = NULL);
		ListaDiciplina* diciplinaG_proximo();
		void diciplinaS_anterior(ListaDiciplina* ante = NULL);
		ListaDiciplina* diciplinaG_anterior();
};
