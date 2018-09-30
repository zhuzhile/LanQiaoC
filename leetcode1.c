#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	int n;
	scanf("%d",&n);
	int nums[n];
	input(nums,n);
	printf("%d\n",findMaxConsecutiveOnes(nums,n));
	return 0;
}

void input(int*a,int n)
{
 while(n--)
 {
 	scanf("%d",a++);
 }
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int i,xb=0;
  static int compute=0;
  int count[numsSize];
  int k;
  for(k=0;k<numsSize;k++)
  {
   count[k]=0;
  }
  for(xb=0;xb<numsSize;xb++)
  {
      
     for(i=compute;i<numsSize;i++)
     {
     if(compute>=numsSize)
      {
          break;  
      }
      if(nums[i]==1)
      {
        compute++;
        count[xb]++;
      }else{
          compute++;
          
          break;
      }
      
     }
  }
  return q_max(count,numsSize);
  
}



int q_max(int*a,int n)
{
  int max=a[0];
  int k;
  for(k=0;k<n;k++)
  {
     if(max<a[k])
     {
         max=a[k];
     }  
  }
  return max;
}
    

    
