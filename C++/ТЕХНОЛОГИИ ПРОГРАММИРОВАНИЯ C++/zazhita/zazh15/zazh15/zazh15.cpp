// zazh15.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "asob.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

int main()
{
	_wsetlocale(LC_CTYPE, L".1251");
	_wsetlocale(LC_CTYPE, L".866");
	srand(time(NULL));

	
	wcout << L"A:" << endl;
	Organization_Vect A;A.setName(L"A");A.read_file(L"A.fbd");A.show();
	wcout << L"B:" << endl;
	Organization_Vect B;B.setName(L"B");B.read_file(L"B.fbd");B.show();
	wcout << L"C:" << endl;
	Organization_Vect C;C.setName(L"C");C.read_file(L"C.fbd");C.show();
	wcout << L"D:" << endl;
	Organization_Vect D;D.setName(L"D");D.read_file(L"D.fbd");D.show();

	Organization_Vect E;E.setName(L"E");
	E = (A - B)*(C - D);
	wcout << endl << L"E=(A-B)*(C-D):" << endl;
	E.show();

	/*
	Organization_Vect F, G;
	F = (A - B);
	wcout << endl << L"F=(A-B):" << endl;
	F.show();wcout << endl;
	G = (C - D);
	wcout << endl << L"G=(C-D):" << endl;
	G.show();
	wcout << endl;
	*/

	system("pause");
	return 0;
}
