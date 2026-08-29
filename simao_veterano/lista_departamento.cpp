#include"lista_departamento.h"
#include "elemento_departamento.h"
#include "departamento.h"
ListaDepartamento::ListaDepartamento() {
	set_nomeD("");
	cabecaDep = NULL;
	atualDep = NULL;
}
ListaDepartamento::~ListaDepartamento() {
	ElemDepartamento* temp = NULL, *depois = NULL;
	for (temp = cabecaDep; temp != NULL; temp = depois) {
		depois = temp->departamentoG_proximo();
		delete temp;
	}
	cabecaDep = NULL;
	atualDep = NULL;
}
void ListaDepartamento::set_nomeD(const char* nomeD) {
	strcpy_s(nome,sizeof(nome),nomeD);
}
void ListaDepartamento:: inclue_departamento(Departamento* dep) {
	ElemDepartamento* departamento = new ElemDepartamento;
	departamento->set_departamento(dep);
	if (dep == NULL) {
		printf("erro departamento com valor nulo");
		return;
	}
	if (cabecaDep == NULL) {
		cabecaDep = departamento;
		atualDep = departamento;
	}
	else {
		ElemDepartamento* temp = atualDep;
		atualDep->departamentoS_proximo(departamento);//di;
		atualDep = atualDep->departamentoG_proximo();
		atualDep->departamentoS_anterior(temp);// = temp;
	}
}
void ListaDepartamento::print_departamento() {
	ElemDepartamento* temp = NULL;
	cout << "os departamentos da universidade são" << endl;
	for (temp = cabecaDep; temp != NULL; temp = temp->departamentoG_proximo()) {
		cout << temp->get_departamento()->qual_departamento() << endl;
	}
}
void ListaDepartamento::printR_departamento() {
	ElemDepartamento* temp = NULL;
	cout << "os departamentos da universidade em ordem inversa são" << endl;
	for (temp = atualDep; temp != NULL; temp = temp->departamentoG_anterior()) {
		cout << temp->get_departamento()->qual_departamento()  << endl;
	}
}
ElemDepartamento* ListaDepartamento::busca_departamento(Departamento* dep) {
	ElemDepartamento* temp = NULL;
	int achou = 0;
	if (cabecaDep == NULL) {
		cout << "Turma vazia" << endl;
		return NULL;
	}
	for (temp = cabecaDep; temp != NULL || achou != 0; temp = temp->departamentoG_proximo()) {
		if (temp->get_departamento() == dep)
			achou = 1;
	}
	if (achou == 1)
		return temp;
	cout << "nao achado" << endl;
	return NULL;
}
void ListaDepartamento::remove_departamento(Departamento* dep) {
	ElemDepartamento* temp = cabecaDep, * departamento;
	departamento = busca_departamento(dep);
	if (dep == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (departamento == cabecaDep) {
		cabecaDep = cabecaDep->departamentoG_proximo();
		cabecaDep->departamentoS_anterior(NULL);// = NULL;
		delete temp;
	}
	else if (departamento == atualDep) {
		temp = atualDep;
		atualDep = atualDep->departamentoG_anterior();
		atualDep->departamentoS_proximo(NULL);// = NULL;
		delete temp;
	}
	else {
		while (temp->departamentoG_proximo() != departamento)
			temp = temp->departamentoG_proximo();
		temp->departamentoS_proximo(temp->departamentoG_proximo()->departamentoG_proximo());// = temp->next->next;
		temp = temp->departamentoG_proximo();
		temp->departamentoS_anterior(temp->departamentoG_anterior()->departamentoG_anterior());// = temp->prev->prev;
		departamento->departamentoS_proximo(NULL);// = NULL;
		departamento->departamentoS_anterior(NULL);// = NULL;
		delete departamento;
	}
}