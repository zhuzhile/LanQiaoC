
/*

问题描述
　　从1999年10月1日开始，公民身份证号码由15位数字增至18位。(18位身份证号码简介)。升级方法为：
　　1、把15位身份证号码中的年份由2位(7,8位)改为四位。
　　2、最后添加一位验证码。验证码的计算方案：
　　将前 17 位分别乘以对应系数 (7 9 10 5 8 4 2 1 6 3 7 9 10 5 8 4 2) 并相加，
    然后除以 11 取余数，0-10 分别对应 1 0 x 9 8 7 6 5 4 3 2。
　　请编写一个程序，用户输入15位身份证号码，程序生成18位身份证号码。假设所有要升级的身份证的四位年份都是19××年
输入格式
　　一个15位的数字串，作为身份证号码
输出格式
　　一个18位的字符串，作为升级后的身份证号码
样例输入
110105491231002
样例输出
11010519491231002x
数据规模和约定
　　不用判断输入的15位字符串是否合理
 
*/
#if 0
#include <stdio.h>

void change(char*);
char select(int);
void output(char*,int);
int test(int*,int,char*);

int main(void)
{
  char s[19];
  gets(s);
  int xs[17]={7 ,9 ,10 ,5 ,8 ,4 ,2 ,1 ,6 ,3 ,7 ,9 ,10 ,5 ,8 ,4 ,2};
  change(s);
  output(s,test(xs,17,s));
  return 0;
}

void change(char*s)
{
 int i;
 for(i=16;i>=8;i--)
 {
  s[i]=s[i-2];
 }
 s[6]='1';
 s[7]='9';
}

int test(int*a,int n,char*s)
{
 int i,sum=0;
 for(i=0;i<18;i++)
 {
  sum+=((s[i]-'0')*a[i]);
 }
 return sum%11;
}


void output(char*s,int n)
{
 int i;
 for(i=0;i<17;i++)
 {
  putchar(s[i]);
 }
 putchar(select(n));
}

char select(int n)
{
 switch(n)
 {
  case 0: return '1';
  break;
  case 1: return '0';
  break;
  case 2: return 'x';
  break;
  case 3: return '9';
  break;
  case 4: return '8';
  break;
  case 5: return '7';
  break;
  case 6: return '6';
  break;
  case 7: return '5';
  break;
  case 8: return '4';
  break;
  case 9: return '3';
  break;
  case 10: return '2';
  break;
  }
}
#endif
/*

问题描述

小明正在玩一个“翻硬币”的游戏。

桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。

比如，可能情形是：**oo***oooo

如果同时翻转左边的两个硬币，则变为：oooo***oooo

现在小明的问题是：如果已知了初始状态和要达到的目标状态，
每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？

我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求：
输入格式

两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000
输出格式

一个整数，表示最小操作步数。
样例输入1
**********
o****o****
样例输出1
5
样例输入2
*o**o***o***
*o***o**o***
样例输出2
1

*/
#if 0
#include <stdio.h>
#include <string.h>
#define zd 1000

int min_step(char*,char*);

int main(void)
{
  char a[zd],b[zd];
  gets(a);
  gets(b);
  printf("%d\n",min_step(a,b));
  return 0;
}

int min_step(char*a,char*b)
{
 int len=strlen(a);
 int i,step=0;
 for(i=0;i<len;i++)
 {
  if(a[i]==b[i])
  {
   continue;
  }else
  {
   b[i+1]=b[i+1]=='*'?'o':'*';
   step++;
  }
 }
 return step;
}
#endif
#if 0
# include <stdio.h>  
int turn(int a[], int b[])  
{  
    int n = 0;
	int i;  
    for( i = 0; a[i] != EOF; i++) {  
        if(a[i] == b[i]) {  
            continue;  
        } else {  
            b[i + 1] = (b[i + 1] == '*' ? 'o' : '*');  
            n++;  
        }  
    }  
    return n;  
}  
int main(void)  
{  
    int a[1000];  
    int b[1000];  
    int c;  
    int i;  
    i = 0;  
    while((c = getchar()) != '\n') {  
        a[i++] = c;  
    }  
    a[i] = EOF;  
    i = 0;  
    while((c = getchar()) != '\n') {  
        b[i++] = c;  
    }  
    b[i] = EOF;  
    printf("%d\n", turn(a, b));  
}  
#endif
/*

标题：贪吃蛇长度


|                                                 |
|    H#############  ##  ## T# ###  ################## ######################################### #######@########################################### # ####@#######@######################@################
|                                           |
|                      |
|                      |
|                   |
|                           |
|                           |
|                       |
|                       |
|        |
|       |
|        |
|                      |
|          |
|                    |
|                      |
+-------------------------------------------------+

    小明在爷爷的私人收藏馆里找到一台老式电脑。居然没有图形界面，只能用控制台编程。
经过小明的一阵摸索，神奇地设计出了控制台上的贪食蛇游戏。

    如上图，是游戏时画面截图。
    其中，H表示蛇头，T表示蛇尾。#表示蛇的身体，@表示身体交叉重叠的地方。
    你能说出现在的贪吃蛇长度是多少吗？

    其实，只要数出#的数目算1，数出@的数目，算2，再加上头尾各算1就计算好了。

    人工数一下？太累眼睛了，聪明的你为什么不让计算机帮忙呢？

    本题的要求就是： 请填写上图中贪食蛇的长度是多少？

    注意：需要提交的是一个整数，不要添加任何多余内容（比如说明或注释）



*/
#include <stdio.h>
#include <string.h>
#define zd 10000

int main(void)
{
 char s[zd];
 int xb=0;
 char c;
 while((c=getchar())!='1')
 {
  s[xb]=c;
  xb++;
 }
 int len=strlen(s);
 int i,sum=0;
 for(i=0;i<len;i++)
 {
  if(s[i]=='#'||s[i]=='T'||s[i]=='H')
  {
   sum++;
  }
  if(s[i]=='@')
  {
   sum+=2;
  }
 }
 printf("%d\n",sum);
 return 0;
} 

