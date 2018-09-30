/*

问题描述
　　扫雷游戏你一定玩过吧！现在给你若干个n×m的地雷阵，请你计算出每个矩阵中每个单元格相邻单元格
内地雷的个数，每个单元格最多有8个相邻的单元格。 0<n,m<=100
输入格式
　　输入包含若干个矩阵，对于每个矩阵，第一行包含两个整数n和m，分别表示这个矩阵的行数和列数。
接下来n行每行包含m个字符。安全区域用‘.’表示，有地雷区域用'*'表示。当n=m=0时输入结束。
输出格式
　　对于第i个矩阵，首先在单独的一行里打印序号：“Field #i:”,接下来的n行中，读入的'.'
应被该位置周围的地雷数所代替。输出的每两个矩阵必须用一个空行隔开。
样例输入
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
样例输出
Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100
（注意两个矩阵之间应该有一个空行，由于oj的格式化这里不能显示出来）
数据规模和约定
　　0<n,m<=100

*/
#if 0
#include <stdio.h>
void input(int,int l,char [][l]);
void output(int,int l,char [][l]);
int q_gs(int,int,int,int l,char [][l]);

int main(void) 
{
	int n,m,gs=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
	 char a[n][m];
	 if(n==0&&m==0)
	 {
	  return 0;
	 }
	 printf("Field #%d:\n",++gs);
	 input(n,m,a);
	 output(n,m,a);
	 putchar('\n');
	}
	return 0;
}

void input(int h,int l,char a[][l])
{
 int i;
 for(i=0;i<h;i++)
 {
  int k;
  for(k=0;k<l;k++)
  {
   scanf(" %c",&a[i][k]);
  }
 }
}

void output(int h,int l,char a[][l])
{
  int i;
  for(i=0;i<h;i++)
  {
  int k;
  for(k=0;k<l;k++)
  {
   if(a[i][k]=='*')
   {
    printf("%c",'*');
   }else{printf("%d",q_gs(i,k,h,l,a));
   }
  }
  putchar('\n');
  }
}


int q_gs(int n,int m,int h,int l,char a[][l])
{
	int i,j,gs=0;
	for(i=n-1;i<=n+1;i++)
	{
	for(j=m-1;j<=m+1;j++)
	{
	 if(a[i][j]=='*'&&i>=0&&j>=0&&i<h&&j<l)
	 {
	  gs++;
	 }
	}
	}
   return gs;
}
#endif
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






