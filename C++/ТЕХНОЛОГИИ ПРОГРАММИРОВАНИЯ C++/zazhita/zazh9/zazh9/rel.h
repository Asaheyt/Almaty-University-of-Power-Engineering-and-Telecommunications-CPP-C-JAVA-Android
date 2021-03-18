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
//----------------------------------------------------------------------
class Liver
{
private:
	wstring name;
	int homeNum;
	int postNum;
	static int count;
	friend class Organization;
public:
	Liver();
	Liver(wstring, int, int);
	~Liver();
	void setName(wstring);
	void setHomeNum(int);
	void setPostNum(int);
	int getHomeNum()const;
	wstring getName()const;
	int getPostNum()const;
	void show();
	void input();
};
//-------------------------------------------------------------------------------
class  Emploee : public Liver
{
private:
	wstring job;
	int wages;
	float seniority;
	Data beginW;
public:
	Emploee();
	Emploee(wstring, int, int, wstring, int, float, Data);
	~Emploee();
	void setJob(wstring);
	void setWages(int);
	void setSeniority(float);
	void setData(Data&);
	Data getData();
	int getWages()const;
	wstring getJob()const;
	float getSeniority()const;
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
	virtual void deleteLastEmploee()=0;
	virtual void addEmploeeIndex(const Emploee&, int)=0;
	virtual void Move(int)=0;
};
//-------------------------------------------------------------------------------
class Organization_Ukaz :public Organization
{
private:
	Emploee *p[maxN];
public:
	void show();
	void addEmploee(const Emploee&);
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void Del_Duplicate(int(*cmp)(Emploee&, Emploee&));
	void RANDOM_Fill(int);
	void deleteLastEmploee();
	void addEmploeeIndex(const Emploee&, int);
	void Del_Wages(int);
	void Del_Seniority(int);
	void Del_Data(Data);
	void Del_Job(wstring);
	void Del_Name(wstring);
	void Del_HomeNum(int);
	void Del_PostNum(int);
	void Move(int);
	Organization_Ukaz& operator=(const Organization_Ukaz&);
};
//---------------------------------------------------------------------------
class Organization_Mas :public Organization
{
private:
	Emploee p[maxN];
public:
	void show();
	void addEmploee(const Emploee&);
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void Del_Duplicate(int(*cmp)(Emploee&, Emploee&));
	void RANDOM_Fill(int);
	void deleteLastEmploee();
	void addEmploeeIndex(const Emploee&, int);
	void Del_Wages(int);
	void Del_Seniority(int);
	void Del_Data(Data);
	void Del_Job(wstring);
	void Del_Name(wstring);
	void Del_HomeNum(int);
	void Del_PostNum(int);
	void Move(int);
	//Organization_Mas& operator=(const Organization_Mas&);
};
typedef int (*cmp)(Emploee&, Emploee&);
void cnslCmd(Organization*);
