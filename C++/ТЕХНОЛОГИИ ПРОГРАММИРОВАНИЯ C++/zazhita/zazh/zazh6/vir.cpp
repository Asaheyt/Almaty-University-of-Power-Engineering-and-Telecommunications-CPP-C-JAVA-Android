#include "vir.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

Array::Array()
{
    NKol=0;
    for(int i=0;i<MaxN;i++)
    {
        A[i]='0';
    }
}
Array::~Array(){}
unsigned char& Array::operator[](int i)
{
    if((i>=MaxN)||(i<0))
    {
        cout<<"Error"<<endl;
    }
    else
    {
        return A[i];
    }
}
//-------------------------------------------------------------
BitString::BitString(int i)
{
    if(i<0||i>MaxN)
    {
        cout<<"Error"<<endl;
    }
    else
    {
        Num=i;
    }
}
BitString::BitString(){}
BitString::~BitString(){}
BitString operator&(BitString& a, BitString& b)
{
    if(a.Num==b.Num)
    {
        BitString c(a.Num);
        for(int i=0;i<c.Num;i++)
        {
            if(a.BS[i]=='1'&&b.BS[i]=='1')
            {
                c.BS[i]='1';
            }
            else
            {
                c.BS[i]='0';
            }
        }
        return c;
    }
    else
    {
        cout<<"Error"<<endl;
    }
}
BitString operator|(BitString& a, BitString& b)
{
    if(a.Num==b.Num)
    {
        BitString c(a.Num);
        for(int i=0;i<c.Num;i++)
        {
            if(a.BS[i]=='0'&&b.BS[i]=='0')
            {
                c.BS[i]='0';
            }
            else
            {
                c.BS[i]='1';
            }
        }
        return c;
    }
    else
    {
        cout<<"Error"<<endl;
    }
}
BitString operator^(BitString& a, BitString& b)
{
    if(a.Num==b.Num)
    {
        BitString c(a.Num);
        for(int i=0;i<c.Num;i++)
        {
            if((a.BS[i]=='0'&&b.BS[i]=='1')||(a.BS[i]=='1'&&b.BS[i]=='0'))
            {
                c.BS[i]='1';
            }
            else
            {
                c.BS[i]='0';
            }
        }
        return c;
    }
    else
    {
        cout<<"Error"<<endl;
    }
}
BitString operator~(BitString& a)
{
    BitString c(a.Num);
    for(int i=0;i<c.Num;i++)
    {
        if(a.BS[i]=='0')
        {
            c.BS[i]='1';
        }
        else
        {
            c.BS[i]='0';
        }
    }
    return c;
}
BitString operator<<(BitString& a, int i)
{
    BitString c(a.Num);
    c=a;
    for(int j=0;j<c.Num-i;j++)
    {
        c.BS[j]=c.BS[j+i];
    }
    for(int j=c.Num-i;j<c.Num;j++)
    {
        c.BS[j]='0';
    }
    return c;
}
BitString operator>>(BitString& a, int i)
{
    BitString c(a.Num);
    c=a;
    for(int j=c.Num-1;j>=i;j--)
    {
       c.BS[j]=c.BS[j-i];
    }
    for(int j=0;j<i;j++)
    {
        c.BS[j]='0';
    }

    return c;
}
void BitString::show()
{
    for(int i=0;i<Num;i++)
    {
        cout<<BS[i];
    }
    cout<<endl;
}
void BitString::random()
{
    int n;
    char t[1];
    for(int i=0;i<Num;i++)
    {
        n=rand()%2;
        itoa(n,t,10);
        BS[i]=(unsigned char)t[0];
    }
}
unsigned char* BitString::getBS()
{
    return BS;
}
int MaxOne(int a, int b)
{
    if(a>b){return a;}
    else {return b;}
}
unsigned char* BitString::sum(unsigned char* uc)
{
    unsigned char *result;
    int first=strlen((char*)BS)-1, second=strlen((char*)uc)-1;
    int res=MaxOne(first,second)+1;
    char memory='0';
    for(;res >= 0;first--,second--,res--)
    {
        if(memory=='1')
        {
            if(BS[first]=='1'||uc[second]=='1')
            {
                if(BS[first]=='1'&&uc[second]=='1'){result[res]='1';}
                else{result[res]='0';}
                memory='1';
            }
            else
            {
                result[res]='1';
                memory='0';
            }
        }
        else
        {
            if(BS[first]=='1'||uc[second]=='1')
            {
                if(BS[first]=='1'&&uc[second]=='1')
                    {
                        result[res]='0';
                        memory='1';
                    }
                else
                {
                    result[res]='1';
                }
            }
            else
            {
                result[res]='0';
            }
        }

    }
    if(result[0]!='0'&&result[0]!='1')
    {
        result [0] = '0';
    }
    int k;
    for(k = 0;result[k]=='0'||result[k]=='1';k++);
    result[k] = '\0';
    return result;
}
//---------------------------------------------------------------------------------------------
Hex::Hex(){}
Hex::Hex(int i)
{
    if(i<0||i>MaxN)
    {
        cout<<"Error"<<endl;
    }
    else
    {
        Num=i;
    }
}
Hex::~Hex(){}
void Hex::random()
{
    int n;
    char t[1];
    for(int i=0;i<Num;i++)
    {
        n=rand()%16;
        itoa(n,t,16);
        H[i]=(unsigned char)t[0];
    }
}
void Hex::show()
{
    cout<<"0x";
    for(int i=Num-1;i>=0;i--)
    {
        cout<<H[i];
    }
    cout<<endl;
}
unsigned char* Hex::getH()
{
    return H;
}
void Hex::setH(unsigned char* uc)
{
    for(int i=0;i<strlen((const char*)uc);i++)
    {
        H[i]=uc[i];
    }
    Num=strlen((const char*)uc)-1;
}
unsigned char* Hex::sum(unsigned char* uc)
{
    unsigned char *result;
    int x,y;
    x=ConvertToInt(H);
    y=ConvertToInt(uc);
    x=x+y;
    result=ConvertToUnCh(x);
    return result;
}
Hex operator-(Hex &a, Hex &b)
{
    unsigned char *result;
    int x,y;
    x=a.ConvertToInt(a.H);
    y=b.ConvertToInt(b.H);
    if(x>y){x=x-y;}
    else{x=y-x;}
    result=a.ConvertToUnCh(x);
    Hex c;
    c.setH(result);
    cout<<endl;
    return c;
}
Hex operator*(Hex &a, Hex &b)
{
    unsigned char *result;
    int x,y;
    x=a.ConvertToInt(a.H);
    y=b.ConvertToInt(b.H);
    x=x*y;
    result=a.ConvertToUnCh(x);
    Hex c;
    c.setH(result);
    cout<<endl;
    return c;
}
Hex operator/(Hex &a, Hex &b)
{
    unsigned char *result;
    int x,y;
    x=a.ConvertToInt(a.H);
    y=b.ConvertToInt(b.H);
    if(x>y){x=x/y;}
    else{x=y/x;}
    result=a.ConvertToUnCh(x);
    Hex c;
    c.setH(result);
    c.Num=c.Num-1;
    cout<<endl;
    return c;
}
int Hex::ConvertToInt(unsigned char* aH)
{
    int temp=0,r,v=1;
    for(int i=0;i<Num;i++,v*=16)
    {
        if(aH[i]=='0'){r=0;temp+=r*v;}
        if(aH[i]=='1'){r=1;temp+=r*v;}
        if(aH[i]=='2'){r=2;temp+=r*v;}
        if(aH[i]=='3'){r=3;temp+=r*v;}
        if(aH[i]=='4'){r=4;temp+=r*v;}
        if(aH[i]=='5'){r=5;temp+=r*v;}
        if(aH[i]=='6'){r=6;temp+=r*v;}
        if(aH[i]=='7'){r=7;temp+=r*v;}
        if(aH[i]=='8'){r=8;temp+=r*v;}
        if(aH[i]=='9'){r=9;temp+=r*v;}
        if(aH[i]=='a'){r=10;temp+=r*v;}
        if(aH[i]=='b'){r=11;temp+=r*v;}
        if(aH[i]=='c'){r=12;temp+=r*v;}
        if(aH[i]=='d'){r=13;temp+=r*v;}
        if(aH[i]=='e'){r=14;temp+=r*v;}
        if(aH[i]=='f'){r=15;temp+=r*v;}
    }
    return temp;
}
unsigned char* Hex::ConvertToUnCh(int f)
{
    unsigned char temp[MaxN];
    int d=100;
    for(int i=0;d>0;i++)
    {
        d=f%16;
        if(d==0){temp[i]='0';}
        if(d==1){temp[i]='1';}
        if(d==2){temp[i]='2';}
        if(d==3){temp[i]='3';}
        if(d==4){temp[i]='4';}
        if(d==5){temp[i]='5';}
        if(d==6){temp[i]='6';}
        if(d==7){temp[i]='7';}
        if(d==8){temp[i]='8';}
        if(d==9){temp[i]='9';}
        if(d==10){temp[i]='a';}
        if(d==11){temp[i]='b';}
        if(d==12){temp[i]='c';}
        if(d==13){temp[i]='d';}
        if(d==14){temp[i]='e';}
        if(d==15){temp[i]='f';}
        f=f/16;
    }
    return temp;
}
Hex Compare(Hex& a, Hex& b)
{
    Hex c;
    if(a.Num>b.Num)
    {
        c=a;
    }
    else
    {
        if(b.Num>a.Num)
        {
            c=b;
        }
        else
        {
            for(int i=a.Num-1;i>=0;i--)
            {
                if(a.H[i]>b.H[i]){c=a;break;}
                else
                {
                    if(b.H[i]>a.H[i]){c=b;break;}
                    else{c=a;}
                }
            }
        }
    }
    return c;
}

