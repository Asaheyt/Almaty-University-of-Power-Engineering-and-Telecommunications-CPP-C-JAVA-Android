#include <iostream>
#include "gib.cpp"
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    base<int,string,string,int,string> obj;
    typedef base<int,string,string,int,string> f;
    Stack<f> R;
    init(R);
    obj = {1,"Евгений","Бобров",54,"Хирург"};push(R,obj);
    obj = {2,"Алекc","Джонсон",13,"Инженер"};push(R,obj);
    obj = {3,"Абылай","Абулхаиров",67,"Программист"};push(R,obj);
    showallstack(R,obj);

    Queue<f> S;
    initque(S);
    obj = {1,"Евгений","Бобров",54,"Хирург"};equque(S,obj);
    obj = {2,"Алекc","Джонсон",13,"Инженер"};equque(S,obj);
    obj = {3,"Абылай","Абулхаиров",67,"Программист"};equque(S,obj);
    showallqueue(S,obj);

    dinmass<f> l;
    initdin(l);
    obj = {1,"Евгений","Бобров",54,"Хирург"};Push_back(l,obj);
    obj = {2,"Алекc","Джонсон",13,"Инженер"};Push_back(l,obj);
    obj = {3,"Абылай","Абулхаиров",67,"Программист"};Push_back(l,obj);
    showalldinmas(l,obj);
    cout << endl;
    cout <<"Сортировка по 1 полю"<<endl;
    sorten(l,cmpnum0<f,f>);showalldinmas(l,obj);cout <<endl;
    cout <<"Сортировка по 2 полю"<<endl;
    sorten(l,cmpnum1<f,f>);showalldinmas(l,obj);cout <<endl;
    cout <<"Сортировка по 3 полю"<<endl;
    sorten(l,cmpnum2<f,f>);showalldinmas(l,obj);cout <<endl;
    cout <<"Сортировка по 4 полю"<<endl;
    sorten(l,cmpnum3<f,f>);showalldinmas(l,obj);cout <<endl;
    cout <<"Сортровка по 5 полю"<<endl;
    sorten(l,cmpnum4<f,f>);showalldinmas(l,obj);cout <<endl;
    return 0;
}
