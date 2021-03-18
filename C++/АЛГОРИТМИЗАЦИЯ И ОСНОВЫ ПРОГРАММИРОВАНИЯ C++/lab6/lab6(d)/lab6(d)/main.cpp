#include <iostream>
#include <cstring>
#include "cstdio"
#include "cstdlib"
using namespace std;
int main()
{
	char x[100];
	char *max = NULL;
	gets(x);
	int i;
	char *t;
	t = strtok(x, " ");
	max = t;
	while (t != NULL)
	{
		if (strlen(t)>strlen(max))
			max = t;
		t = strtok(NULL, " ");
	}
	cout << "Max: " << max << "\n";
	system("pause");
	return 0;
}
