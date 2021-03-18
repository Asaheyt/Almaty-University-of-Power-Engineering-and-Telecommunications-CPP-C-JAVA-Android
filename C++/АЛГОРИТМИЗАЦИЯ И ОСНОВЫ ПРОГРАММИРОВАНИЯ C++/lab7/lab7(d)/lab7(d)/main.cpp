#include <string.h>
#include <iostream>
#include "cstdlib"
#include "cstdio"
#include <algorithm>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string s = "Ã»Õ»Ã”Ã Ã¿ —»Ã”Ã »Õƒ”—“–»ﬂ";
	char c;
	c = s[0];
	
		for (int i = 1; i < s.length(); i++)
		{
			
			if (s[i] == c){ s[i] = '.'; }
			if (s[i] == ' '){ i++; c = s[i]; }
		
		}
		for (int i = 0; i < s.length(); i++)
		{
			cout << s[i];
		}
		cout << endl;
		
		
	
	system("pause");
	return 0;
}