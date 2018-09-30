/*
　给定n个十六进制正整数，输出它们对应的八进制数。
输入格式
　　输入的第一行为一个正整数n （1<=n<=10）。
　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。
输出格式
　　输出n行，每行为输入对应的八进制正整数。
　　【注意】
　　输入的十六进制数不会有前导0，比如012A。
　　输出的八进制数也不能有前导0。
样例输入
2
39
123ABC
样例输出
　　71
　　4435274
　　【提示】
　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。
*/ 
#include <stdio.h>

#define ZD (100000) 
void sr_arr(int [],int *);
int q_sjz(char);
void sc_arr(int [],int);
void q_tw(int *,int *,int);
int q_zhi(int [],int);
void sc_wei(int [],int);

int main(void)
{
	int n;
	scanf("%d\n", &n );
	while( n -- > 0 )
	{
		int arr[ZD] , wei = 0 ;
		sr_arr(arr,&wei);
		sc_arr(arr,wei);
	}
	return 0;
}

void sc_wei(int a[],int n)
{
	int i;
	for( i = 0 ; i < n / 3 ; i ++ , a += 3 )
	{
		printf("%04o", q_zhi(a,3) );
	}
}


int q_zhi(int a[],int n)
{
	int shu = 0;
	while( n -- > 0 )
	{
		shu *= 16;
		shu += * a ++;
	}
	return shu ;
}

void q_tw(int * p_t,int * p_w,int ws)
{
	* p_t = ws % 3 == 0 ? 3 : ws % 3 ;
	* p_w = ws - * p_t;
}

void sc_arr(int a[],int ws)
{
	int tou , wei ;
	q_tw(&tou,&wei,ws);
	printf("%o", q_zhi(a,tou)) ;
	sc_wei(a + tou,wei);
	putchar('\n');
}

int q_sjz(char c)
{
	if( 'A' <= c && c <= 'F')
	{
		return c - 'A' + 10 ;
	}
	return c - '0';
}

void sr_arr(int a[],int * p_w)
{
	char c;
	while( ( c = getchar() ) != '\n')
	{
		a[* p_w] = q_sjz(c);
		++ * p_w;
	}
}

