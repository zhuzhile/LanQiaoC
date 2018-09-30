#include <stdio.h>


int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i,count=0;
	for(i=0;i<n;i++)
	{
	 scanf("%d",&a[i]);
	 if(a[i]!=0)
	 {
	  count++;
	 }
	} 
	printf("%d\n",count);
    int k;
	for(k=0;k<n;k++)
	{
	 if(a[k]==0)
	 {
	  continue;
	 }
	 else{printf("%d ",a[k]);
	 }
	} 
	
	return 0;
}
