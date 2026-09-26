#pragma once
#include"organiza.h"
#include "elemento.h"
template<class TIPO>
class Lista {
	private:
		Elemento<TIPO>*cabeca;
		Elemento<TIPO>*atual;
	public:
		Lista();
		~Lista();
		Elemento<TIPO>*get_cabeca();
		void set_cabeca(Elemento<TIPO> *cab);
		Elemento<TIPO>*get_atual();
		void set_atual(Elemento<TIPO> *rabo);
		void aterrar();
		void destroy();
};
template<class TIPO>
Lista<TIPO>::Lista() {
	aterrar();
}
template<class TIPO>
Lista<TIPO>::~Lista() {
	destroy();
}
template<class TIPO>
void Lista<TIPO>::aterrar() {
	cabeca = NULL;
	atual = NULL;
}
template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::get_atual() {
	return atual;
}
template<class TIPO>
void Lista<TIPO>::set_atual(Elemento<TIPO> *rabo) {
	atual = rabo;
}
template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::get_cabeca() {
	return cabeca;
}
template<class TIPO>
void Lista<TIPO>::set_cabeca(Elemento<TIPO>* cab) {
	cabeca = cab;
}
template<class TIPO>
void Lista<TIPO>::destroy() {
	Elemento<TIPO> *temp = NULL, *depois = NULL;
	for (temp = cabeca; temp != NULL; temp = depois) {
		depois = temp->get_proximo();
		delete temp;
	}
	aterrar();
}


