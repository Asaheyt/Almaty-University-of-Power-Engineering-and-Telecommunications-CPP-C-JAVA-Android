#include <iostream>
#include <cstdlib>
#include "hat.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    const int n=6;
    int w=0;
    Disc *a;
    a=new Disc[n];
    Fill(a,n);
    ShowAll(a,n);
    cout<<endl<<"Вывод данных о пластинках, тираж которых превышает 10000 экземпляров:"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        Opred(a,i,w);
        if(w==1){ShowOne(a,i);}
    }
    return 0;
}
