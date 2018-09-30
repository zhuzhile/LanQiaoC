/*
问题描述
　　给定A, B, P，求(A^B) mod P。
输入格式
　　输入共一行。
　　第一行有三个数，N, M, P。
输出格式
　　输出共一行，表示所求。
样例输入
2 5 3
样例输出
2
数据规模和约定
　　共10组数据
　　对100%的数据，A, B为long long范围内的非负整数，P为int内的非负整数。
 
*/ 
#include <stdio.h>
int q_shu(int,int);

int main(void) 
{
	int N,M,P;
	scanf("%d%d%d",&N,&M,&P);
    printf("%d",q_shu(N,M)%P);
    return 0;
}

int q_shu(int n,int m)
{
  if(m==0)
  {
   return 1;
  }
  return n*q_shu(n,m-1);
}
