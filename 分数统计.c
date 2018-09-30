/*

问题描述
　　2016.4.5已更新此题，此前的程序需要重新提交。
问题描述
　　给定一个百分制成绩T，将其划分为如下五个等级之一：
　　90~100为A，80~89为B，70~79为C，60~69为D，0~59为E
　　现在给定一个文件inp，文件中包含若干百分制成绩（成绩个数不超过100），
 请你统计五个等级段的人数，并找出人数最多的那个等级段，
 按照从大到小的顺序输出该段中所有人成绩（保证人数最多的等级只有一个）。要求输出到指定文件oup中。
输入格式
　　若干0~100的正整数，用空格隔开
输出格式
　　第一行为5个正整数，分别表示A,B,C,D,E五个等级段的人数
　　第二行一个正整数，表示人数最多的等级段中人数
　　接下来一行若干个用空格隔开的正整数，表示人数最多的那个等级中所有人的分数，按从大到小的顺序输出。
样例输入
100 80 85 77 55 61 82 90 71 60
样例输出
2 3 2 2 1
3
85 82 80

*/
#if 0
#include <stdio.h>
void shuru(int*,int);
void fenduan(int*,int,int*);
void output(int*,int);
int q_zd(int*,int,int*);
void select(int,int*,int);
void shuchu(int*,int,int);
void swap(int*,int*);


int main(void) 
{
	int n;
	scanf("%d",&n);
    int a[n];
	shuru(a,n);
	int count[5]={0};
	fenduan(a,n,count);
	output(count,5);
	int xb=0;
	printf("%d\n",q_zd(count,5,&xb));
	select(xb,a,n);
	return 0;
}

void shuru(int*a,int n)
{
  int i; 
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
}

void fenduan(int*a,int n,int*count)
{
  int i;
  for(i=0;i<n;i++)
  {
   if(a[i]<60)
   {
     count[0]++;
   }else{if(a[i]<70)
   {
     count[1]++;
   }else{if(a[i]<80)
   {
    count[2]++;
   }else{if(a[i]<90){
   	count[3]++;
   }else{count[4]++;
   }
   }
   }
   }
  }
}

void output(int *count,int n)
{
  int i;
  for(i=n-1;i>=0;i--)
  {
   printf("%d ",count[i]);
  }
  putchar('\n');
}

int q_zd(int *count,int n,int *p_xb)
{
  int zd=count[0];
  int i;
  for(i=1;i<n;i++)
  {
   if(count[i]>zd)
   {
    zd=count[i];
    *p_xb=i;
   }
  }
  return zd;
}

void paixu(int *a,int n)
{
  int i;
  for(i=1;i<n;i++)
  {
  int k;
  for(k=0;k<n-i;k++)
  {
   if(a[k]>a[k+1])
   {
    swap(a+k,a+k+1);
   }
  }
  }
  output(a,n);
}

void select(int xb,int *a,int n)
{
  switch(xb)
  {
   case 0:shuchu(a,n,60);
   break;
   case 1:shuchu(a,n,70);
   break;
   case 2:shuchu(a,n,80);
   break;
   case 3:shuchu(a,n,90);
   break;
   case 4:shuchu(a,n,100);
   break;
  }

}

void shuchu(int *a,int n,int std)
{
  int i,xb=0;int b[1000];
  if(std==60)
  {
  for(i=0;i<n;i++)
  {
   if(a[i]<std)
   {
    b[xb]=a[i];
    xb++;
   }
  }
  paixu(b,xb);
  }else{if(std==100)
  {
   for(i=0;i<n;i++)
  {
   if(a[i]<=std
   &&a[i]>=std-10)
   {
    b[xb]=a[i];
    xb++;
   }
  }
  paixu(b,xb);
  }else{for(i=0;i<n;i++)
  {
   if(a[i]<std
   &&a[i]>=std-10)
   {
    b[xb]=a[i];
    xb++;
   }
  }
  paixu(b,xb);
  }
  }
  
}

void swap(int *q,int *p)
{
  int t;
  t=*q;
  *q=*p;
  *p=t;
}
#endif

/*
　　已知2011年11月11日是星期五，问YYYY年MM月DD日是星期几？注意考虑闰年的情况。尤其是逢百年不闰，逢400年闰的情况。
输入格式
　　输入只有一行
　　YYYY MM DD
输出格式
　　输出只有一行
　　W
数据规模和约定
　　1599 <= YYYY <= 2999
　　1 <= MM <= 12
　　1 <= DD <= 31，且确保测试样例中YYYY年MM月DD日是一个合理日期
　　1 <= W <= 7，分别代表周一到周日
样例输入
2011 11 11
样例输出
5
*/ 
#if 0
#include<stdio.h>

typedef
	struct
	{
		int nian ;
		int yue ;
		int ri ;
		int xq ;
	} riqi_t ;
	
void shuru(riqi_t *);
int q_xq(riqi_t);//求星期几 
int zq(riqi_t , riqi_t );//原日期在前 

void q_det(riqi_t *);//反复求第二天 
void q_dyd(riqi_t *);//大月底
void q_xyd(riqi_t *);//小月底
void q_eyd(riqi_t *);//二月底
int pdrn(int);//判断闰年
void q_ndd(riqi_t *);//年底

int zh(riqi_t , riqi_t );//原日期在后
void q_qyt(riqi_t *);//求前一天 
void q_qyw31c(riqi_t *);//前一月为31初 
void q_qyw30c(riqi_t *);//前一月为30初 
void q_syc(riqi_t *);//三月初 
void q_nc(riqi_t *);//年初 

int main(void)
{
	riqi_t ddrq;
	shuru(&ddrq);
	printf("%d\n", q_xq(ddrq) );
	return 0;
}

void shuchu(riqi_t const * p_ddrq)
{
	printf("%d-%02d-%02d\n", p_ddrq->nian , p_ddrq->yue , p_ddrq->ri );
}

void q_nc(riqi_t * p_yrq)//年初 
{
	if(p_yrq->ri == 1)
	{
		-- p_yrq->nian;
		p_yrq->yue = 12;
		p_yrq->ri = 31;
		return ;
	}
	-- p_yrq->ri;
}

void q_syc(riqi_t * p_yrq)//三月初
{
	if(p_yrq->ri == 1 )
	{
		-- p_yrq->yue;
		p_yrq->ri = 28 + pdrn(p_yrq->nian);
		return ;
	}
	-- p_yrq->ri;
}

void q_qyw30c(riqi_t * p_yrq)//前一月为30初 
{
	if(p_yrq->ri == 1)
	{
		-- p_yrq->yue;
		p_yrq->ri = 30 ;
		return   ;
	}
	-- p_yrq->ri;	
}

void q_qyw31c(riqi_t * p_yrq)//前一月为31初 
{
	if(p_yrq->ri == 1)
	{
		-- p_yrq->yue;
		p_yrq->ri = 31 ;
		return   ;
	}
	-- p_yrq->ri;	
}

void q_qyt(riqi_t * p_yrq)
{
	p_yrq->xq = p_yrq->xq == 1 ? 7 : ( p_yrq->xq - 1 ); 
	switch(p_yrq->yue)
	{
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			q_qyw31c(p_yrq);
			return ;
		case 5:
		case 7:
		case 10:
		case 12:
			q_qyw30c(p_yrq);
			return ;
		case 3:
			q_syc(p_yrq);
			return ;
		case 1:
			q_nc(p_yrq);
			return ;
	}	
} 

int zh(riqi_t ddrq, riqi_t yrq)
{
	if(ddrq.nian < yrq.nian )
	{
		return 1;
	}
	if(ddrq.nian > yrq.nian )
	{
		return 0;
	}
	if(ddrq.yue < yrq.yue )
	{
		return 1;
	}
	if(ddrq.yue > yrq.yue )
	{
		return 0;
	}
	return 	ddrq.ri < yrq.ri;	
} 

void q_ndd(riqi_t * p_yrq)
{
	if(p_yrq->ri == 31)
	{
		++ p_yrq->nian;
		p_yrq->yue = 1;
		p_yrq->ri = 1;
		return ;
	}
	++ p_yrq->ri;	
} 

int pdrn(int nian)
{
	if( nian % 400 == 0 )
	{
		return 1;
	}
	if( nian % 100 == 0 )
	{
		return 0;
	}
	return nian % 4 == 0;
}

void q_eyd(riqi_t * p_yrq)
{
	if(p_yrq->ri == 28 + pdrn(p_yrq->nian) )
	{
		++ p_yrq->yue;
		p_yrq->ri = 1 ;
		return ;
	}
	++ p_yrq->ri;	
}

void q_xyd(riqi_t * p_yrq)
{
	if(p_yrq->ri == 30)
	{
		++ p_yrq->yue;
		p_yrq->ri = 1 ;
		return ;
	}
	++ p_yrq->ri;	
}

void q_dyd(riqi_t * p_yrq)
{
	if(p_yrq->ri == 31)
	{
		++ p_yrq->yue;
		p_yrq->ri = 1 ;
		return   ;
	}
	++ p_yrq->ri;
}

void q_det(riqi_t * p_yrq)
{
	p_yrq->xq = p_yrq->xq == 7 ? 1 : ( p_yrq->xq + 1 ); 
	switch(p_yrq->yue)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			q_dyd(p_yrq);
			return ;
		case 4:
		case 6:
		case 9:
		case 11:
			q_xyd(p_yrq);
			return ;
		case 2:
			q_eyd(p_yrq);
			return ;	
		case 12:
			q_ndd(p_yrq);
			return ;
	}
}

int zq(riqi_t ddrq, riqi_t yrq)
{
	if(ddrq.nian > yrq.nian )
	{
		return 1;
	}
	if(ddrq.nian < yrq.nian )
	{
		return 0;
	}
	if(ddrq.yue > yrq.yue )
	{
		return 1;
	}
	if(ddrq.yue < yrq.yue )
	{
		return 0;
	}
	return 	ddrq.ri > yrq.ri;
}

int q_xq(riqi_t ddrq)
{
	riqi_t yrq = { 2011 , 11 , 11 , 5 };
	while( zq(ddrq,yrq) )
	{
		q_det(&yrq);
	}
	while( zh(ddrq,yrq) )
	{
		q_qyt(&yrq);
	}
	return yrq.xq ;
} 

void shuru(riqi_t * p_ddrq)
{
	scanf("%d", & p_ddrq->nian);
	scanf("%d", & p_ddrq->yue);
	scanf("%d", & p_ddrq->ri);
}
#endif
/*
问题描述
　　有些西方人比较迷信，如果某个月的13号正好是星期五，他们就会觉得不太吉利，
 用古人的说法，就是“诸事不宜”。请你编写一个程序，统计出在某个特定的年份中，
 出现了多少次既是13号又是星期五的情形，以帮助你的迷信朋友解决难题。
　　说明：（1）一年有365天，闰年有366天，所谓闰年，即能被4整除且不能被100整除的年份，
或是既能被100整除也能被400整除的年份；（2）已知1998年1月1日是星期四，用户输入的年份肯定大于或等于1998年。
　　输入格式：输入只有一行，即某个特定的年份（大于或等于1998年）。
　　输出格式：输出只有一行，即在这一年中，出现了多少次既是13号又是星期五的情形。
输入输出样例
样例输入
1998
样例输出
3
*/
#if 0
#include <stdio.h>

int main(void)
{
	
  int nian;
  scanf("%d",&nian);
  int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  a[1]=panduan(nian)?29:28;
  int xq= nian-1+(nian-1)/4+(nian-1)/400-(nian-1)/100;
  printf("%d\n",xq);
  printf("%d",q_hsxqwcs(12,a,xq));
  return 0;
}

int panduan(int n)
{
 return (n%4==0&&n%100!=0)==1;
}

int q_he(int nian)
{
  int cn,he=0;
  for(cn=1998;cn<nian;cn++)
  {
    he+=panduan(cn)?366:365;
  }
  return he;
}

int q_csxq(int nian)
{
  int xq=(q_he(nian)%7+4)%7;
  return xq;
}

int q_hsxqwcs(int n,int *a,int xq)
{
  int i,count=0,he=0;
  for(i=0;i<n;i++)
  {
   if(he+13+xq-12)%7==4)
   {
    count++;

   }
   he+=a[i];
  }
 return count;
}
#endif

/*
问题描述
　　有些西方人比较迷信，如果某个月的13号正好是星期五，他们就会觉得不太吉利，
 用古人的说法，就是“诸事不宜”。请你编写一个程序，统计出在某个特定的年份中，
 出现了多少次既是13号又是星期五的情形，以帮助你的迷信朋友解决难题。
　　说明：（1）一年有365天，闰年有366天，所谓闰年，即能被4整除且不能被100整除的年份，
或是既能被100整除也能被400整除的年份；（2）已知1998年1月1日是星期四，用户输入的年份肯定大于或等于1998年。
　　输入格式：输入只有一行，即某个特定的年份（大于或等于1998年）。
　　输出格式：输出只有一行，即在这一年中，出现了多少次既是13号又是星期五的情形。
输入输出样例
样例输入
1998
样例输出
3
*/
#if 0
#include <stdio.h>

int main(void)
{
	
  int nian;
  scanf("%d",&nian);
  int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  a[1]=panduan(nian)?29:28;
  
  int xq=q_csxq(nian);

  printf("%d",q_hsxqwcs(12,a,xq));
  return 0;
}

int panduan(int n)
{
 return (n%4==0&&n%100!=0||n%400==0)==1;
}

int q_he(int nian)
{
  int cn,he=0;
  for(cn=1998;cn<nian;cn++)
  {
    he+=panduan(cn)?366:365;
  }
  return he;
}

int q_csxq(int nian)
{
  int xq=q_he(nian)+3;
  return xq;
}

int q_hsxqwcs(int n,int *a,int xq)
{
  int i,count=0,he=0;
  for(i=0;i<n;i++)
  {
   if((he+13+xq-1)%7==5-1)
   {
    count++;
   }
   he+=a[i];
  }
 return count;
}
#endif
  /*
 2 算法训练 黑色星期五
 3 
 4 问题描述
 5 　　有些西方人比较迷信，如果某个月的13号正好是星期五，他们就会觉得不太吉利，用古人的说法，就是“诸事不宜”。请你编写一个程序，统计出在某个特定的年份中，出现了多少次既是13号又是星期五的情形，以帮助你的迷信朋友解决难题。
 6 　　说明：（1）一年有365天，闰年有366天，所谓闰年，即能被4整除且不能被100整除的年份，或是既能被100整除也能被400整除的年份；（2）已知1998年1月1日是星期四，用户输入的年份肯定大于或等于1998年。
 7 　　输入格式：输入只有一行，即某个特定的年份（大于或等于1998年）。
 8 　　输出格式：输出只有一行，即在这一年中，出现了多少次既是13号又是星期五的情形。
 9 　　输入输出样例
10 样例输入
11 1998
12 样例输出
13 3
14 */
#if 0
#include <stdio.h>

int getWeekOfFirstDay(int year)
{
    //已知1998年1月1日是星期四
     int i=1998,week=3;
    int days=0;
    
    for(i=1998;i<year;i++)
    {
        if(i%400==0||(i%4==0&&i%100!=0))
        days+=366;
        else
         days+=365;
     }
    
    return (days+week)%7;
 }
 
 void printBlackFridayTimes(int year)
{
     int day[2][12]={{31,28,31,30,31,30,31,31,30,31,30},{31,29,31,30,31,30,31,31,30,31,30}};
     int week=getWeekOfFirstDay(year),flag=year%400==0||(year%4==0&&year%100!=0)?1:0;
     int times=0,i,days=0;
     
     //遍历12个月 
    for(i=0;i<12;i++)
    {
        //判断每个月13号是否是黑色星期五 
        if((days+13+week)%7==5)
        times++;
        
        days+=day[flag][i]; 
     }
     
     printf("%d\n",times);
     return ;
 } 
 
int main()
 {     int year; 
    scanf("%d",&year);
     printBlackFridayTimes(year);
     
     return 0;
 }
#endif

#include <stdio.h>
#include <string.h>

void getUpper(char *str)
{
    int i = 0;
    while (str[i])
    {
	 if (str[i] >= 'a' && str[i] <= 'z')
        {
           str[i] -= 32;
         }
        i++;
       }
	}
     puts(str);
}

void getLower(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
         {
             str[i] += 32;
        }
         i++;
     }
    puts(str);
}
 
 void getReverse(char *str)
 {
     int len = strlen(str) - 1;
     while (len >= 0)
    {
        printf("%c", str[len--]);
     }
     printf("\n");
 }
 
 void getTra(char *str)
 {
     int i = 0;
     while (str[i])
     {
        if (str[i] >= 'A' && str[i] <= 'Z')
       {
            str[i] += 32;
        }
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
         }
     }
     puts(str);
 }
 
 void getAbb(char *str)
 {
     int flag = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
         }
         i++;
    }
    printf("%c", str[0]);
    for (i = 1; i < strlen(str); i++)
    {
        while (str[i] - str[i - 1] == 1)
        {
            flag++;
            i++;
            if(i)
        }
        if (flag > 1)
        {
            printf("-%c", str[i-1]);
        }
        else
        {
            printf("%c", str[i]);
        }
         flag = 0;
    }
     printf("\n");
}

int main(void)
 {
     int n;
    char str[220];
     scanf("%d%s", &n, str);
    switch (n)
    {
    case 1:
         getUpper(str);
        break;
     case 2:
         getLower(str);
         break;
   case 3:
         getReverse(str);
         break;
    case 4:
        getTra(str);
        break;
     case 5:
        getAbb(str);
     }
     return 0;
 }

