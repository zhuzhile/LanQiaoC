/*
可以把名字和学号都当成字符串处理。可以按以下流程实现。

　　#include<iostream>
　　#include<cstring>
　　using namespace std;

　　struct tstudent
　　{
　　char name[21];
　　char num[21];
　　char sex;
　　};

　　void readdata(tstudent student[], int n)
　　{
输入N个学生的信息
　　}

　　int findstudent(tstudent student[], int n, char* data)
　　{
　　if (data == NULL) return -1;

判断是否有某个学生的学号或名字等于data，如果有，函数返回该学生在student数组中的序号，否则返回-1
　　}

　　void solve(tstudent student[], int n, int m)
　　{
　　char x[21], y[21];
　　for (int i=0; i<m; i++) {
输入两个人的信息X、Y。通过调用findstudent函数判断这两个人能否成为舞伴
　　}
　　}

　　int main()
　　{
　　int n, m;
　　tstudent student[1010];

　　cin>>n;

　　readdata(student, n);
　　cin>>m;
　　solve(student, n, m);
　　}
*/
/*
问题描述
　　新生舞会开始了。n名新生每人有三个属性：姓名、学号、性别。其中，
姓名用长度不超过20的仅由大小写字母构成的字符串表示，学号用长度不超过10的仅由数字构成的字符串表示，
性别用一个大写字符‘F’或‘M’表示。任意两人的姓名、学号均互不相同。
换言之，每个人可被其姓名或学号唯一确定。给出m对两人的信息（姓名或学号），
判断他们是否能共舞。两人能共舞的充要条件为两人性别相异。

输入
　　第一行一个整数n（2<=n<=1000），表示学生人数。接下来的n行每行依次包含一名新生的姓名、
学号、性别，分别用一个空格隔开。
　　之后的一行是一个整数m(1<=m<=1000)，表示询问的数目。
接着的m行每行包含两个信息（姓名或学号），保证两个信息不属于同一人，中间用一个空格隔开。

输出
　　对于每个询问输出一行，如果两人可以共舞，输出一个大写字母‘Y’，否则输出一个大写字母‘N’。

*/

/*
4
John 10 M
Jack 11 M
Kate 20 F
Jim 21 M
3
John 11
20 Jack
Jim Jack
*/
#include <stdio.h>
#include <string.h>
typedef
struct
{
  char name[10];
  char xh[10];
  char sex[10];
}xs_t;

void shuru(int n,xs_t *a);
void panduan(int,int,int,xs_t*);
void output_solve(int m,int n,xs_t*a);
int find(char *s,int n,xs_t *a);

int main(void) 
{
   int n;
   scanf("%d",&n);
   xs_t a[n];
   shuru(n,a);
   int m;
   scanf("%d",&m);
   output_solve(m,n,a);
   return 0;
}

void shuru(int n,xs_t *a)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%s%s%s",&a[i].name,&a[i].xh,&a[i].sex);
  }
}


void output_solve(int m,int n,xs_t*a)
{
  int i;
  char s_0[10],s_1[10];
  for(i=0;i<m;i++)
  {
   scanf("%s%s",&s_0,&s_1);
   panduan(find(s_0,n,a),find(s_1,n,a),n,a); 
  }
}

void panduan(int xb_0,int xb_1,int n,xs_t *a)
{
 //printf("%d %d",xb_0,xb_1);
 if(xb_0==-1||xb_1==-1)
 {
  putchar('N');
  return;
 }
 printf("%c\n",strcmp(a[xb_0].sex,a[xb_1].sex)==0?'N':'Y');
}

int find(char *s,int n,xs_t *a)
{
 int i;
 if(*s<='9'&&*s>='0')
 {
  int i;
  for(i=0;i<n;i++)
  {
    if(strcmp(s,a[i].xh)==0)
    {
     return i;
	}
  }
 }else
 {
  int k;
  for(k=0;k<n;k++)
  {
    if(strcmp(s,a[k].name)==0)
    {
	 return k;
	}
  }
 }
 return -1;
}

