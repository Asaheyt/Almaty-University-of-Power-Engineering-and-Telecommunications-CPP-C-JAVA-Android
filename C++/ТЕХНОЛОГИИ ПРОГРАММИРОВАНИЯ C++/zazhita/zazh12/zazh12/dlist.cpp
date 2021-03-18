#include "stdafx.h"
#include "dlist.h"
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
wchar_t* names[Const] = { L"Мухтар",L"Рекс",L"Вег",L"Нордон",L"Дружок",L"Степа",L"Саша",L"Черный",L"Куро",L"Нойер" };
wchar_t* types[Const] = { L"Пастушьи",L"Терьер",L"Такса",L"Лайка",L"Гончий",L"Чихуаахуа",L"Дворняга",L"Легавые",L"Лабрадор",L"Алабай" };
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
Dog::Dog() {}
Dog::Dog(wchar_t* n, int a, wchar_t* t)
{
	wcscpy_s(name, n);
	age = a;
	wcscpy_s(type, t);
}
Dog::~Dog() {}
void Dog::setName(wchar_t*j)
{
	wcscpy_s(name, j);
}
void Dog::setType(wchar_t*j)
{
	wcscpy_s(type, j);
}
void Dog::setAge(int a)
{
	age=a;
}
int Dog::getAge()const
{
	return age;
}
const wchar_t* Dog::getName()
{
	return name;
}
const wchar_t* Dog::getType()
{
	return type;
}
void Dog::show()
{
	wcout << L" Кличка: " << name << L"  Возраст: " << age << L"  Порода: " << type << L" ";
}
void Dog::input()
{
	wcout << L"Кличка: ";
	bool OK = false;
	while (!OK)
	{
		wcin.getline(name, maxN);
		for (int j = 0;j<wcslen(name); j++)
		{
			if ((name[j] >= L'A' && name[j] <= L'Z') || (name[j] >= L'a' && name[j] <= L'z') || (name[j] >= L'А' && name[j] <= L'Я') || (name[j] >= L'а' && name[j] <= L'я') || (j != 0 && name[j] == L' '))
			{
				OK = true;
			}
			else { OK = false;break; }
		}
		if (OK == false) { wcout << L"Ошибка! Введите кличку: " << endl; }
	}
	wcout << L"Возраст: ";
	while (!(cin >> age) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"Ошибка!Введите возраст: " << endl;
	}
	wcout << L"Порода: ";
	OK = false;
	while (!OK)
	{
		wcin.getline(type, maxN);
		for (int j = 0;j<wcslen(type); j++)
		{
			if ((type[j] >= L'A' && type[j] <= L'Z') || (type[j] >= L'a' && type[j] <= L'z') || (type[j] >= L'А' && type[j] <= L'Я') || (type[j] >= L'а' && type[j] <= L'я') || (j != 0 && type[j] == L' '))
			{
				OK = true;
			}
			else { OK = false;break; }
		}
		if (OK == false) { wcout << L"Ошибка! Введите породу: " << endl; }
	}
	cin.ignore();
}
int cmpName(Dog& e1, Dog& e2)
{
	int t;
	if (wcscmp(e1.getName(), e2.getName()) == -1) { t = 1; }
	if (wcscmp(e1.getName(), e2.getName()) == 1) { t = -1; }
	if (wcscmp(e1.getName(), e2.getName()) == 0) { t = 0; }
	return t;
}
int cmpAge(Dog& e1, Dog& e2)
{
	int t;
	if (e1.getAge()<e2.getAge()) { t = 1; }
	if (e1.getAge()>e2.getAge()) { t = -1; }
	if (e1.getAge() == e2.getAge()) { t = 0; }
	return t;
}
int cmpType(Dog& e1, Dog& e2)
{
	int t;
	if (wcscmp(e1.getType(), e2.getType()) == -1) { t = 1; }
	if (wcscmp(e1.getType(), e2.getType()) == 1) { t = -1; }
	if (wcscmp(e1.getType(), e2.getType()) == 0) { t = 0; }
	return t;
}
//--------------------------------------------------------------------//
List::List()
{
	N_Emploee = 0;
	begin = end = NULL;
}
List::~List() {}
int List::getN_Emploee()
{
	return N_Emploee;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void List::show()
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
void List::push_back(const Dog& e)
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


}void List::push_front(const Dog& e)
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
Dog List::pop_back()
{
	if (begin != NULL)
	{
		Node *a, *b;
		a = end;
		b = end->prev;
		Dog e;
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
Dog List::pop_front()
{
	if (begin != NULL)
	{
		Node *a, *b;
		a = begin;
		b = begin->next;
		Dog e;
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
void List::sorting(int(*cmp)(Dog&, Dog&))
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
			if (cmp(a->data, b->data) < 0)
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
void List::RANDOM_Fill(int k)
{
	Dog e;
	N_Emploee = k;
	for (int i = 0;i<k;i++)
	{
		e.setName(names[rand() % Const]);
		e.setType(types[rand() % Const]);
		e.setAge(rand() % 20);
		this->push_back(e);
	}
}
void List::clean_list()
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
int List::b = 0;
void List::inputinfile()
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
		fout.write((char *)&e->data, sizeof(Dog));
		e = e->next;
	}
	fout.close();
	wcin.get();
}
void List::readfromfile()
{
	this->clean_list();
	system("DIR \*.fbd");
	wstring g;
	wcout << L"Введите имя файла:";
	wcin >> g;
	ifstream fin(g, wios::binary);
	Dog e;
	while (!fin.eof())
	{
		fin.read((char *)&e, sizeof(Dog));
		this->push_back(e);
	}
	fin.close();
	wcin.get();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void List::Sortname(binary_func k)
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
			if (k((wchar_t*)a->data.getName(), (wchar_t*)b->data.getName()) == k.type)
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
void List::Sortage(binary_func k)
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
			if (k(a->data.getAge(), b->data.getAge()) == k.type)
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
void List::Sorttype(binary_func k)
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
			if (k((wchar_t*)a->data.getType(), (wchar_t*)b->data.getType()) == k.type)
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
void Node::setData(const Dog &e)
{
	data = e;
}
void Node::setNext(Node *n)
{
	next = n;
}
Dog Node::getData()
{
	return data;
}
Node* Node::getNext()
{
	return next;
}
//------------------------------------------------------------------------------
