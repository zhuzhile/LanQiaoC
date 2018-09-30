#include <stdio.h>
#include<math.h> 
int main(void) 
{
	double n;
	scanf("%lf",&n);
	int len; 
	len=(int)sqrt(n);
	printf("(%d,%d]",len,len+1);
	return 0;
}
