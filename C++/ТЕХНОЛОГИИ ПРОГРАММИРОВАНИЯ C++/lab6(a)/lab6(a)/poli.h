#pragma once
#include<iostream>
using namespace std;
class Number
{
public:
	Number();
	virtual float Modul() = 0;
};
class Real_Number : public Number
{ 
private:
	float a;
public:
	Real_Number();
	Real_Number(float);
	float Modul();
	Real_Number operator*(Real_Number);
	friend ostream& operator<<(ostream&, const Real_Number&);
	friend istream& operator>>(istream&, Real_Number&);
};

class Complex : public Number
{
private:
	float r,f;
public:
	Complex();
	Complex(float, float);
	float Modul();
	Complex operator*(Complex);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
};
