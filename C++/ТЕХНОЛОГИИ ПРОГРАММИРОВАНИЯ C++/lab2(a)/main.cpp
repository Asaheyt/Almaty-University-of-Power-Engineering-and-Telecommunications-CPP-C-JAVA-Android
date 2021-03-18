#include <iostream>
#include "clinc.h"
#include <cstring>
using namespace std;
int main()
{
    setlocale(LC_ALL,"Russian");
    Tank x;
    x.set_model("Армада");
    x.set_year(2006);
    cout<<endl;
    x.show();
    cout<<endl;
    {Tank z1, z2, z3, z4, z5;}
    cout<<endl;
    Tank q("T_34",1944);
    cout<<endl;
    cout<<q.get_model()<<endl;
    cout<<q.get_year()<<endl;
    cout<<endl;
    Tank *p;
    p=&q;
    p->show();
    return 0;
}
