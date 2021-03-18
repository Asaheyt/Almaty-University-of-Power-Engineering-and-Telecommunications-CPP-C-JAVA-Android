#include <iostream>
#include "cstdlib"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 12;
	int a[n][n], r[n],s,c=0;
	for (int i = 0; i < n; i++)
	{
		cout << "Столбец №" << i + 1 << "\t";
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int j = 0; j < n; j++)
		{
			for (int p = j + 1; p < n; p++)
			{
				if (j!=p && a[i][j] == a[i][p])
				{
					s +=1;
					
				}
				
			}
		}
		cout << "Столбец №"<<i+1<<"  Число пар " << s << endl;
		r[i] = s;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (r[i]>r[c]){ c = i; }
	}
	cout <<"Столбец №"<< c+1 << endl;
	system("pause");
	return 0;
}