#include "universidade.h"
#include"departamento.h"
#include "elemento_diciplina.h"
#include "diciplina.h"
Derpatamento::Derpatamento() {
	set_departamento();
	uni = NULL;
}
Derpatamento::~Derpatamento() {
	uni = NULL;
}
void Derpatamento::set_departamento(const char* nomeU) {
	strcpy_s(nome, sizeof(nome), nomeU);
}
void Derpatamento::print_dep() {
	cout << "Departamento: " << endl;
}
char* Derpatamento::qual_departamento() {
	return nome;
}
Universidade* Derpatamento::set_uni(Universidade* uniD) {
	return uni = uniD;
}
void Derpatamento::print_uni() {
	cout << uni->qual_uni() << endl;
}
void Derpatamento::inclue_diciplina(Diciplina* di) {
	matriz.inclue_diciplina(di);
	
}
void Derpatamento::print_diciplina() {
	matriz.print_diciplina();
}
void Derpatamento::print_reverse() {
	matriz.printR_diciplina();
}
ElemDiciplina* Derpatamento::busca_diciplina(Diciplina* Di) {
	return matriz.busca_diciplina(Di);
}

void Derpatamento::remove_diciplina(Diciplina* di) {
	matriz.remove_diciplina(di);
}