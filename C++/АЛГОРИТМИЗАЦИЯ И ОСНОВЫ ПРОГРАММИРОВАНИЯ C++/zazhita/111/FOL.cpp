#include "Fol.h"
#include <iostream>
#include "cstring"
#include <fstream>
using namespace std;
void Fill(Organizacia &y,Rabotnik &R)
{
    strcpy(R.Familiya,"Гордон");
    R.Dolzhnost="Механик";
    R.D1.day=20;R.D1.month=10;R.D1.year=2016;
    R.Srok=31;
    R.Oklad=400000;
    Add(y,R);

    strcpy(R.Familiya,"Пушкин");
    R.Dolzhnost="Инженер";
    R.D1.day=20;R.D1.month=9;R.D1.year=2016;
    R.Srok=40;
    R.Oklad=200000;
    Add(y,R);

    strcpy(R.Familiya,"Ердаулетов");
    R.Dolzhnost="IT";
    R.D1.day=2;R.D1.month=11;R.D1.year=2016;
    R.Srok=20;
    R.Oklad=4000000;
    Add(y,R);

    strcpy(R.Familiya,"Ли");
    R.Dolzhnost="Консультант";
    R.D1.day=6;R.D1.month=11;R.D1.year=2016;
    R.Srok=14;
    R.Oklad=100000;
    Add(y,R);

    strcpy(R.Familiya,"Хаджимэ");
    R.Dolzhnost="Хирург";
    R.D1.day=5;R.D1.month=11;R.D1.year=2016;
    R.Srok=44;
    R.Oklad=3000000;
    Add(y,R);
}
void Init(Organizacia &y)
{
    y.Kol1=0;
    y.Kol2=0;
}
void Add(Organizacia &y,Rabotnik R)
{
    y.e1[y.Kol1]=new Rabotnik;
    *(y.e1[y.Kol1])=R;
    y.Kol1++;
}
void Add2(Organizacia &y,Rabotnik R)
{
    y.e2[y.Kol2]=new Rabotnik;
    *(y.e2[y.Kol2])=R;
    y.Kol2++;
}
void ShowAll(Organizacia y)
{
    for(int i=0; i<y.Kol1; i++)
    {
        ShowOne(*(y.e1[i]));
    }
    cout<<endl;
}
void ShowAll2(Organizacia y)
{
    for(int i=0; i<y.Kol2; i++)
    {
        ShowOne(*(y.e2[i]));
    }
    cout<<endl;
}
void ShowOne(Rabotnik r)
{
    cout<<"Фамилия работника: "<<r.Familiya;
    cout<<" Должность: "<<r.Dolzhnost;
    cout<<" Дата подписания контракта: "<<r.D1.day<<"."<<r.D1.month<<"."<<r.D1.year;
    cout<<" Срок действия контракта: "<<r.Srok;
    cout<<" Оклад: "<<r.Oklad<<endl;

}
void Swapzn(Rabotnik &c,Rabotnik &v)
{
    Rabotnik t;
    t=c;
    c=v;
    v=t;
}
int SravnFam(Rabotnik c,Rabotnik v)
{
    int z;
    z=strcmp(c.Familiya,v.Familiya);
    return z;
}
int SravnDol(Rabotnik h,Rabotnik v)
{
    int w,x,z;
    string a,b,c,d,e,f,g;
    a="Консультант";
    b="Механик";
    c="Инженер";
    d="Хирург";
    e="IT";
    f=h.Dolzhnost;
    g=v.Dolzhnost;
    if(f==a){w=1;}
    if(f==b){w=2;}
    if(f==c){w=3;}
    if(f==d){w=4;}
    if(f==e){w=5;}

    if(g==a){x=1;}
    if(g==b){x=2;}
    if(g==c){x=3;}
    if(g==d){x=4;}
    if(g==e){x=5;}

    if(w>x){z=1;}
    if(x>w){z=-1;}
    if(w==x){z=-2;}
    return z;
}
int SravnData(Rabotnik c,Rabotnik v)
{
    int z;
    if(c.D1.year<v.D1.year){z=-1;}
    if(c.D1.year>v.D1.year){z=1;}
    if(c.D1.year==v.D1.year)
    {
        if(c.D1.month<v.D1.month){z=-2;}
        if(c.D1.month>v.D1.month){z=3;}
        if(c.D1.month==v.D1.month)
        {
            if(c.D1.day<v.D1.day){z=-3;}
            if(c.D1.day>v.D1.day){z=5;}
            if(c.D1.day==v.D1.day){z=-4;}
        }
    }
    return z;
}
int SravnSrok(Rabotnik c,Rabotnik v)
{
    int z;
    if(c.Srok<v.Srok){z=-1;}
    if(c.Srok>v.Srok){z=1;}
    if(c.Srok==v.Srok){z=-2;}
    return z;
}
int SravnOkl(Rabotnik c,Rabotnik v)
{
    int z;
    if(c.Oklad<v.Oklad){z=-1;}
    if(c.Oklad>v.Oklad){z=1;}
    if(c.Oklad==v.Oklad){z=-2;}
    return z;
}
void SortSt(Organizacia &y,int (*CmpSrav)(Rabotnik, Rabotnik))
{

    for(int i=0;i<y.Kol1-1;i++)
    {
        for(int j=i+1;j<y.Kol1;j++)
        {
            if(CmpSrav(*(y.e1[i]),*(y.e1[j]))>0){Swapzn(*(y.e1[i]),*(y.e1[j]));}
        }
    }
}
void Fileopread(ifstream &rfile,Rabotnik &R,Organizacia &y,string s)
{
    rfile.open(s.c_str());
    while(!rfile.eof())
    {
        rfile>>R.Familiya>>R.Dolzhnost>>R.D1.day>>R.D1.month>>R.D1.year>>R.Srok>>R.Oklad;
        Add2(y,R);
    }
    rfile.close();
}
void FileWrite(ofstream &wfile,Rabotnik &R,Organizacia y,string s)
{
    wfile.open(s.c_str());
    for(int i=0;i<y.Kol1;i++)
    {
        R=*(y.e1[i]);
        wfile<<R.Familiya<<" "<<R.Dolzhnost<<" "<<R.D1.day<<" "<<R.D1.month<<" "<<R.D1.year<<" "<<R.Srok<<" "<<R.Oklad;
        if(i<y.Kol1-1){wfile<<endl;}
    }
    wfile.close();
}
void Proverka(Organizacia y)
{
    int d;string sf1,sf2;
    for(int i=0;i<y.Kol1;i++)
    {
        sf1=y.e1[i]->Familiya;
        sf2=y.e2[i]->Familiya;
        if(sf1!=sf2){d=1;}
        if(y.e1[i]->Dolzhnost!=y.e2[i]->Dolzhnost){d=1;}
        if(y.e1[i]->D1.day!=y.e2[i]->D1.day){d=1;}
        if(y.e1[i]->D1.month!=y.e2[i]->D1.month){d=1;}
        if(y.e1[i]->D1.year!=y.e2[i]->D1.year){d=1;}
        if(y.e1[i]->Srok!=y.e2[i]->Srok){d=1;}
        if(y.e1[i]->Oklad!=y.e2[i]->Oklad){d=1;}
    }
    if(d==1){cout<<"Данные не верны."<<endl;}
    else{cout<<"Данные верны."<<endl;}
}
void Konec(Organizacia &y)
{
    for(int i=0; i<y.Kol1; i++)
    {
		delete y.e1[i];
	}
	for(int i=0; i<y.Kol2; i++)
    {
		delete y.e2[i];
	}
}
void SravMas(Organizacia &y,int (*CmpSrav)(Rabotnik, Rabotnik),int &d)
{
    for(int i=0;i<y.Kol1-1;i++)
    {
        for(int j=i+1;j<y.Kol1;j++)
        {
            if(CmpSrav(*(y.e1[i]),*(y.e1[j]))>0){d=1;}
        }
    }
}
void fillTod(Today &b)
{
    b.day=18;
    b.month=11;
    b.year=2016;
}
void showTod(Today b)
{
    cout<<b.day<<"."<<b.month<<"."<<b.year<<endl;
}
void res(Organizacia &y, Today w)
{
    setlocale(LC_ALL, "Russian");
    int g,h,k;
    for(int i=0;i<y.Kol2;i++)
    {
        opred(y,w,g,h,i);
        k=h+5;
        if(g>h&&g<=k)
        {
            ShowOne(*(y.e2[i]));
        }
    }
}
void opred(Organizacia y,Today w,int &o,int &p,int i)
{
    int a,b,c,d;
    a=y.e1[i]->D1.day;
    b=y.e1[i]->D1.month;
    c=y.e1[i]->D1.year;
    d=y.e1[i]->Srok;
    o=a+(b-1)*30+(c-1)*365+d;
    int f;
    f=b-1;
    if(f<=7&&f%2==0){o+=f/2;}
    if(f<=7&&f%2!=0){o+=f/2+1;}
    if(f>7){o+=f/2+1;}
    p=w.day+((w.month-1)*30)+((w.year-1)*365);
    int s;
    s=w.month-1;
    if(s<=7&&s%2==0){p+=s/2;}
    if(s<=7&&s%2!=0){p+=s/2+1;}
    if(s>7){p+=s/2+1;}
}
