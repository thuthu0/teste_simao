#pragma once
#include"organiza.h"
//#include "elemento_diciplina.h"
//#include "diciplina.h"
class ElemDiciplina;
class Diciplina;
class ListaDiciplina {
	private:
		char nome[50];
		ElemDiciplina* atualD;
		ElemDiciplina* cabecaD;
	public:
		ListaDiciplina();
		~ListaDiciplina();
		void set_Lderpa_nome(const char* npmeDL = "");
		void inclue_diciplina(Diciplina* di);
		void print_diciplina();
		void printR_diciplina();
		ElemDiciplina* busca_diciplina(Diciplina* di);
		void remove_diciplina(Diciplina* di);
};
