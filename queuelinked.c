#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
typedef struct queue node;
node *front;
node *rear=NULL;
node *newnode,*temp;
main()
{
	do
	{
		int ch,value;
		printf("1.insert\n2.delete\n3.display\n");
		printf("enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter value");
			       scanf("%d",&value);
			       insert(value);
			       break;
			case 2: deletion();
			       break;
			case 3:display();
			       break;
		}
	}while(1);
}
void insert(int value)
{
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	if(rear==NULL&&front==NULL)
	{
		newnode->next=NULL;
		front=rear=newnode;
	}
	else
	{
		newnode->next=NULL;
		front->next=newnode;
		front=newnode;
	}
}
void deletion()
{
	temp=rear;
	printf("deleted elt is %d\n",rear->data);
	rear=rear->next;
}
void display()
{
	temp=rear;
	while(temp->next!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
