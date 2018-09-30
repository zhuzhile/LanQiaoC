/*
问题描述
　　Tom教授正在给研究生讲授一门关于基因的课程，有一件事情让他颇为头疼：
一条染色体上有成千上万个碱基对，它们从0开始编号，到几百万，几千万，甚至上亿。
　　比如说，在对学生讲解第1234567009号位置上的碱基时，光看着数字是很难准确的念出来的。
　　所以，他迫切地需要一个系统，然后当他输入12 3456 7009时，会给出相应的念法：
　　十二亿三千四百五十六万七千零九
　　用汉语拼音表示为
　　shi er yi san qian si bai wu shi liu wan qi qian ling jiu
　　这样他只需要照着念就可以了。
　　你的任务是帮他设计这样一个系统：给定一个阿拉伯数字串，你
帮他按照中文读写的规范转为汉语拼音字串，相邻的两个音节用一个空格符格开。
　　注意必须严格按照规范，比如说“10010”读作“yi wan ling yi shi”而
不是“yi wan ling shi”，“100000”读作“shi wan”而不是“yi shi wan”，
“2000”读作“er qian”而不是“liang qian”。
输入格式
　　有一个数字串，数值大小不超过2,000,000,000。
输出格式
　　是一个由小写英文字母，逗号和空格组成的字符串，表示该数的英文读法。
样例输入
1234567009
样例输出
shi er yi san qian si bai wu shi liu wan qi qian ling jiu
 
*/
#include <stdio.h>
#include <stdbool.h>

enum
{
	GW =0 ,
	SW =1 ,
	WW =4 ,
	SWW=5 ,
	YW =8 ,
	SYW=9 ,
};

void du(int);
void q_wq(int *,int *,int);
void du1wei(int,int,int *,bool);
void du_qw0(int ,bool);
void du_sz(int,int,int *,bool);
bool byd0(bool,int *);
bool byd1(bool,int);
void du_wm(int,int,int);
bool bydw(int,int,int);
bool jixudu(int,int);

int main(void)
{
	int szc;
	scanf("%d",&szc);
	du(szc);
	return 0;
}

bool jixudu(int sxs,int wx)
{
	if(sxs!=0)
	{
		return true;
	}
	if(wx!=WW&&wx!=YW&&wx!=GW)
	{
		return true;
	}
	return false;
}

bool bydw(int sz,int wx, int qw0gs)
{
	if(sz!=0)
	{
		return false;
	}
	if(wx!=WW&&wx!=YW)
	{
		return true;
	}
	if(qw0gs<4)
	{
		return false;
	}
	return true;
	
}

void du_wm(int sz,int wx, int qw0gs)
{
	if(bydw(sz,wx,qw0gs)==true)
	{
		return ;
	} 
	static char const * weidf[]={"","shi","bai","qian","wan","shi","bai","qian","yi","shi"};
    printf("%s ",weidf[wx]);
}

bool byd1(bool zgw,int wx)
{
	if(zgw==false)
	{
		return false;
	}
	if(wx==SW||wx==SWW||wx==SYW)
	{
		return true;
	}
	return false;
}

bool byd0(bool zgw,int *p_qw0gs)
{
	if(zgw==false)
	{
		++ * p_qw0gs;
		return  true;
	}
	return  false;
}

void du_sz(int sz,int wx,int *p_qw0gs,bool zgw)
{
	if(sz==0)
	{
		if(byd0(zgw,p_qw0gs)==true)
		{
			return ;
		}
	}
	*p_qw0gs=0;
	if(sz==1)
	{
		if(byd1(zgw,wx)==true )
		{
			return ;
		}
	}
	static char const * szdf[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	printf("%s ",szdf[sz]);
}

void du_qw0(int sz,bool zby0)
{
	if(sz==0)
	{
		return ;
	}
	if(zby0==false) 
	{
		return ;
	}
	printf("ling ");
}

void du1wei(int sz,int wx,int *p_qw0gs,bool zgw)
{
	du_qw0(sz,*p_qw0gs>0);
	du_sz(sz,wx,p_qw0gs,zgw);
	du_wm(sz,wx,*p_qw0gs);
}

void q_wq(int *p_wx,int *p_qn,int s)
{
	*p_wx=0;
	*p_qn=1;
	while(s>9)
	{
		++*p_wx;
		*p_qn*=10;
		s/=10;
	}
}

void du(int s)
{
	int wx;
	int quan;
	q_wq(&wx,&quan,s);
	int qw0gs=0;
	bool zgw=true;
	do
	{
		du1wei(s/quan,wx,&qw0gs,zgw);
		zgw=false;
		s%=quan;
		quan/=10;
		wx--;
	}
	while(jixudu(s,wx+1)==true);
}


