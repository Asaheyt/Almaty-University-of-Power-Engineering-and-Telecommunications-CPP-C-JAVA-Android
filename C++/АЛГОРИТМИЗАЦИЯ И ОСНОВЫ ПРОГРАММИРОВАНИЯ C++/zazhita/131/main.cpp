#include <iostream>
#include "uhu.h"
#include "windows.h"
#include "fstream"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string n1,n2;
    Spisok S;
    Plastina p;
    Init(S);
    n1="gomu.txt";
    n2="gomu2.txt";
    Fileopread(p,S,n1);
    cout<<"Все пластинки:"<<endl;
    Show(S);
    cout<<"Сортировка:"<<endl;
    MenuSort(S);
    cout<<endl;
    FileWrite(p,S,n2);
    return 0;
}
