#include <iostream>
#include <cstdlib>
#include "pr4.h"
using namespace std;
int zap(int *z, int n)
{
 for(int i=0;i<n;i=i+2)
    {
        z[i]=rand()%100;
		z[i + 1] = rand() % 100 * (-1);
	}
 return 0;
}

int showmas(int *z, int n)
{
	for(int i=0;i<n;i++)
    {
	
      cout<<z[i]<<" ";
	}
cout<<endl;
return 0;
}

int mass(int *a,int *b,int *d,int n)
{
  int k = 0;
 for(int i=0;i<n;i++)
    {
		if (a[i] < 0) { d[k] = a[i]; k++; }
		
 }
 for (int i = 0; i<n; i++)
 {
	 
	 if (b[i] < 0) { d[k] = b[i]; k++; }
 }
cout<<endl;


return 0;
}
