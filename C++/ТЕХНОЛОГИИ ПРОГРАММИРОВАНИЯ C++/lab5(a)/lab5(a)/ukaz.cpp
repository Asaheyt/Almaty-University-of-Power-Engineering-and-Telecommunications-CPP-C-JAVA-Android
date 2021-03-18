#include <iostream>
#include <string>
#include "ukaz.h"
#include <windows.h>
using namespace std;
//--------------------------------------------------------------------------------------------------------
int Liver::count = 0;
Liver::Liver()
{
	count++;
}
Liver::Liver(string n, int h, int p)
{
	count++;
	name = n;
	homeNum = h;
	postNum = p;
}
Liver::~Liver()
{
	count--;
}
void Liver::setName(string n)
{
	name = n;
}
void Liver::setHomeNum(int h)
{
	homeNum = h;
}
void Liver::setPostNum(int p)
{
	postNum = p;
}
int Liver::getHomeNum()
{
	return homeNum;
}
string Liver::getName()
{
	return name;
}
int Liver::getPostNum()
{
	return postNum;
}
void Liver::show()
{
	cout << "Имя: " << name << "  Номер дома: " << homeNum << "  Почтовый индекс: " << postNum << "  ";
}
void Liver::input()
{
	cout << "Введите данные: " << endl;
	cout << "Имя: ";
	bool OK = false;
	while (!OK)
	{
		getline(cin,name);
		for (int j = 0;j < name.length(); j++)
		{
			if ((name[j] >= 'A' && name[j] <= 'Z') || (name[j] >= 'a' && name[j] <= 'z') || (name[j] >= 'А' && name[j] <= 'Я') || (name[j] >= 'а' && name[j] <= 'я') || (j != 0 && name[j] == ' '))
			{
				OK = true;
			}
			else { OK = false;break; }
		}
		if (OK == false) { cout << "Ошибка! Введите имя: " << endl; }
	}
	cout << "Номер дома: ";
	while (!(cin >> homeNum) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите номер дома: " << endl;
	}
	cout << "Почтовый индекс: ";
	while (!(cin >> postNum) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите почтовый индекс: " << endl;
	}
	cin.ignore();
}
//--------------------------------------------------------------------------------------------------------
Emploee::Emploee() {}
Emploee::Emploee(string n, int h, int p, string j, int w, float s) :Liver(n, h, p)
{
	job = j;
	wages = w;
	seniority = s;
}
Emploee::~Emploee() {}
void Emploee::setJob(string j)
{
	job = j;
}
void Emploee::setWages(int w)
{
	wages = w;
}
void Emploee::setSeniority(float s)
{
	seniority = s;
}
int Emploee::getWages()
{
	return wages;
}
string Emploee::getJob()
{
	return job;
}
float Emploee::getSeniority()
{
	return seniority;
}
void Emploee::show()
{
	Liver::show();
	cout << "Профессия: " << job << "  Заработная плата: " << wages << "  Стаж работы: " << seniority << "  ";
}
void Emploee::input()
{
	Liver::input();
	cout << "Профессия: ";
	bool OK = false;
	while (!OK)
	{
		getline(cin,job);
		for (int j = 0;j<job.length(); j++)
		{
			if ((job[j] >= 'A' && job[j] <= 'Z') || (job[j] >= 'a' && job[j] <= 'z') || (job[j] >= 'А' && job[j] <= 'Я') || (job[j] >= 'а' && job[j] <= 'я') || (j != 0 && job[j] == ' '))
			{
				OK = true;
			}
			else { OK = false;break; }
		}
		if (OK == false) { cout << "Ошибка! Введите профессию: " << endl; }
	}
	cout << "Заработная плата: ";
	while (!(cin >> wages) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите заработную плату: " << endl;
	}
	cout << "Стаж работы: ";
	while (!(cin >> seniority) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите стаж работы: " << endl;
	}
	cin.ignore();
}
//--------------------------------------------------------------------//
Organization::Organization()
{
	N_Emploee = 0;
}
Organization::Organization(string n)
{
	name = n;
	N_Emploee = 0;
}
Organization::~Organization() {}
void Organization::setName(string n)
{
	name = n;
}
string Organization::getName()
{
	return name;
}
void Organization::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i]->show();
		cout << endl;
	}
}
void Organization::addEmploee(const Emploee& e)
{
	if (N_Emploee == maxN)
	{
		cout << "Массив заполнен" << endl;
	}
	else 
	{
		p[N_Emploee] = new Emploee;
		*p[N_Emploee] = e; 
		N_Emploee++;
	}
	
}
void Organization::deleteLastEmploee()
{
	if (N_Emploee == 0)
	{
		cout << "Массив пуст" << endl;
	}
	else 
	{ 
		delete p[N_Emploee-1];
		N_Emploee--; 
	}
}
Emploee* Organization::find_name(string n)
{
	Emploee *temp;
	temp = NULL;
	for (int i = 0;i < N_Emploee;i++)
	{
		if(p[i]->name == n)
		{
			temp = p[i];
			return temp;
		}
	}
	return temp;
}