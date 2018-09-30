/*
问题描述
　　将1，2，…，9共9个数分成三组，分别组成三个三位数，且使这三个三位数构成
　　1：2：3的比例，试求出所有满足条件的三个三位数。
　　例如：三个三位数192，384，576满足以上条件。
输入格式
　　无输入文件
输出格式
　　输出每行有三个数，为满足题设三位数。各行为满足要求的不同解。
 
*/

#include <stdio.h>

void tjcs(int ,int []);
int panduan(int*,int);

int main(void) 
{
	int shu1;
	for(shu1=100;3*shu1<1000;shu1++)
	{
	int shu2=2*shu1;
	int shu3=3*shu1;
	int s[10]={0};
	tjcs(shu1,s);
	tjcs(shu2,s);
	tjcs(shu3,s);
    if(panduan(s,10))
	{
	 printf("%d %d %d\n",shu1,shu2,shu3);
	}
	}
	return 0;
}

void tjcs(int shu,int s[])
{
  do 
  {
   s[shu%10]++;
  }
  while((shu/=10)!=0);
}

int panduan(int s[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  if(s[i]>1)
  {
   return 0;
  }
  if(s[0]!=0)
  {
   return 0;
  }
 }
 return 1;
}

//192 384 576
//219 438 657
//273 546 819
//327 654 981
//
//192 384 576
//219 438 657
//267 534 801
//273 546 819
//327 654 981
