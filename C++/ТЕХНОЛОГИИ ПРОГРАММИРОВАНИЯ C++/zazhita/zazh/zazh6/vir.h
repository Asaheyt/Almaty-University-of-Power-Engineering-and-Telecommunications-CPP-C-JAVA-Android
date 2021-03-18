#ifndef VIR_H_INCLUDED
#define VIR_H_INCLUDED
#define MaxN 100
#include <iostream>
using namespace std;

class Array
{
private:
    unsigned char A[MaxN];
    int NKol;
public:
    Array();
    ~Array();
    unsigned char& operator[](int);
    virtual unsigned char* sum(unsigned char*)=0;
};
//-------------------------------------------------------
class BitString:public Array
{
private:
    unsigned char BS[MaxN];
    int Num;
public:
    BitString();
    BitString(int);
    ~BitString();
    friend BitString operator&(BitString&, BitString&);
    friend BitString operator|(BitString&, BitString&);
    friend BitString operator^(BitString&, BitString&);
    friend BitString operator~(BitString&);
    friend BitString operator<<(BitString&, int);
    friend BitString operator>>(BitString&, int);
    void show();
    void random();
    unsigned char* getBS();
    unsigned char* sum(unsigned char*);
};
int MaxOne(int, int);

class Hex:public Array
{
private:
    unsigned char H[MaxN];
    int Num;
public:
    Hex();
    Hex(int);
    ~Hex();
    void random();
    void show();
    unsigned char* getH();
    void setH(unsigned char*);
    int ConvertToInt(unsigned char*);
    unsigned char* ConvertToUnCh(int);
    unsigned char* sum(unsigned char*);
    friend Hex operator-(Hex&, Hex&);
    friend Hex operator*(Hex&, Hex&);
    friend Hex operator/(Hex&, Hex&);
    friend Hex Compare(Hex&, Hex&);
};
#endif // VIR_H_INCLUDED
