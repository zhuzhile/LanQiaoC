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

int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
	shuchu(n,m);
	return 0;
}
//int m = n-1;
//	for(i=1;i<=n*2-1;i+=2,m--)//只需要将*转向 
//	{
//	if(i != 1)
//	{
//	 putchar('\n');
//	}
//	for( j = 0 ; j < m ; j ++ ){
//		putchar(' '); 
//	}
//	for(k=0;k<i;k++)
//	 {
//	  printf("%c",'*');
//	 }
//	}
//    return 0;
//}

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
  int a;
  for(a=0;a<2*n-1;a++,n--)
  {
   putchar('*');
  }
  putchar('\n');
  }

}


