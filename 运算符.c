//我们知道，整数做除法时，有时得到有限小数，有时得到无限循环小数。
//　　如果我们把有限小数的末尾加上无限多个0，它们就有了统一的形式。
//
//
//　　本题的任务是：在上面的约定下，求整数除法小数点后的第n位开始的3位数。
//输入格式
//　　一行三个整数：a b n，用空格分开。a是被除数，b是除数，n是所求的小数后位置（0<a,b,n<1000000000）
//输出格式
//　　一行3位数字，表示：a除以b，小数后第n位开始的3位数字。
//样例输入
//1 8 1
//样例输出
//125
//样例输入
//1 8 3
//样例输出
//500
//样例输入
//282866 999000 6
//样例输出
//914
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) 
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
    char *gs=malloc(sizeof(char) * 10000000000);//堆区的内存大于栈区； 
    memset(gs,0,sizeof(char)*10000000000);
	sprintf(gs,"%.1000000000lf", (double)a/(double)b);
    int i=0;
	while(gs[i]!='.')
    {
	 i++;
	}
	int k;
	for(k=0;k<3;k++)
	{
	 int s=n+i;
	 printf("%c",gs[s+k]);
	}
	free(gs);
	return 0;
}
