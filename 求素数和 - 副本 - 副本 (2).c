#include <stdio.h> 

int main(void) 
{
	int i,n;
	scanf("%d",&n);
	int a[n] ;
	for(i=0;i<n;i++)
	{
	 a[i]=i+1;
	}
	a[0]=0;
	int k;
	for(k=0;k<n;k++)
	{
	 if(a[k]==0)
	 {
	  continue;
	 }
	 else{
		int j;
	 	for(j=a[k]+k;j<n;j+=a[k])
	 	{
         a[j]=0;
		}
	    }
	}
	int m;long long he=0LL;
	for(m=0;m<n;m++)
	{
	 if(a[m]!=0)
	 {
	  he+=a[m];
	 }
	}
	printf("%lld\n",he);
	
	
	
	return 0;
}
