/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/ 
#include <stdio.h>
#include <stdlib.h>


void input(char*,int*); 

int main(void) 
{
	char s[20];
	int ws_s=0;
	char s1[20];
	int ws_s1=0;
	input(s,&ws_s);
	input(s1,&ws_s1);
	char*str="abcdefghijklmnopqrstuvwxyz";
	int count_1[26]={0};
	int i;
	for(i=0;i<ws_s;i++)
	{
	 int k;
	 for(k=0;k<26;k++)
	 {
	  if(s[i]==str[k])
	  {
	  	count_1[k]++;
	  }	
	 }	
	}
	int count_2[26]={0};
	for(i=0;i<ws_s1;i++)
	{
	int k;
	 for(k=0;k<26;k++)
	 {
	  if(s1[i]==str[k])
	  {
	  	count_2[k]++;
	  }	
	 }	
	}
	printf("%s",step_to_judge(count_2,count_1)==1?"true":"false");
	return 0;
}

int step_to_judge(int*a,int*b)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(a[i]!=b[i])
		{
			return 0;
		}
	}
	return 1;
}

void input(char*s,int*p_ws)
{
	char c;
     while((c=getchar())!='\n')
	{
	  	s[*p_ws]=c;
	  	++*p_ws;
	}	
}
