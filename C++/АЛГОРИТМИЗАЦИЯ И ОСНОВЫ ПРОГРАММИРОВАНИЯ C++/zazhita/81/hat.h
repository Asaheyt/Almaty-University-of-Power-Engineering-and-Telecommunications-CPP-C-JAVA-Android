#ifndef HAT_H_INCLUDED
#define HAT_H_INCLUDED
#include "string"
#include <iostream>
using namespace std;

struct Disc
{
    string Ispolnitel;
    string Zhanr;
    string NazAlbom;
    int Tirazh;
};
void Fill(Disc *,int);
void ShowAll(Disc *,int);
void ShowOne(Disc *,int);
void Opred(Disc *,int,int &);
#endif // HAT_H_INCLUDED
