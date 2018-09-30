//问题描述
//　　将1，2，…，9共9个数分成三组，分别组成三个三位数，且使这三个三位数构成
//　　1：2：3的比例，试求出所有满足条件的三个三位数。
//　　例如：三个三位数192，384，576满足以上条件。
//输入格式
//　　无输入文件
//输出格式
//　　输出每行有三个数，为满足题设三位数。各行为满足要求的不同解。

#include <stdio.h>

int q_s(int,int,int);
int panduan(int*,int);

int main(void) 
{
	 
	int s[10];
	for(s[0]=1;s[0]<9;s[0]++)
	{
	for(s[1]=0;s[1]<9;s[1]++)
	{
	if(panduan(s,1))
	{
	for(s[2]=0;s[2]<9;s[2]++)
	{
    if(panduan(s,2))
    {
	for(s[3]=1;s[3]<9;s[3]++)
    {
	if(panduan(s,3))
	{
	 for(s[4]=0;s[1]<9;s[4]++)
	{
	if(panduan(s,4))
	{
	 for(s[5]=0;s[5]<9;s[5]++)
	{
	if(panduan(s,5))
	{
	for(s[6]=1;s[6]<9;s[6]++)
	{
	if(panduan(s,6))
	{
	for(s[7]=0;s[7]<9;s[7]++)
	{
	if(panduan(s,7))
	{
	for(s[8]=0;s[8]<9;s[8]++)
	{
	if(panduan(s,8))
	{
	int shu1=q_s(s[0],s[1],s[2]);
	int shu3=q_s(s[6],s[7],s[8]);
	int shu2=q_s(s[3],s[4],s[5]);
	if(shu2/shu1==2
	&&shu3/shu1==3)
	{
	printf("%d %d %d\n",shu1,shu2,shu3);
    }
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
    }
}
	return 0;
}

int q_s(int bw,int sw,int gw)
{
   return bw*100+sw*10+gw;
}

int panduan(int *s, int k)
{
 int i;
 for(i=0;i<k;i++)
 {
  if(s[i]==s[k])
  {
   return 0;
  }
 }
 return 1;
}
