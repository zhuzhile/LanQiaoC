/*
问题描述
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
#define ZD 100000

void shuru(int [],int*);
int z_to_s(char);
void shuchu(int[],int); 
void q_twcd(int*,int*,int);
int q_zhi(int [],int);
int sc_wei(int [],int);
 
int main(void) 
{
	int n;
	scanf("%d\n",&n);
	while(n--)
	{
	 int shu_16[ZD],ws;
	 shuru(shu_16,&ws);
	 shuchu(shu_16,ws);
	}
	return 0;
}

int sc_wei(int s[],int n)
{
 int i;
 for(i = 0;i < n / 3;i ++,s+=3)
 {
  printf("%04o",q_zhi(s,3));
 }
}

int q_zhi(int s[],int ws)
{
 int zhi=0;
 while(ws --)
 {
  zhi*=16;
  zhi+=*s++;
 }
 return zhi;
}

void qiu_tw(int *p_t,int*p_w,int ws)
{
 *p_t=ws%3==0?3:ws%3;
 *p_w=ws-*p_t;
}

int z_to_s(char z)
{
 if('A' <= z && z <= 'Z')
 {
  return z-'A'+10; 
 }
 return z-'0';
}

void shuru(int s[],int *p_ws)
{
 *p_ws = 0;
 char w;
 while((w=getchar())!= '\n'&&w!=EOF)
 {
  s[*p_ws]=z_to_s(w);
  ++*p_ws;
 }
}

void shuchu(int a[],int ws)
{
  int tou,wei;
  q_twd(&tou,&wei,ws);
  printf("%o",q_zhi(a,tou));
  sc_wei(a + tou,wei);
  putchar('\n');
}

















