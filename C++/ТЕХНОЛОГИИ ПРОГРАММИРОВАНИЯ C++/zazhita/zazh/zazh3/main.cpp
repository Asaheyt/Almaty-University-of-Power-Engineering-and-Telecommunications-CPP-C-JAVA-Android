#include "zzh.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
{
	Emploee x; x.setWages(100200); x.setSeniority(3.5);
	x.show();cout << endl;

	GosSluzhazhi y; y.setSeniority(4); y.setWages(200300); y.setRang(6); y.setSenGos(3);
	y.show();cout << endl;

	Ministr z(5.5, 300400, 7, 5, "Младший", 5000000), t, w(6.7, 500100, 7, 3, "Отраслевой",6000000), q;
	cout<<"Сравнение оборота денег двух министров"<<endl;
	z.show();cout << endl<<endl;
	w.show();cout << endl<<endl;
    cout<<"Вывод"<<endl;
	q=z.cmpObDen(w);
	q.show();cout<<endl;

	t.input();
	t.show();cout << endl;


}
	return 0;

}
