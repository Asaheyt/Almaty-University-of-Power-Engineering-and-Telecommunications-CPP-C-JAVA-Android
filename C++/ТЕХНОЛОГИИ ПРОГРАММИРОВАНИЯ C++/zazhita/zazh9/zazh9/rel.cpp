#include "stdafx.h"
#include <iostream>
#include <string>
#include "rel.h"
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;
const int Const = 10;
const wstring names[Const] = { L"Александр",L"Даулет",L"Даша",L"Хаджиме",L"Джакс",L"Соня",L"Абылай",L"Валерий",L"Ибрагим",L"Лена" };
const wstring jobs[Const] = { L"Инженер",L"Программист",L"Бухгалтер",L"Продавец",L"Менеджер",L"Риелтор",L"Водитель",L"Директор",L"Преподаватель",L"Кассир" };
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
//--------------------------------------------------------------------------------------------------------
int Liver::count = 0;
Liver::Liver()
{
	count++;
}
Liver::Liver(wstring n, int h, int p)
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
int Liver::getHomeNum()const
{
	return homeNum;
}
wstring Liver::getName()const
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
int cmpName(Emploee& l1, Emploee& l2)
{
	int t;
	if (l1.getName()<l2.getName()) { t = 1; }
	if (l1.getName()>l2.getName()) { t = -1; }
	if (l1.getName() == l2.getName()) { t = 0; }
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
//--------------------------------------------------------------------------------------------------------
Emploee::Emploee() {}
Emploee::Emploee(wstring n, int h, int p, wstring j, int w, float s, Data d) :Liver(n, h, p)
{
	job = j;
	wages = w;
	seniority = s;
	beginW.setDay(d.getDay());
	beginW.setMonth(d.getMonth());
	beginW.setYear(d.getYear());
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
int Emploee::getWages()const
{
	return wages;
}
wstring Emploee::getJob()const
{
	return job;
}
float Emploee::getSeniority()const
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
	if (e1.getJob()<e2.getJob()) { t = 1; }
	if (e1.getJob()>e2.getJob()) { t = -1; }
	if (e1.getJob() == e2.getJob()) { t = 0; }
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
Organization::~Organization(){}
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
//--------------------------------------------------------------------------------
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
			if ((cmp(*p[i], *p[j]))<0)
			{
				swap(*p[i], *p[j]);
			}
		}
	}
}
void Organization_Ukaz::addEmploeeIndex(const Emploee& e, int index)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (index == i)
		{
			int a = N_Emploee;
			p[a] = new Emploee;
			while (a > index)
			{
				*p[a] = *p[a - 1];
				a--;
			}
			*p[index] = e;
		}
	}
	N_Emploee++;
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
void Organization_Ukaz::Del_Wages(int a)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (p[i]->getWages() == a)
		{
			this->Move(i);
			i--;
		}
	}
}
void Organization_Ukaz::Del_Seniority(int a)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (p[i]->getSeniority() == a)
		{
			this->Move(i);
			i--;
		}
	}
}
void Organization_Ukaz::Del_Data(Data a)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (((p[i]->getData().getDay()) == a.getDay()) && ((p[i]->getData().getMonth()) == a.getMonth()) && ((p[i]->getData().getYear()) == a.getYear()))
		{
			this->Move(i);
			i--;
		}
	}
}
void Organization_Ukaz::Del_Job(wstring a)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (p[i]->getJob() == a)
		{
			this->Move(i);
			i--;
		}
	}
}
void Organization_Ukaz::Del_Name(wstring a)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (p[i]->getName() == a)
		{
			this->Move(i);
			i--;
		}
	}
}
void Organization_Ukaz::Del_HomeNum(int a)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (p[i]->getHomeNum() == a)
		{
			this->Move(i);
			i--;
		}
	}
}
void Organization_Ukaz::Del_PostNum(int a)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (p[i]->getPostNum() == a)
		{
			this->Move(i);
			i--;
		}
	}
}
void Organization_Ukaz::RANDOM_Fill(int k)
{

	Emploee e;
	Data d;
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
			this->addEmploee(e);
		}
		else { i--; }
	}
}
Organization_Ukaz& Organization_Ukaz::operator=(const Organization_Ukaz& a)
{
	if (this == &a) { return *this; }
	else
	{
		this->setName(a.getName());
		N_Emploee = a.N_Emploee;
		for (int i = 0;i<N_Emploee;i++)
		{
			p[i] = new Emploee;
			*p[i] = *a.p[i];
		}
		return *this;
	}

}
//---------------------------------------------------------------------
//--------------------------------------------------------------------------------
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
void Organization_Mas::addEmploeeIndex(const Emploee& e, int index)
{
	for (int i = 0;i<N_Emploee;i++)
	{
		if (index == i)
		{
			int a = N_Emploee;
			while (a > index)
			{
				p[a] = p[a - 1];
				a--;
			}
			p[index] = e;
		}
	}
	N_Emploee++;
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
	Data d;
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
			this->addEmploee(e);
		}
		else { i--; }
	}
}
/*Organization_Mas& Organization_Mas::operator=(const Organization_Mas& a)
{
	if (this == &a) { return *this; }
	else
	{
		wstring n=a.getName();
		this->setName(n);
		N_Emploee = a.N_Emploee;
		for (int i = 0;i<N_Emploee;i++)
		{
			p[i] = a.p[i];
		}
		return *this;
	}

}*/
//---------------------------------------------------------------------
void cnslCmd(Organization* l)
{
	_wsetlocale(LC_CTYPE, L".866");
	Organization *z(l);
	bool A = false;
	Emploee k;
	wstring h;
	cmp a;
	int x;
	while (h != L"stop")
	{
		wcout << L"Для просмотра списка команд введите help.  Введите команду:";
		getline(wcin, h);
		if (h == L"add")
		{
			k.input();
			l->addEmploee(k);
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
			a = cmpName;
			l->Del_Duplicate(a);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delhomenum")
		{
			a = cmpHomeNum;
			l->Del_Duplicate(a);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delpostnum")
		{
			a = cmpPostNum;
			l->Del_Duplicate(a);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"deljob")
		{
			a = cmpJob;
			l->Del_Duplicate(a);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delseniority")
		{
			a = cmpSeniority;
			l->Del_Duplicate(a);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delwages")
		{
			a = cmpWages;
			l->Del_Duplicate(a);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"delbeginw")
		{
			a = cmpBeginW;
			l->Del_Duplicate(a);
			wcout << L"Удалено" << endl;
		}
		else if (h == L"help")
		{
			wcout << L"add - добавление элемента" << endl
				<< L"show - просмотр агрегирующего класса" << endl
				<< L"delname - удаление дубликатов по названиям" << endl
				<< L"delhomenum - удаление дубликатов по номеру дома" << endl
				<< L"delpostnum - удаление дубликатов по почтовому индексу" << endl
				<< L"deljob - удаление дубликатов по профессии" << endl
				<< L"delseniority - удаление дубликатов по стажу работу" << endl
				<< L"delwages - удаление дубликатов по зар.плате" << endl
				<< L"delbeginw - удаление дубликатов по дате начала работы" << endl
				<< L"fill - заполнение массива рандомными данными" << endl
				<< L"sortname - сортировка по имени" << endl
				<< L"sorthomenum - сортировка по номеру дома" << endl
				<< L"sortpostnum - сортировка по почтовому индексу" << endl
				<< L"sortjob - сортировка по профессии" << endl
				<< L"sortseniority - сортировка по стажу работы" << endl
				<< L"sortwages - сортировка по зар.плате" << endl
				<< L"sortbeginw - сортировка по дате начала рботы" << endl
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
			a = cmpName;
			l->sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sorthomenum")
		{
			a = cmpHomeNum;
			l->sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortpostnum")
		{
			a = cmpPostNum;
			l->sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortjob")
		{
			a = cmpJob;
			l->sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortseniority")
		{
			a = cmpSeniority;
			l->sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortwages")
		{
			a = cmpWages;
			l->sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"sortbeginw")
		{
			a = cmpBeginW;
			l->sorting(a);
			wcout << L"Отсортировано" << endl;
		}
		else if (h == L"stop") {}
		else { wcout << L"Ошибка" << endl; }
	}
}
//-----------------------------------------------------------------------------
Exception::Exception(const wstring l)
{
	str = l;
}
void Exception::show()
{
	wcout << str << endl;
}
