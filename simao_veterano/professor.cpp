#include"Professor.h"
Professor::Professor(int diaP, int mesP, int anoP, const char* nomeP):Pessoa( diaP,  mesP,  anoP,  nomeP)
{
	trabalho = NULL;
	localT = NULL;
}
Professor::Professor(): Pessoa() {
	trabalho = NULL;
	localT = NULL;
}
Professor::~Professor() {
	trabalho = NULL;
	localT = NULL;
}
void Professor::setar_trabalho(Universidade* trab) {
	trabalho = trab;
}
void Professor::onde_trabalho() {
	cout << nome << " trabalha na " << trabalho->qual_uni() << endl;
}
void Professor::setar_derpa(Departamento* depT) {
	localT = depT;
}
void Professor::qual_derpa() {
	cout << nome << " trabalha no departamento " << localT->qual_departamento() << " da " << trabalho->qual_uni() << endl;
}