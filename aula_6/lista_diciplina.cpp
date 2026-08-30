#include "Lista_diciplina.h"
#include "elemento_diciplina.h"
#include "diciplina.h"
ListaDiciplina::ListaDiciplina() {
	set_Lderpa_nome();
	cabecaD = NULL;
	atualD = NULL;
	id = rand();
}
ListaDiciplina::~ListaDiciplina() {
	ElemDiciplina* temp = NULL, * depois = NULL;
	for (temp = cabecaD; temp != NULL; temp = depois) {
		depois = temp->diciplinaG_proximo();
		delete temp;
	}
	cabecaD = NULL;
	atualD = NULL;
}
ElemDiciplina* ListaDiciplina::get_cabecaD() {
	if (this == NULL) {
		cout << "cabecaD nula" << endl;
		return NULL;
	}
	return this->cabecaD;
}
ElemDiciplina* ListaDiciplina::get_atualD() {
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
	ElemDiciplina* diciplina = new ElemDiciplina;
	diciplina->colo_diciplina(di);
	if (di == NULL) {
		printf("erro diciplina com valor nulo");
		return;
	}
	if (cabecaD == NULL) {
		cabecaD = diciplina;
		atualD = diciplina;
	}
	else {
		ElemDiciplina* temp = atualD;
		atualD->diciplinaS_proximo(diciplina);//di;
		atualD = atualD->diciplinaG_proximo();
		atualD->diciplinaS_anterior(temp);// = temp;
	}
}
void ListaDiciplina::print_diciplina() {
	ElemDiciplina* temp;
	cout << "as diciplinas que fazem parte do departamento " << nome << " sao " << endl;
	for (temp = cabecaD; temp != NULL; temp = temp->diciplinaG_proximo()) {
		temp->posicao_diciplina()->print_depDis();
		cout << " do " << nome << endl;
	}
}
void ListaDiciplina::printR_diciplina() {
	ElemDiciplina* temp;
	cout << "as diciplinas em ordem reversa do derpatamento sao " << endl;
	for (temp = atualD; temp != NULL; temp = temp->diciplinaG_anterior()) {
		temp->posicao_diciplina()->print_depDis();
		cout << " do " << nome << endl;
	}
}
ElemDiciplina* ListaDiciplina::busca_diciplina(Diciplina* di){
	ElemDiciplina* temp = NULL;
	int achou = 0;
	if (cabecaD == NULL) {
		cout << "Turma vazia" << endl;
		return NULL;
	}
	for (temp = cabecaD; temp != NULL || achou != 0; temp = temp->diciplinaG_proximo()) {
		if (temp->posicao_diciplina() == di)
			achou = 1;
	}
	if (achou == 1)
		return temp;
	cout << "nao achado" << endl;
	return NULL;
}
void ListaDiciplina::remove_diciplina(Diciplina* di) {
	ElemDiciplina* temp = cabecaD, * diciplina;
	diciplina = busca_diciplina(di);
	if (di == NULL) {
		printf("remoção de nulo detectado");
		return;
	}
	if (diciplina == cabecaD) {
		cabecaD = cabecaD->diciplinaG_proximo();
		cabecaD->diciplinaS_anterior(NULL);// = NULL;
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