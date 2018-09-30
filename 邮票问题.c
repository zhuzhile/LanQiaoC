/*
问题描述
　　给定一个信封，有N（1≤N≤100）个位置可以贴邮票，每个位置只能贴一张邮票。我们现在有M(M<=100)种不同邮资的邮票，面值为X1,X2….Xm分（Xi是整数，1≤Xi≤255），每种都有N张。

　　显然，信封上能贴的邮资最小值是min(X1, X2, …, Xm)，最大值是 N*max(X1, X2, …,　　Xm)。由所有贴法得到的邮资值可形成一个集合（集合中没有重复数值），要求求出这个集合中是否存在从1到某个值的连续邮资序列，输出这个序列的最大值。

　　例如，N=4，M=2，面值分别为4分，1分，于是形成1，2，3，4，5，6，7，8，9，10，12，13，16的序列，而从1开始的连续邮资序列为1，2，3，4，5，6，7，8，9，10，所以连续邮资序列的最大值为10分。
输入格式
　　第一行：最多允许粘贴的邮票张数N；第二行：邮票种数M；第三行：空格隔开的M个数字，表示邮票的面值Xi。注意：Xi序列不一定是大小有序的！
输出格式
　　从1开始的连续邮资序列的最大值MAX。若不存在从1分开始的序列（即输入的邮票中没有1分面额的邮票），则输出0.
样例输入

样例一：
4
2
4 1
样例二：
10
5
2 4 6 8 10


样例输出

样例一：
10
样例二：
0
*/
#if 1 
#include <stdio.h>

void input(int*,int);
int q_max(int*,int);
void q_table(int*,int,int*,int,int,int);
void output(int*,int);
void chushih(int*,int);
void fyp(int*,int*,int,int);

int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[m];
	input(a,m);
	int max=q_max(a,m);
	int table[n*max+1];//将面值作为下标
	table[0]=1;
	chushih(table,n*max+1);
	q_table(table,n*max+1,a,m,n,max);
	output(table,n*max+1);
	return 0;
}

void q_table(int*table,int table_cd,int *a,int m,int n,int max)
{
  int i;
  for(i=0;i<n;i++)
  {
  	int k;
  	for(k=max*i;k>=0;k--)
  	{
	 if(table[k]==1)
     {
      fyp(table,a,m,k);
     }
	}
 }
  
}


void output(int *a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(a[i]==0)
    {
	 printf("%d ",i-1);
	 break;
	}
  } 
}

void fyp(int* table,int *a,int m,int xb)
{
 int i;
 for(i=0;i<m;i++)
 {
  table[xb+a[i]]=1;
 }
}

void input(int*a,int n)
{
  while(n--)
  {
   scanf("%d",a++);
  }
}

int q_max(int*a,int n)
{
  int i;
  int max=a[0];
  for(i=1;i<n;i++)
  {
   if(max<a[i])
   {
    max=a[i];
   }
  }
  return max;
}

void chushih(int *a,int n)
{
  int i;
  for(i=1;i<n;i++)
  {
    a[i]=0;
  }
}

#endif

/*

问题描述

如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，
那么我们就说这个数是K好数。求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，
所有K好数为11、13、20、22、30、31、33 共7个。由于这个数目很大，请你输出它对1000000007取模后的值。
输入格式

输入包含两个正整数，K和L。
输出格式
输出一个整数，表示答案对1000000007取模后的值。
样例输入
4 2
样例输出
7
数据规模与约定

对于30%的数据，KL <= 106；

对于50%的数据，K <= 16， L <= 10；

对于100%的数据，1 <= K,L <= 100。
 
*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#define zd (1000000007)
void q_cs(int,int,int khs[][107]);
int q_he(int,int,int[][107]);
int main(void)
{
  int K,L;
  scanf("%d%d",&K,&L);
  int khs[107][107]={0};
  int i;
  for(i=0;i<=K-1;i++)
  {
    khs[1][i]=1;
  }
  q_cs(K,L,khs);
  printf("%d\n",q_he(K,L,khs));
  return 0;
}

int q_he(int k,int l, int khs[][107])
{
  int sum=0;
  int i;
  for(i=1;i<=k-1;i++)
    {
        sum+=khs[l][i];
        sum%=zd;
    }
   return sum;
}

void q_cs(int k,int l,int khs[][107])
{
int i,j,t;
for(i=2;i<=l;i++)
{
  for(j=0;j<k;j++)
  {
    for(t=0;t<k;t++)
    {
     if(abs(t-j)!=1)
     {
        khs[i][j]+=khs[i-1][t];
        khs[i][j]%=zd;
     }
    }
   }
}
}
#endif
  

