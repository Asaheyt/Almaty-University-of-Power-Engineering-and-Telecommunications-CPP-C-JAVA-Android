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
	Emploee(wchar_t*, wchar_t*, int, int);
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
	Emploee operator[](int);
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
//-------------------------------------------------------------------------------
class binary_func
{
private:
	bool type;
public:
	friend void Sortname(Emploee *&, binary_func, int);
	friend void Sortwages(Emploee *&, binary_func, int);
	friend void Sortseniority(Emploee *&, binary_func, int);
	friend void Sortjob(Emploee *&, binary_func, int);
	bool operator()(int, int);
	bool operator()(wchar_t *, wchar_t *);
	binary_func(bool);
	binary_func operator()(bool);
	binary_func();
};
void insert(Emploee *&, int &, Emploee, int &, int, int);
void MoveS(Emploee *&, int &, int &, int);
void indinsert(Emploee *&, Emploee, int &, int &, int);
void push_back(Emploee *&, int &, int &, Emploee);
typedef int(*cmt)(Emploee &, Emploee &);
void Resize(Emploee *&, int, int &, int&);
size_t Capacity(size_t, int);
void Sortname(Emploee *&, binary_func, int);
void Showall(Emploee *&, int);
void fill(Emploee *&, int &, int &, int);
