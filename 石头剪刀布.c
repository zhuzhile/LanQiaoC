#include <stdio.h>


int main(void) 
{
	int n,m;//0代表石头，1是布； 
	scanf("%d%d",&n,&m);
	if(n==m)
	{
	 printf("%d\n",0);//平局 
	}else{
	 if(n-m==1 || n-m == -2)
	 {
	  printf("%d\n",1);//前者赢 
	 }else
	 {
	 printf("%d\n",-1);//前者输 
	 }
	}
	
	return 0;
}
