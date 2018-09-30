///*
//问题描述
//　　编写一个程序，读入一组整数，这组整数是按照从小到大的顺序排列的，
//它们的个数N也是由用户输入的，最多不会超过20。然后程序将对这个数组进行统计，
//把出现次数最多的那个数组元素值打印出来。如果有两个元素值出现的次数相同，即并列第一，那么只打印比较小的那个值。
//　　输入格式：第一行是一个整数N，N? ￡? 20；接下来有N行，每一行表示一个整数，并且按照从小到大的顺序排列。
//　　输出格式：输出只有一行，即出现次数最多的那个元素值。
//输入输出样例
//样例输入
//5
//100
//150
//150
//200
//250
//样例输出
//150
// 
//*/
//#include <stdio.h>
//typedef
//struct
//{
//  int sz;
//  int cs;
//}shuju_t;
//
//void shuru(shuju_t*,int,int*);
//int q_xb(shuju_t*,int);
//
//int main(void) 
//{
//    int N;
//    scanf("%d",&N);
//    if(N>0)
//    {
//	 shuju_t s[N];
//	 int gs=1;
//     shuru(s,N,&gs);
//     printf("%d\n",s[q_xb(s,gs)]);
//	}
//	return 0;
//}
//
//int q_xb(shuju_t* s,int gs)
//{
//  int i,xb=0;
//  int max=s[xb].cs;
//  for(i=1;i<gs;i++)
//  {
//    if(s[i].cs>max)
//    {
//	 max=s[i].cs;
//	 xb=i;
//	}
//  }
//  return xb;
//} 
//
//void shuru(shuju_t* s,int n,int* p_gs)
//{
//  int xb=0;
//  scanf("%d",&s[xb].sz);
//  s[xb].cs=1;
//  while(--n>0)
//  {
//    int t;
//    scanf("%d",&t);
//    if(t==s[xb].sz)
//    {
//	  s[xb].cs++;
//	}else
//	{
//	 xb++;
//	 s[xb].sz=t;
//	 s[xb].cs=1;
//	 ++*p_gs;
//	}
//  }
//}
/*
输出素数  
*/
/*
/*
问题描述
　　给定区间[L, R] ， 请计算区间中素数的个数。
输入格式
　　两个数L和R。
输出格式
　　一行，区间中素数的个数。
样例输入
2 11
样例输出
5
数据规模和约定
　　2 <= L <= R <= 2147483647 R-L <= 1000000
*/
#if 0
#include <stdio.h>

void input( int [] , int );
void shai( int [] , int );
void output( int [] ,int,int);

int main(void)
{
	int R,L;
	scanf("%d%d",&L,&R);
	int a[R];
	input(a,R);
	shai(a,R);
	output(a,R,L);
	return 0;
}

void output(int*a,int R,int L)
{
	int i;
	for(i=L-1;i<R;i++ )
	{
		if(a[i]!=0)
		{
			printf("%d ",a[i]);
		}
	}
}

void shai(int a[],int n)
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		if( a[i] == 0 )
		{
			continue ;
		}
		int bs;
		for( bs=i+a[i];bs<n;bs+=a[i])
		{
			a[bs]=0;
		}
	}
}

void input( int a[] , int n )
{
	int i;
	for( i = 0 ; i < n ; i ++ )
	{
		a[i]=i+1;
	}
	a[0]=0 ; 
}
#endif


/*
问题描述
　　陶陶家的院子里有一棵苹果树，每到秋天树上就会结出n个苹果。苹果成熟的时候，
   陶陶就会跑去摘苹果。陶陶有个30厘米高的板凳，当她不能直接用手摘到苹果的时候，就会踩到板凳上再试试。
　　现在已知n个苹果到地面的高度，以及陶陶把手伸直的时候能够达到的最大高度。
假设她碰到苹果，苹果就会掉下来。请帮陶陶算一下,经过她的洗劫后，苹果树上还有几个苹果。
输入格式
　　输入包括两行数据。第一行只包括两个正整数n(5<=n<=200)和m(60<=m<=200),
表示苹果数目和桃桃伸手可达到的高度（以厘米为单位）。
第二行包含n个100到200之间（包括100和200）的整数（以厘米为单位）分别表示苹果到地面的高度，
两个相邻的整数之间用一个空格隔开。
输出格式
　　输出包括一行，这一行只包含一个整数，表示陶陶不能够摘到的苹果的数目。
样例输入
10 110
100 200 150 140 129 134 167 198 200 111
样例输出
5
*/
#if 0
#include<stdio.h>

void input(int* a,int tzs);
int q_xcs(int* a,int tzs,int gd);

int main(void)
{
  int tzs,gd;
  scanf("%d%d",&tzs,&gd);
  int a[tzs];
  input(a,tzs);
  printf("%d\n",q_xcs(a,tzs,gd));
  return 0;
} 

void input(int *a,int n)
{
  while(n-->0)
  {
   scanf("%d",a++);
  }
}

int q_xcs(int *a,int n,int gd)
{
  int i, xcs=n,zdgd=gd+30;
  for(i=0;i<n;i++)
  {
   if(a[i]<=zdgd)
   {
    xcs--;
   }
  }
  return xcs;
}
#endif
#include <stdio.h>

int main(void)
{
  char a;
  char b;
  scanf("%c",&a);
  printf("%d",a);
  return 0;
}

