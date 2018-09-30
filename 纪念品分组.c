/*
问题描述
　　元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得的纪念品价值 相
对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品，
并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时 间内发完所有纪念品，
乐乐希望分组的数目最少。
　　你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。
输入格式
　　输入包含n+2行：
　　第1行包括一个整数w，为每组纪念品价格之和的上限。
　　第2行为一个整数n，表示购来的纪念品的总件数。
　　第3~n+2行每行包含一个正整数pi (5 <= pi <= w)，表示所对应纪念品的价格。
输出格式
　　输出仅一行，包含一个整数，即最少的分组数目。
样例输入
100
9
90
20
20
30
50
60
70
80
90
样例输出
6
数据规模和约定
　　50%的数据满足：1 <= n <= 15
　　100%的数据满足：1 <= n <= 30000, 80 <= w <= 200

 
*/

#include<stdio.h>

void paixu(int *,int,int);
void jiaohuan(int*,int*);
void shuru(int*,int);
int q_zs(int*,int,int);

int main(void)
{
  int sx,num;
  scanf("%d%d",&sx,&num);
  int a[num];
  shuru(a,num);
  paixu(a,0,num-1);
  printf("%d\n",q_zs(a,num,sx));
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

void paixu( int*a,int beg,int end)
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
        jiaohuan(&a[i], &a[j]);  
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
     jiaohuan(&a[beg], &a[i]);  
     paixu(a,beg,i);  
     paixu(a,j,end);  
    }  
}  


void jiaohuan(int *p_1,int *p_2)
{
  int temp;
  temp=*p_1;
  *p_1=*p_2;
  *p_2=temp;
}

int q_zs(int *a,int n,int sx)
{
  int i,k,count=0;
  for(i=n-1,k=0;k<=i;i--,k++)
  {
    if(a[i]+a[k]>sx)
    {
      k--;;
      count++;
	}else{count++;
	}
  }
  return count;
}


