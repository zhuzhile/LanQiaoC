#include <stdio.h>
#include <string.h>

int main(void) 
{
	char gs[180];
	scanf("%s",gs);
	int min=0;
	int len=strlen(gs);
	len--;
	while(len-->=min++)
	{
	 if(gs[len]!=gs[min])
	 {
	  printf("no!");
	  break;
	 }else{
	 	if(len-min==0)
	 	{
		printf("yes!");
		}
	    }
	}
	
	return 0;
}
