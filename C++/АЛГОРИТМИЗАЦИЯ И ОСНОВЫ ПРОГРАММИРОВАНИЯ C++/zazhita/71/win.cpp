#include <iostream>
#include "win.h"
#include "cstring"
#include "cstdio"
#include "cstdlib"
using namespace std;
void res(string &s)
{
    setlocale(LC_ALL,"Russian");
    for(int i=0;s[i]!=NULL;i++)
    {
        if ((s[i]=='Ô')&&((i==0)||(s[i-1]==' ')))
        {
            for(;;)
            {
                s.erase(i,1);
                if((s[i]==NULL)||(s[i]==' ')){break;}
            }
            if (s[i]==' '){s.erase(i,1);}
        }
    }
}

