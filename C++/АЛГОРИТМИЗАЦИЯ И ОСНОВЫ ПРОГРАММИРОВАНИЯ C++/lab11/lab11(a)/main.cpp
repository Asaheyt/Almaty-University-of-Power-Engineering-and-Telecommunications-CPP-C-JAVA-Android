#include <iostream>
#include <cstdlib>
#include "kmkz.h"
#include "windows.h"
#include "fstream"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream rfile;
    ofstream wfile;
    string name1="l1.txt";
    string name2="l2.txt";
    Organizacia y;
    Rabotnik R;
    Init(y);
    string f;
    while(f!="exit")
    {
        cout<<"Введите команду"<<endl;
        cin>>f;
        if(f=="read"){if(!Empty(rfile,name1)){Fileopread(rfile,y,name1);cout<<"Файл прочитан"<<endl; }else{cout<<"Файл пуст.Заполните новыми значениями"<<endl;}}
        else if(f=="show")  {if(y.Kol1!=0){ShowAll(y);}else{cout<<"Нет данных"<<endl;}}
        else if(f=="add") {if(rfile.is_open()){FileAddEl(wfile,R,y,name1);}else{cout<<"Считайте данные с файла"<<endl;}}
        else if(f=="delete") {if(rfile.is_open()){DelEl(wfile,R,y,name1);cout<<"Работник удален"<<endl;}else{cout<<"Считайте данные с файла"<<endl;}}
        else if(f=="sort")  {MenuSort(y);}
        else if(f=="save") {cout<<"Данные сохранение"<<endl;  FileWrite(wfile,R,y,name2);}
        else if(f=="clear1"){cout<<"Clear1"<<endl;FileClean(wfile,y,name1);}
        else if(f=="clear2"){cout<<"Clear2"<<endl;FileClean2(wfile,name2);}
        else if(f=="erase") {system("cls");}
        else if(f=="new"){cout<<"New"<<endl;New(wfile,y,R,name1);}
        else if(f=="exit") {Close(wfile,rfile);}
        else if(f=="help")
            {
                cout<<endl;
                cout<<"read -- Считывать из файла"<<endl;
                cout<<"show -- Показ вывода"<<endl;
                cout<<"add -- Добавить работника в организацию"<<endl;
                cout<<"delete -- Удалить последнего работника из организации"<<endl;
                cout<<"sort -- Открыть меню сортирования"<<endl;
                cout<<"save -- Сохранить данные в файл№2"<<endl;
                cout<<"clear1 --Очистить файл№1"<<endl;
                cout<<"clear2 -- Очистить файл№2"<<endl;
                cout<<"erase -- Очистить консоль"<<endl;
                cout<<"new -- Создать новую Организацию"<<endl;
                cout<<"exit -- Выход(Закрытие файла)"<<endl;
                cout<<endl;
            }
        else{cout<<"Введите  help  для списка команд"<<endl;}
    }
    for(int i=0; i<y.Kol1; i++)
    {
		delete y.e1[i];
	}
    return 0;
}
