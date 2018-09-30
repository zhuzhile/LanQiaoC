#include <stdio.h>
void jiaohuan(int * ,int *);
void paxiu(int ,int *);
void shuru(int,int *);
void shuchu(int,int *); 

int main(void) 
{
	int n;
	int a[n];//只能在c99中使用 
	scanf("%d",&n);
	shuru(n,a);
	paxiu(n,a);
	shuchu(10,a);
	return 0;
}

void paxiu(int n,int * a)
{
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
}

void jiaohuan(int * a,int * b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

void shuru(int n,int * a)
{
    int m;
	for(m=0;m<n;m++)
	{
	 scanf("%d",&a[m]);
	}

}


void shuchu(int n,int * a)
{
    int m;
	for(m=0;m<n;m++)
	{
	 printf("%d ",a[m]);
	}

}




