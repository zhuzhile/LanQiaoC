/*
兰顿蚂蚁，是于1986年，由克里斯·兰顿提出来的，属于细胞自动机的一种。

　　平面上的正方形格子被填上黑色或白色。在其中一格正方形内有一只“蚂蚁”。
　　蚂蚁的头部朝向为：上下左右其中一方。

　　蚂蚁的移动规则十分简单：
　　若蚂蚁在黑格，右转90度，将该格改为白格，并向前移一格；
　　若蚂蚁在白格，左转90度，将该格改为黑格，并向前移一格。

　　规则虽然简单，蚂蚁的行为却十分复杂。刚刚开始时留下的路线都会有接近对称，
像是会重复，但不论起始状态如何，蚂蚁经过漫长的混乱活动后，会开辟出一条规则的“高速公路”。

　　蚂蚁的路线是很难事先预测的。

　　你的任务是根据初始状态，用计算机模拟兰顿蚂蚁在第n步行走后所处的位置。
输入格式
　　输入数据的第一行是 m n 两个整数（3 < m, n < 100），表示正方形格子的行数和列数。
　　接下来是 m 行数据。
　　每行数据为 n 个被空格分开的数字。0 表示白格，1 表示黑格。

　　接下来是一行数据：x y s k, 其中x y为整数，表示蚂蚁所在行号和列号（行号从上到下增长，列
号从左到右增长，都是从0开始编号）。s 是一个大写字母，表示蚂蚁头的朝向，我们约定：上下左右分别用：
UDLR表示。k 表示蚂蚁走的步数。
输出格式
　　输出数据为两个空格分开的整数 p q, 分别表示蚂蚁在k步后，所处格子的行号和列号。
样例输入
5 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
2 3 L 5
样例输出
1 3
样例输入
3 3
0 0 0
1 1 1
1 1 1
1 1 U 6
样例输出
0 0
*/
#include <stdio.h>
void q_fx(int x,int y,char *p_s,int step,int h,int l,int a[][l],int k);
void select_fx0(int x,int y,char *p_s,int step,int h,int l,int a[][l],int k);
void select_fx1(int x,int y,char *p_s,int step,int h,int l,int a[][l],int k);
void input(int h,int l,int a[][l]);



int main(void)
{
  int n,m;
  scanf("%d%d",&n,&m);
  int a[n][m];
  input(n,m,a);
  int x,y,k;
  char s;
  scanf("%d%d %c%d",&x,&y,&s,&k);
  q_fx(x,y,&s,k,n,m,a,0);
  return 0;
}

void input(int h,int l,int a[][l])
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
//若蚂蚁在黑格，右转90度，将该格改为白格，并向前移一格；
//若蚂蚁在白格，左转90度，将该格改为黑格，并向前移一格。
//0 表示白格，1 表示黑格。

void q_fx(int x,int y,char *p_s,int step,int h,int l,int a[][l],int k)
{
   if(k==step)
   {
   	printf("%d %d",x,y);
    return ;
   }
   if(a[x][y]==1)
   {
    a[x][y]=0;
    select_fx0(x,y,p_s,step,h,l,a,k);
   }else{
    a[x][y]=1;
    select_fx1(x,y,p_s,step,h,l,a,k);
   }
}
//若蚂蚁在黑格，右转90度，将该格改为白格，并向前移一格；

void select_fx0(int x,int y,char *p_s,int step,int h,int l,int a[][l],int k)
{
  switch(*p_s)
  {
   case 'U': *p_s='R';
   q_fx(x,y+1,p_s,step,h,l,a,k+1);
   break;
   case 'R':*p_s='D';
   q_fx(x+1,y,p_s,step,h,l,a,k+1);
   break;
   case 'D':*p_s='L';
   q_fx(x,y-1,p_s,step,h,l,a,k+1);
   break;
   case 'L':*p_s='U';
   q_fx(x-1,y,p_s,step,h,l,a,k+1);
   break;
  }
}
//若蚂蚁在白格，左转90度，将该格改为黑格，并向前移一格。
void select_fx1(int x,int y,char*p_s,int step,int h,int l,int a[][l],int k)
{
  switch(*p_s)
  {
   case 'U': *p_s='L';
   q_fx(x,y-1,p_s,step,h,l,a,k+1);
   break;
   case 'R':*p_s='U';
   q_fx(x-1,y,p_s,step,h,l,a,k+1);
   break;
   case 'D':*p_s='R';
   q_fx(x,y+1,p_s,step,h,l,a,k+1);
   break;
   case 'L':*p_s='D';
   q_fx(x+1,y,p_s,step,h,l,a,k+1);
   break;
  }
}

