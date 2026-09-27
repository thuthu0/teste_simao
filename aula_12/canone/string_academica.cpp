#include"string_academica.h"
namespace total_academico {
	const char StringA::nomeClasse[40] = "String academica";
	int StringA::cout_string = 0;
	using std::ostream;

	StringA::StringA(const char* s) : tam(strlen(s)) {
		set_string(s);
		cout_string++;
	}
	StringA::StringA(const StringA& s) : tam(s.tam) {
		palavra = new char[tam + 1];
		strcpy_s(palavra, tam + 1, s.palavra);
		cout_string++;
	}
	StringA::~StringA() {
		delete[]palavra;
		palavra = NULL;
		cout_string--;
	}
	void StringA::set_string(const char* s) {
		palavra = new char[tam + 1];
		strcpy_s(palavra, tam + 1, s);
	}
	char* StringA::get_string()const {
		return palavra;
	}
	const bool StringA::verifica(StringA& s) {
		if (!strcmp(palavra, s.get_string()))
			return true;

		return false;
	}
	StringA& StringA::operator=(const char* s) {
		if (s != palavra) {
			delete[]palavra;
			tam = strlen(s);
			set_string(s);
		}
		return *this;
	}
	StringA& StringA::operator=(const StringA& s) {
		return operator=(s.get_string());
	}
	StringA StringA::operator+(const char* s) {
		int tamN = tam + (int)strlen(s);
		char* v = new char[tamN + 1];
		strcpy_s(v, tamN + 1, s);
		strcat_s(v, tamN + 1, palavra);
		StringA soma(v);
		delete[]v;
		return soma;
	}
	StringA StringA::operator+(const StringA& s) {
		return operator+(s.get_string());
	}
	StringA StringA::operator+=(const char* s) {
		return operator=(operator+(s));
	}
	StringA StringA::operator+=(const StringA& s) {
		return operator+=(s.get_string());
	}
	bool StringA::operator==(StringA& s) {
		return verifica(s);

	}
	bool StringA::operator!=(StringA& s) {
		return !verifica(s);
	}
	char& StringA::operator[](int indice) {
		return palavra[indice];
	}
	const char& StringA::operator[](int indice) const {
		return palavra[indice];
	}
	const char* StringA::get_nome_classe() {
		return nomeClasse;
	}
	int StringA::get_cout_string() {
		return cout_string;
	}
	ostream& operator<<(ostream& out, const StringA& s) {
		out << s.get_string();
		return out;
	}
	istream& operator>>(istream& in, StringA& s) {
		char buffa[TAM_MAX];
		in.width(sizeof(buffa));
		in >> buffa;
		s = buffa;
		return in;
	}
}