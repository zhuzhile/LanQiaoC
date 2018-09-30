//使用循环结构打印下述图形，打印行数n由用户输入。图中每行事实上包括两部分，中间间隔空格字符数m也由用户输入。
//样例输入n,m: 
//5  4
//样例输出:
//    *    *********
//   ***    *******
//  *****    *****
// *******    ***
//*********    *
//
//注意：两行之间没有空行。
#include <stdio.h>

void shuchu(int,int);
void dashu(int,int);

int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
	shuchu(n,m);
	return 0;
}

void shuchu(int n,int m)
{
  int i,j,g;
  for(i=1,j=n-1;i<=n;i++,j--)
  {
  	for( g = 0 ; g < j ; g ++ )
	{
		putchar(' '); 
	}
  
  int k;
  for(k=0;k<2*i-1;k++)
  {
   putchar('*');
  }
  int h;
  for( h = 0 ; h < m ; h ++ )
	{
		putchar(' '); 
	}
  dashu(n,i);
  putchar('\n');
  }
}

void dashu(int n,int i)
{
  int k;
  for(k=0;k<2*(n-i+1)-1;k++)
  {
   putchar('*');
  }
}


