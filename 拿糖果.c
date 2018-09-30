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
/*
打印质数表，然后筛选 
*/
#include <stdio.h>
#include <math.h>
#define zd 100000

void q_zsb (int [],int [] ,int *);
void natangguo (int [],int ,int );
int max (int ,int );

int main(void) 
{
	int n;
	scanf ("%d",&n);
	int pd[zd] ={0};
	int zsb[zd] = {0};
	int ws = 0;
	q_zsb (pd,zsb,&ws);
	natangguo (zsb,n,ws);
	return 0;
}

int max (int a,int b)
{
	return a > b ? a : b;
}

void natangguo (int zsb[],int n,int ws)
{
	int a[zd];
	int i,j;
	for (i = 1;i <= n;i ++)
	{
		for (j = 0;j < ws;j ++)
		{
			if (zsb[j] * zsb[j] > i)//P是M的一个不大于根号下M的质因数
			{
				break;
			}
			if (i % zsb[j] == 0)
			{
				a[i] = max (a[i],a[i-2*zsb[j]] + zsb[j]);
			}
		}
	}
	printf ("%d\n",a[n]); 
}

void q_zsb (int pd[],int zsb[],int * p_wei)
{
	int n = sqrt (zd);
	int i;
	for (i = 2;i <= n;i ++)
	{
		if (pd[i] == 0)
		{
			zsb[* p_wei] = i;
			(* p_wei) ++;
			if(i*i<=n)
			{
			 pd[i] = 1;
			} 	
		}
	}
}

