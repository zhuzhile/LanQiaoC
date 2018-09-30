#include <stdio.h>
int qiu_gbs(int,int,int);
void shuchu(int);

int main(void) 
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int zx;
    zx=qiu_gbs(b,c,a);
	shuchu(zx);
	return 0;
}

int qiu_gbs(int a,int b,int c)
{
  int i; 
  for(i=a;i<=a*b*c;i++)
  {
   if(i%a==0&&i%b==0&&i%c==0)
   {
    break;
   }
  }
  return i;
}


void shuchu(int zx)
{
  printf("%d\n",zx);
}




