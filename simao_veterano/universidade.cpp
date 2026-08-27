#include"universidade.h"

Universidade::Universidade() {
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
void Universidade ::incluie_dep(Derpatamento* depU) {
	if(depU != NULL)
		dep.push_back(depU);
}
void Universidade::print_dep() {
	int tam = (int)dep.size(), i=-1;
	for(i=0;i<tam;i++)
	cout << dep[i]->qual_departamento() << endl;
}
/*Derpatamento* Universidade::aloca_dep(const char* nomeD) {
	dep = (Derpatamento*)malloc(sizeof(Derpatamento));
	dep->set_departamento(nomeD);
	return dep;
}
void Universidade::desloca_dep() {
	free(dep);
}*/