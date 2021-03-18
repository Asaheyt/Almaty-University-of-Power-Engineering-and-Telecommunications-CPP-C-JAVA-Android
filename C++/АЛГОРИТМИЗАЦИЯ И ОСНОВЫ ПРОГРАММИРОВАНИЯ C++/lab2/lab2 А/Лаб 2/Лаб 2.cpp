
#include "stdafx.h"
#include "iostream"
#include "cstdlib"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	setlocale(LC_ALL, "Russian");

	cout << "¬ведите номер мес€ца :\t";
	cin >> a;
	
	switch (a)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: cout << "¬ этом мес€це 31 день" << endl; break;
	case 4: case 6: case 9: case 11: cout << "¬ этом мес€це 30 дней" << endl; break;
	case 2: cout << "¬ этом мес€це 28 дней" << endl; break;
	default: cout << "“акого мес€ца не существует" << endl;
	}

	system("pause");
	return 0;
}

