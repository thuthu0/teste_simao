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
	int id;

public:
	
	Pessoa(int diaP, int mesP, int anoP, const char * nomeP, int idO = 0);
	Pessoa(int idO = 0);
	~Pessoa();
	void set_id(int n = 0);
	int get_id();
	void set_nome(const char* nomeP);
	char* get_nome();
	void inicializar (int diaP, int mesP, int anoP, const char* nomeP, int idO = 0);
	void calcu_idade(int diaC, int mesC, int anoC);
	char get_charac(int i);
	void print_nome();
	void print_idade();
	int informaidade();
};
#endif