#pragma once
#include "stdafx.h"
using namespace std;
#define maxN 100
//-------------------------------------------------------------------------------
class Liver
{
private:
	wstring name;
	int homeNum;
	int postNum;
public:
	Liver();
	Liver(wstring, int, int);
	~Liver();
	void setName(wstring);
	void setHomeNum(int);
	void setPostNum(int);
	int getHomeNum();
	wstring getName();
	int getPostNum();
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
public:
	Emploee();
	Emploee(wstring, int, int, wstring, int, float);
	~Emploee();
	void setJob(wstring);
	void setWages(int);
	void setSeniority(float);
	int getWages();
	wstring getJob();
	float getSeniority();
	void show();
	void input();
};
//-------------------------------------------------------------------------------
class Organization
{
private:
	wstring name;
protected:
	int N_Emploee;
public:
	Organization();
	Organization(wstring);
	~Organization();
	void setName(wstring);
	wstring getName();
	int getN_Emploee();
	virtual void show() = 0;
	virtual void addEmploee(const Emploee&) = 0;
	virtual void deleteLastEmploee() = 0;
	virtual Emploee* find_name(wstring) = 0;
};
//-----------------------------------------------------------------
class Organization_A : public Organization
{
private:
	Emploee *p[maxN];
public:
	void show();
	void addEmploee(const Emploee&);
	void deleteLastEmploee();
	Emploee* find_name(wstring);
};
class Organization_B :public Organization
{
private:
	Emploee p[maxN];
public:
	void show();
	void addEmploee(const Emploee&);
	void deleteLastEmploee();
	Emploee* find_name(wstring);
};