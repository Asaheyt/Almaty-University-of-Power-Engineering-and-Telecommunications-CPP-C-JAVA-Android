#pragma once
#include <iostream>
using namespace std;
class Emploee
{
private:
	string name;
	int wages;
protected:
	static int count;
public:
	Emploee();
	Emploee(string, int);
	~Emploee();
	void setName(string);
	void setWages(int);
	int getWages();
	string getName();
	void show();
	void input();
};
class Teacher : public Emploee
{
private:
	string subject;
	int seniority;
public:
	Teacher();
	Teacher(string, int, string, int);
	~Teacher();
	void setSubject(string);
	void setSeniority(int);
	int getSeniority();
	string getSubject();
	void input();
	void show();

};
class Manager : public Teacher
{
private:
	int number_of_student;
	string quality;
public:
	Manager();
	Manager(string, int, string, int, string, int);
	~Manager();
	void setNumberOf(int);
	void setQuality(string);
	int getNunberOf();
	string getQuality();
	void input();
	void show();
};