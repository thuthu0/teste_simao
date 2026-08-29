#include"universidade.h"
#include "elemento_departamento.h"
#include "lista_departamento.h"
Universidade::Universidade():matriz() {
	sua_uni();
}
Universidade::~Universidade() {

}
void Universidade::sua_uni(const char* nomeU) {
	strcpy_s(nome,sizeof(nome),nomeU);
}
char * Universidade::qual_uni() {
	return nome;
}
//void Universidade ::incluie_dep(Departamento* depU) {
//	if(depU != NULL)
//		dep.push_back(depU);
//}
//void Universidade::print_dep() {
//	int tam = (int)dep.size(), i=-1;
//	for(i=0;i<tam;i++)
//	cout << dep[i]->qual_departamento() << endl;
//}
void Universidade::inclue_departamento(Departamento* dep) {
	matriz.inclue_departamento(dep);
}
void Universidade::print_departamento() {
	matriz.print_departamento();
}
void Universidade::printR_departamento() {
	matriz.printR_departamento();
}
void Universidade::remove_departamento(Departamento* dep) {
	matriz.remove_departamento(dep);
}
/*Derpatamento* Universidade::aloca_dep(const char* nomeD) {
	dep = (Derpatamento*)malloc(sizeof(Derpatamento));
	dep->set_departamento(nomeD);
	return dep;
}
void Universidade::desloca_dep() {
	free(dep);
}*/