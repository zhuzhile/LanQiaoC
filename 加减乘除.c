#include <stdio.h>


int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
	char fuhao='+';
	switch(fuhao)
	{
	 case '+':printf("%d+%d=%d\n",n,m,n+m);
	 case '-':printf("%d-%d=%d\n",n,m,n-m);
     case '*':printf("%d*%d=%d\n",n,m,n*m);
	 case '/':printf("%d/%d=%d\n",n,m,n/m); 
	}
	return 0;
}
