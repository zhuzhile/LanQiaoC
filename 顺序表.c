typedef struct{
    int n;
    int maxLength;
    int *element;
}SeqList;


void Init(SeqList*,int);
void Find(SeqList ,int );
void Insert(SeqList*,int ,int );
void Delete(SeqList*,int ); 
void meanu();
void Destroy(SeqList*);
void Output(SeqList*);
void makeChoice(int,SeqList*);

int main(void) 
{
    SeqList list;
    int size;
    printf("请输入数组大小\n"); 
    scanf("%d",&size);
    Init(&list,size); 
    meanu();
    printf("请输入你的选择\n"); 
    int choice;
    scanf("%d",&choice);

    while(choice)
    {
     makeChoice(choice,&list);  
     printf("请输入你的选择：\n"); 
     scanf("%d",&choice);
    }           
    return 0;
}


void makeChoice(int choice,SeqList *p_list)
{
    int digital,index;
    switch(choice)
    {
        case 0:
           break; 
        case 1:
            printf("请输入你要查询的值:\n");
            scanf("%d",&digital); 
            Find(*p_list,digital);
        break;
        case 2:
            printf("请输入你要插入的位置，和插入的值\n");
            scanf("%d%d",&index,&digital); 
            Insert(p_list,index,digital); 
//          printf("%d \n",p_list->n);
        break;
        case 3:
             printf("请输入你要删除的位置\n");
             scanf("%d",&index); 
             Delete(p_list,index);
        break;
        case 4:
             Output(p_list);
        break;
        case 5:
             Destroy(p_list);
        break;
        default:
            printf("没有该选项\n");
        break;
    }
}

void meanu()
{
    printf("*************\n");
    printf("****0.退出***\n");
    printf("****1.查询***\n");
    printf("****2.插入***\n");
    printf("****3.删除***\n");
    printf("****4.输出***\n");
    printf("****5.清空***\n"); 
}

void Init(SeqList*L,int mSize)
{
    L->maxLength=mSize;
    L->n=0;
    L->element=malloc(sizeof(int)*mSize);
}


void Find(SeqList L,int x)
{
    int i;
    for(i=0;i<L.n;i++)
    {
        if(x==L.element[i])
        {
            printf("数组中有该元素\n"); 
            return;
        }
    }
    printf("数组中没有该元素\n"); 
}

void Insert(SeqList*L,int i,int x)
{
    int j;
//  if(i<0||i>L->n-1) 他妈的智障 
//  {
//      printf("插入失败\n");
//      return; 
//  }
    if(L->n==L->maxLength)
    {
        printf("插入失败\n");
        return; 
    }
    for(j=L->n-1;j>i-1;j--)//向右循环移位 
    {
        L->element[j+1]=L->element[j];
    } 
    L->element[i]=x;
    L->n++;
}

void Delete(SeqList*L,int i)
{
    int j;
    if(i<0||i>L->n - 1)
    {
        printf("删除失败\n");
        return; 
    }
    if(!L->n)
    {
        printf("删除失败\n");
        return; 
    }
    for(j=i+1;j<L->n;j++)
    {
        L->element[j-1]=L->element[j];//向左循环移位 
    }
    L->n--;
}


void Output(SeqList *L)
{
    int i;
    if(!(L->n))
    {
//      printf("%d",L->n);
        printf("数组中没有元素\n"); 
        return; 
    }
    for( i=0;i<L->n;i++)
    {
        printf("%d ",L->element[i]);
    }
    printf("\n"); 
}

void Destroy(SeqList* L)
{
    L->n=0;
    L->maxLength=0;
    free (L->element);
}
