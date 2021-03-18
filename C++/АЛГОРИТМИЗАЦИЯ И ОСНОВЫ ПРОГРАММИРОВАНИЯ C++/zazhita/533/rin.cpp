#include <iostream>
#include <cstdlib>
#include "rin.h"
using namespace std;

void fillmass(int *mas, int n, int m)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			*(mas + i*m + j) = rand() % 10;
		}
	}
}
void showmass(int *mas, int n, int m)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			cout << *(mas + i*m + j) << "  ";

		}
		cout << endl;
	}
}
int sum(int *mas, int m, int q)
{
	int k=0;
	for (int j = 0; j<m; j++)
    {
        k+=*(mas + q*m + j);
    }
    return k;
}
void erasRow(int *mas, int n, int m, int q)
{

    for (int y = q; y<n; y++)
    {
        for (int x = 0; x<m; x++)
        {
            *(mas + y*m + x) = *(mas + (y+1)*m + x);
        }
    }
}
void geer(int *mas, int &n, int m)
{
    int l;
	for (int i = 0; i<n; i++)
	{
        l=sum(mas,m,i);
		if (l<20)
		{
			erasRow(mas,n,m,i);
			i--;n--;
		}
	}
}
