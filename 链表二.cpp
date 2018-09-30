#include<malloc.h> 
#include <iostream>
using namespace std;

//如果我输入1 2 4 5；在2之后加入3
//输入1 2 3 4 5 6删掉3

typedef
struct node
{
	int data;
	struct node*next;
}*ptr, snode;

void Add(ptr);
void Delete(ptr);
ptr Input(void);
void Show();
void Search(ptr);
void Change(ptr);
void Reverse(ptr);


int main(void)
{
	ptr head = Input();
	Show();
	printf("请输入您的选择");
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: Add(head);
		break;
	case 2: Delete(head);
		break;
	case 3: Search(head);
		break;
	case 4:Change(head);
		break;
	case 5:Reverse(head);
		break;
	default:
		printf("输入有误，请重新输入\n");
	}
	system("pause");
	putchar('\n');
	return 0;
}

void Show()
{
	printf("***********1-添加元素********\n");
	printf("***********2-删除元素********\n");
	printf("***********3-查找元素********\n");
	printf("***********4-修改元素********\n");
	printf("***********5-倒置元素********\n");
}


void Add(ptr head)
{
	printf("请输入要添加的元素：");
	int element;
	cin >> element;
	while (head != NULL)
	{
		if (head->data == element - 1)
		{
			ptr p = (ptr)malloc(sizeof(snode));
			p->data = element;
			p->next = head->next;
			head->next = p;
		}
		cout << head->data << " ";
		head = head->next;
	}
}


void Delete(ptr head)
{
	printf("请输入要删除的元素：");
	int element;
	cin >> element;
	while (head != NULL)
	{
		if (head->data == element - 1)
		{
			ptr p = (ptr)malloc(sizeof(snode));
			p = head->next;
			head->next = p->next;
			free(p);
		}
		cout << head->data << " ";
		head = head->next;
	}
}

ptr Input(void)
{
	ptr head = NULL, last=NULL;
	int x;
	cin >> x;
	while (x != 0)
	{
		ptr p = (ptr)malloc(sizeof(snode));
		p->data = x;
		if (head == NULL)
		{
			p->next = head;
			head = p;
			last = p;
		}
		else
		{
			last->next = p;
			p->next = NULL;
			last = p;
		}
		cin >> x;
	}
	return head;
}

void Search(ptr head)
{
	printf("请输入要查找的元素：");
	int element;
	cin >> element;
	while (head != NULL)
	{
		if (head->data == element)
		{
			printf("存在该元素");
			return;
		}
		head = head->next;
	}
	printf("不存在该元素");
}

void Change(ptr head)
{
	printf("请输入要被修改的元素与修改后的值：");
	int element, value;
	cin >> element >> value;
	while (head != NULL)
	{
		if (head->data == element)
		{
			head->data = value;
		}
		printf("%d ", head->data);
		head = head->next;
	}
}

void Reverse(ptr head)
{
	//  ptr p,q,pr;
	//  p = head->next;
	//  q = NULL;
	//  head->next = NULL;
	//  while(p){
	//    pr = p->next;
	//    p->next = q;
	//    q = p;
	//    p = pr;
	//  }
	//  head->next = q;
	ptr first = head;
	ptr now = head->next;
	ptr next = now->next;
	first->next = NULL;
	do {
		next = now->next;
		now->next = first;
		first = now;
		now = next;
	} while (next != NULL);

	while (first != NULL)
	{
		printf("%d ", first->data);
		first = first->next;
	}
	putchar('\n');
}
