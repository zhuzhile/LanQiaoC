/*
问题描述
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

2 4
1 2 3 4 5 6 8 10
1 3 5
样例输入
4
1 2 3 4
3
5 6 7
19
93 55 99 62 23 54 83 67 71 85 20 57 64 38 4 48 37 29 52 
19
99 62 38 37 85 20 4 93 23 52 67 92 64 83 54 57 79 55 48 
4 20 23 37 38 48 52 54 55 57 62 64 67 83 85 93 99 
4 20 23 29 37 38 48 52 54 55 57 62 64 67 71 79 83 85 92 93 99 
29 71 

9
26 84 59 23 99 61 15 82 40 
9
21 25 55 59 26 12 69 30 82 

26 59 82 
12 15 21 23 25 26 30 40 55 59 61 69 82 84 99 
15 23 40 61 84 99 

26 59 82
12 15 21 23 25 26 30 40 55 59 61 69 82 84 99
15 23 40 61 84 99 


样例输出
1 2 3 4 5 6 7
1 2 3 4
1 2 3 4 5 6 7
1 2 3 4
*/
#include <stdio.h>
#include <stdlib.h>

void shuru (int [],int );
void shuchu (int [],int );
void q_jiao (int [],int *,int [],int ,int [],int );
void jiaohuan (int *,int * );
void q_bing (int * *,int *,int [],int ,int [],int );
void kuoda (int * *,int *,int);
void q_yu (int * *,int *,int [],int ,int [],int );
void paixu (int [],int );

int main(void) 
{
	int a_gs;
	scanf ("%d",&a_gs);	
	int a[a_gs];
	shuru (a,a_gs);	
	int * b,b_gs;
	scanf ("%d",&b_gs);
	b = calloc (b_gs,sizeof (int));
	shuru (b,b_gs);

	paixu (a,a_gs);
	paixu (b,b_gs);
	
	int j[1000],j_gs = 0;
	q_jiao (j,&j_gs,a,a_gs,b,b_gs);
	
	int * bing = NULL,bing_gs = 0;
	q_bing (&bing,&bing_gs,a,a_gs,b,b_gs);
	
	int * yu = NULL,yu_gs = 0;
	q_yu (&yu,&yu_gs,a,a_gs,b,b_gs);
	
	shuchu (j,j_gs);
	shuchu (bing,bing_gs);
	shuchu (yu,yu_gs);
	
	free (bing);
	free (yu);
	free (b);

	return 0;
}

void shuchu (int a[],int n)
{
	if (n==0)
	{
		putchar ('\n');
		return ;
	}
	printf ("%d ",*a);
	shuchu (a+1,n-1);
}

void q_yu (int * * p_p_y,int * p_y,int a[],int a_gs,int b[],int b_gs)
{
	if (a_gs == 0)
	{
		return ;
	}
	if (b_gs == 0 || * a < * b)
	{
	 kuoda (p_p_y,p_y,sizeof (int));
	 (* p_p_y)[* p_y - 1] = * a;
	 q_yu (p_p_y,p_y,a+1,a_gs-1,b,b_gs);
	 return;
	}
	
	if (*a==*b)
	{
	 q_yu (p_p_y,p_y,a+1,a_gs-1,b+1,b_gs-1);
	 return;
	}
	if (* a > * b)
	{
	 q_yu (p_p_y,p_y,a,a_gs,b+1,b_gs-1);
	 return; 
	}
	q_yu (p_p_y,p_y,a,a_gs,b+1,b_gs-1);
}

void kuoda (int * * p_p_b,int * p_bgs,int size)
{
 ++*p_bgs;
 if(*p_p_b==NULL)
 {
  *p_p_b=malloc(*p_bgs*size);
 }else{*p_p_b=realloc(*p_p_b,*p_bgs*size);
 }
}

void q_bing (int * *p_p_b,int * p_b,int a[],int ags,int b[],int bgs)
{
	if (ags != 0||bgs != 0)
	{
	  kuoda (p_p_b,p_b,sizeof (int));
	if(ags==0)
	{
	   (* p_p_b)[* p_b - 1] = * b;
		q_bing (p_p_b,p_b,a,ags,b+1,bgs-1);
		return ;
	}
	if(bgs==0)
	{
	    (* p_p_b)[* p_b - 1] = * a;
		q_bing (p_p_b,p_b,a+1,ags-1,b,bgs);
		return ;
	}
	
	if (* b < * a)
	{
		(* p_p_b)[* p_b - 1] = * b;
		q_bing (p_p_b,p_b,a,ags,b+1,bgs-1);
		return ;
	}
	
	if ( * a < * b) 
	{
		(* p_p_b)[* p_b - 1] = * a;
		q_bing (p_p_b,p_b,a+1,ags-1,b,bgs);
		return ;
	}
	(* p_p_b)[* p_b - 1] = * a;
	q_bing (p_p_b,p_b,a+1,ags-1,b+1,bgs-1);
	} 
}

void jiaohuan (int * p,int * q)
{
	int t = * p;
	* p = * q;
	* q = t;
}


void paixu (int a[],int n)
{
	if (n > 1)
	{
		int i;
		for (i = n - 1;i > 0;i --)
		{
			if (a[i] < a[i-1])
			{
				jiaohuan (a+i,a+i-1);
			}
		}
		paixu (a + 1,n - 1);
	}
	
}

void q_jiao (int j[],int * p_jgs,int a[],int ags,int b[],int bgs)
{
	if (ags == 0 ||bgs == 0)
	{
		return ;
	}
	if (* a < * b)
	{
		q_jiao (j,p_jgs,a+1,ags-1,b,bgs);
		return ;
	}
	if (* b < * a)
	{
		q_jiao (j,p_jgs,a,ags,b+1,bgs-1);
		return ;
	}
	j[(*p_jgs) ++] = * a;
	q_jiao (j,p_jgs,a+1,ags-1,b+1,bgs-1);
}


void shuru (int a[],int n)
{
	if (n > 0)
	{
	 scanf("%d",a);
	 shuru(a+1,n-1);
	}
}


