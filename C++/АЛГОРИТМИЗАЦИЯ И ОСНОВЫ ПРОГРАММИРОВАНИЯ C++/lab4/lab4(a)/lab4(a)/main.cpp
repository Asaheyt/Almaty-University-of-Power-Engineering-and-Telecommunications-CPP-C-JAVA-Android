#include <iostream>
using namespace std;
int main()
{	
	const int n = 10;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    for(int i=0;i<n;i=i+2)
    {
        cout<<a[i]<<" ";
    }
	cout << endl;
    for(int i=1;i<n;i=i+2)
    {
        cout<<a[i]<<" ";
    }
	cout << endl;
	system("pause");
    return 0;
}