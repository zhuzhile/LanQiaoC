#include <stdio.h>
double qiu_jie(double,double);

int main(void) 
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%.2lf",qiu_jie(a,b));
	return 0;
}

double qiu_jie(double a,double b)
{
 return -b/a;
}
