/*
100 可以表示为带分数的形式：100 = 3 + 69258 / 714。

还可以表示为：100 = 82 + 3546 / 197。

注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

类似这样的带分数，100 有 11 种表示法。

输入格式
从标准输入读入一个正整数N (N<1000*1000)

输出格式
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。

注意：不要求输出每个表示，只统计有多少表示法！

样例输入1
100
样例输出1
11
样例输入2
105
样例输出2
6
*/
//全排列； 
#include <stdio.h>

void swap(int*,int*);
void panduan(int*,int ,int* ,int );
int q_shu(int* ,int ,int );
void qupl(int *,int ,int ,int ,int *);

int main(void) 
{
	int n,cs=0;
	scanf("%d",&n);
	int a[9]={1,2,3,4,5,6,7,8,9};
	qupl(a,9,0,n,&cs);
	printf("%d\n",cs);
	return 0;
}

void panduan(int*a,int n,int* p_cs,int shu)
{ 
 int i;
 int shu1,shu2,shu3;
 for(i=0;i<n;i++)
 {
  shu1=q_shu(a,0,i+1);
  if(shu1>shu)
  {
   return;
  }
  int k;
  for(k=(n-i+1)/2-1;k<n-1;k++)//（n-i+1）/2 -1是为了相除时得到是整数 
  { 
   shu2=q_shu(a,i+1,k+1);
   shu3=q_shu(a,k+1,n);
   if(shu2%shu3==0&&shu2/shu3+shu1==shu)
   {
    (*p_cs)++;
   }
  } 
 } 


}

int q_shu(int* a,int low,int high)
{
	int i,shu=0;
	for(i=low;i<high;i++)
	{
	 shu*=10;
	 shu+=a[i];
	}
	return shu;
}


void qupl(int *a,int n,int k,int shu,int *p_cs)
{
  if(k==n)
  {
   panduan(a,n,p_cs,shu);
   return;
  }
  int i;
  for(i=k;i<n;i++)
  {
   swap(a+k,a+i);//先将第一个位置所有可能 
   qupl(a,n,k+1,shu,p_cs); 
   swap(a+k,a+i);//恢复原状 
  }
}

void swap(int *p_a,int*p_b)
{
  int temp;
  temp=*p_a;
  *p_a=*p_b;
  *p_b=temp;
}


