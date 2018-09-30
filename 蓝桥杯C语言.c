/*
按格式格式读入一个3位的整数、一个实数、一个字符 。
　　并按格式输出 一个整数占8位左对齐、一个实数占8位右对齐、一个字符 ，并用|隔开。
输入格式
　　见题面
输出格式
　　见题面
样例输入
123456.789|a
样例输出
123 | 456.8|a
 
*/ 
#if 0
#include <stdio.h>


int main(void) 
{   int a;
    double b;
	char c;
	scanf("%d%lf%d",&a,&b,&c);
	printf("%-8d%8.lf%c",a,b,c);
	
	return 0;
}

#endif
#if 0
#include<stdio.h>
void shuru(int [][18],int n);
void paixu(int [][18],int n);
void shuchu(int [][18],int n);
void swap(int *,int *);

int main(void)
{
  int n;
  int a[n][18];
  shuru(a,n);
  paixu(a,n);
  shuchu(a,n);
  return 0;
}

void shuru(int a[][18],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   int k;
   for(k=0;k<18;k++)
   {
     scanf("%d",&a[i][k]);
   }
  }
}

void shuchu(int a[][18],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   int k;
   for(k=0;k<18;k++)
   {
     printf("%d",a[i][k]);
   }
  }
}

void paixu(int a[][18],int n)
{
  int i;
  for(i=6;i<18;i++)
  {
  int k,len=1;
  for(k=0;k<n-len;k++)
  {
   if(a[i][k]<a[i][k+1])
   {
    swap(a[i],a[i+1])
   }
  }
  }

}

void swap(int *p_1,int *p_2)
{
  int temp;
  temp=*p_1;
  *p_1=*p_2;
  *p_2=temp; 

}
#endif

/*
给出两个整数集合A、B，求出他们的交集、并集以及B在A中的余集。
输入格式
　　第一行为一个整数n，表示集合A中的元素个数。
　　第二行有n个互不相同的用空格隔开的整数，表示集合A中的元素。
　　第三行为一个整数m，表示集合B中的元素个数。
　　第四行有m个互不相同的用空格隔开的整数，表示集合B中的元素。
　　集合中的所有元素均为int范围内的整数，n、m<=1000。
输出格式
　　第一行按从小到大的顺序输出A、B交集中的所有元素。
　　第二行按从小到大的顺序输出A、B并集中的所有元素。
　　第三行按从小到大的顺序输出B在A中的余集中的所有元素。
样例输入
5
1 2 3 4 5
5
2 4 6 8 10
样例输出
2 4
1 2 3 4 5 6 8 10
1 3 5
样例输入
4
1 2 3 4
3
5 6 7
样例输出
1 2 3 4 5 6 7
1 2 3 4
*/
#if 0
#include<stdio.h>

void shuru(int *,int );
void paixu(int*,int );
void jiaohuan(int*,int*);
void shuchu(int*,int);
void q_jq(int *,int*,int,int);
void panduanjq(int *,int*,int);
void panduanbj(int *,int*,int *,int,int);
void panduanyj(int *,int*,int);

int main(void)
{
  int n;
  scanf("%d",&n);
  int a[n];
  shuru(a,n);
  paixu(a,n);
  int m;
  scanf("%d",&m);
  int s[m];
  shuru(s,m);
  paixu(s,m);
  q_jq(a,s,n,m);
  return 0;
}

void shuru(int *a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
}

void q_jq(int *a,int *s,int n,int m)
{
  int count[n];
  int j;
  for(j=0;j<n;j++)
  {
   count[j]=0;
  } 
  int i;
  for(i=0;i<n;i++)
  {
   int k;
   for(k=0;k<m;k++)
   {
    if(a[i]==s[k])
    {
	 count[i]++;
	}
   }
  }
  panduanjq(count,a,i);
  panduanbj(count,a,s,i,m);
  panduanyj(count,a,i);
}

void panduanjq(int *count,int *a,int n)
{ 
  int i;
  for(i=0;i<n;i++)
  {
   if(count[i]==1)
   {
   printf("%d ",a[i]);
   }
  }
  putchar('\n');
}

void panduanyj(int *count,int *a,int n)
{ 
  int i;
  for(i=0;i<n;i++)
  {
   if(count[i]==0)
   {
   printf("%d ",a[i]);
   }
  }
  putchar('\n');
}

void panduanbj(int *count,int *a,int *s,int n,int m)
{ 
  int i,sz[2000]={0},xb=0;
  for(i=0;i<n;i++)
  {
   if(count[i]==0)
   {
     sz[xb]=a[i];
     xb++;
   }
  }
  int j;
  for(j=0;j<m;j++)
  {
   sz[xb]=s[j];
   xb++;
  }
  paixu(sz,xb);
  shuchu(sz,xb);
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
	  jiaohuan(a+k,a+k+1);
	 }
   }
  }
}

void jiaohuan(int*p_1,int*p_2)
{
 int temp;
 temp=*p_1; 
 *p_1=*p_2;
 *p_2=temp;
}

void shuchu(int *count,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   printf("%d ",count[i]);
  } 
  putchar('\n');
}
#endif
/*
问题描述
　　按格式格式读入一个3位的整数、一个实数、一个字符 。
　　并按格式输出 一个整数占8位左对齐、一个实数占8位右对齐、一个字符 ，并用|隔开。
输入格式
　　见题面
输出格式
　　见题面
样例输入
123456.789|a
样例输出
123 | 456.8|a
*/
#if 0
#include <stdio.h>

int main(void)
{
 int n;
 double m;
 char s[2];
 scanf("%3d%lf%s",&n,&m,s) ;
 printf("%-8d|%8.1f%s",n,m,s);
 return 0;
}
#endif

#include<stdio.h>
#include<string.h>
void panduan(char *,char*);
void tjzf(int*,char*);

int main(void)
{
 char s_0[180];
 gets(s_0);
 char s_1[180];
 gets(s_1);
 panduan(s_0,s_1);
 return 0;
}

void tjzf(int *count,char *str)
{
  int len=strlen(str);
  int i;
  for(i=0;i<len;i++)
  {
   if(str[i]>='a'&&str[i]<='z')
   {
    count[str[i]-'a']++;
   }else{count[str[i]-'A']++;
   }
  }

}


void panduan(char str_0[],char str_1[])
{
  int count_0['z'-'a']={0};
  int count_1['z'-'a']={0};
  tjzf(count_0,str_0);
  tjzf(count_1,str_1);
  int i;
  for(i=0;i<'z'-'a';i++)
  {
    if(count_0[i]!=count_1[i])
    {
	 printf("N");
	 return;
	}
  }
  printf("Y");
}



