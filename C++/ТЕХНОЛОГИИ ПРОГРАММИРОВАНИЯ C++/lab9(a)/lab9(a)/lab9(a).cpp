// lab9(a).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <locale>
#include "Loc.h"
#include <string>
using namespace std;

int main()
{
	_wsetlocale(LC_CTYPE, L".1251");
	_wsetlocale(LC_CTYPE, L".866");
	Organization *x;
	Emploee c;
	c.input();
	c.show();
	Organization_A d;
	x = &d;
	x->setName(L"Sony");
	wcout << endl << L"Организация " << x->getName() << endl;
	c.setName(L"Нурберген");c.setHomeNum(1);c.setPostNum(1593578);c.setJob(L"Инженер");c.setWages(200100);c.setSeniority(10);
	x->addEmploee(c);
	c.setName(L"Винни Пух");c.setHomeNum(2);c.setPostNum(456155693578);c.setJob(L"Бухгалтер");c.setWages(300100);c.setSeniority(12);
	x->addEmploee(c);
	c.setName(L"Сая");c.setHomeNum(3);c.setPostNum(1456593578);c.setJob(L"Певец");c.setWages(400100);c.setSeniority(4);
	x->addEmploee(c);
	c.setName(L"Луффи");c.setHomeNum(4);c.setPostNum(1545693578);c.setJob(L"Программист");c.setWages(500100);c.setSeniority(7);
	x->addEmploee(c);
	x->show();
	wstring f = L"Луффи";
	Emploee *g;
	wcout << L"Поиск по имени: " << f << endl;
	g = x->find_name(f);g->show();wcout << endl << endl;

	Organization_B z;
	x = &z;
	x->setName(L"Microsoft");
	wcout << endl << L"Организация " << x->getName() << endl;
	c.setName(L"Нурберген");c.setHomeNum(1);c.setPostNum(1593578);c.setJob(L"Инженер");c.setWages(200100);c.setSeniority(10);
	x->addEmploee(c);
	c.setName(L"Винни Пух");c.setHomeNum(2);c.setPostNum(456155693578);c.setJob(L"Бухгалтер");c.setWages(300100);c.setSeniority(12);
	x->addEmploee(c);
	c.setName(L"Сая");c.setHomeNum(3);c.setPostNum(1456593578);c.setJob(L"Певец");c.setWages(400100);c.setSeniority(4);
	x->addEmploee(c);
	c.setName(L"Луффи");c.setHomeNum(4);c.setPostNum(1545693578);c.setJob(L"Программист");c.setWages(500100);c.setSeniority(7);
	x->addEmploee(c);
	x->show();
	f = L"Сая";
	wcout << L"Поиск по имени: " << f << endl;
	g = x->find_name(f);g->show();wcout << endl << endl;

	wcout << L"size c: " << sizeof(c) << L" size x: " << sizeof(x) << endl;
	wcout << L"size d: " << sizeof(d) << L" size Z: " << sizeof(z) << endl;

	system("pause");
	return 0;
}

