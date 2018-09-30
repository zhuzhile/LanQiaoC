/*
找出输入数据中所有数据两两相乘等于指定值M的个数。
输入描述：
共三行
第一行，整数M的值,-2^31<M<2^31。 
第二行，输入数据的个数n，1<n<100。 
第三行，n个整数，之间用空格隔开，各整数均在[-2^31,2^31]范围内。
输出描述：
n个整数中两两相乘等于指定值M的个数，每个数据用于相乘最多1次。
输入样例：
479001600
11 
1 10000 159667200 9696 38373635 1000000 479001600 3 1 479001600 1 
输出样例：
3
*/
#include <stdio.h>
void shuru(int*,int);//用除法 
int qiu_pd(int*,int,int);
int qiu_pdb(int*,int*,int,int);

int main(void) 
{
	int zhi,gs;
	scanf("%d%d",&zhi,&gs);
	int a[gs];
	shuru(a,gs);
	printf("%d\n",qiu_pd(a,gs,zhi));
	return 0;
}

void shuru(int a[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
}

int qiu_pd(int*a,int n,int zhi)
{
 int count[n];
 int j;
 for(j=0;j<n;j++)
 {
 count[j]=0;
 }
 int i;
 for(i=0;i<n;i++)
 {
  int k;
  for(k=0;k<n;k++)
  { 
   if(a[i]==a[k])
   {
    count[i]++;
   }
  }
 }
 return qiu_pdb(a,count,n,zhi);
}

int qiu_pdb(int*a,int count[],int n,int zhi)
{
  int i;
 for(i=0;i<n;i++)
 {
  int k;
  for(k=0;k<n;k++)
  { 
  if(zhi/a[i]==a[k])
   {
    return count[i]>=count[k]?count[i]:count[i];
   }
  }
 }
}


