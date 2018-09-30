/*
问题描述
　　某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
虽然它的第一发炮弹能够到达任意的高度，
但是以后每一发炮弹都不能高于前一发的高度。
某天，
雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数），
计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
输入格式
　　一行，为导弹依次飞来的高度
输出格式
　　两行，分别是最多能拦截的导弹数与要拦截所有导弹最少要配备的系统数
样例输入
389 207 155 300 299 170 158 65
样例输出
6
2
*/
#if 1
#include <stdio.h>
void q_max(int,int*,int*);

int main(void) 
{
   int i=0;
   int max_len[10];
   int a[10];
   while(1)
   {
    scanf("%d",&a[i]);
    max_len[i]=1;
    i++;
    char ch=getchar();
    if(ch='\n')
    {
	 break;
	}
   }
   q_max(i,a,max_len);
   printf("%d\n",q_zdz(i,max_len));
   return 0;
}

void q_max(int n,int *a,int *max_len)
{
 int i;
 for(i=1;i<n;i++)
 {
 int k;
 for(k=0;k<i;k++)
 {
  if(a[i]<a[k])
  {
   max_len[i]=max(max_len[i],max_len[k]+1);
  }
 }
 }
}

int max(int a,int b)
{
 return a>b?a:b;
}

int q_zdz(int n,int *a)
{
 int i;
 int zd=a[0];
 for(i=1;i<n;i++)
 {
  printf("%d ",a[i]);
  if(zd<a[i])
  {
   zd=a[i];
  }
 }
 return zd;
}
#endif
#if 0
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int maxn = 100;
vector<int> Bomb;
void solve();

void solve() 
{
    int ans = 0, cnt = 0, high;
    int up[maxn],         //最长上升子序列 
        down[maxn];       //最长下降子序列 
    while (cin >> high) {
        Bomb.push_back(high);
    }
    unsigned len = Bomb.size(); 
    for (unsigned i = 0; i < len; i++) {
        down[i] = 1;
        up[i] = 1;
        for (int j = 0; j < i; j++) {
            if (Bomb[j] > Bomb[i]) {
                down[i] = max(down[i], down[j] + 1);
            }
            if (Bomb[j] < Bomb[i]) {
                up[i] = max(up[i], up[j] + 1);
            }
            ans = max(ans, down[i]);
            cnt = max(cnt, up[i]);
        }
    }
    
    printf("%d\n%d\n", ans, cnt);    
}

int main()
{
    solve();
    return 0;
#endif

