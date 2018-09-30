#include <stdio.h>
void jiaohuan(int * ,int *);

int main(void) 
{
	int n;
	int a[n];//只能在c99中使用 
	scanf("%d",&n);
	int m;
	for(m=0;m<n;m++)
	{
	 scanf("%d",&a[m]);
	}
	int k,i;
	for(k=1;k<n;k++)
	{
	 for(i=0;i<n-k;i++)
	{
	 if(a[i]<a[i+1])
	 {
	  jiaohuan(&a[i],&a[i+1]);
	 }
	}
   }  
	 int j;
	 for(j=0;j<10;j++)
	 {
	 printf("%d ",a[j]);
	 }
	return 0;
}


void jiaohuan(int * a,int * b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
