#include "Lista_diciplina.h"
#include "elemento_diciplina.h"
#include "diciplina.h"
ListaDiciplina::ListaDiciplina() {
	set_Lderpa_nome();
	cabecaD = NULL;
	atualD = NULL;
}
ListaDiciplina::~ListaDiciplina() {
	destroy_lista();
}

Elemento<Diciplina>* ListaDiciplina::get_cabecaD() {
	if (this == NULL) {
		cout << "cabecaD nula" << endl;
		return NULL;
	}
	return this->cabecaD;
}
Elemento<Diciplina>* ListaDiciplina::get_atualD() {
	if (this == NULL) {
		cout << "atualD nula" << endl;
		return NULL;
	}
	return this->atualD;
}
void ListaDiciplina::set_Lderpa_nome(const char* nomeLD) {
	strcpy_s(nome,sizeof(nome),nomeLD);
}
void ListaDiciplina::inclue_diciplina(Diciplina* di) {
	Elemento<Diciplina>* diciplina = new Elemento<Diciplina>;
	diciplina->set_elem(di);
	if (di == NULL) {
		printf("erro diciplina com valor nulo");
		return;
	}
	if (cabecaD == NULL) {
		cabecaD = diciplina;
		atualD = diciplina;
	}
	else {
		Elemento<Diciplina>* temp = atualD;
		atualD->set_proximo(diciplina);//di;
		atualD = atualD->get_proximo();
		atualD->set_anterior(temp);// = temp;
	}
}
void ListaDiciplina::print_diciplina() {
	Elemento<Diciplina>* temp;
	cout << "as diciplinas que fazem parte do departamento " << nome << " sao " << endl;
	for (temp = cabecaD; temp != NULL; temp = temp->get_proximo()) {
		temp->get_elem()->print_depDis();
		cout << " do " << nome << endl;
	}
}
void ListaDiciplina::printR_diciplina() {
	Elemento<Diciplina>* temp;
	cout << "as diciplinas em ordem reversa do derpatamento sao " << endl;
	for (temp = atualD; temp != NULL; temp = temp->get_anterior()) {
		temp->get_elem()->print_depDis();
		cout << " do " << nome << endl;
	}
}
Elemento<Diciplina>* ListaDiciplina::busca_diciplina(Diciplina* di){
	Elemento<Diciplina>* temp = NULL;
	if (cabecaD == NULL) {
		cout << "Turma vazia" << endl;
		return NULL;
	}
	for (temp = cabecaD; temp != NULL; temp = temp->get_proximo()) {
		if (temp->get_elem() == di)
			return temp;
	}
	cout << "nao achado" << endl;
	return NULL;
}
void ListaDiciplina::remove_diciplina(Diciplina* di) {
	Elemento<Diciplina>* temp = cabecaD, * diciplina;
	diciplina = busca_diciplina(di);
	if (di == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (diciplina == cabecaD) {
		cabecaD = cabecaD->get_proximo();
		cabecaD->set_anterior(NULL);// = NULL;
		delete temp;
	}
	else if (diciplina == atualD) {
		temp = atualD;
		atualD = atualD->get_anterior();
		atualD->set_proximo(NULL);// = NULL;
		delete temp;
	}
	else {
		while (temp->get_proximo() != diciplina)
			temp = temp->get_proximo();
		temp->set_proximo(temp->get_proximo()->get_proximo());// = temp->next->next;
		temp = temp->get_proximo();
		temp->set_anterior(temp->get_anterior()->get_anterior());// = temp->prev->prev;
		diciplina->set_proximo(NULL);// = NULL;
		diciplina->set_anterior(NULL);// = NULL;
		delete diciplina;
	}
}
void ListaDiciplina::destroy_lista() {
	Elemento<Diciplina>* temp = NULL, * depois = NULL;
	for (temp = cabecaD; temp != NULL; temp = depois) {
		depois = temp->get_proximo();
		delete temp;
	}
	cabecaD = NULL;
	atualD = NULL;
}
void ListaDiciplina::salva_diciplina() {
	ofstream SalvaDiciplina("diciplinas.dat", ios::out);
	if (!SalvaDiciplina) {
		cerr << "nao consegui abrir arquivo diciplina" << endl;
		fflush(stdin);
		return;
	}
	Elemento<Diciplina>* galuno = NULL;
	galuno = cabecaD;
	Diciplina* temp = NULL;
	while (galuno != NULL) {
		temp = galuno->get_elem();
		SalvaDiciplina  << temp->get_id() << temp->get_nome() << endl;
		galuno = galuno->get_proximo();

	}
	SalvaDiciplina.close();
}
void ListaDiciplina::registra_diciplina() {
	ifstream ResgistraDiciplina("diciplinas.dat", ios::in);
	if (!ResgistraDiciplina) {
		cerr << "nao consegui regartar arquivo diciplina" << endl;
		fflush(stdin);
	}
	destroy_lista();
	while (!ResgistraDiciplina.eof()) {
		Diciplina* temp = NULL;
		int id;
		char nome[30];
		ResgistraDiciplina >> id  >> nome;
		if (0 != strcpy_s(nome, sizeof(nome), "")) {
			temp = new Diciplina(-1);
			temp->set_id(id);
			temp->set_nome(nome);
			inclue_diciplina(temp);
		}
	}
	ResgistraDiciplina.close();
}