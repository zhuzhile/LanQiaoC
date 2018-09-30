/*
　在C/C++语言中，整型所能表示的范围一般为-231到231（大约21亿）,
即使long long型，一般也只能表示到-263到263。要想计算更加规模的数，就要用软件来扩展了，
比如用数组或字符串来模拟更多规模的数及共运算。
　　现在输入两个整数，请输出它们的乘积。
输入格式
　　两行，每行一个正整数，每个整数不超过10000位
输出格式
　　一行，两个整数的乘积。
样例输入
99
101
样例输出
9999
数据规模和约定
　　每个整数不超过10000位
*/
#if 1 
#include <stdio.h>
#include <string.h>

void shuru(int [],int *);
void jiaohuan(int*,int*);
void q_ji(int [],int *,int [],int,int [],int);
void jinw(int [],int *);
void shuchu(int [],int);

int main(void)
{
	int s1[10000] = {0} , ws1 = 0;
	int s2[10000] = {0} , ws2 = 0;
	shuru(s1,&ws1);
	shuru(s2,&ws2);
	int ji[40000] = {0} , jws = 0;
	q_ji(ji,&jws,s1,ws1,s2,ws2);
	shuchu(ji,jws);
	return 0;
}

void jinw(int ji[],int * p_jws)
{
	int i;
	for( i = 0 ; i < * p_jws ; i ++ )
	{
			ji[i + 1] += ji[i] / 10;
			ji[i] %= 10; 
	}
	* p_jws += ji[* p_jws] != 0;
}

void q_ji(int ji[],int * p_jws,int s1[],int n1,int s2[],int n2)
{
	int i;
	for( i = 0 ; i < n1 ; i ++ )
	{
		int k;
		for( k = 0 ; k < n2 ; k ++ )
		{
			ji[i + k] += s1[i] * s2[k] ;
			* p_jws = * p_jws > (i + k) ? (* p_jws) : (i + k);	//		
		}		
	}
	jinw(ji,p_jws);
}

void shuchu(int s[],int n)
{
	int i;
	for( i = n - 1 ; i >= 0 ; i -- )
	{
		printf("%d", s[i] );
	}
	putchar('\n');
}

void jiaohuan(int * a,int * b)
{
	int tmp = * a;
	* a = * b;
	* b = tmp ;
}

void nixu(int s[],int ws)
{
	int low = 0 , high = ws - 1;
	while( low < high )
	{
		jiaohuan(&s[low],&s[high]);
		low ++ ;
		high -- ;
	}
}

void shuru(int s[],int * p_ws)
{
	char  s0[10000+1];
	scanf("%s",s0);
	* p_ws=strlen(s0);
	int i;
	for(i=0;i<* p_ws;i++)
	{
	  s[i]=s0[i]-'0';
	}
	nixu(s,* p_ws);
}
#endif 

