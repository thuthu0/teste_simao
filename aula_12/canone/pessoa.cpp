#include"pessoa.h"
int Pessoa::cout_pessoa = 0;

Pessoa::Pessoa(int diaP, int mesP, int anoP,   const char  *nomeP, int idO ) {
	inicializar(diaP,mesP,anoP,nomeP,idO);
}
Pessoa::Pessoa(int idO) {
	inicializar(0,0,0,"", idO);
}
Pessoa :: ~Pessoa() {
	cout_pessoa--;
}
int Pessoa::get_id() {
	return id;
}
char* Pessoa::get_nome() {
	return nome;
}
void Pessoa::set_nome(const char *nomeP) {
	strcpy_s(nome, sizeof(nome), nomeP);
}
void Pessoa:: inicializar(int diaP, int mesP, int anoP, const char* nomeP, int idO) {
	dia = diaP;
	mes = mesP;
	ano = anoP;
	idade = -1;
	cout_pessoa++;
	id = cout_pessoa;
	set_nome(nomeP);
}
void Pessoa::calcu_idade(int diaC, int mesC, int anoC) {
	if ((mesC > mes) || ((mesC == mes) && (diaC >= dia)))
		idade = anoC - ano;
	else
		idade = anoC - (ano + 1);
}
char Pessoa::get_charac(int i) {
	return nome[i];
}
void Pessoa::print_nome() {
	cout << "Nome: " << nome << endl;
}
void Pessoa::print_idade() {
	cout << "a idade de " << nome << " seria " << idade << endl;
}
int Pessoa::informaidade() {
	return idade;
}
void Pessoa::informa_provedos() {
	cout << "nao tem provedor" << endl;
}
