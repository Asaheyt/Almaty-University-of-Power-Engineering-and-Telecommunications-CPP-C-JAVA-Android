#include "zzh.h"
#include <iostream>
#include <string>
using namespace std;
int Emploee::count = 0;
Emploee::Emploee()
{
	count++;
	//cout << "Конструктор Emploee. Количество: " << count << endl;
};
Emploee::Emploee(float s, int w)
{
	count++;
	senioriy=s;
	wages = w;
	//cout << "Конструктор Emploee. Количество: " << count << endl;
}
Emploee::~Emploee()
{
	count--;
	//cout << "Деструктор Emploee. Количество: " << count << endl;
};
void Emploee::setSeniority(float s)
{
	senioriy = s;
}
void Emploee::setWages(int w)
{
	wages = w;
}
int Emploee::getWages() const
{
	return wages;
}
float Emploee::getSeniority() const
{
	return senioriy;
}
void Emploee::show()
{
	cout << "Стаж: " << senioriy << "  Заработная плата: " << wages;
}
void Emploee::input()
{
	cout << "Введите данные:" << endl;
    cout << "Стаж работы: ";
	while (!(cin >> senioriy) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите стаж работы: " << endl;
	}
	cout << "Заработная плата: ";
	while (!(cin >> wages) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите заработную плату: " << endl;
	}
}
Emploee Emploee::cmpWag(const Emploee& e)
{
    Emploee temp;
    if((*this).getWages()>=e.getWages()){temp=*this;}
    else{temp=e;}
    return temp;
}
Emploee Emploee::cmpSen(const Emploee& e)
{
    Emploee temp;
    if((*this).getSeniority()>=e.getSeniority()){temp=*this;}
    else{temp=e;}
    return temp;
}

GosSluzhazhi::GosSluzhazhi()
{
	//cout << "Конструктор GosSluzhazhi. Количество: " << count << endl;
};
GosSluzhazhi::GosSluzhazhi(float s, int w, int r, float sg) :Emploee(s, w)
{
	//cout << "Конструктор GosSluzhazhi. Количество: " << count << endl;
	rang = r;
	seniorityGos = sg;
}
GosSluzhazhi::~GosSluzhazhi()
{
	//cout << "Деструктор GosSluzhazhi. Количество: " << count << endl;
};
void GosSluzhazhi::setRang(int r)
{
	rang=r;
}
void GosSluzhazhi::setSenGos(float sg)
{
	seniorityGos=sg;
}
float GosSluzhazhi::getSenGos() const
{
	return seniorityGos;
}
int GosSluzhazhi::getRang() const
{
	return rang;
}
void GosSluzhazhi::input()
{
	Emploee::input();
	cout << "Ранг: ";
	while (!(cin >> rang) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите ранг: " << endl;
	}
	cout << "Стаж государственного служащего: ";
	while (!(cin >> seniorityGos) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите стаж государственного служащего: " << endl;
	}
}
void GosSluzhazhi::show()
{
	Emploee::show();
	cout << " Ранг: " << rang << "  Стаж государственного служащего: " << seniorityGos;
}
GosSluzhazhi GosSluzhazhi::cmpRang(const GosSluzhazhi& g)
{
    GosSluzhazhi temp;
    if((*this).getRang()>=g.getRang()){temp=*this;}
    else{temp=g;}
    return temp;
}
GosSluzhazhi GosSluzhazhi::cmpSenGos(const GosSluzhazhi& g)
{
    GosSluzhazhi temp;
    if((*this).getSenGos()>=g.getSenGos()){temp=*this;}
    else{temp=g;}
    return temp;
}
Ministr::Ministr()
{
	//cout << "Конструктор Ministr. Количество: " << count << endl;
};
Ministr::Ministr(float s, int w, int r, float sg, string k, int od) :GosSluzhazhi(s, w, r, sg)
{
	//cout << "Конструктор Ministr. Количество: " << count << endl;
	kategoriya=k;
	oborotDeneg = od;
}
Ministr::~Ministr()
{
	//cout << "Деструктор Ministr. Количество: " << count << endl;
};
void Ministr::setObDen(int od)
{
	oborotDeneg=od;
}
void Ministr::setKateg(string k)
{
	kategoriya=k;
}
int Ministr::getObDen() const
{
	return oborotDeneg;
}
string Ministr::getKateg() const
{
	return kategoriya;
}
void Ministr::input()
{
	GosSluzhazhi::input();
	cout << "Оборот денег:";
	while (!(cin >> oborotDeneg) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка!Введите оборот денег: " << endl;
	}
	cout << "Категория:";
    bool OK=false;
    while(!OK)
    {
        cin>>kategoriya;
        for(int j=0;j<kategoriya.length(); j++)
        {
            if((kategoriya[j]>='A'&&kategoriya[j]<='Z')||(kategoriya[j]>='a'&&kategoriya[j]<='z')||(kategoriya[j]>='А'&&kategoriya[j]<='Я')||(kategoriya[j]>='а'&&kategoriya[j]<='я'))
            {
                OK=true;
            }
            else{OK=false;break;}
        }
        if(OK==false){cout<<"Ошибка! Введите категорию: "<<endl;}
    }
}
void Ministr::show()
{
	GosSluzhazhi::show();
	cout << "  Категория: " << kategoriya << "  Оборот денег: " << oborotDeneg;
}
Ministr Ministr::cmpObDen(const Ministr& m)
{
    Ministr temp;
    if((*this).getObDen()>=m.getObDen()){temp=*this;}
    else{temp=m;}
    return temp;
}
Ministr Ministr::cmpKat(const Ministr& m)
{
    Ministr temp;
    if((*this).getKateg()>=m.getKateg()){temp=*this;}
    else{temp=m;}
    return temp;
}
