#include"pessoa.h"


Pessoa::Pessoa(int diaP, int mesP, int anoP,   const char  *nomeP) {
	inicializar(diaP,mesP,anoP,nomeP);
}
Pessoa::Pessoa() {
	inicializar(0,0,0,"");
}
Pessoa :: ~Pessoa() {

}
void Pessoa:: inicializar(int diaP, int mesP, int anoP, const char* nomeP) {
	dia = diaP;
	mes = mesP;
	ano = anoP;
	idade = -1;
	strcpy_s(nome, sizeof(nome), nomeP);
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
