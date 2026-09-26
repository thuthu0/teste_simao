#include"lista_aluno.h"
#include "aluno.h"
ListAluno::ListAluno() {
	setup();
}
ListAluno::~ListAluno() {
	destroy_lista();

}
void ListAluno::setup(int ct, const char* ac) {
	
	strcpy_s(nome, sizeof(nome), "");
	cabecaA = NULL;
	atualA = NULL;
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
	if (cabecaA == NULL) {
		cabecaA = aluno;
		atualA = aluno;
	}
	else {
		int i, fim = 0;
		Elemento<Aluno>* temp, * pasage;
		for (i = 0, temp = atualA; fim == 0; i++) {
			if (Al->get_charac(i) < temp->get_elem()->get_charac(i) || Al->get_charac(i) == '\0') {
				if (temp == cabecaA) {
					temp->set_anterior(aluno);
					aluno->set_proximo(temp);
					cabecaA = aluno;
					fim = 1;
				}
				else {
					temp = temp->get_anterior();
					i = 0;
				}
			}
			else if (Al->get_charac(i) > temp->get_elem()->get_charac(i) || temp->get_elem()->get_charac(i) == '\0') {
				if (temp == atualA) {
					temp->set_proximo(aluno);
					aluno->set_anterior(temp);
					atualA = aluno;
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
	if (cabecaA == NULL)
		return;
	Elemento<Aluno>* temp;
	for (temp = cabecaA; temp != NULL; temp = temp->get_proximo()) {
		temp->get_elem()->print_nome();
		temp->get_elem()->print_RA();
	}
}
void ListAluno::printR_aluno() {
	if (cabecaA == NULL)
		return;
	Elemento<Aluno>* temp;
	for (temp = atualA; temp != NULL; temp = temp->get_anterior()) {
		temp->get_elem()->print_nome();
		temp->get_elem()->print_RA();
	}
}
Elemento<Aluno>* ListAluno::busca_Aluno(Aluno* Al) {
	Elemento<Aluno>* temp = NULL;
	if (cabecaA == NULL) {
		cout << "Turma vazia" << endl;
		return NULL;
	}
	for (temp = cabecaA; temp != NULL; temp = temp->get_proximo()) {
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
	Elemento<Aluno>* temp = cabecaA;
	if (aluno == cabecaA) {
		cabecaA = cabecaA->get_proximo();
		temp->set_proximo(NULL);
		cabecaA->set_anterior(NULL);
		delete temp;
	}
	else if (aluno == atualA) {
		temp = atualA;
		atualA = atualA->get_anterior();
		atualA->set_proximo(NULL);
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
void ListAluno::destroy_lista() {
	Elemento<Aluno>* temp = NULL, * depois = NULL;
	for (temp = cabecaA; temp != NULL; temp = depois) {
		depois = temp->get_proximo();
		delete temp;
	}
	cabecaA = NULL;
	atualA = NULL;
}
void ListAluno::salva_aluno() {
	ofstream SalvaAlunos("alunos.dat", ios::out);
	if (!SalvaAlunos) {
		cerr << "nao consegui abrir arquivo aluno" << endl;
		fflush(stdin);
		return;
		}
	Elemento<Aluno>* galuno = NULL;
	galuno = cabecaA;
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
	destroy_lista();
	while (!ResgistraAluno.eof()) {
		Aluno* temp = NULL;
		int id, ra;
		char nome[30];
		ResgistraAluno >> id >> ra >> nome;
		if (0 != strcpy_s(nome, sizeof(nome), "")) {
			temp = new Aluno(-1);
			temp->set_id(id);
			temp->set_RA(ra);
			temp->set_nome(nome);
			inclue_aluno(temp);
		}
	}
	ResgistraAluno.close();
}