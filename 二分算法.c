#include <stdio.h>
#include <math.h>
#define  pi 3.1415926
double qiu_fcos(double);

int main(void) 
{   
    double x;
	scanf("%lf",&x);
	printf("%.5lf\n",qiu_fcos(x)); 
	return 0;
}

double qiu_fcos(double x)
{
   double lz=0.,rz=pi;//×ó½âÓëÓÒ½â 
   double yj=cos(rz)-x;
   double zz;
   while(zz = (lz+rz)/2.,rz-lz>1E-7)
   {
    if(yj*(cos(zz)-x)>0)
    {
	 rz=zz;
	}
	else
	{
	 lz=zz;
	}
   }
   return zz;
}
