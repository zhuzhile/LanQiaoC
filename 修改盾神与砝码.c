/*
问题描述
　　有一天，他在宿舍里无意中发现了一个天平！这个天平很奇怪，有n个完好的砝码，
但是没有游码。盾神为他的发现兴奋不已！于是他准备去称一称自己的东西。他准备好了m种物品去称。
神奇的是，盾神一早就知道这m种物品的重量，他现在是想看看这个天平能不能称出这些物品出来。
但是盾神稍微想了1秒钟以后就觉得这个问题太无聊了，于是就丢给了你。
输入格式
　　第一行为两个数，n和m。
　　第二行为n个数，表示这n个砝码的重量。
　　第三行为m个数，表示这m个物品的重量。
输出格式
　　输出m行，对于第i行，如果第i个物品能被称出，输出YES否则输出NO。
样例输入
4 2
1 2 4 8
15 16
样例输出
YES
NO
样例输入
4 1
10 7 1 19
6
样例输出
YES
数据规模和约定
　　1<=n<=24, 1<=m<=10
*/
#if 0
#include <stdio.h>
void shuru(int*,int);
void sort(int*,int ); 
void jiaohuan(int*,int*);
int q_zwt(int*a,int n);
int panduan(int *,int ,int ,int ,int);
void output( int [] , int );


int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n];
	shuru(a,n);
	
	int zwt=q_zwt(a,n);
	sort(a,n);
	int sz[m];
	shuru(sz,m);
	
	int i;
	for(i=0;i<m;i++)
	{
	 	printf("%s\n",panduan(a,0,n,sz[i],zwt)?"YES":"NO");
	} 
	return 0;
}

void output( int a[] , int n )
{
	while( n -- )
	{
		printf("%d ", * a ++ );
	}
	putchar('\n');
}


void shuru(int *a,int n)
{
  while(n-->0)
  {
   scanf("%d",a++);
  }
}


int q_zwt(int *a,int n)
{
 int i,he=0;
 for(i=0;i<n;i++)
 {
  he+=a[i];
 }
 return he;
}


void sort(int *a,int n )
{
int i;
for(i=1;i<n;i++ )
{
 int j;
 for(j=0;j<n-i;j++ )
 {
	if(a[j]<a[j+1] )
	{
		jiaohuan(a+j,a+j+1);
	}
 }
}
} 


void jiaohuan(int *q,int* p)
{
  int t=*q;
  *q=*p;
  *p=t;
}


int panduan(int *a,int k,int n,int dcwt,int zfmwt)
{
 if(k==n)
 {
  return dcwt==0;
 }
 if(dcwt==zfmwt)
 {
  return 1;
 }
 if(dcwt>zfmwt)
 {
  return 0;
 }
 return panduan(a,k+1,n,dcwt+a[k],zfmwt-a[k]) ||  
	    panduan(a,k+1,n,dcwt-a[k],zfmwt-a[k]) ||  
		panduan(a,k+1,n,dcwt,zfmwt-a[k]);
}

#endif
/*
问题描述
　　Torry从小喜爱数学。一天，老师告诉他，像2、3、5、7……这样的数叫做质数。Torry突然想到一个问题，
前10、100、1000、10000……个质数的乘积是多少呢？他把这个问题告诉老师。
老师愣住了，一时回答不出来。于是Torry求助于会编程的你，请你算出前n个质数的乘积。
不过，考虑到你才接触编程不久，Torry只要你算出这个数模上50000的值。
输入格式
　　仅包含一个正整数n，其中n<=100000。
输出格式
　　输出一行，即前n个质数的乘积模50000的值。
样例输入

1


样例输出

2


*/
#if 0
#include <stdio.h>
int q_zscj(int n);
int panduan(int);

int main(void)
{
   int n;
   scanf("%d",&n);
   printf("%d\n",q_zscj(n));
   return 0;
}

int q_zscj(int n)
{
  int i,k=0,ji=1;
  for(i=2;k<n;i++)
  {
   if(panduan(i))
   {
    k++;
    ji=ji*i%50000;
   }
  }
  return ji;
}

int panduan(int n)
{
  int i;
  for(i=2;i*i<=n;i++)
  {
   if(n%i==0)
   {
    return 0;
   }
  }
  return 1;
}
#endif

/*
一共有5个红领巾，编号分别为A、B、C、D、E，老奶奶被他们其中一个扶过了马路。

　　五个红领巾各自说话：
   A ：我和E都没有扶老奶奶

　　B ：老奶奶是被C和E其中一个扶过大街的

　　C ：老奶奶是被我和D其中一个扶过大街的

　　D ：B和C都没有扶老奶奶过街

　　E ：我没有扶老奶奶

　　

　　已知五个红领巾中有且只有２个人说的是真话，请问是谁扶这老奶奶过了街？

　　若有多个答案，在一行中输出，编号之间用空格隔开。


　　例如
　　A B C D E（这显然不是正确答案）?
 
*/
#if 0
#include <stdio.h>
void q_flnndr(int*,int,int);

int main(void)
{
  int a[5]={0};
  q_flnndr(a,5,0);
  return 0;
}

void q_flnndr(int*a,int n,int k)
{
  int i;
  for(i=0;i<n;i++)
  {
   a[i]=1;
   if(panduan(a,n))
   {
    printf("%c ",'A'+i);
   }
   a[i]=0;
  }
}


int panduan(int *a,int n)
{
 return (a[0]+a[4]==0)+(a[2]+a[4]==1)+(a[2]+a[3]==1)+(a[1]+a[2]==0)+(a[4]==0)==2;
}

#endif
#if 1
#include <stdio.h>
void test(int*a,int n,int k)
{
  if(k==n)
  {
   output(a,n);
   return ;
  }
  for(a[k]=0;a[k]<2;a[k]++)
  {
   test(a,n,k+1);
  }
}

output(int*a,int n)
{
  while(n-->0)
  {
   printf("%d",*a++);
  }
  putchar('\n');

}

int main(void)
{
  int a[5]={0};
  test(a,5,0);
  return 0;
} 


#endif


