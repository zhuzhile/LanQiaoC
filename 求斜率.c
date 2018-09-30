#include <stdio.h>
typedef
  struct 
  {
    int  x;
    int  y;
  } ZB_t; 

int  qiu_xl(ZB_t,ZB_t);
int main(void) 
{
	ZB_t a;
	scanf("%d%d",&a.x,&a.y);
	ZB_t b;
	scanf("%d%d",&b.x,&b.y);
	if((a.x-b.x)==0)
   {
    printf("INF");
   }else{
   printf("%d",qiu_xl(a,b));}
	
	return 0;
}


int qiu_xl(ZB_t a,ZB_t b)
{
 
 return (a.y-b.y)/(a.x-b.x);
}
