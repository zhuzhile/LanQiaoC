#include <stdio.h>
#include <stdlib.h>

//¶þ·ÖËã·¨ 
int main(void)
{
	int a[6]={9,8,10,5,2,5};
	sort(a,0,5);
	output(a,6);
	printf("%d\n",bserach(a,0,5,5));
	return 0;
}

void output(int *a,int n)
{
	while(n--)
	{
		printf("%d ",*a++);
	}
	putchar('\n');
}

void sort(int *a,int beg,int end)
{
 if(beg<end)
 {
 	int i=beg+1;
 	int j=end;
 	while(i<j)
 	{
 	  if(a[i]>a[beg])
	  {
	   swap(a+i,a+j);
	   j--;
	  }else{i++;
	  }
	}
	if(a[i]>=a[beg])
	{
		i--;
	}
	swap(a+i,a+beg);
	sort(a,beg,i);
	sort(a,j,end);
 }

}

void swap(int*p,int *q)
{
	int t=*p;
	*p=*q;
	*q=t;
}
//int bserach(int *a,int x,int y,int v)
//{
//  int m; 
//  while(x<y) 
//  {
//  	m=x+(y-x)/2;
//  	if(a[m]==v){return m;
//	  }
//	  if(a[m]<v)
//	  {
//	  	x=m+1;
//	  }else{y=m;
//	  }
//  }
//}

int  bserach(int *a,int x,int y,int v)
{
	int m;
  while(x<y)
  {
  	 m=x+(y-x)/2;
  	if(a[m]<=v)
  	{
      x=m+1; 
    }else{y=m;
	}
  }
  return m;
} 
