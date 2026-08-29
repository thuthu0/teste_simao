#ifndef _PESSOA_H_
#define _PESSOA_H_
#include"organiza.h"
class Pessoa {
protected :
	int dia;
	int mes;
	int ano;
	int idade;
	char nome[30];

public:
	
	Pessoa(int diaP, int mesP, int anoP, const char * nomeP);
	Pessoa();
	~Pessoa();
	void inicializar (int diaP, int mesP, int anoP, const char* nomeP);
	void calcu_idade(int diaC, int mesC, int anoC);
	char get_charac(int i);
	void print_nome();
	void print_idade();
	int informaidade();
};
#endif