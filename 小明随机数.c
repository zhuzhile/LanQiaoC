/*明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
输入格式
　　输入有2行，第1行为1个正整数，表示所生成的随机数的个数：
　　N
　　第2行有N个用空格隔开的正整数，为所产生的随机数。
输出格式
　　输出也是2行，第1行为1个正整数M，表示不相同的随机数的个数。第2行为M个用空格隔开的正整数，为从小到大排好序的不相同的随机数。
样例输入
10
20 40 32 67 40 20 89 300 400 15
样例输出
8
15 20 32 40 67 89 300 400
题目来源
*/

#include <stdio.h>
void swap(int*,int*);
void shchu(int*,int);
void paixu(int*,int);
void shuchu(int*,int);
void shuru(int*,int);
void qiu_size(int*,int);

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	shuru(a,n);
	paixu(a,n);
	shchu(a,n);
	 qiu_size(a,n);
	shuchu(a,n);
	return 0;
}

void shuru(int*a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%d",a++);
  }
}

void paixu(int*a,int n)
{
 int i;
 for(i = 1;i < n;i ++)
 {
 int k;
 for(k = 0;k < n - i;k ++)
 {
   if(a[k]>a[k+1])
   {
    swap(&a[k],&a[k+1]); 
   }
 }
 
 }

}

void swap(int *a,int * b)
{ 
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void shchu(int *a,int n)
{
 int i;
 for(i = 0;i < n;i ++)
 {
 int k;
 for(k = i+1;k < n ;k ++)
 {
   if(a[i]==a[k])
   {
    a[k]=a[0];
   }
 }
 }
 
 }
 
 void qiu_size(int*a,int n)
 {
  int count = 1;
  int i;
  for(i = 1;i < n;i ++)
  {
   if(a[i]!=a[0])
   {
    count++;
   }
  } 
 printf("%d\n",count);
}
 
 void shuchu(int *a,int n)
 {
 printf("%d ",a[0]);
 int i;
 for(i = 1;i < n;i ++)
 {
   if(a[i]!=a[0])
   {
   printf("%d ",a[i]);
   }
 }
}
