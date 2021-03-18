#include <string.h>
#include <iostream>
#include "cstdlib"
#include "ctype.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string s="LaboRAtorNaya РаБота";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]>='a'&&s[i]<='z')
		{ 
			s[i] = toupper(s[i]);
		}
		else if (s[i]>='A'&&s[i]<='Z')
		{ 
			s[i] = tolower(s[i]); 
		}
			
		else if (s[i] >= 'а'&&s[i] <= 'я')
		{
			s[i] = toupper(s[i]);
		}
		
		else if (s[i] >= 'А'&&s[i] <= 'Я')
		{
			s[i] = tolower(s[i]);
		}
		cout << s[i];
	}
	cout << endl;
	system("pause");
	return 0;
}