#include <stdio.h>


int main(void) 
{
	int a,b,c;
    for(a=1;a<333;a++)
	{
	for(b=a+1;b<666;b++)
	{
	for(c=b+1;c<1000;c++)
	{
	 if(a*a+b*b==c*c
	   &&a+b+c<1000)
	 {
	  printf("%d %d %d\n",a,b,c);
	 }
	} 
	} 
	} 
	return 0;
}
