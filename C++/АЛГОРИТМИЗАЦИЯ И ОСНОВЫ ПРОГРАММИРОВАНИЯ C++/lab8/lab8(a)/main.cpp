#include <iostream>
using namespace std;
struct Tovar
    {
        string name;
        int kolichestvo;
        float cena;
        string kachestvo ;
        int god;
    };
int main()
{

    setlocale(LC_ALL,"Russian");

    Tovar a1={"DELL",1,150000,"Среднее",2016};
    cout<<a1.name<<endl;
    cout<<a1.kolichestvo<<endl;
    cout<<a1.cena<<endl;
    cout<<a1.kachestvo<<endl;
    cout<<a1.god<<endl;
    cout<<endl;

    Tovar a2={"ASUS",1,200000,"Высшее",2016};
    cout<<a2.name<<endl;
    cout<<a2.kolichestvo<<endl;
    cout<<a2.cena<<endl;
    cout<<a2.kachestvo<<endl;
    cout<<a2.god<<endl;
    cout<<endl;

    Tovar a3={"Apple",1,300000,"Высшее",2016};;
    cout<<a3.name<<endl;
    cout<<a3.kolichestvo<<endl;
    cout<<a3.cena<<endl;
    cout<<a3.kachestvo<<endl;
    cout<<a3.god<<endl;
    cout<<endl;

if(a1.cena<a2.cena&&a1.cena<a3.cena)cout<<"Самый дешевый товар:"<< a1.name<<endl;
if(a2.cena<a1.cena&&a2.cena<a3.cena)cout<<"Самый дешевый товар:"<< a2.name<<endl;
if(a3.cena<a1.cena&&a3.cena<a2.cena)cout<<"Самый дешевый товар:"<< a3.name<<endl;
    return 0;
}
