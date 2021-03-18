#include <iostream>
#include <string>
#include "dub.h"
#include <cstdlib>
#include <time.h>
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
	cout << "Имя: " << name << "\tНомер дома: " << homeNum << "\tПочтовый индекс: " << postNum << "  ";
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
	cout << " Профессия: " << job << "\tЗаработная плата: " << wages << "\tСтаж работы: " << seniority << "\tДата начала работы: "<<beginW.getDay()<<"."<<beginW.getMonth()<<"."<<beginW.getYear()<<" ";
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
Organization::Organization(const Organization& a)
{
    *this=a;
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
void Organization::Del_Duplicate(int (*cmp)(Emploee&, Emploee&))
{
    for(int i=0;i<N_Emploee-1;i++)
    {
        for(int j=i+1;j<N_Emploee;j++)
        {
            if((cmp(*p[i],*p[j]))==0)
            {
                Move(*this,j);
                j--;
            }
        }
    }
}
void Move(Organization& a, int k)
{
    for(int i=k;i<a.N_Emploee-1;i++)
    {
        *a.p[i]=*a.p[i+1];
    }
    a.deleteLastEmploee();
}
void Organization::Del_Wages(int a)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(p[i]->getWages()==a)
        {
            Move(*this,i);
            i--;
        }
    }
}
void Organization::Del_Seniority(int a)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(p[i]->getSeniority()==a)
        {
            Move(*this,i);
            i--;
        }
    }
}
void Organization::Del_Data(Data a)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(((p[i]->getData().getDay())==a.getDay())&&((p[i]->getData().getMonth())==a.getMonth())&&((p[i]->getData().getYear())==a.getYear()))
        {
            Move(*this,i);
            i--;
        }
    }
}
void Organization::Del_Job(string a)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(p[i]->getJob()==a)
        {
            Move(*this,i);
            i--;
        }
    }
}
void Organization::Del_Name(string a)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(p[i]->getName()==a)
        {
            Move(*this,i);
            i--;
        }
    }
}
void Organization::Del_HomeNum(int a)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(p[i]->getHomeNum()==a)
        {
            Move(*this,i);
            i--;
        }
    }
}
void Organization::Del_PostNum(int a)
{
    for(int i=0;i<N_Emploee;i++)
    {
        if(p[i]->getPostNum()==a)
        {
            Move(*this,i);
            i--;
        }
    }
}
//----------------------------------------------------------------------------------
const int Const = 10;
const string names[Const] = {"Александр","Даулет","Даша","Хаджиме","Джакс","Соня","Абылай","Валерий","Ибрагим","Лена"};
const string jobs[Const] = {"Инженер","Программист","Бухгалтер","Продавец","Менеджер","Риелтор","Водитель","Директор","Преподаватель","Кассир"};
void RANDOM(Organization& a, int k)
{

    Emploee e;
    Data d;
    for(int i=0;i<k;i++)
    {
        e.setName(names[rand()%Const]);
        e.setHomeNum(rand()%10);
        e.setPostNum(rand()%70000);
        e.setJob(jobs[rand()%Const]);
        e.setWages(rand()%1000000);
        e.setSeniority(rand()%10);
        d.setDay(rand()%31);
        d.setMonth(rand()%13);
        d.setYear(2000+rand()%17);
        e.setData(d);
        if(d.getYear()==2016-e.getSeniority())
        {a.addEmploee(e);}
        else{i--;}
    }
}
//----------------------------------------------------------------------------------
void sum(const Organization& a, const Organization& b, Organization& c)
{
    if(a.N_Emploee+b.N_Emploee+c.N_Emploee>=maxN)
    {
        cout<<"Слишком много элементов"<<endl;
    }
    else
    {
        for(int i=0;i<a.N_Emploee;i++)
        {
            c.addEmploee(*a.p[i]);
        }
        for(int i=0;i<b.N_Emploee;i++)
        {
            c.addEmploee(*b.p[i]);
        }
    }
}
Organization operator+(const Organization& a, const Organization& b)
{
    Organization c;
    if(a.N_Emploee+b.N_Emploee>=maxN)
    {
        cout<<"Слишком много элементов"<<endl;
    }
    else
    {
        for(int i=0;i<a.N_Emploee;i++)
        {
            c.addEmploee(*a.p[i]);
        }
        for(int i=0;i<b.N_Emploee;i++)
        {
            c.addEmploee(*b.p[i]);
        }
    }
    return c;
}
Organization& Organization::operator=(const Organization& a)
{
    if(this==&a){return *this;}
    else
    {
        name=a.name;
        N_Emploee=a.N_Emploee;
        for(int i=0;i<N_Emploee;i++)
        {
            p[i]=new Emploee;
            *p[i]=*a.p[i];
        }
        return *this;
    }

}
ostream& operator<<(ostream& os, const Organization& a)
{
    os<<"Организация: "<<a.name<<endl;
    for (int i = 0;i < a.N_Emploee;i++)
	{
		a.p[i]->show();
		os << endl;
	}
	return os;
}
