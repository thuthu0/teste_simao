#pragma once
#include"organiza.h"
template<class TIPO>
class Elemento
{
private:
	Elemento<TIPO> *proximo;
	Elemento<TIPO> *anterior;
	TIPO* info;
public:
	Elemento();
	~Elemento();
	TIPO* get_elem();
	void set_elem(TIPO* elem = NULL);
	Elemento<TIPO>* get_proximo();
	void set_proximo(Elemento<TIPO>* prox );
	Elemento<TIPO>* get_anterior();
	void set_anterior(Elemento<TIPO>* ante );

};
template<class TIPO>
Elemento<TIPO>::Elemento()
{
	proximo = NULL;
	anterior = NULL;
	info = NULL;
}
template<class TIPO>
Elemento<TIPO>::~Elemento()
{
	proximo = NULL;
	anterior = NULL;
	info = NULL;
}
template<class TIPO>
TIPO* Elemento<TIPO>::get_elem() {
	return info;
}
template<class TIPO>
void Elemento<TIPO>::set_elem(TIPO* elem) {
	info = elem;
}
template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_proximo() {
	return proximo;
}
template<class TIPO>
void Elemento<TIPO>::set_proximo(Elemento<TIPO>* prox) {
	proximo = prox;
}
template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_anterior() {
	return anterior;
}
template<class TIPO>
void Elemento<TIPO>::set_anterior(Elemento<TIPO>* ante) {
	anterior = ante;
}