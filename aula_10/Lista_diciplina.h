#pragma once
#include"organiza.h"
//#include "elemento_diciplina.h"
//#include "diciplina.h"
template<class TIPO>
class Elemento;
class Diciplina;
class ListaDiciplina {
	private:
		char nome[50];
		Elemento<Diciplina>* atualD;
		Elemento<Diciplina>* cabecaD;
	public:
		ListaDiciplina();
		~ListaDiciplina();
		Elemento<Diciplina>* get_cabecaD();
		Elemento<Diciplina>* get_atualD();
		void set_Lderpa_nome(const char* npmeDL = "");
		void inclue_diciplina(Diciplina* di);
		void print_diciplina();
		void printR_diciplina();
		Elemento<Diciplina>* busca_diciplina(Diciplina* di);
		void remove_diciplina(Diciplina* di);
		void destroy_lista();
		void salva_diciplina();
		void registra_diciplina();
};
