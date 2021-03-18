#pragma once
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
class Node
{
private:
	Emploee data;
	Node *prev;
	Node *next;
	friend class Organization;
public:
	void setData(const Emploee &);
	void setNext(Node*);
	Emploee getData();
	Node* getNext();
};
//-------------------------------------------------------------------------------
class Organization
{
private:
	Node *begin;
	Node *end;
	static int b;
	friend class Node;
	friend class binary_func;
protected:
	int N_Emploee;
public:
	Organization();
	~Organization();
	int getN_Emploee();
	void show();
	void push_back(const Emploee&);
	void push_front(const Emploee&);
	Emploee pop_back();
	Emploee pop_front();
	void sorting(int(*cmp)(Emploee&, Emploee&));
	void RANDOM_Fill(int);
	void clean_list();
	void inputinfile();
	void readfromfile();
	void Sortname(binary_func);
	void Sorthomenum(binary_func);
	void Sortpostnum(binary_func);
	void Sortwages(binary_func);
	void Sortseniority(binary_func);
	void Sortjob(binary_func);
};
//-------------------------------------------------------------------------------
class binary_func
{
private:
	bool type;
	friend class Organization;
public:
	bool operator()(int, int);
	bool operator()(wchar_t *, wchar_t *);
	binary_func(bool);
	binary_func operator()(bool);
	binary_func();
};