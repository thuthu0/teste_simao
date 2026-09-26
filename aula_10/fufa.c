//#include <stdio.h>
//#define ANO_ATUAL 2026
//#define MES_ATUAL 7
//#define DIA_ATUAL 25
//typedef struct pessoa {
//	int dia;
//	int mes;
//	int ano;
//	int idade;
//}Pessoa;
//
//int main() {
//	Pessoa einstein, newton;
//	einstein.dia = 14;
//	einstein.mes = 3;
//	einstein.ano = 1879;
//	newton.dia = 4;
//	newton.mes = 1;
//	newton.ano = 1643;
//	einstein.idade = idade_pessoa(einstein, ANO_ATUAL, MES_ATUAL,DIA_ATUAL);
//	newton.idade = idade_pessoa(newton, ANO_ATUAL, MES_ATUAL, DIA_ATUAL);
//	printf("%d\n%d\n", einstein.idade, newton.idade);
//	return 0;
//}
//
//int idade_pessoa(Pessoa meliante, int ano, int mes, int dia) {
//	if((meliante.mes > mes) || ((meliante.mes == mes) && (meliante.dia > dia)))
//		return ano - meliante.ano;
//	return ano - meliante.ano - 1;
//}