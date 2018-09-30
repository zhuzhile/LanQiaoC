//(1)圆面积，(2)球体表面积，(3)球体体积
#include <stdio.h>
#define PI 3.1415926536
int main(void) 
{
	double i;
	scanf("%lf\n",&i);
	printf("%.10lf %.10lf %.10lf\n",PI*i*i,4*PI*i*i,4./3.*PI*i*i*i);
	return 0;
}
