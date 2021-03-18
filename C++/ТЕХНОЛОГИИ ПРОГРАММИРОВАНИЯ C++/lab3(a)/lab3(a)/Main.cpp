#include "legacy.h"
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
{
	Emploee x;
	x.setWages(100200);
	x.setName("Александр");
	x.show();cout << endl;

	Teacher y;
	y.setName("Ержан");
	y.setWages(200300);
	y.setSubject("Математика");
	y.setSeniority(3);
	y.show();cout << endl;

	Manager z("Арнольд", 300400, "Программирование", 10, "Высшее", 7), t;
	z.show();cout << endl;

	t.input();
	t.show();cout << endl;
}

	system("pause");
	return 0;
	
}