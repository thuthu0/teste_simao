#include"lista_aluno.h"
#include "aluno.h"
ListAluno::ListAluno() {
	setup();
}
ListAluno::~ListAluno() {
	ElemAluno* temp = NULL, * depois = NULL;
	for (temp = cabecaA; temp != NULL; temp = depois) {
		depois = temp->alunoG_proximo();
		delete temp;
	}

}
void ListAluno::setup(int ct, const char* ac) {
	
	strcpy_s(nome, sizeof(nome), "");
	cabecaA = NULL;
	atualA = NULL;
	numero_aluno = 0;
	capacitade_turma = ct;

}
void ListAluno::inclue_aluno(Aluno* Al) {
	ElemAluno* aluno = new ElemAluno;
	aluno->colo_aluno(Al);
	if (Al == NULL || numero_aluno >= capacitade_turma) {
		if (Al == NULL)
			cout << "Tentativa de colocar nulidade em Aluno" << endl;
		else
			cout << "Maximo de alunos na turma, por favor verifique o tamanho da turma" << endl;
		return;
	}
	if (cabecaA == NULL) {
		cabecaA = aluno;
		atualA = aluno;
	}
	else {
		int i, fim = 0;
		ElemAluno* temp, * pasage;
		for (i = 0, temp = atualA; fim == 0; i++) {
			if (Al->get_charac(i) < temp->posicao_aluno()->get_charac(i) || Al->get_charac(i) == '\0') {
				if (temp == cabecaA) {
					temp->alunoS_anterior(aluno);
					aluno->alunoS_proximo(temp);
					cabecaA = aluno;
					fim = 1;
				}
				else {
					temp = temp->alunoG_anterior();
					i = 0;
				}
			}
			else if (Al->get_charac(i) > temp->posicao_aluno()->get_charac(i) || temp->posicao_aluno()->get_charac(i) == '\0') {
				if (temp == atualA) {
					temp->alunoS_proximo(aluno);
					aluno->alunoS_anterior(temp);
					atualA = aluno;
					fim = 1;
				}
				else {
					pasage = temp->alunoG_proximo();
					pasage->alunoS_anterior(aluno);
					temp->alunoS_proximo(aluno);
					aluno->alunoS_proximo(pasage);
					aluno->alunoS_anterior(temp);
					fim = 1;
				}
			}
		}
		/*atualA->alunoS_proximo(Al);
		Al->alunoS_anterior(atualA);
		atualA = atualA->alunoG_proximo();*/
	}
}
void ListAluno::print_aluno() {
	if (cabecaA == NULL)
		return;
	ElemAluno* temp;
	for (temp = cabecaA; temp != NULL; temp = temp->alunoG_proximo()) {
		temp->posicao_aluno()->print_nome();
		temp->posicao_aluno()->print_RA();
	}
}
void ListAluno::printR_aluno() {
	if (cabecaA == NULL)
		return;
	ElemAluno* temp;
	for (temp = atualA; temp != NULL; temp = temp->alunoG_anterior()) {
		temp->posicao_aluno()->print_nome();
		temp->posicao_aluno()->print_RA();
	}
}
ElemAluno* ListAluno::busca_Aluno(Aluno* Al) {
	ElemAluno* temp = NULL;
	int achou = 0;
	if (cabecaA == NULL) {
		cout << "Turma vazia" << endl;
		return NULL;
	}
	for (temp = cabecaA; temp != NULL || achou != 0; temp = temp->alunoG_proximo()) {
		if (temp->posicao_aluno() == Al)
			achou = 1;
	}
	if (achou == 1)
		return temp;
	cout << "nao achado" << endl;
	return NULL;

}
void ListAluno::remove_aluno(Aluno* Al) {
	ElemAluno* aluno = busca_Aluno(Al);
	if (Al == NULL || numero_aluno <= 0) {
		if (Al == NULL)
			cout << "Tentativa de remover nulidade" << endl;
		else
			cout << "Turma com zero Alunos, verifique a quatidade de alunos" << endl;
		return;
	}
	ElemAluno* temp = cabecaA;
	if (aluno == cabecaA) {
		cabecaA = cabecaA->alunoG_proximo();
		temp->alunoS_proximo(NULL);
		cabecaA->alunoS_anterior(NULL);
		delete temp;
	}
	else if (aluno == atualA) {
		temp = atualA;
		atualA = atualA->alunoG_anterior();
		atualA->alunoS_proximo(NULL);
		temp->alunoS_anterior(NULL);
		delete temp;
	}
	else {
		while (temp->alunoG_proximo() != aluno)
			temp = temp->alunoG_proximo();
		temp->alunoS_proximo(temp->alunoG_proximo()->alunoG_proximo());//= temp->next->next;
		temp = temp->alunoG_proximo();
		temp->alunoS_anterior(temp->alunoG_anterior()->alunoG_anterior());// = temp->prev->prev;
		aluno->alunoS_proximo(NULL);
		aluno->alunoS_anterior(NULL);
		delete aluno;
	}
}