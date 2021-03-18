#include <iostream>
#include <cstdlib>

using namespace std;

void fillmass(int *mas, int n, int m)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			*(mas + i*m + j) = rand() % 100-50;
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
void geer(int *mas, int &n, int m)
{
	int k,l=m*2;
	for (int i = 0; i<n; i++)
	{
		k = 0;
		for (int j = 0; j<m; j++)
		{
			if ((*(mas + i*m + j)) < 0){ k++; }

		}
		if (k<3)
		{
			for (int y = i; y<n; y++)
			{
				for (int x = 0; x<m; x++)
				{
					*(mas + y*m + x) = *(mas + (y+1)*m + x);

				}
			}
			i--; n--;
		}
	}
}