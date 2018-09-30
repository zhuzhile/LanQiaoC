#include <stdio.h>

void fjzys(int,int);

int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i = n;i <= m;i ++)
	{
	 printf("%d=",i);
	 fjzys(i , 2);
	 putchar('\n');
	}
	return 0;
}

void fjzys(int n,int yz)
{
  if(n % yz != 0)
  {
   fjzys(n,yz+1);
   return ; 
  }
  printf("%d",yz);
  if(n/yz!=1)
  {
    putchar('*');
    fjzys(n/yz,yz);
  }
}
