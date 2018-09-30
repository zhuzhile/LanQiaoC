/*
问题描述
　　快速排序是最经常使用的一种排序方式，对于给定的n个数组成的一个数组，请使用快速排序对其进行排序。
　　现给定一序列，请用快速排序将其按升序排序并输出。
输入格式
　　第一行一个数N。
　　第2~N+1行每行一个数，表示给定序列。
输出格式
　　共N行，每行一个数，表示所求序列。
样例输入
5
1
4
2
3
4
样例输出
1
2
3
4
4
数据规模和约定
　　共10组数据。
　　对100%的数据，N<=10^5，所有数均为非负数且在int范围内。
 
*/
#if 0
#include <stdio.h>

void jiaohuan(int*,int*);
int q_zd(int*,int,int);
void selcect(int*,int);
void shuru(int*,int);
void shuchu(int*,int);
 
int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	shuru(a,n);
	selcect(a,n);
	return 0;
}

void shuru(int * a,int n)
{ 
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  
}

void selcect(int * a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   int xb=q_zd(a,i,n);
   if(xb!=i)
   {
    jiaohuan(a+xb,a+i);
   }
   printf("swap(a[%d], a[%d]):",i,xb);
   shuchu(a,n);
  }
}

void jiaohuan(int* a,int* b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp ;
}

int q_zd(int *a ,int i,int n)
{
  int k,xb;
  int zx=a[i];
  xb=i;
  for(k=i+1;k<n;k++)
  {
   if(zx>a[k])
   {
	zx=a[k];
	xb=k;
   }
  }
  return xb;
}


void shuchu(int * a,int n)
{ 
  int i;
  for(i=0;i<n;i++)
  {
   printf("%d ",a[i]);
  }
  putchar('\n');
}
#endif

/*
问题描述
　　设x(i), y(i), z(i)表示单个字符，则X={x(1)x(2)……x(m)}，Y={y(1)y(2)……y(n)}，Z={z(1)z(2)……z(k)},我们称其为字符序列，其
    中m,n和k分别是字符序列X，Y，Z的长度，括号()中的数字被称作字符序列的下标。
　　如果存在一个严格递增而且长度大于0的下标序列{i1,i2……ik}，使得对所有的j=1,2,……k，
    有x(ij)=z(j)，那么我们称Z是X的字符子序列。而且，如果Z既是X的字符子序列又是Y的字符子序列，
	那么我们称Z为X和Y的公共字符序列。
　　在我们今天的问题中，我们希望计算两个给定字符序列X和Y的最大长度的公共字符序列，
   这里我们只要求输出这个最大长度公共子序列对应的长度值。
　　举例来说，字符序列X=abcd，Y=acde，那么它们的最大长度为3，
   相应的公共字符序列为acd。
输入格式
　　输入一行，用空格隔开的两个字符串
输出格式
　　输出这两个字符序列对应的最大长度公共字符序列的长度值
样例输入
aAbB aabb
样例输出
2
数据规模和约定
　　输入字符串长度最长为100，区分大小写。
*/

#include<stdio.h>
#include<string.h>

int q_xt(char*,char*);

int main(void)
{
 char s[180];
 char str[180];
 gets(s);
 gets(str);
 printf("%d\n",q_xt(s,str));
 return 0;
}

int q_xt(char*s,char*str)
{
 if(*s==0)
 {
 return 0;
 }
 if(*s==*str)
 {
  return 1;
 }
 return q_xt(s+1,str)+q_xt(s,str+1); 
}

//int count=0;
// int len=strlen(s);
// int len1=strlen(str);
// int i;
// for(i=0;i<len;i++)
// {
//  int k;
//  for(k=0;k<len1;k++)
// {
//   if(s[i]==str[k])
//   {
//    count++;
//    break;
//   }
// }
// }



