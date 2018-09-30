//定义一个学生结构体类型student，包括4个字段，姓名、性别、年龄和成绩。然后在主函数中定义一个结构体数组（长度不超过1000），并输入每个元素的值，程序使用冒泡排序法将学生按照成绩从小到大的顺序排序，然后输出排序的结果。
//　　输入格式：第一行是一个整数N（N<1000），表示元素个数；接下来N行每行描述一个元素，姓名、性别都是长度不超过20的字符串，年龄和成绩都是整型。
//　　输出格式：按成绩从小到大输出所有元素，若多个学生成绩相同则成绩相同的同学之间保留原来的输入顺序。
//输入：　　
/*
3
Alice female 18 98
Bob male 19 90
Miller male 17 92
*/
//
//输出：
//　　Bob male 19 90
//　　Miller male 17 92
//　　Alice female 18 98


#include <stdio.h>
struct student
{ 
  char name[10];
  char sex[10];
  unsigned age;
  unsigned grade;
};
void shuru(struct student *,int);
void shuchu(struct student *,int);
void bijiaocj(struct student *,int);
void jiaohuan(struct student *,struct student *);

int main(void) 
{
	int n;
	scanf("%d",&n);
	struct student sz[n];
	shuru(sz,n);
	bijiaocj(sz,n);
	shuchu(sz,n);
	return 0;
}

void shuru(struct student *sz,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   scanf("%s%s%d%d",&sz[i].name,&sz[i].sex,&sz[i].age,&sz[i].grade);
  }
}

void shuchu(struct student *sz,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
   printf("%s %s %d %d\n",sz[i].name,sz[i].sex,sz[i].age,sz[i].grade);
  }
}

void bijiaocj(struct student *sz,int n)
{
 int i;
 for(i=1;i<n;i++)
 {
 int k;
 for(k=0;k<n-i;k++)
 {
  if(sz[k].grade>sz[k+1].grade)
  {
   jiaohuan(&sz[k],&sz[k+1]);
  }
  }
 }

}

void jiaohuan(struct student * a,struct student * b)
{
  struct student tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}









