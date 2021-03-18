#pragma once
#include <iostream>
using namespace std;
#define maxN 100
//-------------------------------------------------------------------------------
class Liver
{
private:
	string name;
	int homeNum;
	int postNum;
	static int count;
	friend class Organization;
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
	int N_Emploee;
	Emploee *p[maxN];
public:
	Organization();
	Organization(string);
	~Organization();
	void setName(string);
	string getName();
	void show();
	void addEmploee(const Emploee&);
	void deleteLastEmploee();
	Emploee* find_name(string);
};
