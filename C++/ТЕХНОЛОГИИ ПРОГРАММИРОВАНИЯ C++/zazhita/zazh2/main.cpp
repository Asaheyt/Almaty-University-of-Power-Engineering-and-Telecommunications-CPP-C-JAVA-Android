#include <iostream>
#include "incam.h"
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Hospital x("Децентрализованный",54,4.56), y("Централизованный",34,5.65), z, *t;
    x.Show_Data();
    y.Show_Data();
    cout<<endl<<"Сравнение по типу"<<endl;
    z=x.Comparison_Type(y);
    z.Show_Data();
    cout<<endl<<"Сравнение по номеру"<<endl;
    z=x.Comparison_Number(y);
    z.Show_Data();
    cout<<endl<<"Сравнение по оценке"<<endl;
    z=x.Comparison_Valuation(y);
    z.Show_Data();
    t=new Hospital;
    cout<<endl<<"Введите данные больницы"<<endl;
    t->Input_Data();
    t->Show_Data();
    return 0;
}
