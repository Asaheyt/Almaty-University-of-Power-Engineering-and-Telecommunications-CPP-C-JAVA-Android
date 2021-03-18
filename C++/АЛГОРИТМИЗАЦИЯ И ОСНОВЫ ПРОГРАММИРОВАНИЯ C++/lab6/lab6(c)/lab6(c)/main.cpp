#include <iostream>
#include <cstring>
#include "cstdlib"
using namespace std;
int main()
{
	const int N = 100;
	char a[N];
	char c;
	cin >> a;
	cin >> c;
	for (int i = 0; i < strlen(a); ++i)
	{
		if (c == a[i])
		{
			for (int j = strlen(a) + 1; j > i; --j)
			{
				a[j] = a[j - 1];
			}
			a[i] = c;
			i++;
		}
	}
	cout << a <<endl;
	system("pause");
	return 0;
}