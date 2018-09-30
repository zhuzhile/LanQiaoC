#include <stdio.h>
#include<math.h>
int main(void) 
{
	double n;
	scanf("%lf",&n); 
	int  i;
	for(i=0;i<(int)n ;i++)
	{
	 if(i*i<(int)n&&(i+1)*(i+1)>=(int)n)
	 {
	  printf("(%d,%d]",i,i+1);
	  break; 
	 }
	} 
	
	return 0;
}
