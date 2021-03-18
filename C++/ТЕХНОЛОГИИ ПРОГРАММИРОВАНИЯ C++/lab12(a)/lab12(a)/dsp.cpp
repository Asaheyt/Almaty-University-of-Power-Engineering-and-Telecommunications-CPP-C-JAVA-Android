#include "stdafx.h"
#include "dsp.h"
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
//--------------------------------------------------------------------//
Organization::Organization()
{
	N_Emploee = 0;
	begin = end = NULL;
}
Organization::~Organization() {}
int Organization::getN_Emploee()
{
	return N_Emploee;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Organization::show()
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
void Organization::push_back(const Emploee& e)
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
	
	
}void Organization::push_front(const Emploee& e)
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
Emploee Organization::pop_back()
{
	if (begin!=NULL)
	{
		Node *a, *b;
		a = end;
		b = end->prev;
		Emploee e;
		e = a->data;
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
		return e;
	}
	else 
	{ 
		wcout << L"Список пуст." << endl;
	}
}
Emploee Organization::pop_front()
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
			end=begin;
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
void Organization::sorting(int(*cmp)(Emploee&, Emploee&))
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
			if (cmp(a->data, b->data) > 0)
			{
				if (a == begin)
				{
					tmp = b->next;
					b->next=a;
					a->next=tmp;
					begin = b;
					c = b;
				}
				else
				{
					tmp = b->next;
					b->next=a;
					a->next=tmp;
					c->next=b;
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
void Organization::RANDOM_Fill(int k)
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
		this->push_back(e);
	}
}
void Organization::clean_list()
{
	while (begin != NULL)
	{
		this->pop_front();
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
Exception::Exception(const wstring l)
{
	str = l;
}
void Exception::show()
{
	wcout << str << endl;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
int Organization::b = 0;
void Organization::inputinfile()
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
void Organization::readfromfile()
{
	this->clean_list();
	system("DIR \*.fbd");
	wstring g;
	wcout << L"Введите имя файла:";
	wcin >> g;
	ifstream fin(g, wios::binary);
	Emploee e;
	while (!fin.eof())
	{
		fin.read((char *)&e, sizeof(Emploee));
		this->push_back(e);
	}
	fin.close();
	wcin.get();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Organization::Sortname(binary_func k)
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
			if (k((wchar_t*)a->data.getName(), (wchar_t*)b->data.getName()) ==k.type)
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
void Organization::Sorthomenum(binary_func k)
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
			if (k(a->data.getHomeNum(), b->data.getHomeNum()) == k.type)
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
void Organization::Sortpostnum(binary_func k)
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
			if (k(a->data.getPostNum(), b->data.getPostNum()) == k.type)
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
void Organization::Sortwages(binary_func k)
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
			if (k(a->data.getWages(), b->data.getWages()) == k.type)
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
void Organization::Sortseniority(binary_func k)
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
			if (k(a->data.getSeniority(), b->data.getSeniority()) == k.type)
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
void Organization::Sortjob(binary_func k)
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
			if (k((wchar_t*)a->data.getJob(), (wchar_t*)b->data.getJob()) == k.type)
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
bool binary_func::operator()(int x, int y)
{
	return (x > y);
}
binary_func binary_func::operator()(bool a)
{
	type = a;
	return *this;
}
binary_func::binary_func(bool a)
{
	type = a;
}
bool binary_func::operator()(wchar_t *x, wchar_t *y)
{
	int ind;
	bool A = false;
	int i = 0;
	if (wcscmp(x, y) == 0)
	{
		ind = 0;
	}
	else {
		while (x[i] == y[i])
		{
			i++;
		}
		if (x[i] > y[i])
		{
			A = true;
		}
		else if (x[i] < y[i])
		{
			A = false;
		}
	}
	return A;
}
binary_func::binary_func() {}
//------------------------------------------------------------------------------
void Node::setData(const Emploee &e)
{
	data = e;
}
void Node::setNext(Node *n)
{
	next = n;
}
Emploee Node::getData()
{
	return data;
}
Node* Node::getNext()
{
	return next;
}
//------------------------------------------------------------------------------
