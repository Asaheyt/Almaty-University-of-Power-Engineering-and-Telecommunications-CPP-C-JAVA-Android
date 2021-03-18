#include <iostream>
#include "hit.h"
#include "cstring"
#include "cstdio"
#include "cstdlib"
using namespace std;
void res(string &s)
{
    setlocale(LC_ALL,"Russian");
    int z;
    for(int i=0;s[i]!=NULL;i++)
    {
        z=0;
        Opred(s,i,z);
        if (z>3)
        {
            ERase(s,i);
        }
    }
}

void ERase(string &s,int &i)
{
            for(;;)
            {
                s.erase(i,1);
                if((s[i]==NULL)||(s[i]==' ')){break;}
            }
            if (s[i]==' '){s.erase(i,1);i--;}
}
void Opred(string s,int i,int &z)
{
    int j;
        for(j=i;;j++)
        {
            if((s[j]==NULL)||(s[j]==' ')){break;}
            z++;
        }
}

