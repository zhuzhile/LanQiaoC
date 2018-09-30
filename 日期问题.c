/*

问题描述
　　小明正在整理一批历史文献。这些历史文献中出现了很多日期。
小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，
这些日期采用的格式非常不统一，有采用的，有采用的，还有采用的。更加麻烦的是，
年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。


　　比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。


　　给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
输入格式
　　一个日期，格式是"AA/BB/CC"。 (0 <= A, B, C <= 9)
输出格式
　　输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。
样例输入
02/03/04
样例输出
2002-03-04
2004-02-03
2004-03-02
数据规模和约定
　　峰值内存消耗（含虚拟机） < 256M
　　CPU消耗 < 1000ms
请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
注意：
main函数需要返回0;
　　只使用ANSI C/ANSI C++ 标准;
　　不要调用依赖于编译环境或操作系统的特殊函数。
　　所有依赖的函数必须明确地在源文件中 #include <xxx>
　　不能通过工程设置而省略常用头文件。
提交程序时，注意选择所期望的语言类型和编译器类型。

*/

//年/月/日;
//月/日/年;
//日/月/年;

#include <stdio.h>
#include <string.h>

int pandaun(int,int,int,int*);
void s_to_z(int*,char*,int);
int jybpanduan(int,int,int);

int main(void) 
{
   char s[10];
   scanf("%s",s);
   int len=strlen(s);
   int a[len];
   s_to_z(a,s,len);
   int year,month,day;
   for(year=1960;year<=2059;year++)
   {
    for(month=1;month<=12;month++)
    {
	 for(day=1;day<=31;day++)
	 {
	  if(panduan(year,month,day,a))
	  {
	   if(jybpanduan(year,month,day))
	   {
	    printf("%d-%02d-%02d\n",year,month,day);
	   }
	  }
	 }
	}
   }
  
  return 0;
}

void s_to_z(int *a,char*s,int len)
{
 a[0]=(s[0]-'0')*10+s[1]-'0';
 a[1]=(s[3]-'0')*10+s[4]-'0';
 a[2]=(s[6]-'0')*10+s[7]-'0';
}

//年/月/日;
//月/日/年;
//日/月/年;
int panduan(int year,int month,int day,int *a)
{
 if(
 (year%100==a[0]&&month==a[1]&&day==a[2])
 ||(year%100)==a[2]&&(month==a[0])&&(day==a[1])
 ||(year%100)==a[2]&&(month==a[1])&&(day==a[0]))
 {
  return 1;
 }
 return 0;
}

int jybpanduan(int year,int month,int day)
{
  if(month==2)
  {
   if(day<=28+((year%100==0&&year%4!=0)||year%400==0))
   {
   return 1;
   }else{return 0;
   }
  }
  return 1;
}
