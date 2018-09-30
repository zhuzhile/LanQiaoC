#include <stdio.h>

int main(void) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	shuru(a,n);
	int m=1;
	printf("%d %d\n",a[m--],a[m++]); 
	return 0;
}

void shuru(int*a,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
}



