#include <iostream>
#include <cstdlib>
#include "set.h"
#include "windows.h"
using namespace std;
int main()
{
    setlocale(LC_ALL,"Russian");
    Organizacia y;
    Rabotnik R;
    Init(y);
    Fill(y,R);
    cout<<"Все работники: "<<endl;
    ShowAll(y);cout<<endl;
    cout<<"Сортировка по фамилии:"<<endl;
    SortFam(y);
    ShowAll(y);
    cout<<"Сортировка по должности:"<<endl;
    SortDol(y);
    ShowAll(y);
    cout<<"Сортировка по дате:"<<endl;
    SortData(y);
    ShowAll(y);
    cout<<"Сортировка по сроку:"<<endl;
    SortSrok(y);
    ShowAll(y);
    cout<<"Сортировка по окладу:"<<endl;
    SortOkl(y);
    ShowAll(y);cout<<endl;
    Today b;
    fillTod(b);
    cout<<"Сегодня: ";
    showTod(b);
    cout<<endl<<"Вывод сведений о работниках, срок действия контракта которых истекает в течение 5-ти дней:"<<endl<<endl;
    res(y,b);
    ShowAll2(y);
    return 0;
}
