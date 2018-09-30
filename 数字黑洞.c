/*
问题描述
　　任意一个四位数，只要它们各个位上的数字是不全相同的，就有这样的规律：
　　1)将组成该四位数的四个数字由大到小排列，形成由这四个数字构成的最大的四位数；
　　2)将组成该四位数的四个数字由小到大排列，形成由这四个数字构成的最小的四位数(如果四个数中含有0，则得到的数不足四位)；
　　3)求两个数的差，得到一个新的四位数(高位零保留)。
　　重复以上过程，最后一定会得到的结果是6174。
　　比如：4312 3087 8352 6174，经过三次变换，得到6174
输入格式
　　一个四位整数，输入保证四位数字不全相同
输出格式
　　一个整数，表示这个数字经过多少次变换能得到6174
样例输入
4312
样例输出
3
 
*/
 

#include <stdio.h>
void fuzhi(int *,int ,int );
void paixu(int *,int );
void jiaohuan(int*,int*);
int q_shuda(int *,int );
int q_shuxiao(int* ,int );
int q_cs(int,int* );

int main(void ) 
{
	int n;
	scanf("%d",&n);
	int s[4];
	printf("%d\n",q_cs(n,s));
    return 0;
}

int  q_cs(int n,int *s)
{
 if(n==6174)
 {
  return 0;
 }
 fuzhi(s,4,n);
 paixu(s,4);
 int cha=q_shuda(s,n)-q_shuxiao(s,n);
 return q_cs(cha,s)+1;
}


void fuzhi(int *s,int n,int zhi)
{
   do 
   {
    n--;
	s[n]=zhi%10;
   }
   while((zhi/=10)!=0);
}

void paixu(int *s,int n)
{
  int i;
  for(i=1;i<n;i++)
  {
   int k;
   for(k=0;k<n-i;k++)
   {
     if(s[k]<s[k+1])
     {
	  jiaohuan(s+k,s+k+1); 
	 }
   }
  }
}

void jiaohuan(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

int q_shuda(int *s,int n)
{
 return  s[0]*1000+s[1]*100+s[2]*10+s[3];
}

int q_shuxiao(int *s,int n)
{
 return s[3]*1000+s[2]*100+s[1]*10+s[0];
}
