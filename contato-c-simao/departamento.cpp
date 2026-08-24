#include "universidade.h"
#include"departamento.h"
Derpatamento::Derpatamento() {
	set_departamento();
	atualD = NULL;
	cabcaD = NULL;
}
Derpatamento::~Derpatamento() {

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
	if (di == NULL) {
		printf("erro diciplina com valor nulo");
		return;
	}
		if (cabcaD == NULL) {
			cabcaD = di;
			atualD = di;
		}
		else {
			Diciplina* temp = atualD;
			atualD->diciplinaS_proximo(di);//di;
			atualD = atualD->diciplinaG_proximo();
			atualD->diciplinaS_anterior(temp);// = temp;
		}
	
}
void Derpatamento::print_diciplina() {
	Diciplina* temp;
	cout << "as diciplinas que fazem parte do departamento " << nome << " sao " << endl;
	for (temp = cabcaD; temp != NULL; temp = temp->diciplinaG_proximo()) {
		temp->print_depDis();
		cout << " do " << nome << endl;
	}
}
void Derpatamento::print_reverse() {
	Diciplina* temp;
	cout << "as diciplinas em ordem reversa do derpatamento sao " << endl;
	for (temp = atualD; temp != NULL; temp = temp->diciplinaG_anterior()) {
		temp->print_depDis();
		cout << " do " << nome << endl;
	}
}
void Derpatamento::remove_diciplina(Diciplina* di) {
	Diciplina* temp = cabcaD;
	if (di == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (di == cabcaD) {
		cabcaD = cabcaD->diciplinaG_proximo();
		cabcaD->diciplinaS_anterior(NULL);// = NULL;
		temp = NULL;
	}
	else if (di == atualD) {
		temp = atualD;
		atualD = atualD->diciplinaG_anterior();
		atualD->diciplinaS_proximo(NULL);// = NULL;
		temp = NULL;
	}
	else {
		while (temp->diciplinaG_proximo() != di)
			temp = temp->diciplinaG_proximo();
		temp->diciplinaS_proximo(temp->diciplinaG_proximo()->diciplinaG_proximo());// = temp->next->next;
		temp = temp->diciplinaG_proximo();
		temp->diciplinaS_anterior(temp->diciplinaG_anterior()->diciplinaG_anterior());// = temp->prev->prev;
		di->diciplinaS_proximo(NULL);// = NULL;
		di->diciplinaS_anterior(NULL);// = NULL;
		di = NULL;
	}
}