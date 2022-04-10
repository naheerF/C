#include<stdio.h>
#include<stdlib.h>
struct ll
{
	int data;
	struct ll *next,*prev;	
};
typedef struct ll node;
node *start=NULL;
node *newnode;
node *temp;
node *prev12;
main()

{
	int ch,n;
	do
	{
		printf("\n1.create\n2.display\n3.insertion\n4.deletion\ncountnode");
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
 			case 1:printf("enter no of node");
                    scanf("%d",&n);
					create(n);
					break;
			case 2:display();
			       break;
			case 3:insertion();
			        break;
			case 4:deletion();
			        break;
			case 5:countnode();
			       break;
			default :exit(0);			     
		}
	} 
	while(1);
}
node *getnode()
	{
		int element;
		newnode=(node*)malloc(sizeof(node));
		printf("enter data value");
		scanf("%d",&element);
		newnode->data=element;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
create(int n)
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
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
	}
}
	

display()
{
	temp=start;
    while(temp->next!=NULL)
    {
	printf("%d->",temp->data);
	temp=temp->next;
    }  
	printf("%d\n",temp->data); 
    while(temp->prev!=NULL)
    {
    	printf("%d->",temp->data);
    	temp=temp->prev;
	}
printf("%d",temp->data);
}
int countnode(node *temp)
{
	temp=start;
	int ct=1;
	while(temp->next!=NULL)
	{
		ct++;
		temp=temp->next;
	}
	printf("%d",ct);
	return(ct);
}
insertatfirst()
	{
		
		start->prev=newnode;
		newnode->next=start;
		start=newnode;
	}
	insertatlast()
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
	insertatmid()
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
	int x;
	printf("\n1.insert at first\n");
	printf("\n2.insert at middle");
	printf("\n3.insert at last\n");
	printf("\nenter place to insert");
	scanf("%d",&x);
	newnode=getnode();
	switch(x)
	{
		case 1:insertatfirst();
		        break;
		case 2:insertatmid();
		        break;
		case 3:insertatlast();
		         break;
	}
}




deleteatfirst()
{
	temp=start;
	start=start->next;
	start->prev=NULL;
	free(temp);
}
deleteatmid()
{
	
	int ct=1,x;
	node *prev;
	    temp=prev12=start;
		printf("enter positon");
		scanf("%d",&x);
			while(ct<x)
			{
				prev12=temp;
				temp=temp->next;
				ct++;
			}
		prev12->next=temp->next;
		prev=prev12->next;
		prev12->prev=temp->prev;
		free(temp);
	
}
deleteatlast()
{
	temp=prev12=start;
	while(temp->next!=NULL)
	{
		prev12=temp;
		temp=temp->next;
	}
	prev12->next=NULL;
	free(temp);

}
deletion()
{
	int x;
	printf("1.delete at first\n");
    printf("2.delete at mid\n");
    printf("3.delete at last");
	printf("\nenter place to delete");
	scanf("%d",&x);
	switch(x)
	{
		case 1:deleteatfirst();
		        break;
		case 2:deleteatmid();
		        break;
		case 3:deleteatlast();
		         break;
	}
}
