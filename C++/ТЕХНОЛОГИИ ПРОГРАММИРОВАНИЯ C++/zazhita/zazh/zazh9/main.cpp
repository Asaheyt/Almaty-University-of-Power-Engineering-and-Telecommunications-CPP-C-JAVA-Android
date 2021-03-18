#include <iostream>
#include <windows.h>
#include "rel.h"
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

int main()
{   srand(time(NULL));
	_wsetlocale(LC_CTYPE, L".1251");
	_wsetlocale(LC_CTYPE, L".866");

    wcout<< L"Áëà"<<endl;
	/*Organization_Mas v;
	v.RANDOM_Fill(7);
	Organization_Mas l(v);
	l.show();
	wcout << endl;
	cmp k;
	k = cmpName;
	v.Del_Duplicate(k);
	v.show();
	wcout << endl;
	v = l;
	k = cmpHomeNum;
	v.Del_Duplicate(k);
	v.show();
	v = l;
	wcout << endl;
	Organization *g;
	Organization_Ukaz a;
	g = &a;
	cnslCmd(g);*/
	return 0;
}
