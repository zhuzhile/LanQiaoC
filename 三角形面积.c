#include <stdio.h>
#include <math.h>

int main(void) 
{
    double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	double s;
	s=(a+b+c)/2;
	double jieguo; 
	jieguo=s*(s-a)*(s-b)*(s-c);
	printf("%.2lf",sqrt(jieguo));
	return 0;
}
