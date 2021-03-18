#include <iostream>
#include "cstring"
#include "cstdio"
#include "won.h"
#include "algorithm"
using namespace std;
void pro(char *str)
{
    char *t,s[100];
    bool f;
    s[0]='\0';
    t=strtok(str,"!., ;:");
    while(t!=NULL)
    {
        f=true;
        for(int i=0;i<=strlen(t);i++)
        {
            if(t[i]>='A'&&t[i]<='Z'){f=false;}
        }
        if(f==true)
        {
            strcat(s,t);
            strcat(s," ");
        }
        t=strtok(NULL,"!., ;:");
    }
    strcpy(str,s);
}
