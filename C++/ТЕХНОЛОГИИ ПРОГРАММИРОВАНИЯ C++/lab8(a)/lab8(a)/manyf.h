#pragma once
#include "stdafx.h"
using namespace std;
#define maxN 100
//-------------------------------------------------------------------------------
class Liver
{
private:
	string name;
	int homeNum;
	int postNum;
public:
	Liver();
	Liver(string, int, int);
	~Liver();
	void setName(string);
	void setHomeNum(int);
	void setPostNum(int);
	int getHomeNum();
	string getName();
	int getPostNum();
	void show();
	void input();
};
//-------------------------------------------------------------------------------
class  Emploee : public Liver
{
private:
	string job;
	int wages;
	float seniority;
public:
	Emploee();
	Emploee(string, int, int, string, int, float);
	~Emploee();
	void setJob(string);
	void setWages(int);
	void setSeniority(float);
	int getWages();
	string getJob();
	float getSeniority();
	void show();
	void input();
};
//-------------------------------------------------------------------------------
class Organization
{
private:
	string name;
protected:
	int N_Emploee;
public:
	Organization();
	Organization(string);
	~Organization();
	void setName(string);
	string getName();
	int getN_Emploee();
	virtual void show()=0;
	virtual void addEmploee(const Emploee&)=0;
	virtual void deleteLastEmploee()=0;
	virtual Emploee* find_name(string)=0;
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
	Emploee* find_name(string);
};
class Organization_B :public Organization
{
private:
	Emploee p[maxN];
public:
	void show();
	void addEmploee(const Emploee&);
	void deleteLastEmploee();
	Emploee* find_name(string);
};