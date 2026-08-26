#include"aluno.h"
Aluno::Aluno(int diaP, int mesP, int anoP, const char* nomeP) :Pessoa(diaP, mesP, anoP, nomeP) {
	RA = -1;
	//next = NULL;
	//prev = NULL;
}
Aluno::Aluno() :Pessoa() {
	RA = -1;
	//next = NULL;
	//prev = NULL;
}
Aluno::~Aluno() {
	RA = -1;
	//next = NULL;
	//prev = NULL;
}
void Aluno::set_RA(const int & ra) {
	RA = ra;
}
void Aluno::print_RA() {
	cout << "RA: " << RA << endl;
}
int Aluno::get_RA() {
	return RA;
}
//void Aluno::alunoS_proximo(Aluno* prox) {
//	if (this == NULL)
//		cout << "nó aluno não inicializado" << endl;
//
//	else
//		this->next = prox;
//}
//Aluno* Aluno::alunoG_proximo() {
//	if (this == NULL) {
//		cout << "nó aluno não inicializado" << endl;
//		return this;
//	}
//	return this->next;
//}
//void Aluno::alunoS_anterior(Aluno* ante) {
//	if (this == NULL)
//		cout << "nó aluno não inicializado" << endl;
//
//	else
//		this->prev = ante;
//}
//Aluno* Aluno::alunoG_anterior() {
//	if (this == NULL) {
//		cout << "nó aluno não inicializado" << endl;
//		return this;
//	}
//	return this->prev;
//}