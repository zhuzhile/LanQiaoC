//为库设计新函数DelPack，删除输入字符串中所有的重复元素。不连续的重复元素也要删除。
//　　要求写成函数，函数内部使用指针操作。
//样例输入
//1223445667889
//样例输出
//13579
//样例输入
//else
//样例输出
//ls
//数据规模和约定
//　　字符串数组最大长度为100。

#include <stdio.h>
#include <string.h>
void pdxd(char [],int);
void shuchu(char[],int);

int main(void) 
{
	char str[180];
	gets(str);
	int len=strlen(str);
	pdxd(str,len);
	shuchu(str,len);
	return 0;
}

void pdxd(char  str[],int len)
{
 int i; 
 for(i=0;i<len;i++)
 {
  int k;
  for(k=len-1;k>i;k--)
  {
   if(str[i]==str[k])//不适用于三个重复的数； 
   {
    str[i]=0;
    str[k]=0;
   }
  }
 }
}

void shuchu(char str[],int len)
{
  int i;
  for(i=0;i<len;i++)
  {
   if(str[i]!=0)
   {
    printf("%c",str[i]);
   }
  }

}


