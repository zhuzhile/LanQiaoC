#include <stdio.h>

int main() 
{
	FILE*p=fopen("d:\\a","w");
	fputs("hello wrold",p);
	printf("end");
	fclose(p);
	
	return 0;
}
