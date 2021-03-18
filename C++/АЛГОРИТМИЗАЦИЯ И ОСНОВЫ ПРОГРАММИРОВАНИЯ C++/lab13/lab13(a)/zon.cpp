#include "zon.h"
#include <iostream>
#include "cstring"
#include "stdio.h"
using namespace std;
void zp(Rabotnik &R,char *F,string D,int S,int O)
{
    strcpy(R.Familiya,F);
    R.Dolzhnost=D;
    R.Srok=S;
    R.Oklad=O;
}
void Init(Organizacia &y)
{
    y.kol=0;
}
void ShowOne(Rabotnik r)
{
    cout<<"Фамилия работника: "<<r.Familiya;
    cout<<" Должность: "<<r.Dolzhnost;
    cout<<" Срок действия контракта: "<<r.Srok;
    cout<<" Оклад: "<<r.Oklad<<endl;
}
void Push_back(Organizacia &y,Rabotnik R)
{
    Rabotnik *temp=new Rabotnik[y.kol+1];
    copy(y.R,y.R+y.kol,temp);
    delete y.R;
    y.R=new Rabotnik[y.kol+1];
    copy(temp,temp+y.kol,y.R);
    y.R[y.kol] = R;
    y.kol++;
    delete temp;
}
void Pop_back(Organizacia &y,Rabotnik &R)
{
    if(y.kol>0)
    {
        Rabotnik *temp=new Rabotnik[y.kol];
        copy(y.R,y.R+y.kol-1,temp);
        delete y.R;
        y.R=new Rabotnik[y.kol];
        copy(temp,temp+y.kol-1,y.R);
        y.kol--;
        delete temp;
    }
    else {cout<<"Массив пуст."<<endl;}
}
void Clear(Organizacia &y)
{
    delete[] y.R;
    y.kol=0;
}
void Show(Organizacia y)
{
    if(y.kol>0)
    {
        for(int i=0;i<y.kol;i++)
        {
            ShowOne(y.R[i]);
        }
    }
    else {cout<<"Массив пуст."<<endl;}
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

    for(int i=0;i<y.kol-1;i++)
    {
        for(int j=i+1;j<y.kol;j++)
        {
            if(CmpSrav(y.R[i],y.R[j])>0){Swapzn(y.R[i],y.R[j]);}
        }
    }
}
void MenuSort(Organizacia &y)
{
    int d;
    cout<<"Выберите вид сортировки(число):"<<endl;
    cout<<" (1)Сортировка по фамилии;"<<endl;
    cout<<" (2)Сортировка по должности;"<<endl;
    cout<<" (3)Сортировка по сроку;"<<endl;
    cout<<" (4)Сортировка по окладу."<<endl;
    cin>>d;
    if (cin.fail())
    {
		while(cin.fail())
		{
        cout<<"Неправильно, введите правильно: ";
        cin.clear();
        cin.ignore();
        _flushall();
        cin>>d;
        }
    }
    switch (d)
    {
        case 1:{CmpSrav a=SravnFam;SortSt(y,a);break;}
        case 2:{CmpSrav a=SravnDol;SortSt(y,a);break;}
        case 3:{CmpSrav a=SravnSrok;SortSt(y,a);break;}
        case 4:{CmpSrav a=SravnOkl;SortSt(y,a);break;}
        default:{cout<<"Не существует"<<endl;break;}
    }
}







