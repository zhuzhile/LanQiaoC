#include <stdio.h>
int bahws(unsigned );
int qiu_nx(unsigned);

int main(void) 
{
	int n,count=0;
	scanf("%d",&n);
	int a[6];
	for(a[0]=0;a[0]<10;a[0]++)
	{
	 for(a[1]=a[0]==0;a[1]<10;a[1]++)
	{
	 for(a[2]=0;a[2]<10;a[2]++)
	{
	 for(a[3]=0;a[3]<10;a[3]++)
	{
	 for(a[4]=0;a[4]<10;a[4]++)
	{
	 for(a[5]=0;a[5]<10;a[5]++)
	{
	 if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]==n)
	 {
	  if(bahws(a[0]*100000+a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5]*1))
	  {
	   printf("%d\n",a[0]*100000+a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5]*1);
	   count++;
	  } 
	 } 
	}
	}
	}
	}
	}
	}
    count == 0?printf("%d",-1):putchar('\n');
	return 0;
}

int bahws(unsigned n)
{
 return n==qiu_nx(n);
}

int qiu_nx(unsigned n)
{
  int m=0;
  do
  {
   m*=10;
   m+=n%10;
  }
  while((n/=10)!=0);
  return m;
}


