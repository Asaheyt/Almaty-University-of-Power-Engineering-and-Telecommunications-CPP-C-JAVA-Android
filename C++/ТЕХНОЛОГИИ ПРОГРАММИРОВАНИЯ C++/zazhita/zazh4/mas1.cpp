#include <iostream>
#include <string>
#include "mas1.h"
#include <windows.h>
using namespace std;
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
int Liver::getHomeNum()
{
	return homeNum;
}
string Liver::getName()
{
	return name;
}
int Liver::getPostNum()
{
	return postNum;
}
void Liver::show()
{
	cout << "Имя: " << name << "  Номер дома: " << homeNum << " " << "  Почтовый индекс: " << postNum << "  ";
}
void Liver::input()
{
	cout << "Введите данные: " << endl;
	cout << "Имя: ";
	bool OK = false;
	while (!OK)
	{
		cin >> name;
		for (int j = 0;j < name.length(); j++)
		{
			if ((name[j] >= 'A' && name[j] <= 'Z') || (name[j] >= 'a' && name[j] <= 'z') || (name[j] >= 'А' && name[j] <= 'Я') || (name[j] >= 'а' && name[j] <= 'я'))
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
}
//--------------------------------------------------------------------------------------------------------
Emploee::Emploee() {}
Emploee::Emploee(string n, int h, int p, string j, int w, float s) :Liver(n, h, p)
{
	job = j;
	wages = w;
	seniority = s;
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
int Emploee::getWages() const
{
	return wages;
}
string Emploee::getJob() const
{
	return job;
}
float Emploee::getSeniority() const
{
	return seniority;
}
void Emploee::show()
{
	Liver::show();
	cout << "Профессия: " << job << "  Заработная плата: " << wages << "  Стаж работы: " << seniority << "  ";
}
void Emploee::input()
{
	Liver::input();
	cout << "Профессия: ";
	bool OK = false;
	while (!OK)
	{
		cin >> job;
		for (int j = 0;j<job.length(); j++)
		{
			if ((job[j] >= 'A' && job[j] <= 'Z') || (job[j] >= 'a' && job[j] <= 'z') || (job[j] >= 'А' && job[j] <= 'Я') || (job[j] >= 'а' && job[j] <= 'я'))
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
}
int Emploee::cmpJob(const Emploee& e)
{
    int t;
    if(job<e.getJob()){t=1;}
    if(job>e.getJob()){t=-1;}
    if(job==e.getJob()){t=0;}
    return t;
}
int Emploee::cmpWages(const Emploee& e)
{
    int t;
    if(wages<e.getWages()){t=1;}
    if(wages>e.getWages()){t=-1;}
    if(wages==e.getWages()){t=0;}
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
Organization::~Organization() {}
void Organization::setName(string n)
{
	name = n;
}
string Organization::getName()
{
	return name;
}
void Organization::show()
{
	for (int i = 0;i < N_Emploee;i++)
	{
		p[i].show();
		cout << endl;
	}
}
void Organization::addEmploee(const Emploee& e)
{
	try
    {
        if (N_Emploee == maxN)
        {
            throw 123;
        }
        p[N_Emploee] = e;
        N_Emploee++;
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
	else { N_Emploee--; }
}
void Organization::SortByJob()
{
    for(int i=0;i<=N_Emploee-1;i++)
    {
        for(int j=i+1;j<N_Emploee;j++)
        {
            if(p[i].cmpJob(p[j])<0)
            {
                swap(p[i],p[j]);
            }
        }
    }
}
void Organization::SortByWages()
{
    for(int i=0;i<N_Emploee-1;i++)
    {
        for(int j=i;j<N_Emploee;j++)
        {
            if(p[i].cmpWages(p[j])<0)
            {
                swap(p[i],p[j]);
            }
        }
    }
}
void confluence(Organization& o1, const Organization& o2)
{
    if(o1.N_Emploee+o2.N_Emploee>=maxN)
    {
        cout<<"Слишком много элементов"<<endl;
    }
    else
    {
        for(int i=0;i<o2.N_Emploee;i++)
        {
            o1.addEmploee(o2.p[i]);
        }
    }
}
