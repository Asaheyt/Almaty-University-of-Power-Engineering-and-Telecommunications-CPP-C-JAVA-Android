#include "clinc.h"
#include <iostream>
#include <cstring>
using namespace std;
int Tank::Count = 0;
Tank::Tank()
{
    Count++;
    cout<<"Конструктор Tank.Создание экземпляра класса. Число элементов "<<Count<<endl;
}
Tank::~Tank()
{
    if(model==NULL){delete [] model;}
    Count--;
    cout<<"Деструктор Tank.Удаление экземпляра класса. Число элементов "<<Count<<endl;

}
Tank::Tank(const char *m,int y)
{
    Count++;
    cout<<"Конструктор Ttovar: Создание экземпляра класса,число элементов "<<Count<<endl;
    year=y;
    model= new char[strlen(m)+1];
    strcpy(model,m);
}
void Tank::set_model(const char *m)
{
    model= new char[strlen(m)+1];
    strcpy(model,m);
}
char *Tank::get_model()
{
    return &model[0];
}
void Tank::set_year(int y)
{
    year=y;
}
int Tank::get_year()
{
    return year;
}
void Tank::show()
{
    cout<<"Экземпляр класса Tank."<<": Модель: "<<model<<"; Год сборки: "<<year<<endl;
}
