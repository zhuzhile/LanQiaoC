/*

问题描述
　　安全局搜索到了一批(n个)身份证号码，希望按出生日期对它们进行从大到小排序，
如果有相同日期，则按身份证号码大小进行排序。身份证号码为18位的数字组成，出生日期为第7到第14位
输入格式
　　第一行一个整数n，表示有n个身份证号码
　　余下的n行，每行一个身份证号码。
输出格式
　　按出生日期从大到小排序后的身份证号，每行一条
样例输入
5
466272307503271156
215856472207097978
234804580401078365
404475727700034980
710351408803093165
样例输出
404475727700034980
234804580401078365
215856472207097978
710351408803093165
466272307503271156
数据规模和约定
　　n<=100000

*/
#if 0
#include <stdio.h>
#include <string.h>

#define zd 20

typedef
struct 
{char s[zd];
 int  shu;
}jgt;

void input(int,jgt*);
void paixu(jgt*,int);
void output(jgt*,int);
void s_to_z(jgt*);
void swap(jgt*,jgt*);

int main(void) 
{
	int n;
	scanf("%d",&n);
	jgt sz[100000];
	int xb=0;
	input(n,sz);
	paixu(sz,n);
	output(sz,n);
	return 0;
}

void input(int n,jgt*sz)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%s",sz[i].s);
   sz[i].shu=0;
   s_to_z(&sz[i]);
  }
}

void s_to_z(jgt*sz)
{
  int i,k;
  for(k=6;k<=13;k++)
  {
    sz->shu*=10;
    sz->shu+=(sz->s[k]-'0'); 
  }
}

//void paixu( int*a,int beg,int end)
//{  
// int i, j;  
//  if(beg < end)  
//    {  
//     i = beg + 1;   
//     j = end;     
//     while(i < j)  
//    {  
//     if(a[i] > a[beg])    
//     {  
//        jiaohuan(&a[i], &a[j]);  
//        j--;  
//     }  
//     else  
//     {  
//      i++;    
//     }  
//     }  
//    if(a[i] >= a[beg])   
//     {  
//      i--;  
//     }  
//     jiaohuan(&a[beg], &a[i]);  
//     paixu(a,beg,i);  
//     paixu(a,j,end);  
//    }  
//}  


void paixu(jgt *sz,int n)
{
 int i;
 for(i=1;i<n;i++)
 {
  int k;
  for(k=0;k<n-i;k++)
  {
   if(sz[k].shu<sz[k+1].shu)
   {
    swap(sz+k,sz+k+1);
   }else{
    if(sz[k].shu==sz[k+1].shu)
    {
     if(strcmp(sz[k+1].s,sz[k].s)==1)
      {
      swap(sz+k,sz+k+1);
      }
    }
   }
   }
  }
}



void swap(jgt*p,jgt*q)
{
 jgt t;
 t=*p;
 *p=*q;
 *q=t;
}

void output(jgt*a,int n)
{ 
 int i=0;
 while(n--)
 {
  printf("%s\n",a[i++].s);
 }
}
#endif

/*

问题描述
　　给定一个正整数k(3≤k≤15),把所有k的方幂及所有有限个互不相等的k的方幂之和构成一个递增的序列，
例如，当k=3时，这个序列是：
　　1，3，4，9，10，12，13，…
　　（该序列实际上就是：30，31，30+31，32，30+32，31+32，30+31+32，…）
　　请你求出这个序列的第N项的值（用10进制数表示）。
　　例如，对于k=3，N=100，正确答案应该是981。
输入格式
　　只有1行，为2个正整数，用一个空格隔开：
　　k N
　　（k、N的含义与上述的问题描述一致，且3≤k≤15，10≤N≤1000）。
输出格式
　　计算结果，是一个正整数（在所有的测试数据中，结果均不超过2.1*109）。（整数前不要有空格和其他符号）。
样例输入
3 100
样例输出
981
3^0                                  2^0                                  
3^1 3^1+3^0                          2^1
3^2 3^2+3^0 3^2+3^1 3^2+3^0+3^1;     2^2
3^3                                  2^3
*/
#if 0
#include <stdio.h>
int q_cf(int,int);
int q_zhi(int*,int,int,int);
void q_ws(int,int*,int*a);

int main(void)
{
  int n,k,ws=0;
  scanf("%d%d",&k,&n);
  int a[12];
  q_ws(n,&ws,a);
  printf("%d",q_zhi(a,n,k,ws));
  return 0;
}

int q_zhi(int *a,int n,int k,int ws)
{
 int i,he=0;
 for(i=0;i<ws;i++)
 {
  if(a[i]!=0)
  {
   he+=q_cf(k,i);
  }
 }
 return he;
}

void q_ws(int n,int*p_ws,int *a)
{
 while(n!=0)
 {
   a[(*p_ws)++]=n%2;
   n/=2;
 }
}

int q_cf(int a,int n)
{
 int ji=1;
 while(n--)
 {
  ji*=a;
 }
 return ji;
}
#endif

#if 0
  /* 
    分析:   
    3^0                                 
    3^1 3^0+3^1                        
    3^2 3^0+3^2 3^1+3^2  3^0+3^1+3^2    
    规律当前n加进去一个，然后要再加上前面所有的个数  
    如果到了某个n,加前面所有的大于N个,就扫下剩下的第几个就行  
    时间复杂度O(n)  
    f(n)=1+2*f(n-1)   fn表示有几个数目前 
    f(0)=1; 
    f(1)=3; 
    f(2)=7;  
    求得大于等于N时的n，然后N-f(n-1)剩下的从左边开始数  
    */  
    #include <iostream>  
    #include <cstdio>  
    using namespace std;  
    const int N=1000+5;  
    int a[N];   //好奇怪改longlong最后一个测试数据会过不去   
    int main()  
    {  
        int n,i,len;   
        int now,k;   //k^i  
        while(cin>>k>>n){  
            len=0;  
            now=1;  
            while(len<n){  
                int tmp=len;  
                a[len++]=now;  
                for(i=0;i<tmp&&len<n;i++)  
                    a[len++]=now+a[i];          
                now*=k;  
            }  
            cout<<a[n-1]<<endl;  
        }  
        return 0;  
    } 
	
#endif 
#if 0
#include <stdio.h>

void zh (int [],int ,int *);
int q_shulie (int [],int ,int ,int );
int q_mi (int ,int );

int main(void) 
{
	int n,k;
	scanf ("%d%d",&k,&n);
	int a[1000];
	int ws = 1;
	zh (a,n,&ws);
	int sum = q_shulie (a,n,k,ws);
	printf ("%d\n",sum);
	return 0;
}

int q_mi (int k,int n)
{
	int sum = 1;
	int i;
	for (i = 1;i <= n;i ++)
	{
		sum *= k;
	}
	return sum;
}

int q_shulie (int a[],int n,int k,int ws)
{
	int sum = 0;
	int i;
	for (i = 1;i <= ws;i ++)
	{
		if (a[i] != 0)
		{
			sum += q_mi (k,i-1);
		}
	}
	return sum;
}

void zh (int a[],int n,int * p_ws)
{
	while (n != 0)
	{
		a[(* p_ws) ++] = n % 2;
		n /= 2;
	}
	(* p_ws) --;
}
#endif

#if 0
#include <stdio.h>
int main(void)
{

 return 0;
}
#endif

/*

问题描述
　　给定N个物品,每个物品有一个重量W和一个价值V.你有一个能装M重量的背包.
问怎么装使得所装价值最大.每个物品只有一个.
输入格式
　　输入的第一行包含两个整数n, m，分别表示物品的个数和背包能装重量。
　　以后N行每行两个数Wi和Vi,表示物品的重量和价值
输出格式
　　输出1行，包含一个整数，表示最大价值。
样例输入
3 5
2 3
3 5
4 7
样例输出
8
数据规模和约定
　　1<=N<=200,M<=5000.
 
*/
#include<stdio.h>
int panduan_max(int,int);
void shuru(int*dv,int*jz,int n);
void q_zdjz(int*,int*,int,int*,int);
void chush(int*b,int n);

int main(void)
{
    int n,zcwt,dcwt[1000],jz[1000];
    scanf("%d%d", &n, &zcwt);
    int b[5000]={0};
    
    shuru(dcwt,jz,n);
    q_zdjz(dcwt,jz,n,b,zcwt);
    printf("%d\n", b[zcwt]);
    return 0; 
}

int panduan_max(int p,int q)
{
 return p>q?p:q;
}


void shuru(int*dcwt,int*jz,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  scanf("%d%d",&dcwt[i],&jz[i]);
 }
}

void q_zdjz(int*dcwt,int*jz,int n,int *b,int zcwt)
{
  int i;
  for(i=0;i<n;i++)
    {
	int j;
    for(j=zcwt;j>=dcwt[i];j--)//从左向右会被错误覆盖 
    {
        b[j]=panduan_max(b[j],b[j-dcwt[i]]+jz[i]);
    }
    }

}



