#include "mundo.h"
#include "string_academica.h"
int main() {
	//Mundo execução;
	//execução.execudar();
	char vetor[150] = "o mundo dos mortos e um lugar irrisorio";
	StringA s(vetor);
	cout << s.get_string() << endl;
	const char* caixa_alta;
	caixa_alta = s.get_string();
	StringA v;
	v = "pasardaga e o lugar dos sonhos do passado";
	cout << v.get_string() << endl;
	if (v == s)
		cout << "nao e para acontece" << endl;
		v = s;
	if (v == s)
		cout << "e para acontece" << endl;
	cout << v << endl;
	return 0;
}/*Pessoa Einstein(14, 3, 1879,"Albert Einstein"), Newton(4, 1, 1643,"Isacc Newton");
	Einstein.calcu_idade(24, 8, 2009);
	Newton.calcu_idade(24, 8, 2009);
	Einstein.informaidade();
	Newton.informaidade();*/