#include"diciplina.h"
#include "departamento.h"
#include "aluno.h"
#include "elemento_aluno.h"
Diciplina::Diciplina():turma() {
	setup();
}
Diciplina::~Diciplina() {

	depD = NULL;
	//next = NULL;
	//prev = NULL;
}
void Diciplina::setup(int ct, const char* ac) {
	depD = NULL;
	//next = NULL;
	//prev = NULL;
	id = -1;
	strcpy_s(nome, sizeof(nome), "");
	strcpy_s(area_conhecimento, sizeof(area_conhecimento), ac);

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
void Diciplina::set_depDis(Departamento* depDi) {
	depD = depDi;
	depDi->inclue_diciplina(this);
}
void Diciplina::print_depDis() {
	cout << "Dicplina " << nome;
}
Departamento* Diciplina::get_depDis() {
	return depD;
}
void Diciplina::inclue_aluno(Aluno* Al) {
	turma.inclue_aluno(Al);
}
void Diciplina::print_aluno() {
	turma.print_aluno();
}
void Diciplina::printR_aluno() {
	turma.printR_aluno();
}
ElemAluno* Diciplina::busca_Aluno(Aluno* Al) {
	return turma.busca_Aluno(Al);

}
void Diciplina::remove_aluno(Aluno* Al) {
	turma.remove_aluno(Al);
}
//void Diciplina::diciplinaS_proximo(Diciplina* prox) {
//	if(this == NULL)
//		cout << "nó diciplina não inicializado" << endl;
//
//	else
//		this->next = prox;
//}
//Diciplina* Diciplina::diciplinaG_proximo() {
//	if (this == NULL) {
//		cout << "nó diciplina não inicializado" << endl;
//		return this;
//	}
//	return this->next;
//}
//void Diciplina::diciplinaS_anterior(Diciplina* ante) {
//	if (this == NULL)
//		cout << "nó diciplina não inicializado" << endl;
//	else
//	this->prev = ante;
//}
//Diciplina* Diciplina::diciplinaG_anterior() {
//	if (this == NULL) {
//		cout << "nó diciplina não inicializado" << endl;
//		return this;
//	}
//	return this->prev;
//}