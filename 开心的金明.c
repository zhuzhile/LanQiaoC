/*
问题描述
　　Hanks 博士是BT (Bio-Tech，生物技术) 领域的知名专家，他的儿子名叫Hankson。
现 在，刚刚放学回家的Hankson 正在思考一个有趣的问题。 
今天在课堂上，老师讲解了如何求两个正整数c1 和c2 的最大公约数和最小公倍数。
现 在Hankson 认为自己已经熟练地掌握了这些知识，他开始思考一个“求公约数”和“求公 倍数”
之类问题的“逆问题”，这个问题是这样的：已知正整数a0,a1,b0,b1，
设某未知正整 数x 满足： 1． x 和a0 的最大公约数是a1；
 2． x 和b0 的最小公倍数是b1。 Hankson 的“逆问题”就是求出满足条件的正整数x。
 但稍加思索之后，他发现这样的 x 并不唯一，甚至可能不存在。
 因此他转而开始考虑如何求解满足条件的x 的个数。请你帮 助他编程求解这个问题。
输入格式
　　输入第一行为一个正整数n，表示有n 组输入数据。

　　接下来的n 行每 行一组输入数据，为四个正整数a0，a1，b0，b1，
每两个整数之间用一个空格隔开。输入 数据保证a0 能被a1 整除，b1 能被b0 整除。
输出格式
　　输出共n 行。每组输入数据的输出结果占一行，为一个整数。
　　对于每组数据：若不存在这样的 x，请输出0； 若存在这样的 x，请输出满足条件的x 的个数；
样例输入
2
41 1 96 288
95 1 37 1776
样例输出
6
2
样例说明
　　第一组输入数据，x 可以是9、18、36、72、144、288，共有6 个。
　　第二组输入数据，x 可以是48、1776，共有2 个。
数据规模和约定
　　对于 50%的数据，保证有1≤a0，a1，b0，b1≤10000 且n≤100。
*/
/*
题描述
　　金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间他自己专用的很宽敞的房间。
更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎 么布置，你说了算，只要不超过N元钱就行”。
今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈限定的N元。于是，
他把每件物品规定了一 个重要度，分为5等：用整数1~5表示，第5等最重要。
他还从因特网上查到了每件物品的价格（都是整数元）。他希望在不超过N元（可以等于N元）的前提 下，
使每件物品的价格与重要度的乘积的总和最大。
　　设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为 j1，j2，……，jk，则所求的总和为：
　　v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]。（其中*为乘号）
　　请 你帮助金明设计一个满足要求的购物单。
输入格式
　　输入文件 的第1行，为两个正整数，用一个空格隔开：
　　N m
　　（其中N（<30000）表示总钱 数，m（<25）为希望购买物品的个数。）
　　从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有2个非负整数
　　v p
　　（其中v表示该物品的价格(v<=10000)，p表示该物品的重要度(1~5)）
输出格式
　　输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<100000000）。
样例输入
1000 5
800 2
400 5
300 5
400 3
200 2
样例输出
3900
*/
#if 0 
#include <stdio.h>
void shuru(int ,int*a,int *b);
void q_zdjz(int n,int* a,int* b,int *sz,int zjz);
int panduan_max(int p,int q);

int main(void) 
{
	int n,gs;
	scanf("%d%d",&n,&gs);
	int a[gs],b[gs];
	int sz[30010]={0};
	shuru(gs,a,b);
	q_zdjz(gs,a,b,sz,n);
    printf("%d\n",sz[n]);
	return 0;
}

void shuru(int n,int*a,int *b)
{
 int i;
 for(i=0;i<n;i++)
 {
  scanf("%d%d",a+i,b+i);
 }
}

int panduan_max(int p,int q)
{
 return p>q?p:q;
}


void q_zdjz(int n,int* a,int* b,int *sz,int zjz)
{
 int i;
 for(i=0;i<n;i++)
 {
  int j;
  for(j=zjz;j>=a[i];j--)
  {
   sz[j]=panduan_max(sz[j],sz[j-a[i]]+a[i]*b[i]);
  }
 }

}
#endif
/*
问题描述
　　求一个0～N-1的排列（即每个数只能出现一次），给出限制条件
（一张N*N的表，第i行第j列的1或0，表示为j-1这个数不能出现在i-1这个数后面，并保证第i行第i列为0），
将这个排列看成一个自然数，求从小到大排序第K个排列。
数据规模和约定
　　N<=10，K<=500000
输入格式
　　第一行为N和K,接下来的N行，每行N个数，0表示不能，1表示能
输出格式
　　所求的排列
样例输入

3 2
0 1 1
1 0 0
0 1 0


样例输出

1 0 2
解释：
对于N=3的没有任何限制的情况
第一：0 1 2
第二：0 2 1
第三：1 0 2
第四：1 2 0
第五：2 0 1
第六：2 1 0
根据题目所给的限制条件由于2不能出现在1后面，0不能出现在2后面
第一：0 2 1
第二：1 0 2
第三：2 1 0


*/
#if 0
#include <stdio.h>
void input(int ,int l,int a[][l]);
void fuzhi(int ,int *);
void qpl(int,int*,int);

int main(void)
{
  int N,K;
  scanf("%d%d",&N,&K);
  int a[N][N];
  int b[N];
  fuzhi(N,b);
  input(N,N,a);
  qpl(N,a,0);
  return 0;
}

void move_z()

void qpl(int n,int *a,int k)
{
 int i;
 for(i=k;i<n;i++)
 {
  move_z(a+k,a+i);
  qpl(n,a,k);
 }
}

void fuzhi(int n,int a)
{
 int i;
 for(i=0;i<n;i++)
 {
  a[i]=i;
 } 
}

void input(int h,int l,int a[][l])
{
 int i;
 for(i=0;i<h;i++)
 {
 int k;
 for(k=0;k<l;k++)
 {
  scanf("%d",&a[i][k]);
 }
 }
}
#endif






