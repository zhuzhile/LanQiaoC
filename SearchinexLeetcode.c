/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

*/

#include <stdio.h>
#include <stdlib.h>

int search_index(int*,int,int);

int main(void) 
{
	int *p;
	p=(int*)malloc(sizeof(int)*100);
	int n;
	scanf("%d",&n);
	int i;//输入一个有序的数组 
	for(i=0;i<n;i++)
	{
	 scanf("%d",&p[i]);	
	}
	int target;
	scanf("%d",&target);
	printf("%d\n",search_index(p,n,target));
	return 0;
}

int search_index(int*a,int n,int target)
{
   int i;
   for(i=0;i<n;i++)
   {
   	if(target==a[i])
   	{
   	  return i;	
	}
   }
   int k;
   for(k=0;k<n;k++)
   {
   	if(target<a[k])
   	{
   	 return k;	
	}
   }
}


