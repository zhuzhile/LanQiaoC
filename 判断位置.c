#include <stdio.h>
#include <string.h>

int main(void) 
{
	char str[180];
	gets(str);
    int len=strlen(str);
    int min=0;
    while(min<len)
    {
	 if(str[min]=='a'
	 ||str[min]=='e'
	 ||str[min]=='i'
	 ||str[min]=='o'
	 ||str[min]=='u')
	 {
	  min++;
	  printf("%d",min);
	  return 0;
	 }
	 min++;
	}
	if(min-len==0)
	{
	 printf("%d",0);
	}
	
	return 0;
}
