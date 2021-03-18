#include "stdafx.h"
#include "wab.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <io.h>
using namespace std;
const int Const = 10;
wchar_t* names[Const] = { L"Александр",L"Даулет",L"Даша",L"Хаджиме",L"Джакс",L"Соня",L"Абылай",L"Валерий",L"Ибрагим",L"Лена" };
wchar_t* jobs[Const] = { L"Инженер",L"Программист",L"Бухгалтер",L"Продавец",L"Менеджер",L"Риелтор",L"Водитель",L"Директор",L"Преподаватель",L"Кассир" };
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
int Liver::count = 0;
Liver::Liver()
{
	count++;
}
Liver::Liver(wchar_t* n, int h, int p)
{
	count++;
	wcscpy_s(name, n);
	homeNum = h;
	postNum = p;
}
Liver::~Liver()
{
	count--;
}
void Liver::setName(wchar_t* n)
{
	wcscpy_s(name, n);
}
void Liver::setHomeNum(int h)
{
	homeNum = h;
}
void Liver::setPostNum(int p)
{
	postNum = p;
}
int Liver::getHomeNum()const
{
	return homeNum;
}
const wchar_t* Liver::getName()
{
	return name;
}
int Liver::getPostNum()const
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
		wcin.getline(name, maxN);
		for (int j = 0;j < wcslen(name); j++)
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
int cmpName(Emploee& l1, Emploee& l2)
{
	int t;
	if (wcscmp(l1.getName(), l2.getName()) == -1) { t = 1; }
	if (wcscmp(l1.getName(), l2.getName()) == 1) { t = -1; }
	if (wcscmp(l1.getName(), l2.getName()) == 0) { t = 0; }
	return t;
}
int cmpHomeNum(Emploee& l1, Emploee& l2)
{
	int t;
	if (l1.getHomeNum()<l2.getHomeNum()) { t = 1; }
	if (l1.getHomeNum()>l2.getHomeNum()) { t = -1; }
	if (l1.getHomeNum() == l2.getHomeNum()) { t = 0; }
	return t;
}
int cmpPostNum(Emploee& l1, Emploee& l2)
{
	int t;
	if (l1.getPostNum()<l2.getPostNum()) { t = 1; }
	if (l1.getPostNum()>l2.getPostNum()) { t = -1; }
	if (l1.getPostNum() == l2.getPostNum()) { t = 0; }
	return t;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
Emploee::Emploee() {}
Emploee::Emploee(wchar_t* n, int h, int p, wchar_t* j, int w, int s) :Liver(n, h, p)
{
	wcscpy_s(job, j);
	wages = w;
	seniority = s;
}
Emploee::~Emploee() {}
void Emploee::setJob(wchar_t*j)
{
	wcscpy_s(job, j);
}
void Emploee::setWages(int w)
{
	wages = w;
}
void Emploee::setSeniority(int s)
{
	seniority = s;
}
int Emploee::getWages()const
{
	return wages;
}
const wchar_t* Emploee::getJob()
{
	return job;
}
int Emploee::getSeniority()const
{
	return seniority;
}
void Emploee::show()
{
	Liver::show();
	wcout << L" Профессия: " << job << L"  Заработная плата: " << wages << L"  Стаж работы: " << seniority << L" ";
}
void Emploee::input()
{
	Liver::input();
	wcout << L"Профессия: ";
	bool OK = false;
	while (!OK)
	{
		wcin.getline(job, maxN);
		for (int j = 0;j<wcslen(job); j++)
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
void Emploee::RANDOM()
{
	this->setName(names[rand() % Const]);
	this->setHomeNum(rand() % 10);
	this->setPostNum(rand() % 700000);
	this->setJob(jobs[rand() % Const]);
	this->setWages(rand() % 1000000);
	this->setSeniority(rand() % 10);
}
int cmpJob(Emploee& e1, Emploee& e2)
{
	int t;
	if (wcscmp(e1.getJob(), e2.getJob()) == -1) { t = 1; }
	if (wcscmp(e1.getJob(), e2.getJob()) == 1) { t = -1; }
	if (wcscmp(e1.getJob(), e2.getJob()) == 0) { t = 0; }
	return t;
}
int cmpWages(Emploee& e1, Emploee& e2)
{
	int t;
	if (e1.getWages()<e2.getWages()) { t = 1; }
	if (e1.getWages()>e2.getWages()) { t = -1; }
	if (e1.getWages() == e2.getWages()) { t = 0; }
	return t;
}
int cmpSeniority(Emploee& e1, Emploee& e2)
{
	int t;
	if (e1.getSeniority()<e2.getSeniority()) { t = 1; }
	if (e1.getSeniority()>e2.getSeniority()) { t = -1; }
	if (e1.getSeniority() == e2.getSeniority()) { t = 0; }
	return t;
}
//--------------------------------------------------------------------------------------------------
Exception::Exception(const wstring l)
{
	str = l;
}
void Exception::show()
{
	wcout << str << endl;
}
//-----------------------------------------------------------------------------------
Func::Func()
{
	type = false;
}
Func::Func(bool x)
{
	type = x;
}
Func::Func(int r)
{
	g = r;
}
Func::Func(int r, bool k)
{
	type = k;
	g = r;
}
bool Func::compare(Emploee &f, Emploee &s)
{
	int i = 0;
	switch (abs(g)) {
	case 1:
		while (f.getName()[i] == s.getName()[i])
		{
			i++;
		}
		if (f.getName()[i] <  s.getName()[i])
		{
			return true;
		}
		else
		{
			return false;
		};
	case 2:
		while (f.getJob()[i] == s.getJob()[i])
		{
			i++;
		}
		if (f.getJob()[i] <  s.getJob()[i])
		{
			return true;
		}
		else
		{
			return false;
		};
	case 3:	 return f.getPostNum() < s.getPostNum();
	case 4:   return f.getHomeNum() < s.getHomeNum();
	case 5:   return f.getWages() < s.getWages();
	case 6:   return f.getSeniority() < s.getSeniority();
	default: return false;
	}
}
bool Func::operator()(Emploee &t, Emploee &y)
{
	bool ret = compare(t, y);
	return g >= 0 ? ret : !ret;

}
Func Func::operator()(int v)
{
	g = v;
	return *this;
}
Func Func::operator()(bool v)
{
	type = v;
	return *this;
}
bool Func::operator()(wchar_t *t, wchar_t *g)
{
	int ind;
	int i = 0;
	while (t[i] == g[i])
	{
		i++;
	}
	if (t[i] > g[i])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Func::operator()(int t, int g)
{
	if (t < g) { return true; }
	if (t > g) { return false; }
	if (t == g) { t = 0; }
	return t;
}
bool Func::Gettype()
{
	return type;
}
//----------------------------------------------------------------------------------------------

