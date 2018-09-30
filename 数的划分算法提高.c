/*

问题描述
　　一个正整数可以划分为多个正整数的和，比如n=3时：
　　3；1＋2；1＋1＋1；
　　共有三种划分方法。
　　给出一个正整数，问有多少种划分方法。
输入格式
　　一个正整数n
输出格式
　　一个正整数，表示划分方案数
样例输入
3
样例输出
3
数据规模和约定
　　n<=100

*/


#include<stdio.h>   

void copy(int ,int l,int [][l]);
int  q_way(int,int l,int [][l]);
#define zd 100
int main(void)  
{  
int n;  
scanf("%d",&n); 
int arr[zd][zd];
copy(n,n,arr);
printf("%d\n",q_way(n,n,arr));  
}  

void copy(int n ,int l,int arry[][l])
{
int i;
for(i=0;i<=n;i++)  
{  
    arry[i][1]=1;  
    arry[0][i]=1; 
}  

} 

int q_way(int n,int l,int arr[][l])
{
int i;
for( i=1;i<=n;i++)  
{
	int j;
	for(j=1;j<=n;j++)  
    {  
       if(j<=i)
       {  
        arr[i][j]=arr[i][j-1]+arr[i-j][j];      
       }
       else
       {  
        arr[i][j]=arr[i][i]; 
       }  
    }  
}
 return arr[n][n];
}  
