#include"string_academica.h"
StringA::StringA(const char *s): tam(strlen(s)) {
	set_string(s);
}
StringA::~StringA() {
	delete[]palavra;
	palavra = NULL;
}
void StringA::set_string(const char* s) {
	palavra = new char[tam + 1];
	strcpy_s(palavra, tam + 1, s);
}
const char* StringA::get_string() {
	return palavra;
}
void StringA::operator=(const char* s) {
	if (s != palavra) {
		delete[]palavra;
		tam = strlen(s);
		set_string(s);
	}
}
void StringA::operator=(StringA& v) {
	operator=(v.get_string());
}
bool StringA::operator==(StringA& m) {
	if (!strcmp(palavra, m.get_string()))
		return true;

	return false;

}
ostream& operator<<(ostream& out, StringA & s) {
	out << s.get_string();
	return out;
}