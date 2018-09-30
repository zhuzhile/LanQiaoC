#include <stdio.h>


int main(void) 
{
  char str[1]=" ";
  char c; 
  int count = 0;
  while((c=getchar())!='\n'&&c!=EOF)
  {
    if(c==str[0])
    {
	 count++;
	}
  }
  count++;
  printf("%d",count);
	
	return 0;
}
