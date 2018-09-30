/*

问题描述
　　"嘟嘟嘟嘟嘟嘟
　　喇叭响
　　我是汽车小司机
　　我是小司机
　　我为祖国运输忙
　　运输忙"
　　这是儿歌“快乐的小司机”。话说现在当司机光有红心不行，还要多拉快跑。
  多拉不是超载，是要让所载货物价值最大，特别是在当前油价日新月异的时候。
   司机所拉货物为散货，如大米、面粉、沙石、泥土......
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
#if 0
#include <stdio.h>

typedef
struct {int wt;
int jz;
double dwjz;
}wp_t;

void  shuru(wp_t *,int ); 
double q_zdjz(wp_t*,int,int);
void paixu(wp_t*, int);
void swap(wp_t*,wp_t*);
 
int main(void) 
{
	int xz,zl;
	scanf("%d%d",&xz,&zl);
	wp_t a[xz];
	shuru(a,xz);

	paixu(a,xz);

    printf("%.1lf",q_zdjz(a,xz,zl));
	return 0;
}

void shuru(wp_t*a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%d%d",&a[i].wt,&a[i].jz);
   a[i].dwjz=(double)a[i].jz/(double)a[i].wt;
  }
}

void paixu(wp_t*b, int n) 
{
  int i;
  for(i=1;i<n;i++)
  {
   int k;
   for(k=0;k<n-i;k++)
   {
    if(b[k].dwjz<b[k+1].dwjz)
    {
	 swap(b+k,b+k+1);
	}
   }
  }
}

void swap(wp_t*p,wp_t*q)
{
  wp_t t=*p;
  *p=*q;
  *q=t;
}

double q_zdjz(wp_t*a,int n,int zzl)
{
  int i;double ly=0.;
  for(i=0;i<n;i++)
  {
   if(zzl-a[i].wt>0&&zzl>0.)
   {
    ly+=a[i].jz;
    zzl-=a[i].wt;
   }else{ly+=a[i].dwjz*zzl;
   break;
   }
  }
  return ly;
}
#endif
/*
/*
问题描述
　　我们用0表示林丹，1表示李宗伟。
　　输入数据中每行会给出一个0或者1，表示对应选手得1分。
　　当一方得分达到21分时，只要该方与对方分差超过1分，该方即胜出。
　　你需要输出最后获胜选手的代号。
输入格式
　　若干行每行一个0或者1。
输出格式
　　一行一个0或者1表示胜者。
样例输入
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
样例输出
1
数据规模和约定
　　输入数据可能存在多余信息，选手需要在第一次出现胜者时马上输出。
　　读入可以使用while (cin >> x){}，该代码块会在读入所有数据后执行完毕。
*/
#if 1
#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
  int ld=0,lzw=0,fs;
  while(scanf("%d",&fs))
  {
   if(fs==1)
   {
    lzw++;
   }else{ld++;
   }
   if((ld>=21||lzw>=21)&&abs(lzw-ld)>1)
   {
    printf("%d\n",ld>lzw?0:1);
    break;
   }
  }
  return 0;
}
#endif
#if 0 
#include <stdio.h>

int main(void)
{
  int n;
  while(scanf("%d",&n))
  {
   if(n!=1)
   {
    return 0;
   }
  }
  return 0;
}
#endif
