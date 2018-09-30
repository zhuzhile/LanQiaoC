/*

问题描述
　　将整数n分成k份，且每份不能为空，任意两份不能相同(不考虑顺序)。
　　例如：n=7，k=3，下面三种分法被认为是相同的。
　　1，1，5; 1，5，1; 5，1，1;
　　问有多少种不同的分法。
输入格式
　　n，k
输出格式
　　一个整数，即不同的分法
样例输入
7 3
样例输出
4 {四种分法为：1，1，5;1，2，4;1，3，3;2，2，3;}
数据规模和约定
　　6<n<=200，2<=k<=6

*/ 
#if 0
#include <stdio.h>


int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[k];
	int gs=0;
	xh(n,k,a,0,&gs);
	printf("%d\n",gs);
	return 0;
}

void xh(int shu,int n,int *a,int k,int *p_gs)
{
  if(k==n)
  {
   if(q_sum(a,n)==shu)
   {
    ++*p_gs;
    output(a,n); 
   }
   return ;
  }
  for(a[k]=1;a[k]<shu;a[k]++)
  {
   xh(shu,n,a,k+1,p_gs);
  }
}

int judge(int *a,int k)
{
 int i;
 for(i=0;i<k;i++)
 {
  if(a[k]==a[i])
  {
   return 0;
  }
 }
 return 1;
}


void output(int*a,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
 putchar('\n');
}


int q_sum(int *a,int n)
{
 int sum=0;
 while(n--)
 {
  sum+=*a++;
 }
 return sum;
}

#endif

#include<stdio.h>  
  
int q_cs(int n, int k) 
{  
    if(n == k || k==1)
	{
	 return 1;
	} 
    else{return n < k==1?0:q_cs(n-k, k)+q_cs(n-1, k-1);
	}  
}   
  
int main (void) 
{  
   int n, k;   
   scanf("%d%d", &n, &k);  
   printf("%d\n",q_cs(n,k));  
   return 0;  
}  
