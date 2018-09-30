/*

问题描述
　　从一个大小为n的整数集中选取一些元素，使得它们的和等于给定的值T。每个元素限选一次，不能一个都不选。
输入格式
　　第一行一个正整数n，表示整数集内元素的个数。
　　第二行n个整数，用空格隔开。
　　第三行一个整数T，表示要达到的和。
输出格式
　　输出有若干行，每行输出一组解，即所选取的数字，按照输入中的顺序排列。
　　若有多组解，优先输出不包含第n个整数的；若都包含或都不包含，优先输出不包含第n-1个整数的，依次类推。
　　最后一行输出总方案数。
样例输入
5
-7 -3 -2 5 9
0

样例输出
-3 -2 5
-7 -2 9
2
数据规模和约定
　　1<=n<=22
　　T<=maxlongint
　　集合中任意元素的和都不超过long的范围

*/
#if 0
#include <stdio.h>
void xh(int,int*,int*,int,int*,int);
int panduan(int*a,int*b,int n,int jg);
void shuchu(int*a,int*b,int n);
void shuru(int n,int *a);
int tqpd(int*,int);

int main(void) 
{
	int n,jg;
	scanf("%d",&n);
	int a[n];
	shuru(n,a);
	scanf("%d",&jg);
	int b[22]={0};
	int gs=0;
	xh(n,b,a,n-1,&gs,jg);
	printf("%d\n",gs);
	return 0;
}


void shuru(int n,int *a)
{
 while(n--)
 {
  scanf("%d",a++);
 }
}
/*
22
1 -1 2 -2 4 -4 8 -8 16 -16 32 -32 64 -64 128 -128 256 -512 512 -1024 -256 1024
0

*/
void xh(int n,int* a,int*b,int k,int *p_gs,int jg)
{
 if(k<0)
 {
  if(panduan(a,b,n,jg))
  {
   shuchu(a,b,n);
   (*p_gs)++;
  }
  return;
 }
 for(a[k]=0;a[k]<2;a[k]++)
 {
  xh(n,a,b,k-1,p_gs,jg);
 } 
}

int tqpd(int*b,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  if(b[i]!=0)
  {
   return 1;
  }
 }
 return 0;
}

int panduan(int*a,int*b,int n,int jg)
{
 int i,he=0;
 if(tqpd(a,n))
 {
  for(i=0;i<n;i++) 
  {
   he+=a[i]*b[i];
  }
  return he==jg;
 }
 return 0;
}

void shuchu(int*a,int*b,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  if(a[i]!=0)
  {
   printf("%d ",b[i]);
  }
 }
 putchar('\n'); 
}
#endif 
/*
问题描述
　　妈妈给小B买了N块糖！但是她不允许小B直接吃掉。
　　假设当前有M块糖，小B每次可以拿P块糖，其中P是M的一个不大于根号下M的质因数。
这时，妈妈就会在小B拿了P块糖以后再从糖堆里拿走P块糖。然后小B就可以接着拿糖。
　　现在小B希望知道最多可以拿多少糖。
输入格式
　　一个整数N
输出格式
　　最多可以拿多少糖
样例输入
15
样例输出
6
数据规模和约定
　　N <= 100000
*/
#include <stdio.h>
#include <math.h>
int q_zys(int);
int panduan_zs(int);
int panduan_ys(int,int);

int main(void)
{
 int N;
 scanf("%d",&N);
 int zdtg=0;
 while(N>=4)
 {
  zdtg+=q_zys(N);
  printf("%d ",zdtg);
  N-=q_zys(N)*2;
  printf("%d ",N);
  putchar('\n'); 
 }
 printf("%d\n",zdtg);
 return 0;
}

int q_zys(int n)
{
 int i;
 for(i=(int)sqrt(n);i>=2;i--)
 {
  if(panduan_zs(i)&&panduan_ys(i,n))
  {
   return i;
  }
 }
 return 0;
}

int panduan_zs(int n)
{
  int i;
  for(i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
	 return 0;
	}
  }
  return n==1?0:1;
}

int panduan_ys(int ys,int n)
{
 return n%ys==0?1:0;
}








