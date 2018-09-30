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
#if 0
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
	q_jz_m(2,a,c,n,m);
	q_cf(2,a,n,m);
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

void q_cf(long long h, long long a[][2],long long ,c[][2],int n,int m)
{
  int jz[2][2];
  int i;
  for(i=0;i<2;i++)
  {
  	int j;
   for(j=0;j<2;j++)
   {
    jz[i][j]=i==j?1:0;
   }
  }
  while(n)
  {
    if(n&1)
    {
	 q_jz_xc(2,jz,a);
	}
	q_jz_m(2,a,c,2);
	n>>=1;
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

void q_jzxc(int h,long long s[][2],long long a[][2])
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
#endif 
/*

问题描述
　　道德经曰：一生二，二生三，三生万物。
　　对于任意正整数n，我们定义d(n)的值为为n加上组成n的各个数字的和。例如，d(23)=23+2+3=28, 
d(1481)=1481+1+4+8+1=1495。
　　因此，给定了任意一个n作为起点，你可以构造如下一个递增序列：n,d(n),d(d(n)),d(d(d(n)))....
例如，从33开始的递增序列为：
　　33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
　　我们把n叫做d(n)的生成元，在上面的数列中，33是39的生成元，39是51的生成元，
等等。有一些数字甚至可以有两个生成元，比如101，可以由91和100生成。但也有一些数字没有任何生成元，
如42。我们把这样的数字称为寂寞的数字。
输入格式
　　一行，一个正整数n。
输出格式
　　按照升序输出小于n的所有寂寞的数字，每行一个。
样例输入
40
样例输出
1
3
5
7
9
20
31
数据规模和约定
　　n<=10000

*/

#include <stdio.h>
#include <stdbool.h>

void q_jms(int,int*);
void pdjms(int,int*);
int q_he(int);

int main(void)
{
  int n;
  scanf("%d",&n);
  int a[100000]={0};
  pdjms(n,a);
  q_jms(n,a);
  return 0;
}

void q_jms(int n,int *a)
{
  int i;
  for(i=1;i<n;i++)
  {
   if(a[i]==0)
   {
    printf("%d\n",i);
   }
  }
}

void pdjms(int n,int *a)
{
  int i;
  for(i=1;i<n;i++)
  {
    a[i+q_he(i)]=1;
  }
}

int q_he(int n)
{
  int he=0;
  do
  {
   he+=n%10;
  }
  while((n/=10)!=0); 
  return he;
}





