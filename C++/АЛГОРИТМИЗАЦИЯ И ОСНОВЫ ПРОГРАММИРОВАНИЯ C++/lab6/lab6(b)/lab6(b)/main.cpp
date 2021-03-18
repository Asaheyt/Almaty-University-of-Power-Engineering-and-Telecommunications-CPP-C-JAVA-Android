#include <iostream>
#include "cstdlib"
#include <sstream>
#include <bitset>
using namespace std;
int main()
{
	string s,s1;
	cin >> s;
	istringstream iss(s);
	int a;
	iss >> a;
	bitset<sizeof(a)> bset(a);
	s1 = bset.to_string();
	cout << s1 << endl;
	system("pause");
	return 0;
}
