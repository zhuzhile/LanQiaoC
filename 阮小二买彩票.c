/*

问题描述
　　在同学们的帮助下，阮小二是变的越来越懒了，连算账都不愿意自己亲自动手了，每天的工作就是坐在电脑前看自己的银行账户的钱是否有变多。可是一段时间观察下来，阮小二发现自己账户的钱增长好慢啊，碰到节假日的时候连个铜板都没进，更郁闷的是这些天分文不进就算了，可恨的是银行这几天还有可能“落井下石”(代扣个人所得税)，看着自己账户的钱被负增长了，阮小二就有被割肉的感觉(太痛苦了！)，这时阮小二最大的愿望无疑是以最快的速度日进斗金，可什么方法能够日进斗金呢？抢银行(老本行)？不行，太危险，怕有命抢没命花；维持现状？受不了，搂钱太慢了！想来想去，抓破脑袋之后，终于想到了能快速发家致富的法宝----买彩票，不但挣了钱有命花，运气好的话，可以每天中他个几百万的，岂不爽哉！抱着这种想法，阮小二开始了他的买彩票之旅。想法是“好的”（太天真了OR 太蠢了），可是又发现自己的数学功底太差，因为不知道数字都有哪些组合排列？那现在就请同学们写个递归程序，帮助阮小二解决一下这个问题吧！
输入格式
　　不超过6位数的正整数N，注意：构成正整数N的数字可重复
输出格式
　　组成正整数N的所有位数的全排列，这些排列按升序输出，每个排列占一行。

注意：输出数据中不能有重复的排列
样例输入
123
样例输出
123
132
213
231
312
321
样例输入
3121
样例输出
1123
1132
1213
1231
1312
1321
2113
2131
2311
3112
3121
3211
样例输入
4003
样例输出
0034
0043
0304
0340
0403
0430
3004
3040
3400
4003
4030
4300

0034
0043
0304
0340
0403
0430
3004
3040
3400
4003
4030
4300


*/
#if 1
#include <stdio.h>

void q_qpl(int *,int,int,int*,int*);
void shuru(int*,int*);
void shuchu(int*,int,int);
void paixu(int*,int,int);
void swap(int*,int*);
void sqcfys(int*,int,int*,int*);
int q_shu(int*,int);

int main(void) 
{
	int k=0;
	int a[10];
	int ws=0,count=0,gs=0;
	shuru(a,&ws);
	int sz[10000];
	q_qpl(a,ws,k,&count,sz); 
	paixu(sz,0,count-1);
	int sz_0[1000];
	sqcfys(sz,count,sz_0,&gs);
	shuchu(sz_0,gs,ws);
	return 0;
}

void shuru(int a[],int *p_ws)
{
  char c;
  while((c=getchar())!='\n'&&c!=EOF)
  {
    a[*p_ws]=c-'0';
 	(*p_ws)++; 
  }
}

void paixu(int*a,int beg,int end)
{  
 int i, j;  
  if(beg < end)  
    {  
     i = beg + 1;   
     j = end;     
     while(i < j)  
    {  
     if(a[i] > a[beg])    
     {  
        swap(&a[i], &a[j]);  
        j--;  
     }  
     else  
     {  
      i++;    
     }  
     }  
    if(a[i] >= a[beg])   
    {  
      i--;  
     }  
     swap(&a[beg], &a[i]);  
     paixu(a,beg,i);  
     paixu(a,j,end);  
    }  
}
  

void sqcfys(int *sz,int count,int *a,int *p_gs)//删掉重复元素 
{
  int i;
  a[*p_gs]=sz[0];
  for(i=1;i<count;i++)
  {
    if(sz[i]!=a[*p_gs])
    {
	 ++*p_gs;
	 a[*p_gs]=sz[i];
	}
  }
  ++*p_gs;
}

void shuchu(int *sz,int n,int ws)
{
    char gs[80];
	sprintf(gs,"%%0%dd\n", ws );
	int i;
	for(i=0; i<n;i++)
	{
		printf(gs,sz[i]);
	}
}

int q_shu(int *a,int n)
{
  int i,shu=0;
  for(i=0;i<n;i++)
  {
   shu*=10;
   shu+=a[i];
  }
  return shu;
}

void swap(int*p,int*q)
{
  int t;
  t=*q;
  *q=*p;
  *p=t;
}

void q_qpl(int* a,int end,int k,int*p_count,int* sz)
{
  if(k==end)
  {
   sz[*p_count]=q_shu(a,end);
   (*p_count)++;
   return;
  }
  int i;
  for(i=k;i<end;i++)
  {
   swap(a+k,a+i);
   q_qpl(a,end,k+1,p_count,sz);
   swap(a+k,a+i);
 }
}
#endif 
