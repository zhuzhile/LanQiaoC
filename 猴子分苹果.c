/*

问题描述
　　秋天到了，n只猴子采摘了一大堆苹果放到山洞里，约定第二天平分。
这些猴子很崇拜猴王孙悟空，所以都想给他留一些苹果。第一只猴子悄悄来到山洞，
把苹果平均分成n份，把剩下的m个苹果吃了,然后藏起来一份，最后把剩下的苹果重新合在一起。
这些猴子依次悄悄来到山洞，都做同样的操作，恰好每次都剩下了m个苹果。
第二天，这些猴子来到山洞，把剩下的苹果分成n分，巧了，还是剩下了m个。
问，原来这些猴子至少采了多少个苹果。
输入格式
　　两个整数，n m
输出格式
　　一个整数，表示原来苹果的数目
样例输入
5 1
样例输出
15621
数据规模和约定
　　0<m<n<9

*/ 
#include <stdio.h>
#define MAX (100000)
int pandaun(int*,int,int);

int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
    printf("%d\n",q_gs(n,m));
	return 0;
}

int q_gs(int n,int m)
{
 int sum=0,apgs=0;
 while(1)
 {
  sum=apgs*n+m;
  int i;
  for(i=0;i<n;i++)
  {
   if(sum%(n-1)==0)
   {
    sum = sum/(n - 1)*n + m;
   }else{apgs++;
   break;
   }
  }
  if(i==n)
  {
   break;
  }
 }
 return sum;
}

/*
问题描述
　　秋天到了，n只猴子采摘了一大堆苹果放到山洞里，约定第二天平分。
    这些猴子很崇拜猴王孙悟空，所以都想给他留一些苹果。
	第一只猴子悄悄来到山洞，把苹果平均分成n份，把剩下的m个苹果吃了,然后藏起来一份，最后把剩下的苹果重新合在一起。
	这些猴子依次悄悄来到山洞，都做同样的操作，恰好每次都剩下了m个苹果。
	第二天，这些猴子来到山洞，把剩下的苹果分成n分，巧了，还是剩下了m个。
	问，原来这些猴子至少采了多少个苹果。
输入格式
　　两个整数，n m
输出格式
　　一个整数，表示原来苹果的数目
样例输入
5 1
样例输出
15621
数据规模和约定
　　0<m<n<9
*/ 
#if 0
#include <stdio.h>

int q_gs (int ,int );

int main(void) 
{
	int n,m;
	scanf ("%d%d",&n,&m);
	printf ("%d",q_gs (n,m));
	return 0;
}

int q_gs (int n,int m)
{
	int pg = 0;
	int sum;
	int i;
	while (1)
	{
		sum = pg * n + m;
		for (i = 1;i <= n;i ++)
		{
			if ((sum * n) % (n-1) == 0)
			{
				sum = sum * n / (n - 1) + m;
			}
			else
			{
				pg ++;
				break;
			}
		}
		if (i == n+1)/nhuan jieshu panduan
		{
			break;
		}
	}
	return sum;
}
#endif

/*




int panduan(int *a,int n,int m)
{
 int i; 
 for(i=0;i<n;i++)
 {
  if(a[i]*(n-1)%n!=m)
  {
   return 0;
  }
 }
 return (a[0]*n+m)%n==m;
}
*/


