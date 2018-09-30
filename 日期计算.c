/*
　　已知2011年11月11日是星期五，问YYYY年MM月DD日是星期几？注意考虑闰年的情况。尤其是逢百年不闰，逢400年闰的情况。
输入格式
　　输入只有一行
　　YYYY MM DD
输出格式
　　输出只有一行
　　W
数据规模和约定
　　1599 <= YYYY <= 2999
　　1 <= MM <= 12
　　1 <= DD <= 31，且确保测试样例中YYYY年MM月DD日是一个合理日期
　　1 <= W <= 7，分别代表周一到周日
样例输入
2011 11 11
样例输出
5
*/ 
#include <stdio.h>
typedef
struct
{
	int nian;
	int yue;
	int ri;
	int xq;
}rq_t;

void after(rq_t*);
void before(rq_t*);
int q_xq(rq_t);
int panduan(int);

int main(void) 
{
   rq_t dqrq;
   scanf("%d%d%d",&dqrq.nian,&dqrq.yue,&dqrq.ri);	
   printf("%d\n",q_xq(dqrq));
   return 0;
}

void after(rq_t* yzrq)
{
      yzrq->xq=yzrq->xq==7?1:yzrq->xq+1;
	  switch(yzrq->yue)	
	  {
	  case 10:
	  case 8:
	  case 7:
	  case 5:
	  case 3:
	  case 1:if(yzrq->ri==31)
	           {yzrq->ri=1;
	           	yzrq->yue+=1;
			   }
	         else
	          {
			    yzrq->ri+=1;
			  }
	        break; 
	  case 2: if(yzrq->ri==28+panduan(yzrq->nian))
	            {
	               yzrq->ri=1;	
				   yzrq->yue+=1;
				}
	          else
	          {
			    yzrq->ri+=1;
			  }
	        break;
	  case 11:
	  case 9:
	  case 6:
	  case 4:if(yzrq->ri==30)	
	         { yzrq->ri=1;
			   yzrq->yue+=1;
			 }
	        else
	        {
			  yzrq->ri+=1;
			}
	       break;
	  case 12:if(yzrq->ri==31)	
	  	     {yzrq->ri=1;
			  yzrq->nian+=1;
			  yzrq->yue=1;
			 }  
			else	 
			{
			  yzrq->ri+=1;	
		    }	
		    break;
		}	
} 

void before(rq_t*yzrq)
{
	 yzrq->xq=yzrq->xq==1?7:yzrq->xq-1;
	  switch(yzrq->yue)	
	  {
	    case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
        if(yzrq->ri==1)
	           {yzrq->ri=31;
	           	yzrq->yue-=1;
			   }
	         else
	          {
			    yzrq->ri-=1;
			  }
	        break; 
	  case 3: if(yzrq->ri==1)
	            {
	               yzrq->ri=28+panduan(yzrq->nian);
				   yzrq->yue-=1;
				}
	          else
	          {
			    yzrq->ri-=1;
			  }
	        break;
	  case 10:
	  case 12:
	  case 7:
	  case 5:if(yzrq->ri==1)	
	         { yzrq->ri=30;
			   yzrq->yue-=1;
			 }
	        else
	        {
			  yzrq->ri-=1;
			}
	       break;
	  case 1:if(yzrq->ri==1)	
	  	     {yzrq->ri=31;
			 yzrq->nian-=1;
			  yzrq->yue=12;
			 }  
			else	 
			{
			yzrq->ri-=1;	
		    }	
		    break;
		}	
 
} 

int zyq(rq_t dqrq, rq_t yzrq)
{
if(dqrq.nian > yzrq.nian )
{
return 1;
}
if(dqrq.nian < yzrq.nian )
{
return 0;
}
if(dqrq.yue > yzrq.yue )
{
return 1;
}
if(dqrq.yue < yzrq.yue )
{
return 0;
}
return 	dqrq.ri > yzrq.ri;
}

int zyh(rq_t ddrq, rq_t yrq)
{
if(ddrq.nian < yrq.nian )
{
return 1;
}
if(ddrq.nian > yrq.nian )
{
return 0;
}
if(ddrq.yue < yrq.yue )
{
return 1;
}
if(ddrq.yue > yrq.yue )
{
return 0;
}
return 	ddrq.ri < yrq.ri;	
} 


int q_xq(rq_t dqrq)
{
rq_t yrq = { 2011 , 11 , 11 , 5 };
while( zyq(dqrq,yrq) )
{
 after(&yrq);
}
while( zyh(dqrq,yrq) )
{
 before(&yrq);
}
return yrq.xq ;
} 

int panduan(int n)
{
  return (n%4==0&&n%100!=0||n%400==0);
}

