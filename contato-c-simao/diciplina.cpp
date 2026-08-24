#include"diciplina.h"
#include "departamento.h"
#include "aluno.h"
Diciplina::Diciplina() {
	setup();
}
Diciplina::~Diciplina() {
	depD = NULL;
	next = NULL;
	prev = NULL;
}
void Diciplina::setup(int ct, const char* ac) {
	depD = NULL;
	next = NULL;
	prev = NULL;
	id = -1;
	strcpy_s(nome, sizeof(nome), "");
	strcpy_s(area_conhecimento, sizeof(area_conhecimento), ac);
	cabecaA = NULL;
	atualA = NULL;
	numero_aluno = 0;
	capacitade_turma = ct;

}
void Diciplina::set_id(int n) {
	id = n;
}
void Diciplina::print_id() {
	cout << "id: " << id << endl;
}
int Diciplina::get_id() {
	return id;
}
void Diciplina::set_nome(const char* c) {
	strcpy_s(nome, sizeof(nome), c);
}
void Diciplina::print_nome() {
	cout << "Diciplina: " << nome << endl;
}
char* Diciplina::get_nome() {
	return nome;
}
void Diciplina::set_depDis(Derpatamento* depDi) {
	depD = depDi;
	depDi->inclue_diciplina(this);
}
void Diciplina::print_depDis() {
	cout << "Dicplina " << nome;
}
Derpatamento* Diciplina::get_depDis() {
	return depD;
}
void Diciplina::inclue_aluno(Aluno* Al) {
	if (Al == NULL || numero_aluno >= capacitade_turma) {
		if (Al == NULL)
			cout << "Tentativa de colocar nulidade em Aluno" << endl;
		else
			cout << "Maximo de alunos na turma, por favor verifique o tamanho da turma" << endl;
		return;
	}
	if (cabecaA == NULL) {
		cabecaA = Al;
		atualA = Al;
	}
	else {
		int i, fim = 0;
		Aluno* temp, *pasage;
		for (i = 0, temp = atualA; fim == 0; i++) {
			if (Al->get_charac(i) < temp->get_charac(i) || Al->get_charac(i) == '\0') {
				if (temp == cabecaA) {
					temp->alunoS_anterior(Al);
					Al->alunoS_proximo(temp);
					cabecaA = Al;
					fim = 1;
				}
				else {
					temp = temp->alunoG_anterior();
					i = 0;
				}
			}
			else if (Al->get_charac(i) > temp->get_charac(i) || temp->get_charac(i) == '\0') {
				if (temp == atualA) {
					temp->alunoS_proximo(Al);
					Al->alunoS_anterior(temp);
					atualA = Al;
					fim = 1;
				}
				else {
					pasage = temp->alunoG_proximo();
					pasage->alunoS_anterior(Al);
					temp->alunoS_proximo(Al);
					Al->alunoS_proximo(pasage);
					Al->alunoS_anterior(temp);
					fim = 1;
				}
			}
		}
		/*atualA->alunoS_proximo(Al);
		Al->alunoS_anterior(atualA);
		atualA = atualA->alunoG_proximo();*/
	}
}
void Diciplina::print_aluno() {
	if (cabecaA == NULL)
		return;
	Aluno* temp;
	for (temp = cabecaA; temp != NULL; temp = temp->alunoG_proximo()){
		temp->print_nome();
		temp->print_RA();
		}
}
void Diciplina::printR_aluno() {
	if (cabecaA == NULL)
		return;
	Aluno* temp;
	for (temp = atualA; temp != NULL; temp = temp->alunoG_anterior()) {
		temp->print_nome();
		temp->print_RA();
	}
}
void Diciplina::remove_aluno(Aluno* Al) {
	if (Al == NULL || numero_aluno <= 0) {
		if (Al == NULL)
			cout << "Tentativa de remover nulidade" << endl;
		else
			cout << "Turma com zero Alunos, verifique a quatidade de alunos" << endl;
		return;
	}
	Aluno* temp = cabecaA;
	if (Al == cabecaA) {
		cabecaA = cabecaA->alunoG_proximo();
		temp->alunoS_proximo(NULL);
		cabecaA->alunoS_anterior(NULL);
		temp = NULL;
	}
	else if (Al == atualA) {
		temp = atualA;
		atualA = atualA->alunoG_anterior();
		atualA->alunoS_proximo(NULL);
		temp->alunoS_anterior(NULL);
		temp = NULL;
	}
	else {
		while (temp->alunoG_proximo() != Al)
			temp = temp->alunoG_proximo();
		temp->alunoS_proximo(temp->alunoG_proximo()->alunoG_proximo());//= temp->next->next;
		temp = temp->alunoG_proximo();
		temp->alunoS_anterior(temp->alunoG_anterior()->alunoG_anterior());// = temp->prev->prev;
		Al->alunoS_proximo(NULL); //= NULL;
		Al->alunoS_anterior(NULL);// = NULL;
		Al = NULL;
	}
}
void Diciplina::diciplinaS_proximo(Diciplina* prox) {
	if(this == NULL)
		cout << "nó diciplina não inicializado" << endl;

	else
		this->next = prox;
}
Diciplina* Diciplina::diciplinaG_proximo() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return this;
	}
	return this->next;
}
void Diciplina::diciplinaS_anterior(Diciplina* ante) {
	if (this == NULL)
		cout << "nó diciplina não inicializado" << endl;
	else
	this->prev = ante;
}
Diciplina* Diciplina::diciplinaG_anterior() {
	if (this == NULL) {
		cout << "nó diciplina não inicializado" << endl;
		return this;
	}
	return this->prev;
}