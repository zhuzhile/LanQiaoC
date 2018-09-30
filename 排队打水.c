/*
有问题描述
　　N个人要打水，有M个水龙头，第i个人打水所需时间为Ti，请安排一个合理的方案使得所有人的等待时间之和尽量小。
输入格式
　　第一行两个正整数N M 接下来一行N个正整数Ti。
　　N,M<=1000，Ti<=1000
输出格式
　　最小的等待时间之和。（不需要输出具体的安排方案）
样例输入
7 3
3 6 1 4 2 5 7
样例输出
11
提示
　　一种最佳打水方案是，将N个人按照Ti从小到大的顺序依次分配到M个龙头打水。
　　例如样例中，Ti从小到大排序为1，2，3，4，5，6，7，将他们依次分配到3个龙头，则去龙头一打水的为1，4，7；去龙头二打水的为2,5；去第三个龙头打水的为3,6。
　　第一个龙头打水的人总等待时间 = 0 + 1 + (1 + 4) = 6
　　第二个龙头打水的人总等待时间 = 0 + 2 = 2
　　第三个龙头打水的人总等待时间 = 0 + 3 = 3
　　所以总的等待时间 = 6 + 2 + 3 = 11
 

*/
#if 0
#include<stdio.h>
void shuru(int* a,int n);
void paixu(int* a,int n);
void jiaohuan(int*,int*);
int  q_he(int*,int);
int  q_zxsj(int*,int,int);

int main(void)
{
 int n,m;
 scanf("%d%d",&n,&m);
 int a[n];
 shuru(a,n);
 printf("%d\n",q_zxsj(a,n,m));
 return 0;
}

void shuru(int * a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
}

void paixu(int*a ,int n)
{
  int i;
  for(i=1;i<n;i++)
  {
   int k;
   for(k=0;k<n-i;k++)
   {
    if(a[k]>a[k+1])
    {
	 jiaohuan(a+k,a+k+1);
	}

   }
  }

}

int  q_zxsj(int*a,int n,int m)
{
  if(n<=m)
  {
  return 0;
  }
  paixu(a,n);
  int count[n];
  int i;
  for(i=0;i<m;i++)
  {
   count[i]=0;
  }
  int k;
  for(k=m;k<n;k++)
  {
    count[k]=count[k-m]+a[k-m];
  } 
  return q_he(count,n);
}


void jiaohuan(int*p_1,int*p_2)
{
  int temp;
  temp=*p_1;
  *p_1=*p_2;
  *p_2=temp;
}

int q_he(int*a,int n)
{
 int i,he=0;
 for(i=0;i<n;i++)
 {
  he+=a[i];
 }
 return he;
}
#endif
/*
有一份提货单，其数据项目有：商品名（MC）、单价（DJ）、数量（SL）。定义一个结构体prut，
其成员是上面的三项数据。在主函数中定义一个prut类型的结构体数组，输入每个元素的值，计算并输出提货单的总金额。
　　输入格式：第一行是数据项个数N(N<100)，接下来每一行是一个数据项。商品名是长度不超过100的字符串，
单价为double类型，数量为整型。
　　输出格式：double类型的总金额。
输入：
　　4
　　book 12.5 3
　　pen 2.5 10
　　computer 3200 1
　　flower 47 5

输出：
4
book 12.5 3
pen 2.5 10
computer 3200 1
flower 47 5

　　3497.500000
*/
#if 0
#include<stdio.h>
typedef
struct
{
char name[180];
double price;
int amount;
}PRUT_t;

void shuru(PRUT_t *,int );
void shuchu(PRUT_t *,int );

int main(void)
{
  PRUT_t s[100];
  int n;
  scanf("%d",&n);
  shuru(s,n);
  shuchu(s,n);
  return 0;
}

void shuru(PRUT_t *s,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%s%lf%d",s[i].name,&s[i].price,&s[i].amount);
  }
}

void shuchu(PRUT_t *s,int n)
{
  int i;
  double he=0.;
  for(i=0;i<n;i++)
  {
   he+=s[i].price*s[i].amount;
  }
  printf("%lf",he);
}
#endif
/*
问题描述
　　见计算机程序设计基础（乔林）P50第5题。
　　接受两个数，一个是用户一年期定期存款金额，一个是按照百分比格式表示的利率，
计算一年期满后的本金与利息总额。说明：
(1) 存款金额以人民币元为单位，精确到分；
(2) 输入利率时不输入百分号，例如利率为3.87%，用户直接输入3.87；
(3) 按照国家法律，存储利息所得需缴纳5%的所得税，计算结果时应当扣除所得税。(4) 显示的结果精确到人民币分。
　　注意：数据须用float表示；计算结果须保存到一个float变量中，再用printf输出。
输入格式
　　一行，以一个空格隔开的两个浮点数。
输出格式
　　一个浮点数。
样例输入
5000.00 5.00
样例输出
5237.50
数据规模和约定
　　输入数据中每一个数的范围。本金<100000000，利息<100
*/

#include<stdio.h>
double q_lr(double,double);

int main(void)
{
  double qs,lx;
  scanf("%lf%lf",&qs,&lx);
  float jieg=q_lr(qs,lx);
   
  printf("%.2lf",jieg);
  return 0;
}

double q_lr(double qs,double lx)
{
   return qs*lx*0.01*(1.-0.05)+qs;
}






