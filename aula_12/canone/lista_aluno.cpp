#include"lista_aluno.h"
#include "aluno.h"
ListAluno::ListAluno() {
	setup();
}
ListAluno::~ListAluno() {
	listaluno.destroy();
}
void ListAluno::setup(int ct, const char* ac) {
	
	strcpy_s(nome, sizeof(nome), "");
	listaluno.aterrar();
	numero_aluno = 0;
	capacitade_turma = ct;

}
void ListAluno::inclue_aluno(Aluno* Al) {
	Elemento<Aluno>* aluno = new Elemento<Aluno>;
	aluno->set_elem(Al);
	if (Al == NULL || numero_aluno >= capacitade_turma) {
		if (Al == NULL)
			cout << "Tentativa de colocar nulidade em Aluno" << endl;
		else
			cout << "Maximo de alunos na turma, por favor verifique o tamanho da turma" << endl;
		return;
	}
	if (listaluno.get_cabeca() == NULL) {
		listaluno.set_cabeca(aluno);//listaluno.cabeca = aluno;
		listaluno.set_atual(aluno);//listaluno.atual = aluno;
	}
	else {
		int i, fim = 0;
		Elemento<Aluno>* temp, * pasage;
		for (i = 0, temp = listaluno.get_atual(); fim == 0; i++) {
			if (Al->get_charac(i) < temp->get_elem()->get_charac(i) || Al->get_charac(i) == '\0') {
				if (temp == listaluno.get_cabeca()) {
					temp->set_anterior(aluno);
					aluno->set_proximo(temp);
					listaluno.set_cabeca(aluno);//cabecaA = aluno;
					fim = 1;
				}
				else {
					temp = temp->get_anterior();
					i = 0;
				}
			}
			else if (Al->get_charac(i) > temp->get_elem()->get_charac(i) || temp->get_elem()->get_charac(i) == '\0') {
				if (temp == listaluno.get_atual()) {
					temp->set_proximo(aluno);
					aluno->set_anterior(temp);
					listaluno.set_atual(aluno);//atualA = aluno;
					fim = 1;
				}
				else {
					pasage = temp->get_proximo();
					pasage->set_anterior(aluno);
					temp->set_proximo(aluno);
					aluno->set_proximo(pasage);
					aluno->set_anterior(temp);
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
	if (listaluno.get_cabeca() == NULL)
		return;
	Elemento<Aluno>* temp;
	for (temp = listaluno.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
		temp->get_elem()->print_nome();
		temp->get_elem()->print_RA();
	}
}
void ListAluno::printR_aluno() {
	if (listaluno.get_cabeca() == NULL)
		return;
	Elemento<Aluno>* temp;
	for (temp = listaluno.get_atual(); temp != NULL; temp = temp->get_anterior()) {
		temp->get_elem()->print_nome();
		temp->get_elem()->print_RA();
	}
}
Elemento<Aluno>* ListAluno::busca_Aluno(Aluno* Al) {
	Elemento<Aluno>* temp = NULL;
	if (listaluno.get_cabeca() == NULL) {
		cout << "Turma vazia" << endl;
		return NULL;
	}
	for (temp = listaluno.get_cabeca(); temp != NULL; temp = temp->get_proximo()) {
		if (temp->get_elem() == Al)
			return temp;
	}	
	cout << "nao achado" << endl;
	return NULL;

}
void ListAluno::remove_aluno(Aluno* Al) {
	Elemento<Aluno>* aluno = busca_Aluno(Al);
	if (Al == NULL || numero_aluno <= 0) {
		if (Al == NULL)
			cout << "Tentativa de remover nulidade" << endl;
		else
			cout << "Turma com zero Alunos, verifique a quatidade de alunos" << endl;
		return;
	}
	Elemento<Aluno>* temp = listaluno.get_cabeca();
	if (aluno == listaluno.get_cabeca()) {
		listaluno.set_cabeca(listaluno.get_cabeca()->get_proximo());//cabecaA = cabecaA->get_proximo();
		temp->set_proximo(NULL);
		listaluno.get_cabeca()->set_anterior(NULL);//cabecaA->set_anterior(NULL);
		delete temp;
	}
	else if (aluno == listaluno.get_atual()) {
		temp = listaluno.get_atual();
		listaluno.set_atual(listaluno.get_atual()->get_anterior());//atualA = atualA->get_anterior();
		listaluno.get_atual()->set_proximo(NULL);//atualA->set_proximo(NULL);
		temp->set_anterior(NULL);
		delete temp;
	}
	else {
		while (temp->get_proximo() != aluno)
			temp = temp->get_proximo();
		temp->set_proximo(temp->get_proximo()->get_proximo());//= temp->next->next;
		temp = temp->get_proximo();
		temp->set_anterior(temp->get_anterior()->get_anterior());// = temp->prev->prev;
		aluno->set_proximo(NULL);
		aluno->set_anterior(NULL);
		delete aluno;
	}
}
void ListAluno::salva_aluno() {
	ofstream SalvaAlunos("alunos.dat", ios::out);
	if (!SalvaAlunos) {
		cerr << "nao consegui abrir arquivo aluno" << endl;
		fflush(stdin);
		return;
		}
	Elemento<Aluno>* galuno = NULL;
	galuno = listaluno.get_cabeca();
	Aluno* temp = NULL;
	while (galuno != NULL) {
		temp = galuno->get_elem();
		SalvaAlunos << temp->get_RA() << temp->get_id() << temp->get_nome() << endl;
		galuno = galuno->get_proximo();

	}
	SalvaAlunos.close();
}
void ListAluno::registra_aluno() {
	ifstream ResgistraAluno("alunos.dat", ios::in);
	if (!ResgistraAluno) {
		cerr << "nao consegui regartar arquivo aluno" << endl;
		fflush(stdin);
	}
	listaluno.destroy();
	while (!ResgistraAluno.eof()) {
		Aluno* temp = NULL;
		int id, ra;
		char nome[30];
		ResgistraAluno >> id >> ra >> nome;
		if (0 != strcpy_s(nome, sizeof(nome), "")) {
			temp = new Aluno(-1);
			temp->set_RA(ra);
			temp->set_nome(nome);
			inclue_aluno(temp);
		}
	}
	ResgistraAluno.close();
}