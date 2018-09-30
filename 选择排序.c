#include <stdio.h>
void jiaohuan(int * ,int *);
void paxiu(int ,int *);
void shuru(int,int *);
void shuchu(int,int *); 
int qiu_zd(int,int*,int);

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];//只能在c99中使用 
	shuru(n,a);
	int low;
	paxiu(n,a);
	shuchu(10,a);
	return 0;
}
void paxiu(int n,int * a)
{
  int low;
  for(low=0;low<n;low++)
  {
  	int j;
    j = qiu_zd(n,a,low);
   if(low != j )
   {
    jiaohuan(&a[low],&a[j]);
   }
  }
} 

int qiu_zd(int n,int * a, int low)
{
    int zd=a[low];
    int i;
    for(i=low+1;i<n;i++)
    {
	  if(zd<a[i])
	  {
	   low=i;
	   zd=a[low];
	  }
	}
	return low;
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




