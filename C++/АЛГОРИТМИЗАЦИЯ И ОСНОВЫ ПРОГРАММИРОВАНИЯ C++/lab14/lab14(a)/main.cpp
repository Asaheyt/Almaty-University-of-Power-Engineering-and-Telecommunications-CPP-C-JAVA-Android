#include <iostream>
#include<windows.h>
#include "gas.cpp"
using namespace std;

int main()
{
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        cout <<"Шаблон стека"<<endl;
        cout <<"Имя, Фамилия, Номер квартиры, Кол-во детей, Возраст"<<endl;
        cout << endl;
        typedef random<string,string,int,int,float> x;
        Stack<x> g;
        random<string,string,int,int,float> obj;
        init(g);
        obj = {"Валерий","Сидоров",28,89,5};push(g,obj);
        obj = {"Айбек","Гурбан",23,76,2};push(g,obj);
        for(int i = 0;i < g.nmen;i++)
        {
            pop(g,obj);
            show(obj);
        }
        cout << endl;
        cout <<"Шаблон очереди"<<endl;
        cout <<"Кол-во убитых, Звание, Кол-во ранений, Номер роты, Год рождения"<<endl;
        cout << endl;
        typedef random<int,string,int,int,float> k;
        Queue<k> v;
        initque(v);
        random<int,string,int,int,float> obj1;
        obj1 = {24,"Генерал",35,1990,56};equque(v,obj1);
        obj1 = {98,"Лейтенант",45,1993,23};equque(v,obj1);
        for(int i = 0;i < v.kmen;i++)
        {
            dequque(v,obj1);
            show(obj1);
        }
        cout << endl;
        cout <<"Шаблон динамического массива"<<endl;
        cout <<"Возраст, Имя, Фамилия, Кличка, Количество орехов"<<endl;
        cout << endl;
        typedef random<int,string,string,int,string> f;
        dinmassrandom<f> l;
        random<int,string,string,int,string> obj3;
        initdin(l);
        obj3 = {24,"Евгений","Бобров",45,"Смельчак"};push_back(l,obj3);
        obj3 = {27,"Александр","Синицин",135,"Легенда"};push_back(l,obj3);
        for(int i = 0;i < l.n;i++)
        {
            show(l.p[i]);
        }
        cout <<endl;
        cout <<"После удаления последнего элемента"<< endl;
        pop_back(l,obj3);
        for(int i = 0;i < l.n;i++)
        {
            show(l.p[i]);
        }
    return 0;
}
