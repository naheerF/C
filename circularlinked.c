#include<stdio.h>
#include<stdlib.h>
struct cll
{
    int data;
    struct cll *next;
};
typedef struct cll node;
node *start=NULL,*newnode,*temp,*prev;
node *getnode()
{
    int ele;
    newnode=(node*)malloc(sizeof(node));
    printf("\n enter the data");
    scanf("%d",&ele);
    newnode->data=ele;
    newnode->next=newnode;
}
void traverse()
{
    temp=start;
    while(temp->next!=start)
    {
    printf("%d->",temp->data);
    temp=temp->next;
     }
   printf("%d",temp->data);
}
void insertatfirst()
{
    newnode->next=start;
    while(temp->next!=start)
    temp=temp->next;
    temp->next=newnode;
    start=newnode;
}
void insertatlast()
{
    temp=start;
    while(temp->next!=start)
    temp=temp->next;
    temp->next=newnode;
    newnode->next=start;
     
}
int count(node *temp)
{
    int ct=1;
    temp=start;
    while(temp->next!=start)
    {
        temp=temp->next;
        ct++;
    }
    return (ct);
}
void insertatmiddle()
{
    int ct=1,pos,nodeed;
    printf("\n enter the position to insert");
    scanf("%d",&pos);
    node *prev;
    temp=start;
    nodeed=count(temp);
    if(pos>1 && pos<nodeed)
    {
        temp=start;
        prev=start;
        while(ct<pos)
        {
            prev=temp;
            temp=temp->next;
            ct++;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
}
void insertion()
{
    int ch;
    printf("\n 1.insert at first");
    printf("\n 2.insert at middle");
    printf("\n 3.insert at last");
    printf("\n enter your choice");
    scanf("%d",&ch);
    newnode=getnode();
    switch(ch)
    {
        case 1:insertatfirst();
        break;
        case 2:insertatmiddle();
        break;
        case 3:insertatlast();
        break;
    }
}
void deleteatfirst()
{
    temp=start;
    while(temp->next!=start)
    temp=temp->next;
    temp->next=start->next;
    temp=start;
    start=start->next;
}
void deleteatlast()
{
    temp=prev=start;
    while(temp->next!=start)
    {	prev=temp;
    temp=temp->next;
}
    prev->next=start;
    
}
void deleteatmiddle()
{
    int ct=1,pos,nodeed;
    node *prev;
    printf("\n enter the position to delete");
    scanf("%d",&pos);
    temp=start;
    nodeed=count(temp);
    if(pos>1 && pos<nodeed)
    {
        temp=start;
        prev=start;
        while(ct<pos)
        {
            prev=temp;
            temp=temp->next;
            ct++;
        }
        prev->next=temp->next;
        temp->next=NULL;
    }
}
void deletion()
{
    int ch;
    printf("\n 1.deletion at first");
    printf("\n 2.delete at middle");
    printf("\n 3.delete at last");
    printf("\n enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:deleteatfirst();
        break;
        case 2:deleteatmiddle();
        break;
        case 3:deleteatlast();
        break;
    }
}
void create(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        newnode=getnode();
        if(start==NULL)
        start=newnode;
        
        else
        {
            temp=start;
            while(temp->next!=start)
            temp=temp->next;
            temp->next=newnode;
            newnode->next=start;
        }
    }
}
    
 main()
{
    int ch,n;
    do
    {
        printf("\n 1.create");
        printf("\n 2.traverse");
        printf("\n 3.insertion");
        printf("\n 4.deletion");
        printf("\n enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n enter the number of nodes");
            scanf("%d",&n);
            create(n);
            break;
            case 2:traverse();
            break;
            case 3:insertion();
            break;
            case 4:deletion();
            break;
        }
    }while(1);
}
