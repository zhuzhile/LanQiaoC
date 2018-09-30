/* 
格子中输出

StringInGrid函数会在一个指定大小的格子中打印指定的字符串。
要求字符串在水平、垂直两个方向上都居中。
如果字符串太长，就截断。
如果不能恰好居中，可以稍稍偏左或者偏上一点。

下面的程序实现这个逻辑，请填写划线部分缺少的代码。
*/
#if 0
#include <stdio.h>
#include <string.h>

void StringInGrid(int width, int height, const char* s)
{
	int i,k;
	char buf[1000];
	strcpy(buf, s);
	if(strlen(s)>width-2) buf[width-2]=0;
	
	printf("+");
	for(i=0;i<width-2;i++) printf("-");
	printf("+\n");
	
	for(k=1; k<(height-1)/2;k++){
		printf("|");
		for(i=0;i<width-2;i++) printf(" ");
		printf("|\n");
	}
	
	printf("|");


	
	printf("%*s%s%*s","     ",buf,"     ");  //填空
	          
	printf("|\n");
	
	for(k=(height-1)/2+1; k<height-1; k++){
		printf("|");
		for(i=0;i<width-2;i++) printf(" ");
		printf("|\n");
	}	
	
	printf("+");
	for(i=0;i<width-2;i++) printf("-");
	printf("+\n");	
}

int main()
{
	StringInGrid(20,6,"abcd1234");
	return 0;
}

#endif
#if 0 
int f(char s[], int begin, int end)
{
	int mid;
	if(end-begin==1) return s[begin] - '0';
	mid = (end+begin) / 2;
	return f(s,mid,end)+f(s,begin,mid);  //填空
}
	
int main()
{
	char s[] = "4725873285783245723";
	printf("%d\n",f(s,0,strlen(s)));
	return 0;
}
#endif 
/*
奇妙的数字

小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
你能猜出这个数字是多少吗？

请填写该数字，不要填写任何多余的内容。
*/
#if 0
#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	int cap=n,sum=0;
	while(1)
	{
		if(cap/3==0)
		{
		 break;	
		} 
		sum+=cap/3;
		int cap_=cap;
		cap/=3;
	    cap+=cap_%3;
	}
	printf("%d ",sum+n);
	return 0;
}
#endif

    #include <stdio.h>    
    int main()    
    {    
        int sum = 1225;  
        int tmp=0;  //临时变量，在程序中保存中间结果   
        int res=0;  //用来保存将“+”改变成“*”号后的结果
		int i;   
        for(i=2; i<=47; ++i)  
         {    
            tmp = res = sum-(i+(i-1))+i*(i-1); 
			int j;   
              
            for(j=i+2; j<=49; ++j)   
            {    
                res = tmp-(j+(j-1))+j*(j-1);    
                if(res == 2015)  
                {    
                    printf("(i= %d ,j= %d)\n", i-1,j-1);    
                }      
            }    
        }    
    }  



