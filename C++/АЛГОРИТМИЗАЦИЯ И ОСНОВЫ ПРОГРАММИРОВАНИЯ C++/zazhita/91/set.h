#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include "string"
#include <iostream>
using namespace std;
struct Today
{
    int day;
    int month;
    int year;
};
struct Data
{
    int day;
    int month;
    int year;
};
struct Rabotnik
{
    string Familiya;
    string Dolzhnost;
    Data D1;
    int Srok;
    int Oklad;
};
void fillTod(Today &);
void Fill(Rabotnik *);
void ShowAll(Rabotnik *, int);
void ShowOne(Rabotnik *, int);
void showTod(Today);
void res(Rabotnik *, Today, int);
void opred(Rabotnik *, Today, int &, int &, int);
#endif // SET_H_INCLUDED
