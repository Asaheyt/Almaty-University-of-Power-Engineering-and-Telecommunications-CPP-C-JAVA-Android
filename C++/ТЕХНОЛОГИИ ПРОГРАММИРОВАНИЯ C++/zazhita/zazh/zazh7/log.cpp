#include <iostream>
#include <complex>
#include "log.h"
using namespace std;
Complex::Complex(){}
Complex::Complex(double v, double a)
{
    x = v;
    y = a;
}
Complex::~Complex(){}
Complex operator+(const Complex& a, const Complex& b)
{
    Complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}
Complex operator-(const Complex& a, const Complex& b)
{
    Complex c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}
Complex operator*(const Complex& a, const Complex& b)
{
    Complex c;
    c.x = a.x*b.x - a.y*b.y;
    c.y = b.x*a.y + a.x*b.y;
    return c;
}
Complex operator/(const Complex& a, const Complex& b)
{
    Complex c;
    c.x = (a.x*b.x+a.y*b.y)/(pow(b.x,2)+pow(b.y,2));
    c.y = (a.y*b.x - a.x*b.y)/(pow(b.x,2)+pow(b.y,2));
    return c;
}
Complex operator*(const Complex& b, double a)
{
    Complex c;
    c.x = a * b.x;
    c.y = a * b.y;
    return c;
}
Complex operator/(const Complex& b, double a)
{
    Complex c;
    c.x = b.x/a;
    c.y = b.y/a;
    return c;
}
Complex operator+(const Complex& b, double a)
{
    Complex c;
    c.x = a+b.x;
    c.y = b.y;
    return c;
}
Complex operator-(const Complex& b, double a)
{
    Complex c;
    c.x = b.x-a;
    c.y = b.y;
    return c;
}
ostream& operator<<(ostream& os, const Complex& a)
{
    os <<"("<< a.x <<";"<< a.y <<"i)"<<endl;
    return os;
}
istream& operator>>(istream& is, Complex& a)
{
    cout << "¬ведите действительную часть:";
    is >> a.x;
    cout << "¬ведите мнимую часть:";
    is >> a.y;
}
//------------------------------------------------------------------------
double Exp_Dou(double x)
{
    double a, n;
    double eps = 0.00000001;
    double y;
    a = 1;
    y = a;
    n = 1;
    while(fabs(a) > eps)
    {
        a = a * x / n;
        y = y + a;
        n++;
    }
    return y;
}
double Cos_Dou(double x)
{
    double a, eps;
    double y;
    int n;
    double g;
    eps = 0.00000001;
    a = 1;
    y = a;
    n = 1;
    g = x;
    while(g < 0)
    {
        g = g + 2*M_PI;
    }
    while(g > 2*M_PI)
    {
        g = g - 2*M_PI;
    }
    while (fabs(a) > eps)
    {
        a = a * (-1) * g * g/((2 * n) * (2 * n - 1));
        y = y + a;
        n++;
    }
    return y;
}
double Sin_Dou(double x)
{
    double a, b, eps,c;
    double y,y1;
    int n;
    double g;
    eps = 0.00000001;
    g = x;
    while(g < 0)
    {
        g = g + 2*M_PI;
    }
    while(g > 2*M_PI)
    {
        g = g - 2*M_PI;
    }
    a = g;
    y = a;
    n = 1;
    while (fabs(a) > eps)
    {
        a = a *(-1)* g * g/(2*n*(2*n+1));
        y = y + a;
        n++;
    }
    return y;
}
Complex Exp_Com(const Complex& a)
{
    Complex b;
    b.x=Exp_Dou(a.x)*Cos_Dou(a.y);
    b.y=Exp_Dou(a.x)*Sin_Dou(a.y);
    return b;
}
Complex Th_Com(const Complex& a)
{
    Complex b, c;
    double d=-1;
    c=a*d;
    b=(Exp(a)-Exp(c))/(Exp(a)+Exp(c));
    return b;
}
double Ln_Dou(double x)
{
    double a, b, eps, c;
    double y, y1;
    int n;
    eps = 0.00000001;
    a = (x-1)/(x+1);
    y = a;
    n = 1;
    b = a;
    while (fabs(a) > eps)
    {
        if(n == 1)
        {
        a = a * b *(x - 1)/((x + 1) * (2 * n + 1));
        }
        else {
        a = a * b * (x - 1)*c/((x + 1)*(2*n+1));
        }
        y = y + a;
        c = (2 * n + 1);
        n++;
    }
    y = y * 2;
    return y;
}
double Arctg_Dou(double x)
{
    double y;
    if(fabs(x) < 1)
    {
        double a,c ,eps;
        int n;
        eps = 0.000001;
        a = x;
        y = a;
        n = 1;
        c = 1;
        while (fabs(a) > eps)
        {
            a = a *(-1)* x * x * c/(2*n+1);
            y = y + a;
            c = 2*n+1;
            n++;
        }
    }
    else
        if(fabs(x) >= 1)
        {
            double a, b ,eps,c;
            int n;
            eps = 0.000001;
            a =-(1/x);
            y = a;
            n = 1;
            while (fabs(a) > eps)
            {
                if(n == 1){
                a = a *(-1)/((2*n+1)* x * x);
                }
                else if(n > 1){
                    a = a *(-1) * c/((2*n+1)* x * x);
                }
                y = y + a;
                c = (2 * n + 1);
                n++;
            }
            a =-(1/x);
            if(a < 0)
            {
                y = M_PI_2 + y;
            }
            else if(a > 0)
            {
                y = y - M_PI_2;
            }
    }
    return y;
}double Ch(double x)
{
    double a, b ,eps,c;
    double y,y1;
    int n;
    double g;
    eps = 0.000001;
    a = 1;
    y = a;
    n = 0;
    g = x;
    while (fabs(a) > eps)
    {
        if(n == 0)
    {
       a = a * g * g/2;
    }
    else if(n >= 1)
    {
        a = a * g * g/((2*n+2)*(2*n+1));
    }
       y = y + a;
       n++;
    }

    return y;
}
double Sh1(double x)
{
    double a, b ,eps,c;
    double y,y1;
    int n;
    eps = 0.00000001;
    a = x;
    y = a;
    n = 1;
    while (fabs(a) > eps)
    {
        a = a * x * x/(2*n*(2*n+1));
        y = y + a;
        n++;
    }
    return y;
}
Complex Sincompl(Complex t)
{/*
    double a = x.x;
    double b = x.y;
    x.x = Sin_Dou(a)*Ch(b);
    x.y = Sh1(b)*Cos_Dou(a);
    return x;*/
    Complex a, b,c;
    Complex y,y1;
    double eps;
    int n;
    Complex g;
    eps = 0.001;
    g = t;
    while(MyABC(g) < 0)
    {
        g = g + 2*M_PI;
    }
    while(MyABC(g) > 2*M_PI)
    {
        g = g - 2*M_PI;
    }
    a = g;
    y = a;
    n = 1;
    while (MyABC(a) > eps)
    {
        a = a *(-1)* g * g/(2*n*(2*n+1));
        y = y + a;
        n++;
    }
    return y;
}
/*Complex Exp_Com(const Complex& a)
{
    Complex b;
    b.x=Exp_Dou(a.x)*Cos_Dou(a.y);
    b.y=Exp_Dou(a.x)*Sin_Dou(a.y);
    return b;
}*/
/*Complex Th_Com(const Complex& a)
{
    Complex b, c;
    double d=-1;
    c=a*d;
    b=(Exp(a)-Exp(c))/(Exp(a)+Exp(c));
    return b;
}*/
Complex Coscompl(Complex x)
{
    float a = x.x;
    float b = x.y;
    x.x = Cos_Dou(a)*Ch(b);
    x.y = -Sin_Dou(a)*Sh1(b);
    return x;
}
Complex Ln_Com(const Complex& a)
{
    Complex b;
    b.x=Ln_Dou(Pow_Dou(a.x*a.x+a.y*a.y,0.5));
    b.y=Arctg_Dou(a.y/a.x);
    return b;
}
double Pow_Dou(double a, double b)
{
    return Exp_Dou(b*Ln_Dou(a));
}
Complex Sqrt_Com(const Complex& a)
{
    Complex b;
    double r,f;
    r=Pow_Dou(a.x*a.x+a.y*a.y,0.5);
    f=Arctg_Dou(a.y/a.x);
    b.x=Pow_Dou(r,0.5)*Cos_Dou(f/2);
    b.y=Pow_Dou(r,0.5)*Sin_Dou(f/2);
    return b;
}
Complex Pow_Com(const Complex& a, const Complex& b)
{
    Complex c, d, f;
    d=Ln_Com(a);
    f=d*b;
    c=Exp_Com(f);
    return c;
}
//------------------------------------------------------------------------
Complex Log(const Complex& x)
{
    Complex a, b;
    Complex y, y1;
    int n, c ;
    double eps=0.001;
    a = (x-1)/(x+1);
    y = a;
    n = 1;
    b = a;
    while (MyABC(a) > eps)
    {
        if(n == 1)
        {
        a = a * b *(x - 1)/((x + 1) * (2 * n + 1));
        }
        else {
        a = a * b * (x - 1)*c/((x + 1)*(2*n+1));
        }
        y = y + a;
        c = (2 * n + 1);
        n++;
    }
    y = y * 2;
    return y;
}
Complex Exp(const Complex& x)
{
    Complex a(1,0);
    double eps = 0.001, n;
    Complex y;
    y = a;
    n = 1;
    while(MyABC(a) > eps)
    {
        a = a * x / n;
        y = y + a;
        n++;
    }
    return y;
}
double MyABC(const Complex& a)
{
    double r;
    r=Pow_Dou((a.x*a.x+a.y*a.y),0.5);
    return r;
}
Complex Sh(const Complex& x)
{
    Complex a, b ,c;
    Complex y,y1;
    double eps;
    int n;
    eps = 0.001;
    a = x;
    y = a;
    n = 1;
    while (MyABC(a) > eps)
    {
        a = a * x * x/(2*n*(2*n+1));
        y = y + a;
        n++;
    }
    return y;
}

Complex Tg(const Complex& a)
{
    Complex r;
    r=Sincompl(a)/Coscompl(a);
    return r;
}

