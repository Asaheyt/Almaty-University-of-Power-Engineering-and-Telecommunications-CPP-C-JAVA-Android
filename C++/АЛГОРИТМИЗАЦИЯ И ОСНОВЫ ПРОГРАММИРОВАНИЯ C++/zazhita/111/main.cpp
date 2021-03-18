#include <iostream>
#include <cstdlib>
#include "Fol.h"
#include "windows.h"
#include "fstream"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream rfile;
    ofstream wfile;
    string n1;
    CmpSrav a;
    Today q;
    Organizacia y;
    Rabotnik R;
    Init(y);
    Fill(y,R);
    cout<<"Все работники:"<<endl;
    ShowAll(y);cout<<endl;
    cout<<"Сортировка по фамилии:"<<endl;
    a=SravnFam; SortSt(y,a);ShowAll(y);
    cout<<"Сортировка по должности:"<<endl;
    a=SravnDol; SortSt(y,a);ShowAll(y);
    cout<<"Сортировка по дате:"<<endl;
    a=SravnData; SortSt(y,a);ShowAll(y);
    cout<<"Сортировка по сроку:"<<endl;
    a=SravnSrok; SortSt(y,a);ShowAll(y);
    cout<<"Сортировка по окладу:"<<endl;
    a=SravnOkl; SortSt(y,a);ShowAll(y);
    cout<<endl;
    cout<<"Введите имя файла: ";
    cin>>n1;
    FileWrite(wfile,R,y,n1);
    cout<<"Данные записаны в файл."<<endl;
    cout<<endl;
    Fileopread(rfile,R,y,n1);
    cout<<"Данные записаны в новый массив."<<endl;cout<<endl;
    cout<<"Проверка данных:"<<endl;
    Proverka(y);cout<<endl;
    cout<<"Вывод на консоль нового массива:"<<endl;
    ShowAll2(y);
    cout<<endl;
    cout<<"Сегодня:"<<endl;
    fillTod(q);
    showTod(q);cout<<endl;
    cout<<"Вывод данных работников, срок которых истекает в течение 5 дней:"<<endl;
    res(y,q);
    Konec(y);
    return 0;
}
