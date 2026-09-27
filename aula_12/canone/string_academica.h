#pragma once
#include"organiza.h"
namespace total_academico {
	class StringA {
	private:
		char* palavra;
		int tam;
	private:
		void set_string(const char* s = "");
		const bool verifica(StringA& m);
		static const char nomeClasse[40];
		static int cout_string;
	public:
		StringA(const char* s = "");
		StringA(const StringA& s);
		~StringA();
		char* get_string()const;
		StringA& operator=(const char* s);
		StringA& operator=(const StringA& s);
		StringA operator+(const char* s);
		StringA operator+(const StringA& s);
		StringA operator+=(const char* s);
		StringA operator+=(const StringA& s);
		bool operator==(StringA& s);
		bool operator!=(StringA& s);
		char& operator[](int indice);
		const char& operator[](int indice) const;
		static const char* get_nome_classe();
		static int get_cout_string();
	};
	ostream& operator<<(ostream& out, const StringA& s);
	istream& operator>>(istream& in, StringA& s);
}
	

