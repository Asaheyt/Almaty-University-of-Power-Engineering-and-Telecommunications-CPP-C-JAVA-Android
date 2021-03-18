#include <iostream>
#include <windows.h>
#include "Mas.h"
#include <string>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Liver a;
	a.setName("Adil");
	a.setHomeNum(50);
	a.setPostNum(1234567);
	a.show();cout << endl;

	Emploee b("Asaheyt", 4, 9876543, "Программист", 500400, 5), c;
	b.show();cout << endl;
	b.input();
	b.show();cout << endl;


	Organization z("Microsoft");
	cout << endl << "Организация " << z.getName() << endl;
	c.setName("Нурберген");c.setHomeNum(1);c.setPostNum(1593578);c.setJob("Инженер");c.setWages(200100);c.setSeniority(10);
	z.addEmploee(c);
	c.setName("Винни");c.setHomeNum(2);c.setPostNum(456155693578);c.setJob("Бухгалтер");c.setWages(300100);c.setSeniority(12);
	z.addEmploee(c);
	c.setName("Сая");c.setHomeNum(3);c.setPostNum(1456593578);c.setJob("Певец");c.setWages(400100);c.setSeniority(4);
	z.addEmploee(c);
	c.setName("Луффи");c.setHomeNum(4);c.setPostNum(1545693578);c.setJob("Программист");c.setWages(500100);c.setSeniority(7);
	z.addEmploee(c);
	z.show();
	cout << endl << "Удаление елемента " << endl;
	z.deleteLastEmploee();
	z.show();
	system("pause");
	return 0;
}
