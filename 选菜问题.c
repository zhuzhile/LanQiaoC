#include <stdio.h>


int main(void) 
{
	int a[4];
	int s[5]={0};
	int i; 
	for(i=0;i<4;i++)
	{
	 scanf("%d",&a[i]);
	}
	while(a[0]>0&&a[1]>0&&a[3]>0)
	{
	 a[0]-=2;
	 a[1]--;
	 a[3]--;
	 s[0]++;
	}
	while(a[0]>0&&a[1]>0&&a[3]>0&&a[2]>0)
	{
	 a[0]--;
	 a[1]--;
	 a[2]--;
	 a[3]--;
	 s[1]++;
	}
	while(a[2]>0&&a[3]>0)
	{
	 a[2]-=2;
	 a[3]--;
	 s[2]++;
	}
	while(a[1]>0)
	{
	 a[1]-=3;
	 s[3]++;
	}
	while(a[0]>0&&a[3]>0)
	{
	 a[0]--;
	 a[3]--;
	 s[4]++;
	}
	
	int k; 
	for(k=0;k<5;k++)
	{
	 printf("%d\n",s[k]);
	}
	return 0;
}
