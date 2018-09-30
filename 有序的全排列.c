/*

问题描述
　　0、1、2三个数字的全排列有六种，按照字母序排列如下：
　　012、021、102、120、201、210
　　输入一个数n
　　求0~9十个数的全排列中的第n个（第1个为0123456789）。
输入格式
　　一行，包含一个整数n
输出格式
　　一行，包含一组10个数字的全排列
样例输入
1
样例输出
0123456789
数据规模和约定
　　0 < n <= 10!

01234
 
15 15/3 15%3=3 3/2 3%2(递归关系） 
*/ 

#include<stdio.h>

void q_dncpl(int*a,int,int,int);
int q_jc(int);
void output(int*,int);
void xhyw(int*,int,int);

int main(void)
{
  int n;
  scanf("%d",&n);
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  q_dncpl(a,9,n-1,q_jc(9));
  output(a,10);
  return 0;
} 
void output(int *a,int n)
{
  while(n-->0)
  {
   printf("%d",*a++);
  }
}

void xhyw(int*a,int end,int jw)
{
 int i,t=a[end];
 for(i=end;i>0;i--)
 {
  a[i]=a[i-jw];
 }
 a[0]=t;
} 

void q_dncpl(int *a,int n,int m,int jc)
{
 if(n==0)
 {
  return;
 }
 xhyw(a,m/jc,1);
 q_dncpl(a+1,n-1,m%jc,jc/n);//看向下一次阶乘 
}

int q_jc(int n)
{
 if(n==0)
 {
  return 1;
 }
 return q_jc(n-1)*n;
}
