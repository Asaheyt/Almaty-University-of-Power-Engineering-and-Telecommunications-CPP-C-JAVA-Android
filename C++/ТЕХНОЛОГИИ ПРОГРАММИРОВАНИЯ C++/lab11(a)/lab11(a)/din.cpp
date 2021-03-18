#include "stdafx.h"
#include "din.h"
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
Data::Data() {}
Data::Data(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
Data::~Data() {}
void Data::setDay(int d)
{
	day = d;
}
void Data::setMonth(int m)
{
	month = m;
}
void Data::setYear(int y)
{
	year = y;
}
int Data::getDay()const
{
	return day;
}
int Data::getMonth()const
{
	return month;
}
int Data::getYear()const
{
	return year;
}
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
Emploee::Emploee(wchar_t* n, int h, int p, wchar_t* j, int w, int s, Data d) :Liver(n, h, p)
{
	wcscpy_s(job, j);
	wages = w;
	seniority = s;
	beginW.setDay(d.getDay());
	beginW.setMonth(d.getMonth());
	beginW.setYear(d.getYear());
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
void Emploee::setData(Data& d)
{
	beginW.setDay(d.getDay());
	beginW.setMonth(d.getMonth());
	beginW.setYear(d.getYear());
}
Data Emploee::getData()
{
	return beginW;
}
void Emploee::show()
{
	Liver::show();
	wcout << L" Профессия: " << job << L"  Заработная плата: " << wages << L"  Стаж работы: " << seniority << L"  Дата начала работы: " << beginW.getDay() << L"." << beginW.getMonth() << L"." << beginW.getYear() << L" ";
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
	wcout << L"Дата начала работы: " << endl;
	int a;
	wcout << L"   День: " << endl;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"   Ошибка!Введите день: " << endl;
	}
	beginW.setDay(a);
	wcout << L"   Месяц: " << endl;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"   Ошибка!Введите месяц: " << endl;
	}
	beginW.setMonth(a);
	wcout << L"   Год: " << endl;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		wcout << L"   Ошибка!Введите год: " << endl;
	}
	beginW.setYear(a);
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
int cmpBeginW(Emploee& e1, Emploee& e2)
{
	int t;
	Data a, b;
	a = e1.getData();
	b = e2.getData();
	if (a.getYear()<b.getYear()) { t = 1; }
	if (a.getYear()>b.getYear()) { t = -1; }
	if (a.getYear() == b.getYear())
	{
		if (a.getMonth()<b.getMonth()) { t = 1; }
		if (a.getMonth()>b.getMonth()) { t = -1; }
		if (a.getMonth() == b.getMonth())
		{
			if (a.getDay()<b.getDay()) { t = 1; }
			if (a.getDay()>b.getDay()) { t = -1; }
			if (a.getDay() == b.getDay()) { t = 0; }
		}
	}
	return t;
}
//--------------------------------------------------------------------//
Organization::Organization()
{
	N_Emploee = 0;
	p = NULL;
}
Organization::Organization(const Organization& a)
{
	*this = a;
}
Organization::Organization(wstring n)
{
	name = n;
	N_Emploee = 0;
	p = NULL;
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
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Organization::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i].show();
		wcout << endl;
	}
}
void Organization::push_back(const Emploee& e)
{
	Emploee *temp = new Emploee[N_Emploee + 1];
	copy(p, p + N_Emploee, stdext::make_unchecked_array_iterator(temp));
	delete []p;
	p = new Emploee[N_Emploee + 1];
	copy(temp, temp + N_Emploee, stdext::make_unchecked_array_iterator(p));
	p[N_Emploee] = e;
	N_Emploee++;
	delete []temp;
	//cout << "Добавлен новый элемент" << endl;
}
Emploee Organization::pop_back()
{
	if (N_Emploee>0)
	{
		Emploee *temp = new Emploee[N_Emploee];
		copy(p, p + N_Emploee-1, stdext::make_unchecked_array_iterator(temp));
		Emploee e;
		e = p[N_Emploee - 1];
		delete []p;
		p = new Emploee[N_Emploee];
		copy(temp, temp + N_Emploee-1, stdext::make_unchecked_array_iterator(p));
		N_Emploee--;
		delete []temp;
		return e;
	}
	else { wcout << L"Массив пуст." << endl; }
}
void Organization::sorting(int(*cmp)(Emploee&, Emploee&))
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
void Organization::Insert_Index(const Emploee& e, int index)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (index == i)
		{
			Emploee *temp = new Emploee[N_Emploee + 1];
			copy(p, p + N_Emploee, stdext::make_unchecked_array_iterator(temp));
			delete []p;
			p = new Emploee[N_Emploee + 1];
			copy(temp, temp + N_Emploee, stdext::make_unchecked_array_iterator(p));
			int a = N_Emploee;
			while (a > index)
			{
				p[a] = p[a - 1];
				a--;
			}
			p[index] = e;
			N_Emploee++;
			delete []temp;
			break;
		}
	}
}
void Organization::Insert_M_Index(const Emploee& e, int index, int m)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (index == i)
		{
			Emploee *temp = new Emploee[N_Emploee + m];
			copy(p, p + N_Emploee, stdext::make_unchecked_array_iterator(temp));
			delete []p;
			p = new Emploee[N_Emploee + m];
			copy(temp, temp + N_Emploee, stdext::make_unchecked_array_iterator(p));
			int a = N_Emploee+m-1;
			while (a > index+m-1)
			{
				p[a] = p[a - m];
				a--;
			}
			for (int j = index;j <= index + m-1;j++)
			{
				p[j] = e;
				N_Emploee++;
			}
			delete []temp;
			break;
		}
	}
}
void Organization::RANDOM_Fill(int k)
{
	Emploee e;
	Data d;
	p = new Emploee[k];
	N_Emploee = k;
	for (int i = 0;i<k;i++)
	{
		e.setName(names[rand() % Const]);
		e.setHomeNum(rand() % 10);
		e.setPostNum(rand() % 70000);
		e.setJob(jobs[rand() % Const]);
		e.setWages(rand() % 1000000);
		e.setSeniority(rand() % 10);
		d.setDay(rand() % 31);
		d.setMonth(rand() % 13);
		d.setYear(2000 + rand() % 17);
		e.setData(d);
		if (d.getYear() == 2016 - e.getSeniority())
		{
			p[i] = e;;
		}
		else { i--; }
	}
}
Organization& Organization::operator=(const Organization& a)
{
	if (this == &a) { return *this; }
	else
	{
		this->setName(a.getName());
		int k = a.N_Emploee;
		for (int i = 0;i<k;i++)
		{
			this->push_back(a.p[i]);
		}
		return *this;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void cnslCmd(Organization& l)
{
	Emploee k;
	wstring h, im;
	cmp a;
	int x, y;
	wcout << L"Введите имя организации:";
	getline(wcin, im);
	l.setName(im);
	while (h != L"stop")
	{
		wcout << L"Для просмотра списка команд введите help. Введите команду:";
		getline(wcin, h);
		if (h == L"add")
		{
			k.input();
			l.push_back(k);
		}
		else if (h == L"show" && l.getN_Emploee() > 0)
		{
			l.show();
		}
		else if (h == L"show" && l.getN_Emploee() == 0)
		{
			wcout << L"Массив пуст" << endl;
		}
		else if (h == L"help")
		{
			wcout << L"add - добавление элемента" << endl
				<< L"show - просмотр агрегирующего класса" << endl
				<< L"fill - заполнение массива рандомными данными" << endl
				<< L"sortname - сортировка по имени" << endl
				<< L"sorthomenum - сортировка по номеру дома" << endl
				<< L"sortpostnum - сортировка по почтовому индексу" << endl
				<< L"sortjob - сортировка по профессии" << endl
				<< L"sortseniority - сортировка по стажу работы" << endl
				<< L"sortwages - сортировка по зар.плате" << endl
				<< L"sortbeginw - сортировка по дате начала рботы" << endl
				<< L"readfromfile - чтение из файла" << endl
				<< L"inputinfile - запись в файл" << endl
				<< L"insertindex - вставка по индексу одного элемента" << endl
				<< L"insert_m_index - вставка по индексу m элементов" << endl
				<< L"stop - выход" << endl;
		}
		else if(h == L"insertindex")
		{
			wcout << L"Введите индекс:";
			wcin >> x;
			wcin.get();
			wcout << L"Введите данные элемента:" << endl;
			k.input();
			l.Insert_Index(k, x);
			wcout << L"Данные внесены под индексом " << x << endl;
		}
		else if (h == L"insert_m_index")
		{
			wcout << L"Введите индекс:";
			wcin >> x;
			wcout << L"Введите количество:";
			wcin >> y;
			wcin.get();
			wcout << L"Введите данные элемента:" << endl;
			k.input();
			l.Insert_M_Index(k, x, y);
			wcout << L"Данные внесены под индексом " << x << L", Количество " << y << endl;
		}
		else if (h == L"fill")
		{
			wcout << L"Введите количество элем в массиве:";
			wcin >> x;
			l.RANDOM_Fill(x);
			wcout << L"Массив заполнен" << endl;
			wcin.get();
		}
		else if (h == L"sortname")
		{
			a = cmpName;
			l.sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sorthomenum")
		{
			a = cmpHomeNum;
			l.sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortpostnum")
		{
			a = cmpPostNum;
			l.sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortjob")
		{
			a = cmpJob;
			l.sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortseniority")
		{
			a = cmpSeniority;
			l.sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortwages")
		{
			a = cmpWages;
			l.sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortbeginw")
		{
			a = cmpBeginW;
			l.sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"readfromfile")
		{
			l.readfromfile();
			wcout << L"Чтение завершено" << endl;
		}
		else if (h == L"inputinfile")
		{
			l.inputinfile();
			wcout << L"Записано" << endl;
		}
		else if (h == L"stop") {}
		else { wcout << L"Ошибка" << endl; }
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
	fout.write((char *)p, sizeof(Emploee)*N_Emploee);
	fout.close();
	wcin.get();
}
void Organization::readfromfile()
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
