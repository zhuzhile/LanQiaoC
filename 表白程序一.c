#include<stdio.h> 
#include<string.h>  
#include<windows.h>  

int main(void) 
{  
char str[3];  
int count=0;
flag:printf("Do you love me?(yes/no)\n");
int flag=1;   
scanf("%s",str);
if(count>=2&&strcmp(str,"no")!=0&&strcmp(str,"NO")!=0)
{
  printf("I don't love you anymore\n");
  exit(0);
}
if(strcmp(str,"no")!=0&&strcmp(str,"NO")!=0&&count<2)  
{   
  printf("I love you,too\n");  exit(0);
} 
if(strcmp(str,"yes")!=0&&strcmp(str,"YES")!=0)  
{  
  count++;printf("ÇëÖØÐÂÊäÈë£¡£¡£¡\n");   
  printf("I will be waiting for you\n");  
  Sleep(200);  printf("\n");  
  printf("after a long time...\n");  
  goto flag;  
} 
return 0; 
}
