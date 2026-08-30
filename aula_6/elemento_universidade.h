#pragma once
#include "organiza.h"
class Universidade;
class ElemUniversidade {
	private:
		Universidade* ua;
		ElemUniversidade* next;
		ElemUniversidade* prev;
		int id;
	public:
		ElemUniversidade();
		~ElemUniversidade();
		Universidade* get_universidade();
		void set_universidade(Universidade* uni = NULL);
		void universidadeS_proximo(ElemUniversidade* uni = NULL);
		ElemUniversidade* universidadeG_proximo();
		void universidadeS_anterior(ElemUniversidade* uni = NULL);
		ElemUniversidade* universidadeG_anterior();
};
