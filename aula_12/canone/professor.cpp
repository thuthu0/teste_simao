#include"Professor.h"
Professor::Professor(int diaP, int mesP, int anoP, const char* nomeP, float sal, float BP, int idO ):Pessoa( diaP,  mesP,  anoP,  nomeP, idO )
{
	trabalho = NULL;
	localT = NULL;
	salario = sal;
	bolsa_projeto = BP;
}
Professor::Professor(int idO): Pessoa(idO) {
	trabalho = NULL;
	localT = NULL;
	salario = 1000;
	bolsa_projeto = 0;
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
void Professor::informa_provedos() {
	cout << salario + bolsa_projeto << endl;
}
void Professor::setar_derpa(Departamento* depT) {
	localT = depT;
}
void Professor::qual_derpa() {
	cout << nome << " trabalha no departamento " << localT->qual_departamento() << " da " << trabalho->qual_uni() << endl;
}