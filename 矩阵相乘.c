/*
问题描述
　　输入两个矩阵，分别是m*s，s*n大小。输出两个矩阵相乘的结果。
输入格式
　　第一行，空格隔开的三个正整数m,s,n（均不超过200）。
　　接下来m行，每行s个空格隔开的整数，表示矩阵A（i，j）。
　　接下来s行，每行n个空格隔开的整数，表示矩阵B（i，j）。
输出格式
　　m行，每行n个空格隔开的整数，输出相乘後的矩阵C（i，j）的值。
样例输入
2 3 2
1 0 -1
1 1 -3
0 3
1 2
3 1
样例输出
-3 2
-8 2

提示
矩阵C应该是m行n列，其中C(i,j)等于矩阵A第i行行向量与矩阵B第j列列向量的内积。
例如样例中C(1,1)=(1,0,-1)*(0,1,3) = 1 * 0 +0*1+(-1)*3=-3
 
*/ 
#if 0
#include <stdio.h>

void shuru(int,int l,long long [][l]);
void q_jz_xc(int,int l0,int,int l1,long long [][l0],long long [][l1],long long  [][l1]);
void shuchu(int,int l,long long [][l]);

int main(void) 
{
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	long long  a[m][n];
	shuru(m,n,a);
	long long sz[n][s];
	shuru(n,s,sz);
	long long arry[m][s];
	q_jz_xc(m,n,n,s,a,sz,arry);
	shuchu(m,s,arry);
	return 0;
}

void shuru(int h,int l,long long a[][l])
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

void q_jz_xc(int h0,int l0,int h1,int l1,long long a[][l0],long long s[][l1],long long arry[][l1])
{
 int i;
 for(i=0;i<h0;i++)
 {
  int j;
  for(j=0;j<l1;j++)
  {
  arry[i][j]=0;
  int k;
  for(k=0;k<l0;k++)
  {
  arry[i][j]+=a[i][k]*s[k][j];
  }
  }
 }
}

void shuchu(int h,int l,long long a[][l])
{
  int i;
  for(i=0;i<h;i++)
  {
   int k;
   for(k=0;k<l;k++)
   {
    printf("%d ",a[i][k]);
   }
   putchar('\n');
  }
}
#endif
/*
问题描述
　　编写并测试如下函数：
　　void Add (int a[], int m, int b[], int n);
　　该函数将数组b的前n个元素追加到数组a的前m个元素后，假定数组a具有至少存放m+n个元素的空间。
例如，如果数组a为{22,33,44,55,66,77,88,99}，数组b为{20,30,40,50,60,70,80,90}，
则调用Add(a,5,b,3)后，将把数组a变为{22,33,44,55,66,20,30,40}。注意数组b并没有改变，而且数组a中只需改变n个元素。
测试
　　输入：4行。第一行为两个整数：m，n，并以空格隔开，分别表示将要输入的数组a和数组b的元素的个数。
第二行为m个整数，为数组a的元素；第三行为n个整数，为数组b的元素。第四行为两个整数m1，n1，
表示把数组b的前n1个元素追加到数组a的前m1个元素后。
　　输出：1行。第一行为最后数组a中的元素，两个元素之间以逗号隔开。最后一个元素输出后，输出一个空行。
*/

#if 0
#include<stdio.h>
void shuru(int*,int );
void sc_sz(int*,int );
void Add(int [], int , int [], int );

int main(void)
{
int m, n;
scanf("%d%d",&m,&n);
int a[m],b[n];
shuru(a,m);
shuru(b,n);
int m1, n1;
scanf("%d%d",&m1,&n1);
Add(a,m1,b,n1);
if(n1==0)
{
sc_sz(a,m);
return 0;
}
sc_sz(a,m1+n1);
return 0;
}

void shuru(int*a,int n)
{
  while(n-->0)
  {
   scanf("%d",a++);
  }
}

void Add(int a[], int m, int b[], int n)
{
int i,k;
for(i=m,k=0;k<n;i++,k++)
{
a[i]=b[k];
}
}

void sc_sz(int a[],int n)
{
 while(n-->1)
 {
  printf("%d, ",*a++);
 }
 printf("%d ",*a++);
 putchar('\n');
}
#endif

#if 1
#include <stdio.h>

void shuru ( int , int ); 

int main(void) 
{
	int shu1 , shu2 ;
	shuru ( shu1 , shu2 );
	printf("二%d  %d\n", shu1 , shu2 ); 
	return 0;
}

void shuru ( int s1 , int s2 )
{
	scanf ("%d%d", &s1, &s2);
	//printf("一 %d  %d\n",  s1 , s2 );
}
#endif









