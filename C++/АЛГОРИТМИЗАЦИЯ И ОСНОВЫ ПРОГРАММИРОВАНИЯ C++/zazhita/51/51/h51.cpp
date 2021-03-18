#include "h51.h"
#include <iostream>
using namespace std;
void zap(int *mas, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			
			*(mas+i*M+j)=rand() % 100;
		}
	}
}
void show(int *mas, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << *(mas + i*M + j) << " ";
		}
		
	}
	cout << endl;
}
void umn(int *mas0,int *mas1, int *mas2, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			(*(mas2 + i*M + j)) = (*(mas0 + i*M + j))*(*(mas1 + i*M + j));
		}
	}
}
void sum(int *mas0, int *mas1, int *mas2, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			(*(mas2 + i*M + j)) = (*(mas0 + i*M + j))+(*(mas1 + i*M + j));
		}
	}
}