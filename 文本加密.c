#include <stdio.h> 

int main(void) 
{
	char str[180];
	int len=0;
	scanf("%s",str);
	while(str[len++]);
	len--;
   //	printf("%d",len);
   if(str[len]<'a')
	while(--len>=0)
	{
	if(str[len]<'A'||str[len]>'z'||str[len]<'a'&&str[len]>'Z')
	{
	 continue;
	}
	if(str[len]=='z')
	{
	 str[len]='A';
	}else{if(str[len]=='Z')
    {
	 str[len]='a';
	}else{str[len]++;
	}
	}
	}
	puts(str);
	return 0;
}
