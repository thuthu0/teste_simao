#include "universidade.h"
#include"departamento.h"
#include "lista_diciplina.h"
#include "diciplina.h"
Derpatamento::Derpatamento() {
	set_departamento();
	atualD = NULL;
	cabcaD = NULL;
}
Derpatamento::~Derpatamento() {
	ListaDiciplina* temp = NULL, *depois = NULL;
	for (temp = cabcaD; temp != NULL; temp = depois) {
		depois = temp->diciplinaG_proximo();
		delete temp;
	}
	atualD = NULL;
	cabcaD = NULL;
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
	ListaDiciplina* diciplina = new ListaDiciplina;
	diciplina->colo_diciplina(di);
	if (di == NULL) {
		printf("erro diciplina com valor nulo");
		return;
	}
		if (cabcaD == NULL) {
			cabcaD = diciplina;
			atualD = diciplina;
		}
		else {
			ListaDiciplina* temp = atualD;
			atualD->diciplinaS_proximo(diciplina);//di;
			atualD = atualD->diciplinaG_proximo();
			atualD->diciplinaS_anterior(temp);// = temp;
		}
	
}
void Derpatamento::print_diciplina() {
	ListaDiciplina* temp;
	cout << "as diciplinas que fazem parte do departamento " << nome << " sao " << endl;
	for (temp = cabcaD; temp != NULL; temp = temp->diciplinaG_proximo()) {
		temp->posicao_diciplina()->print_depDis();
		cout << " do " << nome << endl;
	}
}
void Derpatamento::print_reverse() {
	ListaDiciplina* temp;
	cout << "as diciplinas em ordem reversa do derpatamento sao " << endl;
	for (temp = atualD; temp != NULL; temp = temp->diciplinaG_anterior()) {
		temp->posicao_diciplina()->print_depDis();
		cout << " do " << nome << endl;
	}
}
ListaDiciplina* Derpatamento::busca_diciplina(Diciplina* Di) {
	ListaDiciplina* temp = NULL;
	int achou = 0;
	if (cabcaD == NULL) {
		cout << "Turma vazia" << endl;
		return NULL;
	}
	for (temp = cabcaD; temp != NULL || achou != 0; temp = temp->diciplinaG_proximo()) {
		if (temp->posicao_diciplina() == Di)
			achou = 1;
	}
	if (achou == 1)
		return temp;
	cout << "nao achado" << endl;
	return NULL;
}

void Derpatamento::remove_diciplina(Diciplina* di) {
	ListaDiciplina* temp = cabcaD, *diciplina;
	diciplina = busca_diciplina(di);
	if (di == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (diciplina == cabcaD) {
		cabcaD = cabcaD->diciplinaG_proximo();
		cabcaD->diciplinaS_anterior(NULL);// = NULL;
		delete temp;
	}
	else if (diciplina == atualD) {
		temp = atualD;
		atualD = atualD->diciplinaG_anterior();
		atualD->diciplinaS_proximo(NULL);// = NULL;
		delete temp;
	}
	else {
		while (temp->diciplinaG_proximo() != diciplina)
			temp = temp->diciplinaG_proximo();
		temp->diciplinaS_proximo(temp->diciplinaG_proximo()->diciplinaG_proximo());// = temp->next->next;
		temp = temp->diciplinaG_proximo();
		temp->diciplinaS_anterior(temp->diciplinaG_anterior()->diciplinaG_anterior());// = temp->prev->prev;
		diciplina->diciplinaS_proximo(NULL);// = NULL;
		diciplina->diciplinaS_anterior(NULL);// = NULL;
		delete diciplina;
	}
}