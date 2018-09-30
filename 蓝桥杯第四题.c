
/*
打印方格

小明想在控制台上输出 m x n 个方格。
比如 10x4的，输出的样子是：
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

（如果显示有问题，可以参见【图1.jpg】）

以下是小明写的程序，请你分析其流程，填写划线部分缺少的代码。

*/ 
#if 0
#include <stdio.h>

//打印m列，n行的方格 
void f(int m, int n)
{
	int row;
	int col;
	
	for(row=0; row<n; row++){
		for(col=0; col<m; col++) printf("+---");
		printf("+\n");
		printf("|");
		for(col=0; col<m; col++) printf("   |");
		putchar('\n');		
	}
	
	printf("+");
	
	
	for(col=0; col<m; col++) printf("---+");
	putchar('\n');
	
}

int main()
{
	f(10,4);
	return 0;
}
#endif
/*
平方怪圈

如果把一个正整数的每一位都平方后再求和，得到一个新的正整数。
对新产生的正整数再做同样的处理。

如此一来，你会发现，不管开始取的是什么数字，
最终如果不是落入1，就是落入同一个循环圈。

请写出这个循环圈中最大的那个数字。

请填写该最大数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/


#include <stdio.h>
#define max (10000)

int q_zd(int *a,int n)
{
 int zd=a[0];
 int i;
 for(i=0;i<n;i++)
 {
  if(zd<a[i])
  {
   zd=a[i];
  }
 }
 return zd;
}

int main(void)
{
  int n,sum,a[max];
  n=123,sum=0;
  int i;
  for(i=0;a[i]!=1;i++)
  {
  sum=0;
  do
  {
   sum+=(n%10)*(n%10);
  }while(n/=10);
  n=sum;
  a[i]=sum;
  }
  printf("%d\n",q_zd(a,i));
  return 0;
}




