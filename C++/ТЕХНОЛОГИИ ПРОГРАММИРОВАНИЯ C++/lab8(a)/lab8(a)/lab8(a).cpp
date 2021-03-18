// lab8(a).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "manyf.h"
#include <string>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Organization *x;
	Emploee c;
	Organization_A d;
	x = &d;
	x->setName("Sony");
	cout << endl << "Организация " << x->getName() << endl;
	c.setName("Нурберген");c.setHomeNum(1);c.setPostNum(1593578);c.setJob("Инженер");c.setWages(200100);c.setSeniority(10);
	x->addEmploee(c);
	c.setName("Винни Пух");c.setHomeNum(2);c.setPostNum(456155693578);c.setJob("Бухгалтер");c.setWages(300100);c.setSeniority(12);
	x->addEmploee(c);
	c.setName("Сая");c.setHomeNum(3);c.setPostNum(1456593578);c.setJob("Певец");c.setWages(400100);c.setSeniority(4);
	x->addEmploee(c);
	c.setName("Луффи");c.setHomeNum(4);c.setPostNum(1545693578);c.setJob("Программист");c.setWages(500100);c.setSeniority(7);
	x->addEmploee(c);
	x->show();
	string f="Луффи";
	Emploee *g;
	cout << "Поиск по имени: " << f << endl;
	g = x->find_name(f);g->show();cout << endl << endl;

	Organization_B z;
	x = &z;
	x->setName("Microsoft");
	cout << endl << "Организация " << x->getName() << endl;
	c.setName("Нурберген");c.setHomeNum(1);c.setPostNum(1593578);c.setJob("Инженер");c.setWages(200100);c.setSeniority(10);
	x->addEmploee(c);
	c.setName("Винни Пух");c.setHomeNum(2);c.setPostNum(456155693578);c.setJob("Бухгалтер");c.setWages(300100);c.setSeniority(12);
	x->addEmploee(c);
	c.setName("Сая");c.setHomeNum(3);c.setPostNum(1456593578);c.setJob("Певец");c.setWages(400100);c.setSeniority(4);
	x->addEmploee(c);
	c.setName("Луффи");c.setHomeNum(4);c.setPostNum(1545693578);c.setJob("Программист");c.setWages(500100);c.setSeniority(7);
	x->addEmploee(c);
	x->show();
	f = "Сая";
	cout << "Поиск по имени: " << f << endl;
	g = x->find_name(f);g->show();cout << endl << endl;

	cout << "size c: " << sizeof(c) << " size x: " << sizeof(x) << endl;
	cout << "size d: " << sizeof(d) << " size Z: " << sizeof(z) << endl;
	
	system("pause");
    return 0;
}

