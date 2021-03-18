#include <iostream>
#include "ras.h"
using namespace std;

int main()
{
    Organizacia G;
    init(G);
    AddEl(G);
    AddEl(G);
    AddEl(G);
    ShowYONKO(G);
    cout<<endl;
    cout<<"Сортировка по зарплате:"<<endl;
    OtsortZar(G);
    ShowYONKO(G);
    cout<<endl;
    cout<<"Сортировка по часам:"<<endl;
    OtsortChas(G);
    ShowYONKO(G);
    cout<<endl;
    cout<<"Сортировка по рангу:"<<endl;
    OtsortRang(G);
    ShowYONKO(G);
    cout<<endl;
    cout<<"Сортировка по должности:"<<endl;
    OtsortDol(G);
    ShowYONKO(G);
    cout<<endl;
    cout<<"Сортировка по времени:"<<endl;
    OtsortVr(G);
    ShowYONKO(G);
    cout<<endl;
    cout<<"Удаление элемента:"<<endl;
    DelEl(G);
    ShowYONKO(G);
    cout<<endl;
    return 0;
}
