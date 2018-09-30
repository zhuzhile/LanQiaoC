/*
问题描述
　　判断给定的三位数是否 水仙花 数。所谓 水仙花 数是指其值等于它本身 每位数字立方和的数。例 153 就是一个 水仙花 数。 153=13+53+33
输入格式
　　一个整数。
输出格式
　　是水仙花数,输出"YES",否则输出"NO"(不包括引号)
样例输入
123
样例输出
NO
数据规模和约定
　　一个三位的整数,否则输出"NO"
*/
#if 0
#include <stdio.h>

int pdsxhs(int);
int q_cf(int);

int main(void) 
{
	int n;
	scanf("%d",&n);
	printf("%s",pdsxhs(n)==n?"YES":"NO");
	return 0;
}

int pdsxhs(int n)
{
  int he=0;
  if(n) 
  {
  he=q_cf(n%10);
  return he+pdsxhs(n/10) ; 
  }
  return he;
}

int q_cf(int n)
{
  return n*n*n;
}
#endif
/*
　自己实现一个比较字符串大小的函数，也即实现strcmp函数。函数：int myStrcmp(char *s1,char *s2) 
按照ASCII顺序比较字符串s1与s2。若s1与s2相等返回0，s1>s2返回1，s1<s2返回-1。具体来说，
两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直
到出现不同的字符或遇'\0'为止（注意'\0'值为0，小于任意ASCII字符）。
 如：
　　"A"<"B"
　　"a">"A"
　　"computer">"compare"
　　"hello"<"helloworld"
样例输出

数据规模和约定
　　字符串长度<100。
 

*/
#if 1
#include<stdio.h>

int compare(char*,char*);

int main (void)
{
 char s0[100];
 char s1[100];
 gets(s0);
 gets(s1);
 printf("%d",compare(s0,s1));
 return 0;
}

int compare(char*s0,char*s1)
{
	if(*s0>*s1)
	{
	 return 1;
	}
	if(*s0<*s1)
	{
	 return -1;
	}
	if(*s0==*s1)
	{
	 return 0;
	}
   return compare(s0+1,s1+1);
}
#endif
