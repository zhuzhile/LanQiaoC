/*
问题描述
　　银行近期推出了一款新的理财计划“重复计息储蓄”。储户只需在每个月月初存入固定金额的现金，
    银行就会在每个月月底根据储户账户内的金额算出该月的利息并将利息存入用户账号。
   现在如果某人每月存入k元，请你帮他计算一下，n月后，他可以获得多少收益。
输入格式
　　输入数据仅一行，包括两个整数k(100<=k<=10000)、n(1<=n<=48)和一个小数p(0.001<=p<=0.01)，
    分别表示每月存入的金额、存款时长、存款利息。
输出格式
　　输出数据仅一个数，表示可以得到的收益。
样例输入
1000 6 0.01
样例输出
213.53
*/
#include <stdio.h>

double qiu_lx(double,int,double);

int main(void) 
{
	int k;int n;
	double p;
	scanf("%d%d ",&k,&n);
	scanf("%lf",&p);
	printf("%.2lf\n",qiu_lx((double)k,n,p));
	return 0;
}

double qiu_lx(double k,int n,double p)
{
  double cb=k*n;
  double  k_=k; 
      int i;
      for(i=0;i<n;i++)
      {
	   k=k+(i!=0?k_:0)+(k+(i!=0?k_:0))*p;
	  }
	return k-cb;
}

