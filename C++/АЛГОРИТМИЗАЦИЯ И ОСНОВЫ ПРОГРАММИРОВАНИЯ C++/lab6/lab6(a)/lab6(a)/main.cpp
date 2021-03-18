#include <iostream>
#include "cstdlib"
#include "cstring"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russuan");
	int n = 3;
	char s[] = "abcdefghijfj";
	cout << s << endl;
	for (int i = 0; i < strlen(s) ; ++i)
	{
		if (i == strlen(s)-1)
		{
			cout << s[i];
		}
		else
		{
			cout << s[i];
			for (int j = 0; j < n; j++)
			{
				cout << "*";
			}
		}
	}
	cout << endl;
	system ("pause");
	return 0;
}