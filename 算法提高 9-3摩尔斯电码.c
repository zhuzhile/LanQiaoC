/*

问题描述
　　摩尔斯电码破译。类似于乔林教材第213页的例6.5，要求输入摩尔斯码，返回英文。请不要使用"zylib.h"，
   只能使用标准库函数。用' * '表示' . '，中间空格用' | '表示，只转化字符表。

　　摩尔斯码定义见：http://baike.baidu.com/view/84585.htm?fromId=253988。

提示
　　清橙进行评测时，输入是以EOF结尾的，而不是换行符。（EOF不是一个字符，“以EOF结尾”
   是一种通俗但不严谨的说法。）因此可以通过以下方式之一获取输入：

　　1. 一次读入整行字符串，再进行后续解析。

　　2. 使用getchar或scanf一次读入一个字符，通过它们的返回值判断输入结束。
样例输出

*/
#include<stdio.h>  
#include<string.h>
#include<time.h> 
#define zd 10000
void compare(char*);
void output_password(char*);

int main(void)  
{  
    char s[zd];        
    scanf("%s",s);  
    output_password(s);
    printf("%.2lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;  
} 

void output_password(char * p)
{
	char str[10];
	int i=0;
    while(*p)  
    {  
        if(*p=='|')  
        {  
            str[i]='\0';  
            compare(str);  
            i=0;  
        }  
        else  
        {  
            str[i++]=*p;  
        }  
        p++;  
    }  
    str[i]='\0';  
    compare(str);  
    putchar('\n');   

}

void compare(char str[])  
{  
    if(strcmp(str,"*-")==0) 
	{
	 printf("a");
	}
	   
    if(strcmp(str,"-***")==0)
	{
	  printf("b");
	} 
	   
    if(strcmp(str,"-*-*")==0)
	{
	 printf("c");
	} 
	   
    if(strcmp(str,"-**")==0)
	{
	  printf("d");
	}
	    
    if(strcmp(str,"*")==0)
	{
	  printf("e");
	} 
	 
    if(strcmp(str,"**-*")==0)
	{
	  printf("f");
	} 
	   
    if(strcmp(str,"--*")==0)
	{
	  printf("g");
	}
	    
    if(strcmp(str,"****")==0)
	{
	 printf("h");
	}
	  
    if(strcmp(str,"**")==0)
	{
	  printf("i");
	} 
	   
    if(strcmp(str,"*---")==0)
	{
	 printf("j");
	} 
	   
    if(strcmp(str,"-*-")==0)
	{
	   printf("k");
	} 
	   
    if(strcmp(str,"*-**")==0)
	{
	  printf("l");
	}
	   
    if(strcmp(str,"--")==0)
	{
	  printf("m");
	}  
         
    if(strcmp(str,"-*")==0)
	{
	  printf("n");
	}  
          
    if(strcmp(str,"---")==0)
	{
	  printf("o");
	}  
          
    if(strcmp(str,"*--*")==0)
	{
	  printf("p");
	}  
         
    if(strcmp(str,"--*-")==0)
	{
	  printf("q");
	}  
          
    if(strcmp(str,"*-*")==0)
	{
	   printf("r");
	}  
        
    if(strcmp(str,"***")==0)
	{
	  printf("s");
	}  
          
    if(strcmp(str,"-")==0) 
	{
	  printf("t");
	} 
         
    if(strcmp(str,"**-")==0)
	{
	   printf("u");
	}  
         
    if(strcmp(str,"***-")==0) 
	{
	 printf("v");
	} 
          
    if(strcmp(str,"*--")==0)
	{
	 printf("w");
	}  
          
    if(strcmp(str,"-**-")==0)
	{
	  printf("x");
	}  
         
    if(strcmp(str,"-*--")==0)
	{
	 printf("y");
	}  
          
    if(strcmp(str,"--**")==0) 
	{
	   printf("z");
	} 
        
}    
