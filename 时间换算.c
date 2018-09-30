#include <stdio.h>

int main(void) 
{
	char c;
	while((c=getchar()) != '\n'&&c != EOF)
	{
	 int count=0;
	 if(c<='z'&&c>='a'||c<='Z'&&c>'A')
	 {
	  count ++;
	 }
	}
	printf("%d\n",count);
	return 0;
}
