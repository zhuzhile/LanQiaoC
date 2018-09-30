/*
问题描述
　　扑克牌排序：构造扑克牌数组，对扑克牌进行排序。排序原则如下：
数字从小到大是2-10、J、Q、K和A，花色从小到大是方块（diamond）、
梅花（club）、红桃（heart）、黑桃（spade）。两张牌比较时先看数字，数
字相同时看花色。要求对输入的扑克牌进行从小到大排序。
　　输入五张牌（表示黑桃2、红桃3、黑桃3、方块A和梅花J）： 2 s 3 h 3 s A d J c
　　输出结果应为：2 s 3 h 3 s J c A d数组长度固定为5。
样例输出
与上面的样例输入对应的输出。
例：

数据规模和约定
　　输入数据中每一个数的范围。
*/

#include<stdio.h>
typedef
struct
{
 char shu;
 char hs;
}PDX_t;

void shuru(PDX_t *,int);
void shuchu(PDX_t *,int );
void bjiao(PDX_t *,int,char*,char*);
int find(char,char*);
void jiaohuan(PDX_t*,PDX_t*);

int main(void)
{
  PDX_t ps[5];
  shuru(ps,5);
 char shuz[]={'2','3','4','5','6','7','8','9','J','Q','K','A'};
 char hss[]={'d','c','h','s'};
 bjiao(ps,5,shuz,hss);
  shuchu(ps,5); 
  return 0;
}

void shuru(PDX_t *s,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  scanf(" %c %c",&s[i].shu,&s[i].hs);
 }
}

int find(char a,char*sz)
{
	int i,count=0;
	while(*sz!=0)
	{
	 count++;
	 if(a==*sz)
	 {
	  break;
	 }
	 sz++;
	}
	return count;
}

void bjiao(PDX_t *s,int n,char *shuz,char*hss)
{
  int i;
  for(i=1;i<n;i++)
  {
   int k;
   for(k=0;k<n-i;k++)
   {
   	   int kdx=find(s[k].shu,shuz);
   	   int kdx1=find(s[k+1].shu,shuz);
    if ( kdx>kdx1 )
    {
	  jiaohuan(s+k,s+1+k);
	}
	else
	{
	  if(kdx==kdx1)
	  {
	    if(find(s[k].hs,hss)>find(s[k+1].hs,hss))
	    {
		  jiaohuan(s+k,s+1+k);
		}
	  }
	}
    }
  }
}

void jiaohuan(PDX_t *p,PDX_t *q)
{
  PDX_t t;
  t=*p;
  *p=*q;
  *q=t;
}

void shuchu(PDX_t *s,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("%c%c ",s[i].shu,s[i].hs);
 }
}


