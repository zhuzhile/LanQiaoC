#include <stdio.h>


int main(void)
{
	char c;
	scanf("%c",&c);
	int n;
	int m;
	scanf("%d%d",&n,&m);
	switch(c)
	{
	 case '+':printf("%d",n+m);
	 break;
	 case '-':printf("%d",n-m);
	 break;
	 case '*':printf("%d",n*m);
	 break;
	 case '/':printf("%d",n/m);
	 break;
	}
	return 0;
}
