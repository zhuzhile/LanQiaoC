#include <stdio.h>
#include <stdlib.h>

void sort(int*,int,int,int);
void output_arry(int*,int);
void swap(int*,int*);

int main(void) 
{
    int a[5]={1,3,4,5,6};
    sort(a,5,0,4);
    output_arry(a,5);
	return 0;
}

void sort(int*a,int n,int beg,int end)
{
 int i,j;
 if(beg<end)
 {
  i=beg+1;
  j=end;
  while(i<j)
  {
   if(a[i]>a[beg])
   {
   	swap(a+i,a+j);
    j--;
   }else{i++;
   }
  }
   
  swap(a+beg,a+i);
  sort(a,n,beg,i);
  sort(a,n,j,end);
 }

}

void output_arry(int*a,int n)
{
  while(n--)
  {
   printf("%d ",*a++);
  }
}

void swap(int*a,int*b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}
