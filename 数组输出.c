#include <stdio.h>
#include <math.h>
typedef
struct
{
 int zhi;
 int xiab1;
 int xiab2;
}Zt_t;



void shuru(int [][4],int);
Zt_t  qiu_zd(int [][4],int);
void jiaohuan(int *,int*);


int main(void) 
{
	int a[3][4];
	shuru(a,3);
	Zt_t zd;
	zd=qiu_zd(a,3);
	printf("%d %d %d\n",abs(zd.zhi),zd.xiab1+1,zd.xiab2+1); 
	return 0;
}

void shuru(int a[][4],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  int k;
  for(k=0;k<4;k++)
  {
    scanf("%d",&a[i][k]);
  }
 }

}

Zt_t qiu_zd(int a[][4],int n)
{
 Zt_t zd;
 zd.zhi=a[0][0];
 zd.xiab1=0;
 zd.xiab2=0;
 int i;
 for(i=0;i<n;i++)
 {
  int k;
  for(k=0;k<4;k++)
  {
   if(abs(zd.zhi)<abs(a[i][k])) 
   {
     zd.xiab1=i;
     zd.xiab2=k;
	 jiaohuan(&zd.zhi,&a[i][k]);
   }
  }
 }
 return zd;

}

void jiaohuan(int * a,int *b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

