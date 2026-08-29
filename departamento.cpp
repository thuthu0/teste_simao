#include "universidade.h"
#include"departamento.h"
#include "elemento_diciplina.h"
#include "diciplina.h"
Departamento::Departamento() {
	set_departamento();
	uni = NULL;
}
Departamento::~Departamento() {
	uni = NULL;
}
void Departamento::set_departamento(const char* nomeU) {
	strcpy_s(nome, sizeof(nome), nomeU);
}
void Departamento::print_dep() {
	cout << "Departamento: " << endl;
}
char* Departamento::qual_departamento() {
	return nome;
}
Universidade* Departamento::set_uni(Universidade* uniD) {
	return uni = uniD;
}
void Departamento::print_uni() {
	cout << uni->qual_uni() << endl;
}
void Departamento::inclue_diciplina(Diciplina* di) {
	matriz.inclue_diciplina(di);
	
}
void Departamento::print_diciplina() {
	matriz.print_diciplina();
}
void Departamento::print_reverse() {
	matriz.printR_diciplina();
}
ElemDiciplina* Departamento::busca_diciplina(Diciplina* Di) {
	return matriz.busca_diciplina(Di);
}

void Departamento::remove_diciplina(Diciplina* di) {
	matriz.remove_diciplina(di);
}