#include <stdio.h>
void lianjie(char*,char*);

int mian(void)
{
  char *s;
  scanf("%s",s);
  char*s1;
  scanf("%s",s1);
  lianjie(s,s1);
  return 0;
}

void lianjie(char*s,char*s1)
{
 while(*s!=0)
 {
  s++;
 }
 while(*s=*s1)
 {
  if(*s1==0)
  {
   break;
  }
  s1++;
 }
 
}
	

