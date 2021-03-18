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
	virtual void show() = 0;
	virtual void addEmploee(const Emploee&) = 0;
	virtual void sorting(int(*cmp)(Emploee&, Emploee&)) = 0;
	virtual void Del_Duplicate(int(*cmp)(Emploee&, Emploee&)) = 0;
	virtual void RANDOM_Fill(int) = 0;
	virtual void deleteLastEmploee() = 0;
	virtual void addEmploeeIndex(const Emploee&, int) = 0;
	virtual void Move(int) = 0;
	virtual void inputinfile() = 0;
	virtual void readfromfile() = 0;
};
//-------------------------------------------------------------------------------
class Organization_Ukaz :public Organization
{
private:
	Emploee *p[maxN];
	static int b;
public:
	void show();
	void addEmploee(const Emploee&);
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void Del_Duplicate(int(*cmp)(Emploee&, Emploee&));
	void RANDOM_Fill(int);
	void deleteLastEmploee();
	void addEmploeeIndex(const Emploee&, int);
	void Move(int);
	Organization_Ukaz& operator=(const Organization_Ukaz&);
	void inputinfile();
	void readfromfile();
};
//-------------------------------------------------------------------------------
class Organization_Mas :public Organization
{
private:
	Emploee p[maxN];
	static int a;
public:
	void show();
	void addEmploee(const Emploee&);
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void Del_Duplicate(int(*cmp)(Emploee&, Emploee&));
	void RANDOM_Fill(int);
	void deleteLastEmploee();
	void addEmploeeIndex(const Emploee&, int);
	void Move(int);
	Organization_Mas& operator=(const Organization_Mas&);
	void inputinfile();
	void readfromfile();
};
typedef int(*cmp)(Emploee&, Emploee&);
void cnslCmd(Organization*);
string WstrToStr(const wstring &);
wstring StrToWstr(const string &);