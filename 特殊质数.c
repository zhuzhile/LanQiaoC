/*
问题描述
　　农民约翰母牛总是产生最好的肋骨。你能通过农民约翰和美国农业部标记在每根肋骨上的数字认出它们。
农民约翰确定他卖给买方的是真正的质数肋骨，是因为从右边开始切下肋骨，每次还剩下的肋骨上的数字都组成一个质数。

　　例如有四根肋骨的数字分别是：7 3 3 1，那么全部肋骨上的数字 7331是质数；三根肋骨 733是质数；
二根肋骨 73 是质数；当然,最后一根肋骨 7 也是质数。7331 被叫做长度 4 的特殊质数。

　　写一个程序对给定的肋骨的数目 N (1<=N<=8),求出所有的特殊质数。数字1不被看作一个质数。
输入格式
　　单独的一行包含N。
输出格式
　　按顺序输出长度为 N 的特殊质数,每行一个。
样例输入
4
样例输出
2333 
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393
*/
#include <stdio.h>
int pdtszs(int);
int pandzs(int);
int q_cf(int);

int main(void)
{
	int n;
	scanf("%d",&n);
	int i;
	int shu=q_cf(n-1);
	for(i=shu*2;i<shu*9;i++)
    {
    if(pdtszs(i))
    {
     printf("%d\n",i);
    }
    }
  return 0;
}

int pdtszs(int n)
{
  if(n==0)
  {
   return 1;
  }
  if(pandzs(n))
  {
   return pdtszs(n/10);
  }else{return 0;
  }
}

int pandzs(int n)
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

int q_cf(n)
{
  if(n==0)
  {
   return 1;
  }
  return 10*q_cf(n-1);
}





