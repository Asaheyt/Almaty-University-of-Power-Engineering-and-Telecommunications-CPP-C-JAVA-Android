#include"poli.h"
#include<iostream>
using namespace std;
Number::Number() {}
Real_Number::Real_Number() {}
Real_Number::Real_Number(float f)
{
	a = f;
}
float Real_Number::Modul() 
{
	return fabs(a);
}
Real_Number Real_Number::operator*(Real_Number b)
{
	Real_Number c;
	c.a = b.a*a;
	return c;
}
ostream& operator<<(ostream& os, const Real_Number& r)
{
	os << r.a;
	return os;
}
istream& operator >> (istream& is, Real_Number & r)
{
	cout << "¬ведите R: ";
	is >> r.a;
	return is;
}

Complex::Complex() {}
Complex::Complex(float f1, float f2)
{
	r = f1;
	f = f2;
}
float Complex::Modul()
{
	return fabs(r);
}
Complex Complex::operator*(Complex a)
{
	Complex c;
	c.r = a.r*r;
	c.f = a.f + f;
	return c;
}
ostream& operator<<(ostream& os, const Complex& c)
{
	os << c.r <<"*[cos("<< c.f<<")+i*sin("<<c.f<<")]";
	return os;
}
istream& operator>>(istream& is, Complex& c)
{
	cout << "¬ведите R: ";
	is >> c.r;
	cout << "¬ведите F: ";
	is >> c.f;
	return is;
}