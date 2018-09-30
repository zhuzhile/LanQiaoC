/*
问题描述
小明开了一家糖果店。他别出心裁：把水果糖包成4颗一包和7颗一包的两种。糖果不能拆包卖。
小朋友来买糖的时候，他就用这两种包装来组合。当然有些糖果数目是无法组合出来的，比如要买 10 颗糖。
你可以用计算机测试一下，在这种包装情况下，最大不能买到的数量是17。大于17的任何数字都可以用4和7组合出来。
本题的要求就是在已知两个包装的数量时，求最大不能组合出的数字。
输入格式
两个正整数，表示每种包装中糖的颗数(都不多于1000)
输出格式
一个正整数，表示最大不能买到的糖数
样例输入1
4 7
样例输出1
17 
样例输入2
3 5
样例输出2
7 
*/

#if 1
#include <stdio.h>
void paixu(int*,int*);
void swap(int*,int*);
int maibudao(int,int);
void initial(int*,int,int);
int lianx(int*,int,int);
int q_zx(int*,int);
int panduan(int,int*,int);


int main(void)
{
  int n,m;
  scanf("%d%d",&n,&m);
  paixu(&n,&m);
  printf("%d\n",maibudao(n,m));
  return 0;
}

int panduan(int shu,int *a,int n)
{
 int k;
 for(k=0;k<n;k++)
 {
  if(shu==a[k])
  {
   return 1;
  }
 }
 return 0;
}

int lianx(int *a,int zx,int n)
{
 int i;
 for(i=a[zx]+1;i<a[zx]+n;i++)
 {
  if(panduan(i,a,n)==0)
  {
   return 0;
  }
 }
 return 1;
}

int q_zx(int*a,int n)
{
 int i;
 int zx=a[0],key=0;
 for(i=1;i<n;i++)
 {
  if(a[i]<zx)
  {
   zx=a[i];
   key=i;
  }
 }
 return key;
}

void initial(int*a,int n1,int n2) 
{
 int i;
 for(i=0;i<n1;i++)
 {
  a[i]=i*n2;
 }
}

int maibudao(int n1,int n2)
{
 int a[n1],zx=0;
 initial(a,n1,n2);

 while(lianx(a,zx,n1)!=1)
 {
   a[zx]+=n1;
   zx= q_zx(a,n1);
 }
 return a[zx]-1; 
}

void paixu(int*p_n,int*p_m)
{
  if(*p_n>*p_m)
  {
   swap(p_n,p_m);
  }
}

void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}

#endif
#if 0 
#include <stdio.h>

void shuru (int *,int *);
void jiaohuan (int *,int *);
int maibudao (int ,int );
void chushihua (int [],int ,int );
int panudan_lx (int [],int ,int );
int sfcz (int [],int ,int );
int q_min (int [],int );

int main(void)
{
	int bao1,bao2;
	shuru (&bao1,&bao2);
	printf ("%d\n",maibudao (bao1,bao2));
	return 0;
}

int q_min (int a[],int n)
{
	int i;
	int zx = a[0];
	int min = 0;
	for (i = 1;i < n;i ++)
	{
		if (a[i] < zx)
		{
			min = i;
			zx = a[i];
		}
	}
	return min;
}

int sfcz (int a[],int n,int t)
{
	int i;
	for (i = 0;i < n;i ++)
	{
		if (a[i] == t)
		{
			return 1;
		}
	}
	return 0;
}

int panudan_lx (int a[],int min,int n)
{
	int i;
	for (i = a[min]+1;i < a[min] + n;i ++)
	{
		if (sfcz (a,n,i) == 0)
		{
			return 0;
		}
	}
	return 1;
}

void chushihua (int a[],int n,int m)
{
	int i;
	for (i = 0;i < n;i ++)
	{
		a[i] = i * m;
	}
}

int maibudao (int n,int m)
{
	int a[n];
	int min = 0;
	chushihua (a,n,m);
	int i;
	while (panudan_lx (a,min,n) != 1)
	{
		a[min] += n;
		min = q_min (a,n);
	}
	return a[min] - 1;
}

void jiaohuan (int * p,int * q)
{
	int t = * p;
	* p = * q;
	* q = t;
}

void shuru (int * p_bao1,int * p_bao2)
{
	scanf ("%d%d",p_bao1,p_bao2);
	if (* p_bao1 > * p_bao2)
	{
		jiaohuan (p_bao1,p_bao2);
	}
}

#endif 
