/*
问题描述
　　有n（2≤n≤20）块芯片，有好有坏，已知好芯片比坏芯片多。
　　每个芯片都能用来测试其他芯片。用好芯片测试其他芯片时，能
正确给出被测试芯片是好还是坏。而用坏芯片测试其他芯片时，会随机给出好或是坏的测试结果（
即此结果与被测试芯片实际的好坏无关）。
　　给出所有芯片的测试结果，问哪些芯片是好芯片。
输入格式
　　输入数据第一行为一个整数n，表示芯片个数。
　　第二行到第n+1行为n*n的一张表，每行n个数据。表
中的每个数据为0或1，在这n行中的第i行第j列（1≤i, j≤n）的
数据表示用第i块芯片测试第j块芯片时得到的测试结果，1表示好，
0表示坏，i=j时一律为1（并不表示该芯片对本身的测试结果。芯片不能对本身进行测试）。
输出格式
　　按从小到大的顺序输出所有好芯片的编号
样例输入
3
1 0 1
0 1 0
1 0 1
样例输出
1 3
*/ 
#include <stdio.h>
void shuru(int ,int n,int [][n]);
void panduan(int,int n,int[][n]);
void select(int*,int*,int);

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	shuru(n,n,a);
	panduan(n,n,a);
	return 0;
}

void shuru(int h,int l,int a[][l])
{ 
   int i;
   for(i=0;i<h;i++)
   {
    int k;
	for(k=0;k<l;k++)
    {
	 scanf("%d",&a[i][k]);
	}
   }
}

void panduan(int h,int l,int a[][l])
{
   int count[h];
   int count_0[h];
   int j;
   for(j=0;j<h;j++)
   {
    count[j]=0;
    count_0[j]=0;
   }
   int i;
   for(i=0;i<l;i++)
   {
    int k;
	for(k=0;k<h;k++)
    {
	 count[i]+=a[i][k];
	 count_0[i]+=a[k][i];
	}
   }
   select(count,count_0,h);
}

void select(int *a,int *count,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   if(a[i]>=(n+1)/2)
   {
    if(count[i]>=(n+1)/2)
    {
	 printf("%d ",i+1);
	}
   }
  }

}

