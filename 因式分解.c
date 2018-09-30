#include <stdio.h>

void shuchu(int ,int );
int main(void) 
{
	int n;
	scanf("%d",&n);
	shuchu(n,2);
	return 0;
}

void shuchu(int n,int yz )
{
 int n_=n; 
 printf("%d=",n_);
 if(n%yz!=0)
 {
 shuchu(n,yz+1);//如果n%yz不为零则不断调用直至所得数是素数为止 
 return ;
 }
 printf("%d=%d",n_,yz);
 if(n/yz!=1)
 {
  putchar('*');
  shuchu(n/yz,yz);
 } 
} 
