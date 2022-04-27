#include<stdio.h>
#include<stdlib.h>
#define max 3
int pri[max],front=-1,rear=-1,ch,data;
main()
{
	do
	{
	printf("1.insert\n2.display3.delete\n");
	printf("\nenter ur choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("enter elts");
		       scanf("%d",&data);
		        insert(data);
		       break;
		       case 3:deleting();
		               break;
		case 2:display();
		         break;
	}
	 }
	 while(1);	
}
insert(int data)
{
	if(rear>=max-1)
	{
		printf("overflow");
		return;
	}
	if(front==-1&&rear==-1)
	{
		front++;
		rear++;
		pri[rear]=data;
		return;
	}
	else
	{
		check(data);
		rear++;
	}
}
check(int data)
{
	int i,j;
	for(i=0;i<=rear;i++)
	{
		if(data>=pri[i])
		{
			for(j=rear+1;j>i;j--)
			{
				pri[j]=pri[j-1];
			}
			pri[i]=data;
			return;
		}
	}
	pri[i]=data;
}
deleting()
{
	printf("deleted data is %d",pri[front]);
	pri[front++];
}
display()
{
	int i;
	if(front==-1&&rear==-1)
	{
		printf("empty");
		return;
	}
	for(i=front;i<=rear;i++)
	printf("%d\t",pri[i]);
}
