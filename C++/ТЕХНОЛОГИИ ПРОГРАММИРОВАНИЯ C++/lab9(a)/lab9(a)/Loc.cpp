#include "stdafx.h"
#include <iostream>
#include <string>
#include "Loc.h"
#include <windows.h>
using namespace std;
//--------------------------------------------------------------------------------------------------------
Liver::Liver() {}
Liver::Liver(wstring n, int h, int p)
{
	name = n;
	homeNum = h;
	postNum = p;
}
Liver::~Liver() {}
void Liver::setName(wstring n)
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
wstring Liver::getName()
{
	return name;
}
int Liver::getPostNum()
{
	return postNum;
}
void Liver::show()
{
	wcout << L"Имя: " << name << L"  Номер дома: " << homeNum << L"  Почтовый индекс: " << postNum << L"  ";
}
void Liver::input()
{
	wcout << L"Введите данные: " << endl;
	wcout << L"Имя: ";
	bool OK = false;
	while (!OK)
	{
		getline(wcin, name);
		for (int j = 0;j < name.length(); j++)
		{
			if ((name[j] >= L'A' && name[j] <= L'Z') || (name[j] >= L'a' && name[j] <= L'z') || (name[j] >= L'А' && name[j] <= L'Я') || (name[j] >= L'а' && name[j] <= L'я') || (j != 0 && name[j] == L' '))
			{
				OK = true;
			}
			else { OK = false;break; }
		}
		if (OK == false) { wcout << L"Ошибка! Введите имя: " << endl; }
	}
	wcout << L"Номер дома: ";
	while (!(cin >> homeNum) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"Ошибка!Введите номер дома: " << endl;
	}
	wcout << L"Почтовый индекс: ";
	while (!(cin >> postNum) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"Ошибка!Введите почтовый индекс: " << endl;
	}
	cin.ignore();
}
//--------------------------------------------------------------------------------------------------------
Emploee::Emploee() {}
Emploee::Emploee(wstring n, int h, int p, wstring j, int w, float s) :Liver(n, h, p)
{
	job = j;
	wages = w;
	seniority = s;
}
Emploee::~Emploee() {}
void Emploee::setJob(wstring j)
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
wstring Emploee::getJob()
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
	wcout << L"Профессия: " << job << L"  Заработная плата: " << wages << L"  Стаж работы: " << seniority << L"  ";
}
void Emploee::input()
{
	Liver::input();
	wcout << L"Профессия: ";
	bool OK = false;
	while (!OK)
	{
		getline(wcin, job);
		for (int j = 0;j<job.length(); j++)
		{
			if ((job[j] >= L'A' && job[j] <= L'Z') || (job[j] >= L'a' && job[j] <= L'z') || (job[j] >= L'А' && job[j] <= L'Я') || (job[j] >= L'а' && job[j] <= L'я') || (j != 0 && job[j] == L' '))
			{
				OK = true;
			}
			else { OK = false;break; }
		}
		if (OK == false) { wcout << L"Ошибка! Введите профессию: " << endl; }
	}
	wcout << L"Заработная плата: ";
	while (!(cin >> wages) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"Ошибка!Введите заработную плату: " << endl;
	}
	wcout << L"Стаж работы: ";
	while (!(cin >> seniority) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"Ошибка!Введите стаж работы: " << endl;
	}
	cin.ignore();
}
//--------------------------------------------------------------------//
Organization::Organization()
{
	N_Emploee = 0;
}
Organization::Organization(wstring n)
{
	name = n;
	N_Emploee = 0;
}
Organization::~Organization() {}
void Organization::setName(wstring n)
{
	name = n;
}
wstring Organization::getName()
{
	return name;
}
int Organization::getN_Emploee()
{
	return N_Emploee;
}
//----------------------------------------------------------------------------------------------
void Organization_A::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i]->show();
		wcout << endl;
	}
}
void Organization_A::addEmploee(const Emploee& e)
{
	if (N_Emploee == maxN)
	{
		wcout << L"Массив заполнен" << endl;
	}
	else
	{
		p[N_Emploee] = new Emploee;
		*p[N_Emploee] = e;
		N_Emploee++;
	}

}
void Organization_A::deleteLastEmploee()
{
	if (N_Emploee == 0)
	{
		wcout << L"Массив пуст" << endl;
	}
	else
	{
		delete p[N_Emploee - 1];
		N_Emploee--;
	}
}
Emploee* Organization_A::find_name(wstring n)
{
	Emploee *temp;
	temp = NULL;
	for (int i = 0;i < N_Emploee;i++)
	{
		if (p[i]->getName() == n)
		{
			temp = p[i];
			return temp;
		}
	}
	wcout << L"Совпадении нет." << endl;
	return temp;
}
//----------------------------------------------------------------------------------------------
void Organization_B::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i].show();
		wcout << endl;
	}
}
void Organization_B::addEmploee(const Emploee& e)
{
	if (N_Emploee == maxN)
	{
		wcout << L"Массив заполнен" << endl;
	}
	else
	{
		p[N_Emploee] = e;
		N_Emploee++;
	}

}
void Organization_B::deleteLastEmploee()
{
	if (N_Emploee == 0)
	{
		wcout << L"Массив пуст" << endl;
	}
	else
	{
		N_Emploee--;
	}
}
Emploee* Organization_B::find_name(wstring n)
{
	Emploee *temp;
	temp = NULL;
	for (int i = 0;i < N_Emploee;i++)
	{
		if (p[i].getName() == n)
		{
			temp = &p[i];
			return temp;
		}
	}
	wcout << L"Совпадении нет." << endl;
	return temp;
}
