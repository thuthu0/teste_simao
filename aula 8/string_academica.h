#pragma once
#include"organiza.h"
class StringA {
	private:
		char* palavra;
		int tam;
	private:
		void set_string(const char* s = "");
	public:
		StringA(const char *s = "");
		~StringA();
		const char* get_string();
		void operator=(const char* s);
		void operator=(StringA& v);
		bool operator==(StringA& m);
};
ostream&operator<<(ostream& out, StringA & s);
