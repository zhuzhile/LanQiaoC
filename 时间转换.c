
/*
输入格式
　　输入只有一行，是一个整数t（0<=t<=86399）。
输出格式
　　输出只有一行，是以“<H>:<M>:<S>”的格式所表示的时间，不包括引号。
样例输入
0
样例输出
0:0:0
样例输入
5436
样例输出
1:30:36
*/

#include <stdio.h>

int main(void) 
{
	int n;
	scanf("%d",&n);
	printf("%d:%d:%d",n/3600,
	n/60-n/3600*60,
	n-n/3600*3600-(n/60-n/3600*60)*60); 
	return 0;
}

