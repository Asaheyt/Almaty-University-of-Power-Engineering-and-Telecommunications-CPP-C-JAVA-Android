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
class  Dog
{
private:
	wchar_t name[maxN];
	int age;
	wchar_t type[maxN];
public:
	Dog();
	Dog(wchar_t*, int, wchar_t*);
	~Dog();
	void setName(wchar_t*);
	void setAge(int);
	void setType(wchar_t*);
	int getAge()const;
	const wchar_t* getName();
	const wchar_t* getType();
	void show();
	void input();
};
int cmpName(Dog&, Dog&);
int cmpAge(Dog&, Dog&);
int cmpType(Dog&, Dog&);
//-------------------------------------------------------------------------------
class Node
{
private:
	Dog data;
	Node *prev;
	Node *next;
	friend class List;
public:
	void setData(const Dog &);
	void setNext(Node*);
	Dog getData();
	Node* getNext();
};
//-------------------------------------------------------------------------------
class List
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
	List();
	~List();
	int getN_Emploee();
	void show();
	void push_back(const Dog&);
	void push_front(const Dog&);
	Dog pop_back();
	Dog pop_front();
	void sorting(int(*cmp)(Dog&, Dog&));
	void RANDOM_Fill(int);
	void clean_list();
	void inputinfile();
	void readfromfile();
	void Sortname(binary_func);
	void Sortage(binary_func);
	void Sorttype(binary_func);
};
//-------------------------------------------------------------------------------
class binary_func
{
private:
	bool type;
	friend class List;
public:
	bool operator()(int, int);
	bool operator()(wchar_t *, wchar_t *);
	binary_func(bool);
	binary_func operator()(bool);
	binary_func();
};