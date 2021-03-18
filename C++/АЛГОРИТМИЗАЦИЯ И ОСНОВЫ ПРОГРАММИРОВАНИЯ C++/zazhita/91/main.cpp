#include <iostream>
#include <cstdlib>
#include "set.h"
using namespace std;

int main()
{

    setlocale(LC_ALL,"Russian");
    const int n=5;
    Rabotnik *a;
    a=new Rabotnik[n];
    Today b;
    fillTod(b);
    Fill(a);
    cout<<"Все работники: "<<endl;
    ShowAll(a,n);
    cout<<endl;
    cout<<"Сегодня: ";showTod(b);
    cout<<endl<<"Вывод сведений о работниках, срок действия контракта которых истекает в течение 5-ти дней:"<<endl<<endl;
    res(a,b,n);
    return 0;
}
