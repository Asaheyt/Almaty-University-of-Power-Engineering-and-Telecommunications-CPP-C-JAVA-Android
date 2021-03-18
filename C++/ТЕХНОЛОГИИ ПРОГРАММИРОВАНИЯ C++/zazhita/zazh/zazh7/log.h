#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

using namespace std;
#include <complex>
class Complex
{
private:
    double x;
    double y;
public:
    Complex();
    Complex(double, double);
    ~Complex();
    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, double);
    friend Complex operator/(const Complex&, double);
    friend Complex operator+(const Complex&, double);
    friend Complex operator-(const Complex&, double);
    friend ostream& operator<<(ostream & ,const Complex &);
    friend istream& operator>>(istream &, Complex &);
    friend Complex Pow_Com(const Complex&, const Complex&);
    friend Complex Exp_Com(const Complex&);
    friend Complex Th_Com(const Complex&);
    friend Complex Ln_Com(const Complex&);
    friend Complex Sincompl(Complex);
    friend Complex Coscompl(Complex);
    friend Complex Sqrt_Com(const Complex&);


    friend Complex Log(const Complex&);
    friend Complex Exp(const Complex&);
    friend double MyABC(const Complex&);
    friend Complex Sh(const Complex&);
    friend Complex Tg(const Complex&);
    friend Complex Cos(const Complex&);
    friend Complex Sin(const Complex&);



};
double Cos_Dou(double);
double Sin_Dou(double);
double Exp_Dou(double);
double Ln_Dou(double);
double Arctg_Dou(double);
double Pow_Dou(double, double);
double Ch(double);
double Sh1(double);

#endif // LOG_H_INCLUDED
