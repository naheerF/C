#include<stdio.h>
#include<stdlib.h>
struct cdll
{
	int data;
	struct cdll *next;
	struct cdll *prev;
};
typedef struct cdll node;
node *newnode,*start=NULL,*temp,*prev12,*prev;
int n;
main()
{
	int ch,n;
	do
	{
		printf("1.create\n2.traverse\n3.insert\n4.delete\n");
		printf("enter ur choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter no nodes");
			        scanf("%d",&n);
			        create(n);
			        break;
			case 2:display();
			        break;
			case 3:insertion();
			        break;
			case 4:deletion();
			       break;
			       
			        
		}
	}
	while(1);
}
node *getnode()
{
	int ele;
	newnode=(node*)malloc(sizeof(node));
	printf("enter data");
	scanf("%d",&ele);
	newnode->data=ele;
	newnode->next=newnode;
	newnode->prev=newnode;
}
int countnode(node *temp)
{
	int ct=1;
	while(temp->next!=start)
	{
		ct++;
		temp=temp->next;
	}
	return ct;
	
}
create(int n)
{
	int i;
	//temp=start;
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
            newnode->prev=temp;
            newnode->next=start;
            start->prev=newnode;
        }
    }
}
 display()
{
    temp=start;
    while(temp->next!=start)
    {
    printf("%d->",temp->data);
    temp=temp->next;
     }
   printf("%d\n",temp->data);
   while(temp!=start)
    {
    	printf("%d->",temp->data);
    	temp=temp->prev;
	}
printf("%d\n",temp->data);
}
insertatfirst()
{
    newnode->next=start;
    start->prev=newnode;
    temp=start;
    while(temp->next!=start)
    temp=temp->next;
    temp->next=newnode;
    start=newnode;
}
insertatlast()
{
    temp=start;
    while(temp->next!=start)
    temp=temp->next;
    temp->next=newnode;
    newnode->next=start;
    newnode->prev=temp;
}
insertatmiddle()
{
    int ct=1,x,nodect;
		node *prev,*temp;
		printf("enter positon");
		scanf("%d",&x);
		temp=start;
		nodect=countnode(temp);
		if(x>1&&x<nodect)
		{
			temp=prev12=start;
			while(ct<x)
			{
				prev12=temp;
				temp=temp->next;
				ct++;
			}
		prev12->next=newnode;
		newnode->next=temp;
		newnode->prev=prev12;
		temp->prev=newnode;
    }
}
insertion()
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
deleteatfirst()
{
    prev12=start->next;
	temp=start;
    while(temp->next!=start)
    temp=temp->next;
    temp->next=prev12;
    start=prev12;
    
}
deleteatlast()
{
    temp=prev12=start;
	while(temp->next!=start)
	{
		prev12=temp;
		temp=temp->next;
	}
	prev12->next=start;
	//free(temp);
    
}
deleteatmiddle()
{
    int ct=1,x,nodect;
	    temp=prev12=start;
		printf("enter positon");
		nodect=countnode(temp);
		scanf("%d",&x);
			while(ct<x)
			{
				prev12=temp;
				temp=temp->next;
				ct++;
			}
		prev12->next=temp->next;
		prev12=prev12->next;
		prev12->prev=temp->prev;
		//free(temp);
	}
		
deletion()
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

