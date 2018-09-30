#if 0
#include <stdio.h>
void lianjie(char*,char*);

int main(void)
{
  char s[300];
  scanf("%s",s);
  char s1[180];
  scanf("%s",s1);
  lianjie(s,s1);
  puts(s);
  return 0;
}

void lianjie(char*s,char*s1)
{
 while(*s!=0)
 {
  s++;
 }
 while(*s=*s1,*s!=0)
 {
  s1++;
  s++;
 }
}
#endif
/*
"嘟嘟嘟嘟嘟嘟
　　喇叭响
　　我是汽车小司机
　　我是小司机
　　我为祖国运输忙
　　运输忙"
　　这是儿歌“快乐的小司机”。话说现在当司机光有红心不行，还要多拉快跑。多 
 拉不是超载，是要让所载货物价值最大，特别是在当前油价日新月异的时候。司机所拉货物为散货，如大米、面粉、沙石、泥土......
　　现在知道了汽车核载重量为w，可供选择的物品的数量n。
  每个物品的重量为gi,价值为pi。求汽车可装载的最大价值。（n<10000,w<10000,0<gi<=100,0<=pi<=100)
输入格式
　　输入第一行为由空格分开的两个整数n w
　　第二行到第n+1行，每行有两个整数，由空格分开，分别表示gi和pi
输出格式
　　最大价值（保留一位小数）
样例输入
5 36
99 87
68 36
79 43
75 94
7 35
样例输出
71.3
解释：
先装第5号物品，得价值35，占用重量7
再装第4号物品，得价值36.346,占用重量29
最后保留一位小数，得71.3
*/
#if0
#include <stdio.h>
typedef
struct
{
  int w;
  int v;
}zt_t;

void shuru(zt_t,int);

int main(void)
{
  int gs,zw;
  scanf("%d%d",&gs,&zw);
  zt_t zg;
  shuru(zg,gs);
  
  return 0;
}

void shuru(zt_t zg,int gs)
{
  int i;
  for(i=0;i<gs;i++) 
  {
   scanf("%d%d",&zg.w,&zg.v);
  }
}
#endif
/*
有n个人排队到r个水龙头去打水，他们装满水桶的时间t1、t2………..tn为整数且各不相等，
应如何安排他们的打水顺序才能使他们总共花费的时间最少？
输入格式
　　第一行n，r (n <=500,r<=75)
　　第二行为n个人打水所用的时间Ti (Ti<=100)；
输出格式
　　最少的花费时间
样例输入
3 2
1 2 3
样例输出
7

数据规模和约定
　　其中80%的数据保证n<=10


*/

#include<stdio.h>
void shuru(int* a,int n);
void paixu(int* a,int n);
void jiaohuan(int*,int*);
int q_he(int*,int);
int q_zxsj(int*,int,int);

int main(void)
{
 int n,m;
 scanf("%d%d",&n,&m);
 int a[n];
 shuru(a,n);
 printf("%d\n",q_zxsj(a,n,m));
 return 0;
}

void shuru(int * a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
}

void paixu(int*a ,int n)
{
  int i;
  for(i=1;i<n;i++)
  {
   int k;
   for(k=0;k<n-i;k++)
   {
    if(a[k]>a[k+1])
    {
	 jiaohuan(a+k,a+k+1);
	}

   }
  }

}

int q_zxsj(int*a,int n,int m)
{
  if(n<=m)
  {
  return q_he(a,n);
  }
  paixu(a,n);
  int count[n];
  int i;
  for(i=0;i<m;i++)
  {
   b[i]=a[i];
  }
  int k;
  for(k=i;k<n;k++)
  {
    b[k]=a[i]+a[i-r];
  } 
  return q_he(b,n);
}

void jiaohaun(int*p_1,int*p_2)
{
  int temp;
  temp=*p_1;
  *p_1=*p_2;
  *p_2=temp;
}

int q_he(int*a,int n)
{
 int i,he=0;
 for(i=0;i<n;i++)
 {
  he+=a[i];
 }
 return he;
}

