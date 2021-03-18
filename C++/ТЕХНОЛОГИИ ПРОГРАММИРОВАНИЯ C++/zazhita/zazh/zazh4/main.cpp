#include <iostream>
#include <windows.h>
#include "mas1.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Emploee c;
	Organization z("Microsoft"),y("Nokia");
	cout << endl << "Организация " << z.getName() << endl;
	srand(time(NULL));
	c.setName("Нурберген");c.setHomeNum(1);c.setPostNum(1593578);c.setJob("Инженер");c.setWages(rand()%1000000);c.setSeniority(10);
	z.addEmploee(c);
	c.setName("Винни");c.setHomeNum(2);c.setPostNum(456155693578);c.setJob("Бухгалтер");c.setWages(rand()%1000000);c.setSeniority(12);
	z.addEmploee(c);
	c.setName("Сая");c.setHomeNum(3);c.setPostNum(1456593578);c.setJob("Певец");c.setWages(rand()%1000000);c.setSeniority(4);
	z.addEmploee(c);
	c.setName("Луффи");c.setHomeNum(4);c.setPostNum(1545693578);c.setJob("Программист");c.setWages(rand()%1000000);c.setSeniority(7);
	z.addEmploee(c);
	z.show();

	cout << endl << "Организация " << y.getName() << endl;
	c.setName("Нурcултан");c.setHomeNum(5);c.setPostNum(1593578);c.setJob("Инженер");c.setWages(rand()%1000000);c.setSeniority(10);
	y.addEmploee(c);
	c.setName("Вил");c.setHomeNum(6);c.setPostNum(456155693578);c.setJob("Бухгалтер");c.setWages(rand()%1000000);c.setSeniority(12);
	y.addEmploee(c);
	c.setName("По");c.setHomeNum(7);c.setPostNum(1456593578);c.setJob("Певец");c.setWages(rand()%1000000);c.setSeniority(4);
	y.addEmploee(c);
	c.setName("Лесли");c.setHomeNum(8);c.setPostNum(1545693578);c.setJob("Программист");c.setWages(rand()%1000000);c.setSeniority(7);
	y.addEmploee(c);
	y.show();cout<<endl;

    cout<<"Слияние объектов класса Organizacia"<<endl;
	confluence(z,y);
	z.show();cout<<endl;

	cout<<"Сортировка по профессии(по алфавиту)"<<endl;
	z.SortByJob();
	z.show();cout<<endl;

	cout<<"Сортировка по заработной плате(по возрастанию)"<<endl;
	z.SortByWages();
	z.show();cout<<endl;

	system("pause");
	return 0;
}
