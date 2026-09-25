#pragma once
#include"organiza.h"
class StringA {
	private:
		char* palavra;
		int tam;
	private:
		void set_string(const char* s = "");
		 const bool verifica(StringA& m);
	public:
		StringA(const char *s = "");
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
};
ostream&operator<<(ostream& out, StringA & s);
istream&operator>>(istream& in, StringA& s);
