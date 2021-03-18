#include "kmkz.h"
#include <iostream>
#include "cstring"
#include "windows.h"
#include <fstream>
using namespace std;
void zp(Rabotnik &R)
{
    cout<<"Введите данные:"<<endl;
    cout<<"Фамилия: ";
    cin>>R.Familiya;
    cout<<"Должность: ";
    cin>>R.Dolzhnost;
    cout<<"Дата:"<<endl;
    cout<<" День: ";
    cin>>R.D1.day;
    if (cin.fail()){
		while(cin.fail()){
			cout<<"Неправильно, введите правильно: ";
			cin.clear();
			cin.ignore();
			_flushall();
			cin>>R.D1.day;
		}
	}
    cout<<" Месяц: ";
    cin>>R.D1.month;
    if (cin.fail()){
		while(cin.fail()){
			cout<<"Неправильно, введите правильно: ";
			cin.clear();
			cin.ignore();
			_flushall();
			cin>>R.D1.month;
		}
	}
    cout<<" Год: ";
    cin>>R.D1.year;
    if (cin.fail()){
		while(cin.fail()){
			cout<<"Неправильно, введите правильно: ";
			cin.clear();
			cin.ignore();
			_flushall();
			cin>>R.D1.year;
		}
	}
    cout<<"Срок: ";
    cin>>R.Srok;
    if (cin.fail()){
		while(cin.fail()){
			cout<<"Неправильно, введите правильно: ";
			cin.clear();
			cin.ignore();
			_flushall();
			cin>>R.Srok;
		}
	}
    cout<<"Оклад: ";
    cin>>R.Oklad;
    if (cin.fail()){
		while(cin.fail()){
			cout<<"Неправильно, введите правильно: ";
			cin.clear();
			cin.ignore();
			_flushall();
			cin>>R.Oklad;
		}
	}
}
void Init(Organizacia &y)
{
    y.Kol1=0;
}
void Add(Organizacia &y,Rabotnik R)
{

    y.e1[y.Kol1]=new Rabotnik;
    *(y.e1[y.Kol1])=R;
    y.Kol1++;
}
void ShowAll(Organizacia y)
{
    cout<<"Название: "<<y.name<<endl;
    cout<<"Количество: "<<y.Kol1<<endl;
    for(int i=0; i<y.Kol1; i++)
    {
        ShowOne(*(y.e1[i]));
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
void MenuSort(Organizacia &y)
{
    int d;
    cout<<"Выберите вид сортировки(число):"<<endl;
    cout<<" (1)Сортировка по фамилии;"<<endl;
    cout<<" (2)Сортировка по должности;"<<endl;
    cout<<" (3)Сортировка по дате;"<<endl;
    cout<<" (4)Сортировка по сроку;"<<endl;
    cout<<" (5)Сортировка по окладу."<<endl;
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
        case 3:{CmpSrav a=SravnData;SortSt(y,a);break;}
        case 4:{CmpSrav a=SravnSrok;SortSt(y,a);break;}
        case 5:{CmpSrav a=SravnOkl;SortSt(y,a);break;}
        default:{cout<<"Не существует"<<endl;break;}
    }
}

//----------------------------------------------------------------------------------------------
void DelEl(ofstream &rfile,Rabotnik &R,Organizacia &y,string s)
{
    delete y.e1[y.Kol1];
    y.Kol1--;
    FileWrite(rfile,R,y,s);
}
void Fileopread(ifstream &rfile, Organizacia &y,string s)
{
    rfile.open(s.c_str());
    rfile>>y.name;
    while(!rfile.eof())
    {
        int k=y.Kol1;
        y.e1[k]=new Rabotnik;
        rfile>>y.e1[k]->Familiya>>y.e1[k]->Dolzhnost>>y.e1[k]->D1.day>>y.e1[k]->D1.month>>y.e1[k]->D1.year>>y.e1[k]->Srok>>y.e1[k]->Oklad;
        y.Kol1++;
    }

}
void FileWrite(ofstream &wfile,Rabotnik &R,Organizacia y,string s)
{
    wfile.open(s.c_str());
    wfile<<y.name;
    for(int i=0;i<y.Kol1;i++)
    {
        R=*(y.e1[i]);
        wfile<<endl<<R.Familiya<<" "<<R.Dolzhnost<<" "<<R.D1.day<<" "<<R.D1.month<<" "<<R.D1.year<<" "<<R.Srok<<" "<<R.Oklad;

    }
    wfile.close();
}
void FileAddEl(ofstream &wfile,Rabotnik &R,Organizacia &y,string s)
{
    wfile.open(s.c_str(),ios::app);
    zp(R);Add(y,R);
    wfile<<endl<<R.Familiya<<" "<<R.Dolzhnost<<" "<<R.D1.day<<" "<<R.D1.month<<" "<<R.D1.year<<" "<<R.Srok<<" "<<R.Oklad;
    wfile.close();
}
void FileClean(ofstream &file, Organizacia &y,string s)
{
        file.open(s.c_str(),ios::trunc);
        for (int i=0; i<y.Kol1; i++)
        {
            delete y.e1[i];
        }
        y.Kol1=0;
        y.name.erase();
        file.close();
}
void FileClean2(ofstream &file,string s)
{
        file.open(s.c_str(),ios::trunc);
        file.close();
}
void Close(ofstream &wfile,ifstream &rfile)
{
        wfile.close();
        rfile.close();
}
void New(ofstream &wfile,Organizacia &y,Rabotnik &R,string s)
{
    cout<<"Название Организации: ";
    cin>>y.name;
    zp(R);
    Add(y,R);
    FileWrite(wfile,R,y,s);
}
bool Empty(ifstream &rfile,string s)
{
    long Fsize;
    rfile.open(s.c_str());
    rfile.seekg(0,ios::end);
    Fsize=rfile.tellg();
    if(Fsize==0){return true;}
    rfile.close();
    return false;
}
