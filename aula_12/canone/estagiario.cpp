#include "estagiario.h"

Estagiario::Estagiario(int diaP, int mesP, int anoP, const char* nomeP, float BE, int idO) :Aluno(diaP, mesP, anoP, nomeP, idO) {
	bolsa_estudo = BE;
}
Estagiario::Estagiario(int idO) :Aluno(idO) {
	bolsa_estudo = 400;
}
Estagiario::~Estagiario(){

}

void Estagiario::informa_provedos() {
	cout << bolsa_estudo << endl;
}