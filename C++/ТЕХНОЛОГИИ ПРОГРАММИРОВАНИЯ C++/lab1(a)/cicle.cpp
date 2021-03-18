#include "cicle.h"
#include <math.h>
float Arcsin(float x)
{
    int n=0;
	float a=x, result=x, eps=0.00001;
	while (fabs(a) >= eps)
    {
        a*=(x*x*(2*n+1)*(2*n+1)/(2*(n+1)*(2*n+3)));
		result+=a;
		n++;
	}
	return result;
}

float Ctg(float x)
{
	float sin=x, cos=1, cotan=0, a=1,eps=0.00001;
	int n=2;
	while (fabs(cos/sin-cotan)>eps)
	{
		cotan = cos/sin;
		a*=-x*x/((n-1)*n);
		cos+= a;
		sin+= a*x/(n+1);
		n+=2;
	}
	cotan = cos/sin;
	return cotan;
}

