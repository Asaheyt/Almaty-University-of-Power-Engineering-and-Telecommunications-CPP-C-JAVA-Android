#pragma once
#include "stdafx.h"
#include <iostream>
#include <iterator>
using namespace std;
#define maxN 100
class Exception
{
private:
	wstring str;
public:
	Exception(const wstring);
	void show();
};
//-------------------------------------------------------------------------------
class Liver
{
private:
	wchar_t name[maxN];
	int homeNum;
	int postNum;
	static int count;
	friend class Organization;
public:
	Liver();
	Liver(wchar_t*, int, int);
	~Liver();
	void setName(wchar_t*);
	void setHomeNum(int);
	void setPostNum(int);
	int getHomeNum()const;
	const wchar_t* getName();
	int getPostNum()const;
	void show();
	void input();
};
//-------------------------------------------------------------------------------
class  Emploee : public Liver
{
private:
	wchar_t job[maxN];
	int wages;
	int seniority;
public:
	Emploee();
	Emploee(wchar_t*, int, int, wchar_t*, int, int);
	~Emploee();
	void setJob(wchar_t*);
	void setWages(int);
	void setSeniority(int);
	int getWages()const;
	const wchar_t* getJob();
	int getSeniority()const;
	void show();
	void input();
	void RANDOM();
};
int cmpJob(Emploee&, Emploee&);
int cmpWages(Emploee&, Emploee&);
int cmpSeniority(Emploee&, Emploee&);
int cmpName(Emploee&, Emploee&);
int cmpHomeNum(Emploee&, Emploee&);
int cmpPostNum(Emploee&, Emploee&);
//-------------------------------------------------------------------------------
class Func
{
private:
	bool type;
	int g;
public:
	Func(bool);
	Func(int);
	Func(int, bool);
	Func();
	Func operator()(int);
	Func operator()(bool);
	bool compare(Emploee &, Emploee &);
	bool operator()(wchar_t *, wchar_t *);
	bool operator()(int, int);
	bool operator()(Emploee &, Emploee &);
	bool Gettype();
};
//-------------------------------------------------------------------------------
template <class T>
class OrganizationMyVect
{
private:
	T *p;
	int numT;
	int k;
public:
	OrganizationMyVect()
	{
		numT = 0;
		p = NULL;
		k = 0;
	}
	void delfile()
	{
		this->pop_back();
		this->save_file();
	}
	void push_back(T x)
	{
		try {
			if (numT >= maxN)
			{
				throw Exception(L"Массив переполнен");
			}
			T *t = new T[numT+1];
			copy(p, p + numT, stdext::make_unchecked_array_iterator(t));
			t[numT] = x;
			delete[] p;
			p = t;
			numT++;
		}
		catch (Exception tur)
		{
			tur.show();
		}
	}
	void Del_name(wchar_t *r)
	{
		for (int i = 0; i < numT; i++)
		{
			if ((wcscmp(p[i].getName(), r)) == 0)
			{
				this->MoveMyVect(*this, i);
				i--;
			}
		}
	}
	void pop_back()
	{
		if (numT > 0)
		{
			T *t = new T[numT];
			copy(p, p + numT - 1, stdext::make_unchecked_array_iterator(t));
			delete[] p;
			p = t;
			numT--;
		}
	}
	void MoveMyVect(int v)
	{
		{
			for (int i = v; i < numT - 1; i++)
			{
				p[i] = p[i + 1];
			}
			this->pop_back();
		}
	}
	void list_shops()
	{
		if (numT < maxN)
		{
			for (int i = 0; i < numT; i++)
			{
				p[i].show();
				wcout << endl;
			}
		}
		else { wcout << L"Ошибка" << endl; }

	}
	void read_file()
	{
		setlocale(LC_CTYPE, ".1251");
		system("DIR \*.fbd");
		char g[50];
		int h;
		T x;
		cout << "Введите имя файла:";
		cin >> g;
		ifstream fin(g, ios::binary);
		fin.seekg(0, ios::end);
		int k;
		k = fin.tellg();
		fin.seekg(0, ios::beg);
		h = k / sizeof(T);
		nshops = 0;
		for (int i = 0; i < h; i++)
		{
			fin.read((char *)&x, sizeof(T));
			this->push_back(x);
		}
	}
	void find_name(wchar_t *r)
	{
		T *x;
		x = NULL;
		for (int i = 0; i < numT; i++)
		{
			if (wcscmp(r, p[i].getname()) == 0)
			{
				x = &p[i];
				x->show();
				wcout << endl;
			}
		}
	}
	void save_file()
	{
		setlocale(LC_CTYPE, ".1251");
		char g[50];
		char v[10] = "";
		char u[50] = { 0 };
		int temp = 0;
		cout << "Введите имя файла:";
		cin >> g;
		if (_access(g, 0) == 0)
		{
			k++;
			for (int i = 0; i < strlen(g); i++)
			{

				if (g[i] != '.') {
					u[temp] = g[i];
					temp++;
				}
				if (g[i] == '.')
				{
					_itoa_s(k, v, 10);
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
		k.write((char *)p, sizeof(T)*numT);
		k.close();
	}
	void addfromfile(T x)
	{
		system("DIR \*.fbd");
		char g[50];
		int h;
		T x;
		cout << "Введите имя файла:";
		cin >> g;
		ifstream fin(g, ios::binary);
		fin.read((char*)&x, sizeof(T));
		this->push_back(x);
	}
	void Sort(Func x)
	{
		for (int i = 0; i<numT - 1; i++)
		{
			for (int j = i + 1; j<numT; j++)
			{
				if ((x(p[i], p[j])) == x.Gettype())
				{
					swap(p[i], p[j]);
				}
			}
		}
	}
	void Del_Duplicate(int(*cmp)(T &, T &))
	{
		for (int i = 0; i<numT - 1; i++)
		{
			for (int j = i + 1; j<numT; j++)
			{
				if ((cmp(p[i], p[j])) == 0)
				{
					this->MoveMyVect(j);
					j--;
				}
			}
		}
	}
};
