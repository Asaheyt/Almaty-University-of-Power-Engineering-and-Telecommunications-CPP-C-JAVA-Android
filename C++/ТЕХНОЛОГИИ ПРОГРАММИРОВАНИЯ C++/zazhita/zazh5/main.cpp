#include <iostream>
#include <windows.h>
#include "uk.h"
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Emploee c; Data d;
	Organization z("Microsoft");
	cout << endl << "Организация " << z.getName() << endl;
	c.setName("Нурберген");c.setHomeNum(rand()%10);c.setPostNum(rand()%70000);c.setJob("Инженер");c.setWages(rand()%1000000);c.setSeniority(rand()%10);d.setDay(rand()%31);d.setMonth(rand()%13);d.setYear(rand()%2017);c.setData(d);
	z.addEmploee(c);
	c.setName("Винни");c.setHomeNum(rand()%10);c.setPostNum(rand()%70000);c.setJob("Бухгалтер");c.setWages(rand()%1000000);c.setSeniority(rand()%10);d.setDay(rand()%31);d.setMonth(rand()%13);d.setYear(rand()%2017);c.setData(d);
	z.addEmploee(c);
	c.setName("Сая");c.setHomeNum(rand()%10);c.setPostNum(rand()%70000);c.setJob("Певец");c.setWages(rand()%1000000);c.setSeniority(rand()%10);d.setDay(rand()%31);d.setMonth(rand()%13);d.setYear(rand()%2017);c.setData(d);
	z.addEmploee(c);
	c.setName("Луффи");c.setHomeNum(rand()%10);c.setPostNum(rand()%70000);c.setJob("Программист");c.setWages(rand()%1000000);c.setSeniority(rand()%10);d.setDay(rand()%31);d.setMonth(rand()%13);d.setYear(rand()%2017);c.setData(d);
	z.addEmploee(c);
	z.show();cout<<endl;

	cmp a;
	a=cmpName;
	z.sorting(a);
	cout<<endl<<"Сортировка по профессии(по алфавиту):"<<endl;
	z.show();cout<<endl;
	a=cmpWages;
	z.sorting(a);
	cout<<endl<<"Сортировка по заработной плате(по возрастанию):"<<endl;
	z.show();cout<<endl;
	a=cmpBeginW;
	z.sorting(a);
	cout<<endl<<"Сортировка по дате начала работы(по возрастанию):"<<endl;
	z.show();cout<<endl;

	c.setName("Адиль Алдамжаров Хайратович");c.setHomeNum(rand()%10);c.setPostNum(rand()%70000);c.setJob("Программист");c.setWages(rand()%1000000);c.setSeniority(rand()%10);d.setDay(rand()%31);d.setMonth(rand()%13);d.setYear(rand()%2017);c.setData(d);
	cout<<"Добавление элемента под индексом 2"<<endl;
	z.addEmploeeIndex(c,2);
	z.show();

	return 0;
}
