#include <iostream>
#include "cstring"
#include "cstdio"
#include "full.h"
using namespace std;
int main()
{
    setlocale(LC_ALL,"Russian");
    int *c;
    c=new int[100];
    int n=0,m=0;
    char a[]={"5870 9674 31 2"};
    cout<<"Начальная строка:"<<endl<<a<<endl;
    cel(a,c,n);
    cout<<"Результат:"<<endl;
    show(c,n,m);
    return 0;
}
