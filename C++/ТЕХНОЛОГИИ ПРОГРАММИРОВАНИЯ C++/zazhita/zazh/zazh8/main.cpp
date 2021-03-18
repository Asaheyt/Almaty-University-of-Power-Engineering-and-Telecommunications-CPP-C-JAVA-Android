#include <iostream>
#include <windows.h>
#include "dub.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Organization z("Microsoft"),x("Sony"),y("Nokia");
	RANDOM(z,3);
	RANDOM(x,3);
	RANDOM(y,4);
	cout<<"-----До слияния-----"<<endl;
	cout << endl << "Организация " << z.getName() << endl;
	z.show();cout<<endl;
	cout << endl << "Организация " << x.getName() << endl;
	x.show();cout<<endl;
    cout << endl << "Организация " << y.getName() << endl;
	y.show();cout<<endl;
	cout<<"-----После слияния-----"<<endl;
    sum(x,z,y);
    y.show();cout<<endl;
    cout<<"-----После сортировки(по имени)-----"<<endl;
    cmp a;
    a=cmpName;
    y.sorting(a);
    y.show();cout<<endl;
    cout<<"-----После удаления дубликатов(по имени)-----"<<endl;
    y.Del_Duplicate(a);
    y.show();cout<<endl;
    cout<<"-----Введите зар.плату, которую хотите удалить-----"<<endl;
    int f;
    cin>>f;
    cout<<"-----После удаления элемента(по зар.плате)-----"<<endl;
    y.Del_Wages(f);
    y.show();cout<<endl;
    cout<<"-----c(x+z)-----"<<endl;
    Organization c(x+z),v;
    c.show();cout<<endl;
    cout<<"-----v=c=x-----"<<endl;
    v=c=x;
    cout<<v<<endl;
    cout<<c<<endl;
    cout<<x<<endl;

	return 0;
}
