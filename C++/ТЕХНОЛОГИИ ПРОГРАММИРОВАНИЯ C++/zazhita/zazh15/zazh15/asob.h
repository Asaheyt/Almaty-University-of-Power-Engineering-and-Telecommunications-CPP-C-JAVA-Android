#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
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
public:
	Emploee();
	Emploee(wchar_t*, int, int, wchar_t*, int, int);
	~Emploee();
	void setJob(wchar_t*);
	void setWages(int);
	void setSeniority(int);
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
//-------------------------------------------------------------------------------
class Func
{
private:
	bool type;
	int g;
public:
	Func(bool);
	Func(int);
	Func(int, bool);
	Func();
	Func operator()(int);
	Func operator()(bool);
	bool compare(Emploee &, Emploee &);
	bool operator()(wchar_t *, wchar_t *);
	bool operator()(int, int);
	bool operator()(Emploee &, Emploee &);
	friend class Organization_Ukaz;
	friend class Organization_Mas;
	friend class Organization_DinList;
	friend class Organization_DinMas;
	friend class Organization_Vect;
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
	virtual void inputinfile() = 0;
	virtual void readfromfile() = 0;
	virtual void find_name(wchar_t *) = 0;
	virtual void del_name(wchar_t *) = 0;
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
	void Move(int);
	void inputinfile();
	void readfromfile();
	void find_name(wchar_t *);
	void del_name(wchar_t *);
	void SortName(Func);
	void SortPostNum(Func);
	void SortHomeNum(Func);
	void SortJob(Func);
	void SortWage(Func);
	void SortSeniority(Func);
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
	void Move(int);
	void inputinfile();
	void readfromfile();
	void find_name(wchar_t *);
	void del_name(wchar_t *);
	void SortName(Func);
	void SortPostNum(Func);
	void SortHomeNum(Func);
	void SortJob(Func);
	void SortWage(Func);
	void SortSeniority(Func);
};
//------------------------------------------------------------------------------
class Organization_DinMas :public Organization
{
private:
	Emploee *p;
	static int c;
public:
	Organization_DinMas();
	void show();
	void addEmploee(const Emploee&);
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void Del_Duplicate(int(*cmp)(Emploee&, Emploee&));
	void Move(int);
	void RANDOM_Fill(int);
	void deleteLastEmploee();
	void inputinfile();
	void readfromfile();
	void find_name(wchar_t *);
	void del_name(wchar_t *);
	void SortName(Func);
	void SortPostNum(Func);
	void SortHomeNum(Func);
	void SortJob(Func);
	void SortWage(Func);
	void SortSeniority(Func);
};
//-------------------------------------------------------------------------------
class Node
{
private:
	Emploee data;
	Node *prev;
	Node *next;
	friend class Organization_DinList;
public:
	void setData(const Emploee &);
	void setNext(Node*);
	Emploee getData();
	Node* getNext();
};
//-------------------------------------------------------------------------------
class Organization_DinList :public Organization
{
private:
	Node *begin;
	Node *end;
	static int d;
	friend class Node;
public:
	Organization_DinList();
	void show();
	void addEmploee(const Emploee&);
	void push_front(const Emploee&);
	void deleteLastEmploee();
	Emploee pop_front();
	void Del_Duplicate(int(*cmp)(Emploee&, Emploee&));
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void RANDOM_Fill(int);
	void inputinfile();
	void readfromfile();
	void find_name(wchar_t *);
	void del_name(wchar_t *);

	void SortName(Func);
	void SortPostNum(Func);
	void SortHomeNum(Func);
	void SortJob(Func);
	void SortWage(Func);
	void SortSeniority(Func);
};
//-----------------------------------------------------------------------------
class Organization_Vect :public Organization
{
private:
	vector<Emploee> t;
	vector<Emploee>::iterator nt;
	static int e;
public:
	void show();
	void addEmploee(const Emploee&);
	void deleteLastEmploee();
	void RANDOM_Fill(int);
	void Move(int);
	void Del_Duplicate(int(*cmp)(Emploee&, Emploee&));
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void readfromfile();
	void inputinfile();
	void find_name(wchar_t *);
	void del_name(wchar_t *);
	void SortName(Func);
	void SortPostNum(Func);
	void SortHomeNum(Func);
	void SortJob(Func);
	void SortWage(Func);
	void SortSeniority(Func);
	void read_file(wchar_t*);
	Organization_Vect operator+(Organization_Vect);
	Organization_Vect operator-(Organization_Vect);
	Organization_Vect operator*(Organization_Vect);
};
//-----------------------------------------------------------------------------------------
void cnslCmd(Organization*);
