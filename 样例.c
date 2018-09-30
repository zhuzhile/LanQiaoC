#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char name[10]={"maybe"};
	char p[20];
	strcpy(p,name);
	printf("将name字符串的东西赋值给p\n");
	printf("p=");
	puts(p);
	return 0;
}
