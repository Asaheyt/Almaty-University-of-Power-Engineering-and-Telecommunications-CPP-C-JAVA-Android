#include "legacy.h"
#include <iostream>
#include <string>
using namespace std;
int Emploee::count = 0;
Emploee::Emploee()
{
	count++;
	cout << "Конструктор Emploee. Количество: " << count << endl;
};
Emploee::Emploee(string n, int w)
{
	count++;
	name = n;
	wages = w;
	cout << "Конструктор Emploee. Количество: " << count << endl;
}
Emploee::~Emploee() 
{
	count--;
	cout << "Деструктор Emploee. Количество: " << count << endl;
};
void Emploee::setName(string n)
{
	name = n;
}
void Emploee::setWages(int w)
{
	wages = w;
}
int Emploee::getWages()
{
	return wages;
}
string Emploee::getName()
{
	return name;
}
void Emploee::show()
{
	cout << "Имя: " << name << "\tЗаработная плата: " << wages;
}
void Emploee::input()
{
	cout << "Введите данные:" << endl;
	cout << "Имя: ";
	cin >> name;
	cout << "Заработная плата: ";
	while (!(cin >> wages) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите заработную плату: " << endl;
	}
}

Teacher::Teacher() 
{
	cout << "Конструктор Teacher. Количество: " << count << endl;
};
Teacher::Teacher(string n, int w, string sub, int sen) :Emploee(n, w)
{
	cout << "Конструктор Teacher. Количество: " << count << endl;
	subject = sub;
	seniority = sen;
}
Teacher::~Teacher() 
{
	cout << "Деструктор Teacher. Количество: " << count << endl;
};
void Teacher::setSubject(string sub)
{
	subject = sub;
}
void Teacher::setSeniority(int sen)
{
	seniority = sen;
}
int Teacher::getSeniority()
{
	return seniority;
}
string Teacher::getSubject()
{
	return subject;
}
void Teacher::input()
{
	Emploee::input();
	cout << "Предмет: ";
	cin >> subject;
	cout << "Стаж: ";
	while (!(cin >> seniority) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите стаж: " << endl;
	}
}
void Teacher::show()
{
	Emploee::show();
	cout << "\tПредмет: " << subject << "\tСтаж: " << seniority;
}

Manager::Manager() 
{
	cout << "Конструктор Manager. Количество: " << count << endl;
};
Manager::Manager(string n, int w, string sub, int sen, string q, int num) :Teacher(n, w, sub, sen)
{
	cout << "Конструктор Manager. Количество: " << count << endl;
	quality = q;
	number_of_student = num;
}
Manager::~Manager()
{
	cout << "Деструктор Manager. Количество: " << count << endl;
};
void Manager::setNumberOf(int num)
{
	number_of_student = num;
}
void Manager::setQuality(string q)
{
	quality = q;
}
int Manager::getNunberOf()
{
	return number_of_student;
}
string Manager::getQuality()
{
	return quality;
}
void Manager::input()
{
	Teacher::input();
	cout << "Количество студентов:";
	while (!(cin >> number_of_student) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите количество студентов: " << endl;
	}
	cout << "Качество:";
	cin >> quality;
}
void Manager::show()
{
	Teacher::show();
	cout << "\tКачество: " << quality << "\tКоличество студентов: " << number_of_student;
}