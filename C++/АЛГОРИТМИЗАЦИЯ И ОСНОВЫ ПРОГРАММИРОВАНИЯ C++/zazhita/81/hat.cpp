#include "hat.h"
#include <iostream>
using namespace std;
void Fill(Disc *Muz, int N)
{
    Muz[0].Ispolnitel="Michael Jackson";
    Muz[0].Zhanr="Pop";
    Muz[0].NazAlbom="Favourite";
    Muz[0].Tirazh=1070090;

    Muz[1].Ispolnitel="Pizza";
    Muz[1].Zhanr="Pop";
    Muz[1].NazAlbom="Love";
    Muz[1].Tirazh=8700;

    Muz[2].Ispolnitel="AC/DC";
    Muz[2].Zhanr="Rock-n-Roll";
    Muz[2].NazAlbom="Let there be rock";
    Muz[2].Tirazh=2056080;

    Muz[3].Ispolnitel="Enigma";
    Muz[3].Zhanr="New age";
    Muz[3].NazAlbom="Voyage";
    Muz[3].Tirazh=9578;

    Muz[4].Ispolnitel="Bob Marley";
    Muz[4].Zhanr="Reggy";
    Muz[4].NazAlbom="African Herbsman";
    Muz[4].Tirazh=108700;

    Muz[5].Tirazh=1;
}
void ShowAll(Disc *Muz, int N)
{
    setlocale(LC_ALL,"Russian");
    for(int i=0; i<N; i++)
    {
        cout<<"Исполнитель:"<<Muz[i].Ispolnitel<<"  ";
        cout<<"Жанр:"<<Muz[i].Zhanr<<"  ";
        cout<<"Название альбома:"<<Muz[i].NazAlbom<<"  ";
        cout<<"Тираж:"<<Muz[i].Tirazh<<endl;
    }
}
void ShowOne(Disc *Muz, int j)
{
    setlocale(LC_ALL,"Russian");
    cout<<"Исполнитель:"<<Muz[j].Ispolnitel<<"  ";
    cout<<"Жанр:"<<Muz[j].Zhanr<<"  ";
    cout<<"Название альбома:"<<Muz[j].NazAlbom<<"  ";
    cout<<"Тираж:"<<Muz[j].Tirazh<<endl;
}
void Opred(Disc *Muz,int N,int &w)
{
    w=0;
    if(Muz[N].Tirazh>10000)
    {
        w=1;
    }
}
