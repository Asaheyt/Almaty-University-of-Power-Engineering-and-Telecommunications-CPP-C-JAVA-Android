#ifndef DUB_H_INCLUDED
#define DUB_H_INCLUDED

#include <iostream>
using namespace std;
#define maxN 100
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
	int getHomeNum()const;
	string getName()const;
	int getPostNum()const;
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
	Data beginW;
public:
	Emploee();
	Emploee(string, int, int, string, int, float, Data);
	~Emploee();
	void setJob(string);
	void setWages(int);
	void setSeniority(float);
	void setData(Data&);
	Data getData();
	int getWages()const;
	string getJob()const;
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
	string name;
	int N_Emploee;
	Emploee *p[maxN];
public:
	Organization();
	Organization(const Organization&);
	Organization(string);
	~Organization();
	void setName(string);
	string getName();
	int getN_Emploee();
	void show();
	void addEmploee(const Emploee&);
	void deleteLastEmploee();
	Emploee* find_name(string);
	void sorting(int (*cmp)(Emploee&, Emploee&));
	void addEmploeeIndex(const Emploee&, int);
	void Del_Duplicate(int (*cmp)(Emploee&, Emploee&));
	void Del_Wages(int);
	void Del_Seniority(int);
	void Del_Data(Data);
	void Del_Job(string);
	void Del_Name(string);
	void Del_HomeNum(int);
	void Del_PostNum(int);
	friend void Move(Organization&, int);
	friend void sum(const Organization&, const Organization&, Organization&);
	friend Organization operator+(const Organization&, const Organization&);
	Organization& operator=(const Organization&);
	friend ostream& operator<<(ostream& os, const Organization&);
};
void RANDOM(Organization&, int);
typedef (*cmp)(Emploee&, Emploee&);

#endif // DUB_H_INCLUDED
