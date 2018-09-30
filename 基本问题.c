/*
问题描述
给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。

输入格式
第一行包含一个数n，表示序列长度。

第二行包含n个正整数，表示给定的序列。
5
1 2 3 4 5
2
1 5 2
2 3 2
第三个包含一个正整数m，表示询问个数。

接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，从大往小第K大的数是哪个。序列元素从1开始标号。

输出格式
总共输出m行，每行一个数，表示询问的答案。
样例输入

样例输出
4
2
数据规模与约定
对于30%的数据，n,m<=100；

对于100%的数据，n,m<=1000；

保证k<=(r-l+1)，序列中的数<=106。

 
*/
#include <stdio.h>
void shuru(int*,int);
void shuchu(int *,int);
int  maxkey(int*,int,int);
void select(int*,int,int);
void swap(int*,int*);
void fuzhi(int*,int*,int,int);

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	int c[n];
	shuru(a,n);
	int m;
	scanf("%d",&m);
	int low,high,zhi;
    int i;
	for(i=0;i<m;i++) 
	{
	scanf("%d%d%d",&low,&high,&zhi);
	fuzhi(c,a,low,high);
	select(c,0,high-low);
	shuchu(c,zhi-1);
	}
	return 0;
}

int maxkey(int * a,int low,int high)
{
  int max=low;
  int key=a[max];
  int i;
  for(i=low+1;i<=high;i++)
  {
   if(key<a[i])
   {
    key=a[i];
    max=i;
   }
  }
  return max;
}

void shuru(int *a,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
}

void fuzhi(int*c,int*a,int low,int high)
{
  int i,k;
  for(i=0,k=low-1;k<high;i++,k++)
  {
   c[i]=a[k];
  }
}

void shuchu(int *c,int zhi)
{
  printf("%d\n",c[zhi]);
}


void select(int *a,int low,int high)
{
  int i;
  for(i=low;i<=high;i++)
  {
   int j=maxkey(a,i,high);
   if(j!=i)
   {
    swap(&a[i],&a[j]);
   }
  }
}

void swap(int *p_a,int *p_b)
{
  int temp=*p_a;
      *p_a=*p_b;
      *p_b=temp;
}
