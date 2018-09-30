#include <stdio.h>
#include <stdlib.h>


int main(void) 
{
	int a[3]={1,1,2};
	output(a,removeDuplicates(a,3));
	return 0;
}

void output(int*a,int n)
{
	while(n--)
	{
		printf("%d ",*a++);
	}
}

int removeDuplicates(int* nums, int numsSize) 
{
    int i,index=1;
    for(i=1;i<numsSize;i++)
    {
      if(nums[i]!=nums[i-1])
      {
         nums[index++]=nums[i]; 
      }
      
    }
    return index;
}
