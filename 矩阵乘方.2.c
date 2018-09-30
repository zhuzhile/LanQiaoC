/*
问题描述
　　给定一个矩阵A,一个非负整数b和一个正整数m，求A的b次方除m的余数。
　　其中一个nxn的矩阵除m的余数得到的仍是一个nxn的矩阵，这个矩阵的每一个元素是原矩阵对应位置上的数除m的余数。
　　要计算这个问题，可以将A连乘b次，每次都对m求余，但这种方法特别慢，当b较大时无法使用。下面给出一种较快的算法(用A^b表示A的b次方)：
　　若b=0，则A^b%m=I%m。其中I表示单位矩阵。
　　若b为偶数，则A^b%m=(A^(b/2)%m)^2%m，即先把A乘b/2次方对m求余，然后再平方后对m求余。
　　若b为奇数，则A^b%m=(A^(b-1)%m)*a%m，即先求A乘b-1次方对m求余，然后再乘A后对m求余。
　　这种方法速度较快，请使用这种方法计算A^b%m，其中A是一个2x2的矩阵，m不大于10000。
输入格式
　　输入第一行包含两个整数b, m，第二行和第三行每行两个整数，为矩阵A。
输出格式
　　输出两行，每行两个整数，表示A^b%m的值。
样例输入
2 2
1 1
0 1
样例输出
1 0
0 1
*/ 

#include <stdio.h>

void shuru(long long ,long long[][2]);
void q_jz_m(long long ,long long [][2],long long [][2],long long );
void shuchu(long long ,long long [][2]);
void q_jz_ys(long long ,long long [][2],long long [][2],long long ,long long );
void q_m_yu(long long  [][2],long long ,long long );
void q_jz_xc(long long  h,long long  [][2],long long [][2]);

long long main(void) 
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long a[2][2];
	shuru(2,a);
	long long c[2][2];
	q_jz_ys(2,a,c,n,m);
	return 0;
}


void shuru(long long h,long long  a[][2])
{
 long long i;
 for(i=0;i<h;i++)
 {
 long long k;
 for(k=0;k<2;k++)
 {
  scanf("%lld",&a[i][k]);
 }
 }
}

void q_jz_m(long long h,long long a[][2],long long c[][2],long long b)
{
 long long s[2][2];
 long long i;
 for(i=0;i<2;i++)
 {
 long long k;
 for(k=0;k<2;k++)
 {
  s[i][k]=i==k?1:0;
  c[i][k]=i==k?1:0;
 }
 }
 
 while(b--)
 {
 	
  long long i_;
  for(i_=0;i_<h;i_++)
  {
  long long j_;
  for(j_=0;j_<2;j_++)
  {
  long long k_;
  c[i_][j_]=0;
  for(k_=0;k_<2;k_++)
  {
  c[i_][j_]+=s[i_][k_]*a[k_][j_];
  }
  }
  }
  
  long long i_0;
  for(i_0=0;i_0<h;i_0++)
  {
  long long k_0;
  for(k_0=0;k_0<2;k_0++)
  {
  s[i_0][k_0]=c[i_0][k_0];
  }
  }
  }

}
//若b=0，则A^b%m=I%m。其中I表示单位矩阵。
//若b为偶数，则A^b%m=(A^(b/2)%m)^2%m，即先把A乘b/2次方对m求余，然后再平方后对m求余。
//若b为奇数，则A^b%m=(A^(b-1)%m)*a%m，即先求A乘b-1次方对m求余，然后再乘A后对m求余。

void q_jz_ys(long long h,long long a[][2],long long c[][2],long long b,long long m)//
{
  if(b==0)
  {
  q_jz_m( h, a, c, b);
  q_m_yu(c,h,m);
  shuchu(2,c);
  }
  else{
  
  if(b%2==0)
  {
  q_jz_m( h, a, c, b/2);
  q_m_yu(c,h,m);
  q_jz_m(h,c,a,2);
  q_m_yu(a,h,m);
  shuchu(2,a);
  }
  
  else{
  q_jz_m(h,a,c,b-1);
  q_m_yu(c,h,m);
  q_jz_xc(h,a,c);
  q_m_yu(c,h,m);
  shuchu(2,c);
  }
  
  } 

}

void q_jz_xc(long long h,long long a[][2],long long c[][2])
{
  
  long long s[2][2];
  long long i_;
  for(i_=0;i_<h;i_++)
  {
  long long j_;
  for(j_=0;j_<2;j_++)
  {
  long long k_;
  s[i_][j_]=0;
  for(k_=0;k_<2;k_++)
  {
  s[i_][j_]+=c[i_][k_]*a[k_][j_];
  }
  }
  }
  
  long long i_0;
  for(i_0=0;i_0<h;i_0++)
  {
  long long k_0;
  for(k_0=0;k_0<2;k_0++)
  {
  c[i_0][k_0]=s[i_0][k_0];
  }
  }
}

void q_m_yu(long long c[][2],long long h,long long m)
{
  long long i;
  for(i=0;i<h;i++)
  {
   long long k;
   for(k=0;k<2;k++)
   {
    c[i][k]%=m;
   }
  }

}

void shuchu(long long h,long long  c[][2]) 
{
 long long i;
 for(i=0;i<h;i++)
 {
 long long k;
 for(k=0;k<2;k++)
 {
   printf("%lld ",c[i][k]);
 }
 putchar('\n');
 }
}




