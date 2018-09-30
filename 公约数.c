#include <stdio.h>
int qiu_zdys(int,int);

int main(void)
{
	int n;
	int m;
	scanf("%d%d",&n,&m);
	printf("%d\n",qiu_zdys(n,m)); 
	return 0;
}

int qiu_zdys(int n,int m)
{
  int i;
  for(i=n;i>0;i--)
  {
   if(m%i==0&&n%i==0)
   {
    break;
   }
  }
  return i; 
}

