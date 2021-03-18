#include <string>
#include <iostream>
#include "cstdlib"
#include <algorithm>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string s = "ЛабОРаторная работа студента работа", s0 = "работа";
	size_t len = s0.length();
	size_t n = s.find(s0);
	s.erase(n,len);
	cout << s << endl;
	system("pause");
	return 0;
}