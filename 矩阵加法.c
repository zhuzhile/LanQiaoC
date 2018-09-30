/*问题描述
　　给定两个N×M的矩阵，计算其和。其中：
　　N和M大于等于1且小于等于100，矩阵元素的绝对值不超过1000。
输入格式
　　输入数据的第一行包含两个整数N、M，表示需要相加的两个矩阵的行数和列数。接下来2*N行每行包含M个数，其中前N行表示第一个矩阵，后N行表示第二个矩阵。
输出格式
　　你的程序需要输出一个N*M的矩阵，表示两个矩阵相加的结果。注意，输出中每行的最后不应有多余的空格，否则你的程序有可能被系统认为是Presentation　　Error
样例输入
2 2
1 2
3 4
5 6
7 8

样例输出


6 8
10 12
*/
#include <stdio.h>
void shuru(int[][100],int n,int m);
void shuchu(int [][100],int n,int m);
void xj(int[][100],int[][100],int[][100],int n,int m);

int main(void) 
{
	int n,m;
	scanf("%d%d",&n,&m);
	int jz0[100][100];
	int jz1[100][100];
	shuru(jz0,n,m);
	shuru(jz1,n,m);
	int jz[100][100];
	xj(jz0,jz1,jz,n,m);
	shuchu(jz,n,m);
	return 0;
}

void shuru(int jz[][100],int n,int m)
{ 
  int i;
  for(i=0;i<n;i++)
  {
   int k;
   for(k=0;k<m;k++)
   {
    scanf("%d",&jz[i][k]);
   }
  }
}

void shuchu(int jz[][100],int n,int m)
{ 
  int i;
  for(i=0;i<n;i++)
  {
   int k;
   for(k=0;k<m;k++)
   {
    printf("%d ",jz[i][k]);
   }
   putchar('\n');
  }
}

void xj(int jz0[][100],int jz1[][100],int jz[][100],int n,int m)
{ 
  int i;
  for(i=0;i<n;i++)
  {
   int k;
   for(k=0;k<m;k++)
   {
   	jz[i][k]= jz0[i][k]+jz1[i][k];
   }
  }
}
