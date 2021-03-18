#include <iostream>
#include <windows.h>
#include "ukaz.h"
#include <string>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Emploee c;
	c.input();
	c.show();cout << endl;

	Organization z("Microsoft");
	cout << endl << "Организация " << z.getName() << endl;
	z.addEmploee(c);
	c.setName("Нурберген");c.setHomeNum(1);c.setPostNum(1593578);c.setJob("Инженер");c.setWages(200100);c.setSeniority(10);
	z.addEmploee(c);
	c.setName("Винни Пух");c.setHomeNum(2);c.setPostNum(456155693578);c.setJob("Бухгалтер");c.setWages(300100);c.setSeniority(12);
	z.addEmploee(c);
	c.setName("Сая");c.setHomeNum(3);c.setPostNum(1456593578);c.setJob("Певец");c.setWages(400100);c.setSeniority(4);
	z.addEmploee(c);
	c.setName("Луффи");c.setHomeNum(4);c.setPostNum(1545693578);c.setJob("Программист");c.setWages(500100);c.setSeniority(7);
	z.addEmploee(c);
	z.show();

	string f;
	cout << "Введите имя работника:" << endl;
	getline(cin,f);
	Emploee *g;
	g = z.find_name(f);
	if (g != NULL) 
	{
		g->show();
		cout << endl;
	}
	else
	{
		cout << "Не существует" << endl;
	}

	cout << "size Emploee: " << sizeof(Emploee) << " size z: " << sizeof(z) << endl;
	
	system("pause");
	return 0;
}
