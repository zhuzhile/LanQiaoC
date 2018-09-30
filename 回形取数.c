/*
问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。
   一开始位于矩阵左上角，方向向下。
输入格式
　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7 8 9 6 3 2 5
样例输入
3 2
1 2
3 4
5 6
样例输出
1 3 5 6 4 2
*/
#if 0
#include <stdio.h>

void shuru(int h,int l,int a[][l]);
void shuchu(int l,int a[][l],int h);

int main(void)
{
  int h,l;
  scanf("%d%d",&h,&l);
  int a[h][l];
  shuru(h,l,a);
  shuchu(l,a,h);
  return 0;
}

void shuru(int h,int l,int a[][l])
{
  int i;
  for(i=0;i<h;i++)
  {
   int k;
   for(k=0;k<l;k++)
   {
    scanf("%d",&a[i][k]);
   }
  }
}

void shuchu(int l,int arr[][l],int h)
{
int i;
for(i = 0; i < (h+1)/2 && i < (l+1)/2; i++)
{
    int j;
	for(j = i; j < h-i; j++)
    {
	 printf("%d ",arr[j][i]);
	}
    for(j = i+1; j < l-i; j++ )
    {
	 printf("%d ",arr[h-i-1][j]);
	}
    if(l-i-1 > i)
    {
        for(j = h-i-2; j >= i; j--)
        {
		 printf("%d ",arr[j][l-i-1]);
		}
    }
    if (h-i-1 > i)
    {
        for(j = l-i-2; j > i; j--)
        {
		 printf("%d ",arr[i][j]);
		}
    }
  }
}
#endif
#if 1
#include <stdio.h>
#define maxN 101
int main(int argc, char *argv[])
{
     int row,col,i,j,k;
     int a[maxN][maxN];
     int count;
     
     scanf("%d%d",&row,&col);
     for(i=0;i<row;i++)
     {
         for(j=0;j<col;j++)
         {
             scanf("%d",&a[i][j]);
        }
    }    
    if(row==1)//只有一行
     {
         i=0;j=0; 
         for(k=1;k<=col;k++)
         { printf("%d\n",a[i][j]);j++;}
     }
     else if(col==1)//只有一列
    {
         i=0;j=0;
         for(k=1;k<=row;k++)
         { printf("%d\n",a[i][j]);i++;}
     }
     else
     {
         i=0;j=0;
         count=row*col;
         while(count>0)
         {
             for(k=1;k<col;k++)
             { count--; printf("%d\n",a[i][j]);j++;}  //输出一个环的上面那一条边 
             
             for(k=1;k<row;k++)
             { count--; printf("%d\n",a[i][j]);i++;}  //输出一个环的右侧那一条边
             
             for(k=1;k<col;k++)
             { count--; printf("%d\n",a[i][j]);j--;}  //输出一个环的下面那一条边
             
             for(k=1;k<row;k++)
             { count--; printf("%d\n",a[i][j]);i--;}  //输出一个环的左侧那一条边
             
             i++;
             j++;
             row-=2;
             col-=2;
             if(row==1)//只剩下一行
            {
                for(k=1;k<=col;k++)
                
			{ count--; printf("%d\n",a[i][j]);j++;}
            }
             else if(col==1)//只剩下一列
            {
                for(k=1;k<=row;k++)
                { count--; printf("%d\n",a[i][j]);i++;}
             }
        }
    }
     return 0;
 }
#endif


