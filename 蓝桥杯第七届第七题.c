/*

寒假作业

现在小学的数学题目也不是那么好玩的。
看看这个寒假作业：

   □ + □ = □
   □ - □ = □
   □ × □ = □
   □ ÷ □ = □
   
   (如果显示不出来，可以参见【图1.jpg】)
   
每个方块代表1~13中的某一个数字，但不能重复。
比如：
 6  + 7 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

以及： 
 7  + 6 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

就算两种解法。（加法，乘法交换律后算不同的方案）
 
你一共找到了多少种方案？


请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。


*/ 
#if 0
#include <stdio.h>
void output(int*,int);
void qpl(int n,int k,int *a,int*);
void swap(int*,int*);
int panduan(int*,int);

int main(void) 
{
	int a[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
	int gs=0;
	qpl(13,0,a,&gs);
	printf("%d\n",gs);
	return 0;
}

void qpl(int n,int k,int *a,int* p_gs)
{
 if(k==n)
 {
  if(panduan(a,n))
  {
  ++*p_gs;
  }
  return;
 }
 int i;
 for(i=k;i<n;i++)
 {
   swap(a+k,a+i);
   qpl(n,k+1,a,p_gs);
   swap(a+k,a+i);
 }
}

int panduan(int*a,int n)
{
 if(a[0]+a[1]==a[2]&&a[3]-a[4]==a[5]&&a[6]*a[7]==a[8]&&a[9]%a[10]==0&&a[9]/a[10]==a[11])
 {
  output(a,n);
  return 1;
 }
 return 0;
}

void output(int *a,int n)
{
 while(n--)
 {
  printf("%d ",*a++);
 }
 putchar('\n');
}

void swap(int *p,int *q)
{
 int t=*p;
 *p=*q;
 *q=t;
}
#endif
/*
凑算式

     B      DEF
A + --- + ------- = 10
     C      GHI
     
（如果显示有问题，可以参见【图1.jpg】）
	 
	 
这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。

比如：
6+8/3+952/714 就是一种解法，
5+3/1+972/486 是另一种解法。

这个算式一共有多少种解法？

注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。

*/
#if 0
#include <stdio.h>
void qpl(int,int,int*,int*);
void output(int*,int);
int panduan(int*,int);

int main(void)
{
  int a[9]={1,2,3,4,5,6,7,8,9};
  int gs=0;
  qpl(9,0,a,&gs);
  printf("%d\n",gs);
  return 0;
}

void qpl(int n,int k,int *a,int *p_gs)
{
  if(k==n)
  {
   if(panduan(a,n))
   {
    ++*p_gs;
   }
   return;
  }
  int i;
  for(i=k;i<n;i++)
  {
   swap(a+k,a+i);
   qpl(n,k+1,a,p_gs);
   swap(a+k,a+i);
  }
}

void swap(int*p,int*q)
{
 int t=*p;
 *p=*q;
 *q=t;
}

int panduan(int*a,int n)
{
 if(fabs(a[0]*1.0 + a[1]*1.0 / a[2] + (a[3] * 100 + a[4] * 10 + a[5])*1.0 / (a[6] * 100 + a[7] * 10 + a[8]) - 10.00)
  < 0.0000000001)
 {
  output(a,n);
  return 1;
 }
 return 0;
}

void output(int *a,int n)
{
 while(n--)
 {
  printf("%d ",*a++);
 }
 putchar('\n');
}
#endif
#if 0
#include <stdio.h>

void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int p, int r)
{
    int i = p;
    int j = r + 1;
    int x = a[p];
    while(1){
        while(i<r && a[++i]<x);
        while(a[--j]>x);
        if(i>=j) break;
        swap(a,i,j);
    }
    printf("%d\n",j);
    return j;
}

void quicksort(int a[], int p, int r)
{
    if(p<r){
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
    
int main()
{
	int i;
	int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
	int N = 12;
	
	quicksort(a, 0, N-1);
	
	for(i=0; i<N; i++) printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}

#endif

/*

问题描述
　　安全局搜索到了一批(n个)身份证号码，希望按出生日期对它们进行从大到小排序，如果有相同日期，
则按身份证号码大小进行排序。身份证号码为18位的数字组成，出生日期为第7到第14位
输入格式
　　第一行一个整数n，表示有n个身份证号码
　　余下的n行，每行一个身份证号码。
输出格式
　　按出生日期从大到小排序后的身份证号，每行一条
样例输入
5
466272307503271156
215856472207097978
234804580401078365
404475727700034980
710351408803093165
样例输出
404475727700034980
234804580401078365
215856472207097978
710351408803093165
466272307503271156
数据规模和约定
　　n<=100000

*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void s_to_z(char*s,int n,int*a);
void output(int n,int *a);

int main(void)
{
  int n;
  scanf("%d",&n);
  char s[20];
  int a[n];
  memset(a,0,sizeof(a));
  output(n,a);
  return 0;
}

void s_to_z(char*s,int k,int*a)
{
  int i;
  int zd=1000000;
  for(i=6;i<13;i++)
  {
   a[k]+=(s[i]-'0')*zd;
   zd/=10;
  }
}

void output(int n,int *a)
{
 while(n--)
 {
  printf("%d ",*a++);
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
#if 1
#include <stdio.h>
#include <math.h>
#define zd  100000
void dyzsb(int*,int*,int*);
int q_max(int,int);
void nantg(int*,int,int);

int main(void)
{
  int n;
  scanf("%d",&n);
  int dyb[zd]={0},zsb[zd]={0},ws=0;
  dyzsb(zsb,dyb,&ws);
  nantg(zsb,n,ws);
  return 0;
}

void dyzsb(int*zsb,int*dyb,int*p_ws)//筛法 
{
 int i;
 int zhi=sqrt(zd);
 for(i=2;i<=zhi;i++)
 {
  if(dyb[i]==0)
   {
    zsb[*p_ws]=i;
    ++*p_ws;
    dyb[i]=1; 
   }
  }
}

int q_max(int a,int b)
{
 return a>b?a:b;
}

void nantg(int*zsb,int n,int ws)
{
 int i,k,a[zd];
 for(i=1;i<=n;i++)
 {
  for(k=0;k<ws;k++)
  {
   if(zsb[k]*zsb[k]>i)
   {
    break;
   }
   if(i%zsb[k]==0)
   {
    a[i]=q_max(a[i],a[i-2*zsb[k]]+zsb[k]);
   }
  }
 }
 printf("%d\n",a[n]);
}
#endif
 
 
 
#if 0
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
			int j;
			for (j = i*i;j <= n;j ++)
			{
				pd[j] = 1;
			}
		}
	}
}

#endif
#if 0
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
				pd[i] = 1;

		}
	}
}
#endif

