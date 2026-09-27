#pragma once
#include "organiza.h"
#include "Aluno.h"
class Estagiario : public Aluno {
	private:
		float bolsa_estudo;
	public:
		Estagiario(int diaP, int mesP, int anoP, const char* nomeP, float BE,int idO = 0);
		Estagiario(int idO = 0);
		~Estagiario();
		void informa_provedos();
};
