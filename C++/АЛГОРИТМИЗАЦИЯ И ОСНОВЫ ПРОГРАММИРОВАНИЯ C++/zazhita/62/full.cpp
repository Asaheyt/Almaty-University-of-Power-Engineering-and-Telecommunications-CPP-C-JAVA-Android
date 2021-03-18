#include "full.h"
#include <iostream>
#include "cstring"
#include "cstdlib"
using namespace std;

void cel(char *s,int *s2, int &n)
{
    char f;int i=0;
    while(i<=strlen(s))
    {
        if(s[i]==' ')
        {
            *(s2+i)=101;
        }
        else
        {
            f=s[i];
            *(s2+i)=atoi(&f);
        }
        n=i;i++;
    }
}

void show(int * s2,int num,int m)
{
    for(int i=0;i<num;i++)
    {
        if(s2[i]==101){cout<<";";}
        else {cout<<*(s2+i);}
    }
}
