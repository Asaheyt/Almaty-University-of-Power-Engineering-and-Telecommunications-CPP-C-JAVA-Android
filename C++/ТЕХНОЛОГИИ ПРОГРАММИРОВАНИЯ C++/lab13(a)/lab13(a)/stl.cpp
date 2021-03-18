#include "stdafx.h"
#include "stl.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <iterator>
#include <vector>
#include <algorithm>
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
bool cmpName1(Emploee& l1, Emploee& l2)
{
	bool t=true;
	if (wcscmp(l1.getName(), l2.getName()) == -1) { t = true; }
	if (wcscmp(l1.getName(), l2.getName()) == 1) { t = false; }
	if (wcscmp(l1.getName(), l2.getName()) == 0) { t = true; }
	return t;
}
bool cmpHomeNum1(Emploee& l1, Emploee& l2)
{
	bool t;
	if (l1.getHomeNum()<l2.getHomeNum()) { t = true; }
	if (l1.getHomeNum()>l2.getHomeNum()) { t = false; }
	if (l1.getHomeNum() == l2.getHomeNum()) { t = true; }
	return t;
}
bool cmpPostNum1(Emploee& l1, Emploee& l2)
{
	bool t;
	if (l1.getPostNum()<l2.getPostNum()) { t = true; }
	if (l1.getPostNum()>l2.getPostNum()) { t = false; }
	if (l1.getPostNum() == l2.getPostNum()) { t = true; }
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
bool cmpJob1(Emploee& e1, Emploee& e2)
{
	bool t;
	if (wcscmp(e1.getJob(), e2.getJob()) == -1) { t = true; }
	if (wcscmp(e1.getJob(), e2.getJob()) == 1) { t = false; }
	if (wcscmp(e1.getJob(), e2.getJob()) == 0) { t = true; }
	return t;
}
bool cmpWages1(Emploee& e1, Emploee& e2)
{
	bool t;
	if (e1.getWages()<e2.getWages()) { t = true; }
	if (e1.getWages()>e2.getWages()) { t = false; }
	if (e1.getWages() == e2.getWages()) { t = true; }
	return t;
}
bool cmpSeniority1(Emploee& e1, Emploee& e2)
{
	bool t;
	if (e1.getSeniority()<e2.getSeniority()) { t = true; }
	if (e1.getSeniority()>e2.getSeniority()) { t = false; }
	if (e1.getSeniority() == e2.getSeniority()) { t = true; }
	return t;
}
//----------------------------------------------------------------------------------------------------
Organization::Organization()
{
	N_Emploee = 0;
}
Organization::Organization(const Organization& a)
{
	*this = a;
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
wstring Organization::getName()const
{
	return name;
}
int Organization::getN_Emploee()
{
	return N_Emploee;
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
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void Organization_Ukaz::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i]->show();
		wcout << endl;
	}
}
void Organization_Ukaz::addEmploee(const Emploee& e)
{
	try
	{
		if (N_Emploee >= maxN)
		{
			throw Exception(L"Массив заполнен");
		}
		p[N_Emploee] = new Emploee;
		*p[N_Emploee] = e;
		N_Emploee++;
		//cout << "Добавлен новый элемент" << endl;
	}
	catch (Exception a)
	{
		a.show();
	}
}
void Organization_Ukaz::deleteLastEmploee()
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
void Organization_Ukaz::sorting(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(*p[i], *p[j]))>0)
			{
				swap(*p[i], *p[j]);
			}
		}
	}
}
void Organization_Ukaz::Del_Duplicate(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(*p[i], *p[j])) == 0)
			{
				this->Move(j);
				j--;
			}
		}
	}
}
void Organization_Ukaz::Move(int k)
{
	for (int i = k;i<N_Emploee - 1;i++)
	{
		*p[i] = *p[i + 1];
	}
	this->deleteLastEmploee();
}
void Organization_Ukaz::RANDOM_Fill(int k)
{

	Emploee e;
	for (int i = 0;i<k;i++)
	{
		e.setName(names[rand() % Const]);
		e.setHomeNum(rand() % 10);
		e.setPostNum(rand() % 70000);
		e.setJob(jobs[rand() % Const]);
		e.setWages(rand() % 1000000);
		e.setSeniority(rand() % 10);
			this->addEmploee(e);
	}
}
int Organization_Ukaz::b = 0;
void Organization_Ukaz::inputinfile()
{
	char g[50];
	char u[50] = { 0 };
	int temp = 0;
	wcout << L"Введите имя файла:";
	cin >> g;
	if (_access(g, 0) == 0)
	{
		b++;
		for (int i = 0; i < strlen(g); i++)
		{

			if (g[i] != '.') {
				u[temp] = g[i];
				temp++;
			}
			if (g[i] == '.')
			{
				u[temp] = b + 48;
				temp++;
				u[temp] = g[i];
				temp++;
			}

		}
	}
	else {
		for (int i = 0; i < strlen(g); i++)
		{
			u[i] = g[i];
		}
	}
	ofstream fout(u, wios::binary);
	for (int i = 0; i < N_Emploee; i++)
	{
		fout.write((char *)p[i], sizeof(Emploee));
	}
	fout.close();
	wcin.get();
}
void Organization_Ukaz::readfromfile()
{
	if (N_Emploee > 0) { wcout << L"В массиве указателей уже имеются данные" << endl; }
	else
	{
		system("DIR \*.fbd");
		wstring g;
		wcout << L"Введите имя файла:";
		wcin >> g;
		ifstream fin(g, wios::binary);
		fin.seekg(0, wios::end);
		int k;
		k = fin.tellg();
		fin.seekg(0, wios::beg);
		N_Emploee = k / sizeof(Emploee);
		for (int i = 0; i < N_Emploee; i++)
		{
			p[i] = new Emploee;
			fin.read((char *)p[i], sizeof(Emploee));
		}
		fin.close();
		wcin.get();
	}
}
//----------------------------------------------------------------------------------------------------
void Organization_Mas::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i].show();
		wcout << endl;
	}
}
void Organization_Mas::addEmploee(const Emploee& e)
{
	try
	{
		if (N_Emploee >= maxN)
		{
			throw Exception(L"Массив заполнен");
		}
		p[N_Emploee] = e;
		N_Emploee++;
		//cout << "Добавлен новый элемент" << endl;
	}
	catch (Exception a)
	{
		a.show();
	}
}
void Organization_Mas::deleteLastEmploee()
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
void Organization_Mas::sorting(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(p[i], p[j]))<0)
			{
				swap(p[i], p[j]);
			}
		}
	}
}
void Organization_Mas::Del_Duplicate(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(p[i], p[j])) == 0)
			{
				this->Move(j);
				j--;
			}
		}
	}
}
void Organization_Mas::Move(int k)
{
	for (int i = k;i<N_Emploee - 1;i++)
	{
		p[i] = p[i + 1];
	}
	this->deleteLastEmploee();
}
void Organization_Mas::RANDOM_Fill(int k)
{

	Emploee e;
	for (int i = 0;i<k;i++)
	{
		e.setName(names[rand() % Const]);
		e.setHomeNum(rand() % 10);
		e.setPostNum(rand() % 70000);
		e.setJob(jobs[rand() % Const]);
		e.setWages(rand() % 1000000);
		e.setSeniority(rand() % 10);
		this->addEmploee(e);
	}
}
int Organization_Mas::a = 0;
void Organization_Mas::inputinfile()
{
	char g[50];
	char u[50] = { 0 };
	int temp = 0;
	wcout << L"Введите имя файла:";
	cin >> g;
	if (_access(g, 0) == 0)
	{
		a++;
		for (int i = 0; i < strlen(g); i++)
		{

			if (g[i] != '.') {
				u[temp] = g[i];
				temp++;
			}
			if (g[i] == '.')
			{
				u[temp] = a + 48;
				temp++;
				u[temp] = g[i];
				temp++;
			}

		}
	}
	else {
		for (int i = 0; i < strlen(g); i++)
		{
			u[i] = g[i];
		}
	}
	ofstream fout(u, wios::binary);
	fout.write((char *)p, sizeof(Emploee)*N_Emploee);
	fout.close();
	wcin.get();
}
void Organization_Mas::readfromfile()
{
	if (N_Emploee > 0) { wcout << L"В массиве объектов уже имеются данные" << endl; }
	else
	{
		system("DIR \*.fbd");
		wstring g;
		wcout << L"Введите имя файла:";
		wcin >> g;
		ifstream fin(g, wios::binary);
		fin.seekg(0, wios::end);
		int k;
		k = fin.tellg();
		fin.seekg(0, wios::beg);
		fin.read((char *)p, k);
		N_Emploee = k / sizeof(Emploee);
		fin.close();
		wcin.get();
	}
}
//------------------------------------------------------------------------------------------------
Organization_DinMas::Organization_DinMas()
{
	p = NULL;
}
void Organization_DinMas::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i].show();
		wcout << endl;
	}
}
void Organization_DinMas::addEmploee(const Emploee& e)
{
	Emploee *temp = new Emploee[N_Emploee + 1];
	copy(p, p + N_Emploee, stdext::make_unchecked_array_iterator(temp));
	temp[N_Emploee] = e;
	delete[]p;
	p = temp;
	N_Emploee++;
	//cout << "Добавлен новый элемент" << endl;
}
void Organization_DinMas::deleteLastEmploee()
{
	if (N_Emploee>0)
	{
		Emploee *temp = new Emploee[N_Emploee];
		copy(p, p + N_Emploee - 1, stdext::make_unchecked_array_iterator(temp));
		Emploee e;
		e = p[N_Emploee - 1];
		delete[]p;
		p = temp;
		N_Emploee--;
	}
	else { wcout << L"Массив пуст." << endl; }
}
void Organization_DinMas::sorting(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(p[i], p[j]))<0)
			{
				swap(p[i], p[j]);
			}
		}
	}
}
void Organization_DinMas::Del_Duplicate(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(p[i], p[j])) == 0)
			{
				this->Move(j);
				j--;
			}
		}
	}
}
void Organization_DinMas::Move(int k)
{
	for (int i = k;i<N_Emploee - 1;i++)
	{
		p[i] = p[i + 1];
	}
	this->deleteLastEmploee();
}
void Organization_DinMas::RANDOM_Fill(int k)
{
	Emploee e;
	for (int i = 0;i<k;i++)
	{
		e.setName(names[rand() % Const]);
		e.setHomeNum(rand() % 10);
		e.setPostNum(rand() % 70000);
		e.setJob(jobs[rand() % Const]);
		e.setWages(rand() % 1000000);
		e.setSeniority(rand() % 10);
		this->addEmploee(e);
	}
}
int Organization_DinMas::c = 0;
void Organization_DinMas::inputinfile()
{
	char g[50];
	char u[50] = { 0 };
	int temp = 0;
	wcout << L"Введите имя файла:";
	cin >> g;
	if (_access(g, 0) == 0)
	{
		c++;
		for (int i = 0; i < strlen(g); i++)
		{

			if (g[i] != '.') {
				u[temp] = g[i];
				temp++;
			}
			if (g[i] == '.')
			{
				u[temp] = c + 48;
				temp++;
				u[temp] = g[i];
				temp++;
			}

		}
	}
	else {
		for (int i = 0; i < strlen(g); i++)
		{
			u[i] = g[i];
		}
	}
	ofstream fout(u, wios::binary);
	fout.write((char *)p, sizeof(Emploee)*N_Emploee);
	fout.close();
	wcin.get();
}
void Organization_DinMas::readfromfile()
{
	if (N_Emploee > 0) { wcout << L"В массиве объектов уже имеются данные" << endl; }
	else
	{
		system("DIR \*.fbd");
		wstring g;
		wcout << L"Введите имя файла:";
		wcin >> g;
		ifstream fin(g, wios::binary);
		fin.seekg(0, wios::end);
		int k;
		k = fin.tellg();
		fin.seekg(0, wios::beg);
		N_Emploee = k / sizeof(Emploee);
		p = new Emploee[N_Emploee];
		fin.read((char *)p, k);
		fin.close();
		wcin.get();
	}
}
//-----------------------------------------------------------------------------------
Organization_DinList::Organization_DinList()
{
	begin = end = NULL;
}
void Organization_DinList::show()
{
	if (begin != NULL)
	{
		Node *a;
		a = begin;
		a->data.show();
		wcout << endl;
		while (a->next != NULL)
		{
			a = a->next;
			a->data.show();
			wcout << endl;
		}
	}
	else
	{
		wcout << L"Список пуст." << endl;
	}
}
void Organization_DinList::addEmploee(const Emploee& e)
{
	Node *a;
	a = new Node;
	a->data = e;
	a->next = NULL;
	if (begin == NULL)
	{
		a->prev = NULL;
		begin = a;
		end = begin;
	}
	else
	{
		a->prev = end;
		end->next = a;
		end = a;
	}
	N_Emploee++;


}
void Organization_DinList::push_front(const Emploee& e)
{
	Node *a;
	a = new Node;
	a->data = e;
	a->prev = NULL;
	if (begin == NULL)
	{
		a->next = NULL;
		begin = a;
		end = begin;
	}
	else
	{
		a->next = begin;
		begin->prev = a;
		begin = a;
	}
	N_Emploee++;
}
void Organization_DinList::deleteLastEmploee()
{
	if (begin != NULL)
	{
		Node *a, *b;
		a = end;
		b = end->prev;
		if (b != NULL)
		{
			end = b;
			end->next = NULL;
		}
		if (b == NULL)
		{
			end->prev = NULL;
			end = NULL;
			begin = end;
		}
		delete a;
		N_Emploee--;
	}
	else
	{
		wcout << L"Список пуст." << endl;
	}
}
Emploee Organization_DinList::pop_front()
{
	if (begin != NULL)
	{
		Node *a, *b;
		a = begin;
		b = begin->next;
		Emploee e;
		e = a->data;
		if (b != NULL)
		{
			begin = b;
			begin->prev = NULL;
		}
		if (b == NULL)
		{
			begin->prev = NULL;
			begin = NULL;
			end = begin;
		}
		delete a;
		N_Emploee--;
		return e;
	}
	else
	{
		wcout << L"Список пуст." << endl;
	}
}
void Organization_DinList::sorting(int(*cmp)(Emploee&, Emploee&))
{
	Node *a = NULL;
	Node *b = NULL;
	Node *c = NULL;
	Node *e = NULL;
	Node *tmp = NULL;
	while (e != begin->next)
	{
		c = a = begin;
		b = a->next;
		while (a != e)
		{
			if (cmp(a->data, b->data) <0)
			{
				if (a == begin)
				{
					tmp = b->next;
					b->next = a;
					a->next = tmp;
					begin = b;
					c = b;
				}
				else
				{
					tmp = b->next;
					b->next = a;
					a->next = tmp;
					c->next = b;
					c = b;
				}
			}
			else
			{
				c = a;
				a = a->next;
			}
			b = a->next;
			if (b == e)
				e = a;
		}
	}
}
void Organization_DinList::Del_Duplicate(int(*cmp)(Emploee&, Emploee&))
{
	Node *t, *q, *p = begin, *i = begin;
	while (p != NULL) 
	{
		for (t = i = p->next; i != NULL; ) 
		{
			if (cmp(i->data, p->data)==0)
			{
				q = i->next;
				if (t == i)
				{
					t = p->next = i->next;
				}
				else
				{
					t->next = i->next;
				}
				delete i;
				i = q;
				continue;
			}
			t = i;
			i = i->next;
		}
		p = p->next;
	}
}
void Organization_DinList::RANDOM_Fill(int k)
{
	Emploee e;
	N_Emploee = k;
	for (int i = 0;i<k;i++)
	{
		e.setName(names[rand() % Const]);
		e.setHomeNum(rand() % 10);
		e.setPostNum(rand() % 70000);
		e.setJob(jobs[rand() % Const]);
		e.setWages(rand() % 1000000);
		e.setSeniority(rand() % 10);
		this->addEmploee(e);
	}
}
int Organization_DinList::d = 0;
void Organization_DinList::inputinfile()
{
	char g[50];
	char u[50] = { 0 };
	int temp = 0;
	wcout << L"Введите имя файла:";
	cin >> g;
	if (_access(g, 0) == 0)
	{
		d++;
		for (int i = 0; i < strlen(g); i++)
		{

			if (g[i] != '.') {
				u[temp] = g[i];
				temp++;
			}
			if (g[i] == '.')
			{
				u[temp] = d + 48;
				temp++;
				u[temp] = g[i];
				temp++;
			}

		}
	}
	else {
		for (int i = 0; i < strlen(g); i++)
		{
			u[i] = g[i];
		}
	}
	ofstream fout(u, wios::binary);
	Node *e;
	e = begin;
	while (e->next != NULL)
	{
		fout.write((char *)&e->data, sizeof(Emploee));
		e = e->next;
	}
	fout.close();
	wcin.get();
}
void Organization_DinList::readfromfile()
{
	if (N_Emploee > 0) { wcout << L"В массиве объектов уже имеются данные" << endl; }
	else
	{
		system("DIR \*.fbd");
		wstring g;
		wcout << L"Введите имя файла:";
		wcin >> g;
		ifstream fin(g, wios::binary);
		Emploee e;
		while (!fin.eof())
		{
			fin.read((char *)&e, sizeof(Emploee));
			this->addEmploee(e);
		}
		this->deleteLastEmploee();
		fin.close();
		wcin.get();
	}
}
//---------------------------------------------------------------------------------------
void Organization_Vect::addEmploee(const Emploee& e)
{
		t.push_back(e);
		N_Emploee++;
}
void Organization_Vect::deleteLastEmploee()
{
	t.pop_back();
	N_Emploee--;
}
void Organization_Vect::show()
{
	if (N_Emploee > 0)
	{
		for (int i = 0; i < N_Emploee; i++)
		{
			t[i].show();
			wcout << endl;
		}
	}
	else { wcout << L"Вектор пуст" << endl; }
}
void Organization_Vect::sorting(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(t[i], t[j]))<0)
			{
				swap(t[i], t[j]);
			}
		}
	}
}
void Organization_Vect::Del_Duplicate(int(*cmp)(Emploee&, Emploee&))
{
	for (int i = 0;i<N_Emploee - 1;i++)
	{
		for (int j = i + 1;j<N_Emploee;j++)
		{
			if ((cmp(t[i], t[j])) == 0)
			{
				this->Move(j);
				j--;
			}
		}
	}
}
void Organization_Vect::Move(int k)
{
	for (int i = k;i<N_Emploee - 1;i++)
	{
		t[i] = t[i + 1];
	}
	this->deleteLastEmploee();
}
void Organization_Vect::RANDOM_Fill(int k)
{
	Emploee e;
	for (int i = 0; i < k; i++)
	{
		e.setName(names[rand() % Const]);
		e.setHomeNum(rand() % 10);
		e.setPostNum(rand() % 700000);
		e.setJob(jobs[rand() % Const]);
		e.setSeniority(rand() % 10);
		e.setWages(rand() % 1000500);
		this->addEmploee(e);
	}
}
int Organization_Vect::e = 0;
void Organization_Vect::inputinfile()
{
	char g[50];
	char v[10] = "";
	char u[50] = { 0 };
	int temp = 0;
	cout << "Введите имя файла:";
	cin >> g;
	if (_access(g, 0) == 0)
	{
		e++;
		for (int i = 0; i < strlen(g); i++)
		{

			if (g[i] != '.') {
				u[temp] = g[i];
				temp++;
			}
			if (g[i] == '.')
			{
				_itoa_s(e, v, 10);
				for (int j = 0; j < strlen(v); j++)
				{
					u[temp] = v[j];
					temp++;
				}
				u[temp] = g[i];
				temp++;
			}

		}
	}
	else {
		for (int i = 0; i < strlen(g); i++)
		{
			u[i] = g[i];
		}
	}
	ofstream k(u, ios::binary);
	k.write((char*)&t.front(), sizeof(Emploee)*t.size());
	k.close();
}
void Organization_Vect::readfromfile()
{
	if (N_Emploee > 0) { wcout << L"В массиве объектов уже имеются данные" << endl; }
	else
	{
		system("DIR \*.fbd");
		wchar_t g[50];
		int h;
		Emploee x;
		wcout << L"Введите имя файла:";
		wcin >> g;
		ifstream fin(g, ios::binary);
		fin.seekg(0, ios::end);
		int k;
		k = fin.tellg();
		fin.seekg(0, ios::beg);
		for (int i = 0; i < k / sizeof(Emploee); i++)
		{
			fin.read((char *)&x, sizeof(Emploee));
			this->addEmploee(x);
		}
		wcin.get();
	}
}
//-------------------------------------------------------------------------------------------------------------
void cnslCmd(Organization* l)
{
	Emploee k;
	wstring h, im;
	int x;
	wcout << L"Введите имя организации:";
	getline(wcin, im);
	l->setName(im);
	while (h != L"stop")
	{
		wcout << L"Для просмотра списка команд введите help.Введите команду:";
		getline(wcin, h);
		if (h == L"add")
		{
			k.input();
			l->addEmploee(k);
			wcout << L"Добавлено" << endl;
		}
		else if (h == L"deletelast")
		{
			l->deleteLastEmploee();
			wcout << L"Удалено" << endl;
		}
		else if (h == L"show" && l->getN_Emploee() > 0)
		{
			l->show();
		}
		else if (h == L"show" && l->getN_Emploee() == 0)
		{
			wcout << L"Массив пуст" << endl;
		}
		else if (h == L"delname")
		{
			l->Del_Duplicate(cmpName);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delhomenum")
		{
			l->Del_Duplicate(cmpHomeNum);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delpostnum")
		{
			l->Del_Duplicate(cmpPostNum);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"deljob")
		{
			l->Del_Duplicate(cmpJob);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delseniority")
		{
			l->Del_Duplicate(cmpSeniority);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delwages")
		{
			l->Del_Duplicate(cmpWages);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"help")
		{
			wcout << L"add - добавление элемента" << endl
				<< L"deletelast - добавление элемента" << endl
				<< L"show - просмотр агрегирующего класса" << endl
				<< L"delname - удаление дубликатов по названиям" << endl
				<< L"delhomenum - удаление дубликатов по номеру дома" << endl
				<< L"delpostnum - удаление дубликатов по почтовому индексу" << endl
				<< L"deljob - удаление дубликатов по профессии" << endl
				<< L"delseniority - удаление дубликатов по стажу работу" << endl
				<< L"delwages - удаление дубликатов по зар.плате" << endl
				<< L"fill - заполнение массива рандомными данными" << endl
				<< L"sortname - сортировка по имени" << endl
				<< L"sorthomenum - сортировка по номеру дома" << endl
				<< L"sortpostnum - сортировка по почтовому индексу" << endl
				<< L"sortjob - сортировка по профессии" << endl
				<< L"sortseniority - сортировка по стажу работы" << endl
				<< L"sortwages - сортировка по зар.плате" << endl
				<< L"readfromfile - чтение из файла" << endl
				<< L"inputinfile - запись в файл" << endl
				<< L"stop - выход" << endl;
		}
		else if (h == L"fill")
		{
			wcout << L"Введите количество элем в массиве:";
			wcin >> x;
			l->RANDOM_Fill(x);
			wcout << L"Массив заполнен" << endl;
			wcin.get();
		}
		else if (h == L"sortname")
		{
			l->sorting(cmpName);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sorthomenum")
		{
			l->sorting(cmpHomeNum);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortpostnum")
		{
			l->sorting(cmpPostNum);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortjob")
		{
			l->sorting(cmpJob);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortseniority")
		{
			l->sorting(cmpSeniority);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortwages")
		{
			l->sorting(cmpWages);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"readfromfile")
		{
			l->readfromfile();
			wcout << L"Чтение завершено" << endl;
		}
		else if (h == L"inputinfile")
		{
			l->inputinfile();
			wcout << L"Записано" << endl;
		}
		else if (h == L"stop") {}
		else { wcout << L"Ошибка" << endl; }
	}
}