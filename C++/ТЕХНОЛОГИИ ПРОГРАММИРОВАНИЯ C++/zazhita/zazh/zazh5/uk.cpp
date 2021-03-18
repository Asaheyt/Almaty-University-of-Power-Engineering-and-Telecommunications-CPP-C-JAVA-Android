#include <iostream>
#include <string>
#include "uk.h"
using namespace std;
Data::Data(){}
Data::Data(int d, int m, int y)
{
    day=d;
    month=m;
    year=y;
}
Data::~Data(){}
void Data::setDay(int d)
{
    day=d;
}
void Data::setMonth(int m)
{
    month=m;
}
void Data::setYear(int y)
{
    year=y;
}
int Data::getDay()
{
    return day;
}
int Data::getMonth()
{
    return month;
}
int Data::getYear()
{
    return year;
}
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
int Liver::getHomeNum()const
{
	return homeNum;
}
string Liver::getName()const
{
	return name;
}
int Liver::getPostNum()const
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
int cmpName(Emploee& l1, Emploee& l2)
{
    int t;
    if(l1.getName()<l2.getName()){t=1;}
    if(l1.getName()>l2.getName()){t=-1;}
    if(l1.getName()==l2.getName()){t=0;}
    return t;
}
int cmpHomeNum(Emploee& l1, Emploee& l2)
{
    int t;
    if(l1.getHomeNum()<l2.getHomeNum()){t=1;}
    if(l1.getHomeNum()>l2.getHomeNum()){t=-1;}
    if(l1.getHomeNum()==l2.getHomeNum()){t=0;}
    return t;
}
int cmpPostNum(Emploee& l1, Emploee& l2)
{
    int t;
    if(l1.getPostNum()<l2.getPostNum()){t=1;}
    if(l1.getPostNum()>l2.getPostNum()){t=-1;}
    if(l1.getPostNum()==l2.getPostNum()){t=0;}
    return t;
}
//--------------------------------------------------------------------------------------------------------
Emploee::Emploee() {}
Emploee::Emploee(string n, int h, int p, string j, int w, float s, Data d) :Liver(n, h, p)
{
	job = j;
	wages = w;
	seniority = s;
	beginW.setDay(d.getDay());
    beginW.setMonth(d.getMonth());
    beginW.setYear(d.getYear());
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
int Emploee::getWages()const
{
	return wages;
}
string Emploee::getJob()const
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
	cout << "Профессия: " << job << "  Заработная плата: " << wages << "  Стаж работы: " << seniority << " Дата начала работы: "<<beginW.getDay()<<"."<<beginW.getMonth()<<"."<<beginW.getYear()<<" ";
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
	cout<<"Дата начала работы: "<<endl;
	int a;
	cout<<"   День: "<<endl;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "   Ошибка!Введите день: " << endl;
	}
	beginW.setDay(a);
	cout<<"   Месяц: "<<endl;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "   Ошибка!Введите месяц: " << endl;
	}
	beginW.setMonth(a);
	cout<<"   Год: "<<endl;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "   Ошибка!Введите год: " << endl;
	}
	beginW.setYear(a);
	cin.ignore();
}
int cmpJob(Emploee& e1, Emploee& e2)
{
    int t;
    if(e1.getJob()<e2.getJob()){t=1;}
    if(e1.getJob()>e2.getJob()){t=-1;}
    if(e1.getJob()==e2.getJob()){t=0;}
    return t;
}
int cmpWages(Emploee& e1, Emploee& e2)
{
    int t;
    if(e1.getWages()<e2.getWages()){t=1;}
    if(e1.getWages()>e2.getWages()){t=-1;}
    if(e1.getWages()==e2.getWages()){t=0;}
    return t;
}
int cmpSeniority(Emploee& e1, Emploee& e2)
{
    int t;
    if(e1.getSeniority()<e2.getSeniority()){t=1;}
    if(e1.getSeniority()>e2.getSeniority()){t=-1;}
    if(e1.getSeniority()==e2.getSeniority()){t=0;}
    return t;
}
int cmpBeginW(Emploee& e1, Emploee& e2)
{
    int t;
    Data a,b;
    a=e1.getData();
    b=e2.getData();
    if(a.getYear()<b.getYear()){t=1;}
    if(a.getYear()>b.getYear()){t=-1;}
    if(a.getYear()==b.getYear())
    {
        if(a.getMonth()<b.getMonth()){t=1;}
        if(a.getMonth()>b.getMonth()){t=-1;}
        if(a.getMonth()==b.getMonth())
        {
            if(a.getDay()<b.getDay()){t=1;}
            if(a.getDay()>b.getDay()){t=-1;}
            if(a.getDay()==b.getDay()){t=0;}
        }
    }
    return t;
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
Organization::~Organization()
{
    delete [] p;
}
void Organization::setName(string n)
{
	name = n;
}
string Organization::getName()
{
	return name;
}
int Organization::getN_Emploee()
{
    return N_Emploee;
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
    try
    {
        if (N_Emploee >= maxN)
        {
            throw 123;
        }
        p[N_Emploee] = new Emploee;
		*p[N_Emploee] = e;
		N_Emploee++;
		//cout << "Добавлен новый элемент" << endl;
    }
    catch(int i)
    {
        cout << "Массив заполнен " << endl;
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
void Organization::sorting(int (*cmp)(Emploee&, Emploee&))
{
    for(int i=0;i<N_Emploee-1;i++)
    {
        for(int j=i+1;j<N_Emploee;j++)
        {
            if((cmp(*p[i],*p[j]))<0)
            {
                swap(*p[i],*p[j]);
            }
        }
    }
}
void Organization::addEmploeeIndex(const Emploee& e, int index)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(index==i)
        {
            int a = N_Emploee;
            p[a]=new Emploee;
            while(a > index)
            {
                *p[a] = *p[a-1];
                a--;
            }
            *p[index] = e;
        }
    }
    N_Emploee++;
}
