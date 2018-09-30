#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef
struct node
{
	int date;
	struct node*next;
}*ptr,snode;


int main(void) 
{
	ptr head=NULL,last;
    int x;
    scanf("%d",&x);
	while(x!=0)
	{
	  ptr p=(ptr)malloc(sizeof(snode));
	  p->date=x;
	  if(head!=NULL)
	  {
	  	p->next=head;
	  	head=p;
	  	last=p;
	  }else{
	  	last->next=p;
	  	p->next=NULL;
	  	last=p;
	  }
	 scanf("%d",&x); 
	}
	printf("%d ",head->date);

//		head=head->next; 
	
	putchar('\n');
	return 0;
}
