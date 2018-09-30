#include <stdio.h>
void shuru(double [][4],int);
void shuchu (double[],int);
int main(void) 
{
	double cj[4][4];
	shuru(cj,4); 
	double pj[4];
	int i;
   int k;
   for(k=0;k<4;k++)
   {
   pj[0]+=cj[k][0];
   }
   for(k=0;k<4;k++)
   {
   pj[1]+=cj[0][1];
   }
   for(k=0;k<4;k++)
   {
   pj[2]+=cj[k][2];
   }
   for(k=0;k<4;k++)
   {
   pj[3]+=cj[k][3];
   }
   shuchu(pj,4);
   return 0;
}


void shuru(double cj[][4],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  int k;
  for(k=0;k<4;k++)
  {
   scanf("%lf",&cj[i][k]);
  }
 }
}

void shuchu(double pj[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("%.2lf\n",pj[i]/4.);
 }
}

