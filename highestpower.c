#include<stdio.h>
struct ll
{
	int data,power;
	char var,s[100];
	struct ll *next;	
};
typedef struct ll node;
node *start=NULL;
node *newnode;
node *temp;
main()
{
	int ch,n;
	do
	{
		printf("\n1.create");
		printf("\nenter ur choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter no of nodes");
			        scanf("%d",&n);
			        create(n);
		}
	}while(1);
	
}
node *getnode()
{

	char s[100];
	newnode=(node*)malloc(sizeof(node));
	newnode->next=NULL;
	
}
void create(int n)
{
	int i,j,c=0,high=0,b=0,a[100],s[100];
	printf("\n enter a string");
	scanf("%s",s);
	for(i=0;i<n;i++)
	{
		newnode=getnode();
		if(start==NULL)
		{
			start=newnode;
				while(s[c]!='\0'&&s[c]!='+')
				{
					start->data=s[c];
					c++;
					start->var=s[c];
					c++;
					start->power=s[c];
					c++;
				    printf("expression");
				}
			}
			else
			{
				while(s[c]!='\0'&&s[c]!='+')
				{
					newnode->data=s[c];
					c++;
					newnode->var=s[c];
					c++;
					newnode->power=s[c];
					c++;
				}
				temp=start;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				b=temp->power;
				a[b]++;
				temp->next=newnode;
			}
		}
		b=temp->power;
		a[b]++;
		for(j=0;j<100;j++)
		{
			if(a[j])
			high=j;
		}
		printf("\nhigh=%d",high);
	
	
}
