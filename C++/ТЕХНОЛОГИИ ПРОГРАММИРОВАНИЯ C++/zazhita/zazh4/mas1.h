#ifndef MAS1_H_INCLUDED
#define MAS1_H_INCLUDED
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
class  Emploee: public Liver
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
	int getWages() const;
	string getJob() const;
	float getSeniority() const;
	void show();
	void input();
	int cmpJob(const Emploee&);
	int cmpWages(const Emploee&);
};
//-------------------------------------------------------------------------------
class Organization
{
private:
	string name;
	int N_Emploee;
	Emploee p[maxN];
public:
	Organization();
	Organization(string);
	~Organization();
	void setName(string);
	string getName();
	void show();
	void addEmploee(const Emploee&);
	void deleteLastEmploee();
	void SortByJob();
	void SortByWages();
	friend void confluence(Organization&, const Organization&);
};


#endif // MAS1_H_INCLUDED
