#include "incam.h"
#include <iostream>
#include <cstring>
using namespace std;

Hospital::Hospital(){}
Hospital::Hospital(string r1, int r2, float r3)
{
    type=r1;
    number=r2;
    valuation=r3;
}
Hospital::~Hospital(){}

void Hospital::Set_Type(string r1)
{
    type=r1;
}
string Hospital::Get_Type() const
{
    string r1;
    r1=type;
    return r1;
}
void Hospital::Set_Number(int r2)
{
    number=r2;
}
int Hospital::Get_Number() const
{
    int r2;
    r2=number;
    return r2;
}
void Hospital::Set_Valuation(float r3)
{
    valuation=r3;
}
float Hospital::Get_Valuation() const
{
    float r3;
    r3=valuation;
    return r3;
}
void Hospital::Input_Data()
{
    string r1;
    cout<<"Введите тип больницы: ";
    cin>>r1;
    type=r1;
    int r2;
    cout<<"Введите номер больницы: ";
    while(!(cin>>r2)||(cin.peek()!='\n'))
    {
        cin.clear();
        while(cin.get()!='\n');
        cout<<"Ошибка!Введите номер больницы: "<<endl;
    }
    number=r2;
    float r3;
    cout<<"Введите оценку больницы: ";
    while(!(cin>>r3)||(cin.peek()!='\n'))
    {
        cin.clear();
        while(cin.get()!='\n');
        cout<<"Ошибка!Введите оценку больницы: "<<endl;
    }
    valuation=r3;
}
void Hospital::Show_Data()
{
    cout<<"Тип больницы: "<<type<<". Номер больницы: "<<number<<". Оценка больницы: "<<valuation<<"."<<endl;
}
Hospital Hospital::Comparison_Type(const Hospital& r)
{
    Hospital temp;
    if(type<=r.Get_Type())
    {
        temp=*this;
    }
    else
    {
        temp=r;
    }
    return temp;
}
Hospital Hospital::Comparison_Number(const Hospital& r)
{
    Hospital temp;
    if(number<=r.Get_Number())
    {
        temp=*this;
    }
    else
    {
        temp=r;
    }
    return temp;
}
Hospital Hospital::Comparison_Valuation(const Hospital& r)
{
    Hospital temp;
    if(valuation<=r.Get_Valuation())
    {
        temp=*this;
    }
    else
    {
        temp=r;
    }
    return temp;
}
/*
friend void Input_Data(Hospital& r)
{
    string r1;
    cout<<"Введите тип больницы: ";
    cin>>r1;
    r.type=r1;
    int r2;
    cout<<"Введите номер больницы: ";
    while(!(cin>>r2)||(cin.peek()!='\n'))
    {
        cin.clear();
        while(cin.get()!='\n');
        cout<<"Ошибка!Введите номер больницы: "<<endl;
    }
    r.number=r2;
    float r3;
    cout<<"Введите оценку больницы: ";
    while(!(cin>>r3)||(cin.peek()!='\n'))
    {
        cin.clear();
        while(cin.get()!='\n');
        cout<<"Ошибка!Введите оценку больницы: "<<endl;
    }
    r.valuation=r3;
}
friend void Show_Data(const Hospital& r)
{
    cout<<"Тип больницы: "<<r.type<<". Номер больницы: "<<r.number<<". Оценка больницы: "<<r.valuation<<"."<<endl;
}
friend Hospital Comparison_Type(const Hospital& rr1, const Hospital& rr2)
{
    Hospital temp;
    if(rr1.type<=rr2.Get_Type())
    {
        temp=*this;
    }
    else
    {
        temp=r;
    }
    return temp;
}
friend Hospital Comparison_Number(const Hospital& rr1, const Hospital& rr2)
{
    Hospital temp;
    if(rr1.number<=rr2.Get_Number())
    {
        temp=*this;
    }
    else
    {
        temp=r;
    }
    return temp;
}
friend Hospital Comparison_Valuation(const Hospital& rr1, const Hospital& rr2)
{
    Hospital temp;
    if(rr1.valuation<=rr2.Get_Valuation())
    {
        temp=*this;
    }
    else
    {
        temp=r;
    }
    return temp;
}
*/
