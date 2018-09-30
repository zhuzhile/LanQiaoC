#include <stdio.h>
#include <math.h>
double qiu_hs(double);
int main(void) 
{
	double n;
	scanf("lf",&n);
	printf("%.5lf",qiu_hs(n));
	return 0;
}

double qiu_hs(double n)
{
  
  return fabs(cos(cos(n)));
}
