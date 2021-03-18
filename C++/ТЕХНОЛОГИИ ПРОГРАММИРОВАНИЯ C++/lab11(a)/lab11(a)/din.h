#pragma once
#include "stdafx.h"
#include <iostream>
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
class Data
{
private:
	int day;
	int month;
	int year;
public:
	Data();
	Data(int, int, int);
	~Data();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
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
	Data beginW;
public:
	Emploee();
	Emploee(wchar_t*, int, int, wchar_t*, int, int, Data);
	~Emploee();
	void setJob(wchar_t*);
	void setWages(int);
	void setSeniority(int);
	void setData(Data&);
	Data getData();
	int getWages()const;
	const wchar_t* getJob();
	int getSeniority()const;
	void show();
	void input();
};
int cmpJob(Emploee&, Emploee&);
int cmpWages(Emploee&, Emploee&);
int cmpSeniority(Emploee&, Emploee&);
int cmpName(Emploee&, Emploee&);
int cmpHomeNum(Emploee&, Emploee&);
int cmpPostNum(Emploee&, Emploee&);
int cmpBeginW(Emploee&, Emploee&);
//-------------------------------------------------------------------------------
class Organization
{
private:
	Emploee *p;
	static int b;
	wstring name;
protected:
	int N_Emploee;
public:
	Organization();
	Organization(const Organization&);
	Organization(wstring);
	~Organization();
	void setName(wstring);
	wstring getName()const;
	int getN_Emploee();
	void show();
	void push_back(const Emploee&);
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void RANDOM_Fill(int);
	Emploee pop_back();
	void Insert_Index(const Emploee&, int);
	void Insert_M_Index(const Emploee&, int, int);
	Organization& operator=(const Organization&);
	void inputinfile();
	void readfromfile();
};
//-------------------------------------------------------------------------------
typedef int(*cmp)(Emploee&, Emploee&);
void cnslCmd(Organization&);