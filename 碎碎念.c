#include <stdio.h>  
#include <string.h>  
  
  
int len(int from[],int i)  
{  
    int l = 1;  
    int t = from[i];  
    while(t)  
    {  
        t = from[t];  
        l++;  
    }  
    return l;  
}  
int main()  
{  
    int from[1000];  
    int n,i;  
    while(~scanf("%d",&n))  
    {  
        for(i = 1; i <= n; i++)  
            scanf("%d",&from[i]);  
        int mmax = 0;  
        for(i = 1; i <= n; i++)  
        {  
            if(from[i]==0)  
            {  
                if(mmax<1)  
                    mmax = 1;  
            }  
            else  
            {  
                int length = len(from,i);  
                if(mmax<length)  
                    mmax = length;  
            }  
        }  
        printf("%d\n",mmax);  
    }  
    return 0;  
}  
