#include<stdio.h>
#include<stdlib.h>
struct binary
{
	int data;
	struct binary *lc,*rc;
};
typedef struct binary node;
node *temp,*root=NULL,*newnode;
int ch,key;
main()
{
	
	do
	{
		printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.min element\n6.max element\n7.search\n8.delete");
		printf("\nenter ur choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			        break;
			case 2:inorder(root);
			        break;
			case 3:preorder(root);
			        break;
			case 4:postorder(root);
			        break;
			case 5: min(root);
			        break;
			case 6:max(root);
			       break;
			case 7:search(root);
			        break;
			case 8:
			printf("enter element to delete");
        scanf("%d",&key);
        deleting(root,key);
			        break;
			        
		}
	}
	while(1);
}

void insert()
{   int ele;
	newnode=(node*)malloc(sizeof(node));
	printf("enter elements");
	scanf("%d",&ele);
	newnode->data=ele;
	newnode->lc=NULL;
	newnode->rc=NULL;
	if(root==NULL)
	{
		root=newnode;
		return;
	}
	temp=root;
	while(1)
	{
		if(newnode->data<temp->data)
		{
			if(temp->lc==NULL)
			{
				temp->lc=newnode;
				return;
			}
			temp=temp->lc;
		}
		else if(newnode->data>temp->data)
		{
			if(temp->rc==NULL)
			{
				temp->rc=newnode;
				return;
			}
			temp=temp->rc;
			}
			else
			{
				printf("no duplicate elt");
				return;
			}
	}
}
void inorder(node*temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lc);
		printf("%d\t",temp->data);
		inorder(temp->rc);
	}
}
void preorder(node *temp)
{
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorder(temp->lc);
		preorder(temp->rc);
	}
}
void postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lc);
		postorder(temp->rc);
		printf("%d\t",temp->data);
	}
}
 void min(node *temp)
{
	while(temp->lc!=NULL)
	{
		temp=temp->lc;
	}
	printf("%d",temp->data);
}
 void max(node *temp)
{
	while(temp->rc!=NULL)
	{
		temp=temp->rc;
	}
	printf("%d",temp->data);
}
void search(node *temp)
{   
    int n;
	printf("enter element to be searched");
	scanf("%d",&n);
	while(temp!=NULL)
	{
		if(temp->data==n)
		{
			printf("\nelt found");
			return;
		}
		else if(temp->data>n)
		{
			temp=temp->lc;
		}
		else if(temp->data<n)
		{
			temp=temp->rc;
		}
	}
	printf("\nnot found");
}
void deleting(node *temp,int key)
{
	node *remv=root,*parent_remv=root,*replacable,*parent_replacable;
	while(1)
	{
		if(remv->data==key)
		break;
		parent_remv=remv;
		if(remv->data>key)
		remv=remv->lc;
		else if(remv->data<key)
		remv=remv->rc;
		if(remv==NULL)
		{
			printf("given key is not in BST,so deletion is not possible");
			return;
		}
    }
  printf("\ndeleted elt is %d",remv->data);
  if(remv->lc==NULL&&remv->rc==NULL)
  {
  	if(remv==root)
  	{
  		root=NULL;
  		free(remv);
  		return;
	  }
	  if(parent_remv->data>remv->data)
	    parent_remv->lc=NULL;
	    else if(parent_remv->data<remv->data)
	    parent_remv->rc=NULL;
	    free(remv);
	    return;
	}
	    else if(remv->lc!=NULL&&remv->rc==NULL)
		{
			if(remv==root)
			{
				root=remv->lc;
				free(remv);
				return;
			}
			if(parent_remv->data>remv->data)
			parent_remv->lc=remv->lc;
			else if(parent_remv->data<remv->data)
			parent_remv->rc=remv->rc;
			free(remv);
			return;
		}
		else if(remv->lc==NULL&&remv->rc!=NULL)
		{
			if(remv==root)
			{
				root=remv->rc;
				free(remv);
				return;
			}
			if(parent_remv->data>remv->data)
			parent_remv->lc=remv->rc;
			else if(parent_remv->data<remv->data)
			parent_remv->rc=remv->rc;
			free(remv);
			return;
		}
		parent_replacable=remv;
		replacable=remv->lc;
		if(replacable->rc==NULL)
		{
			remv->lc=replacable->lc;
			remv->data=replacable->data;
			free(replacable);
			return;
		}
		while(replacable->rc!=NULL)
		{
		parent_replacable=replacable;
		replacable=replacable->rc;
	    }
	    remv->data=replacable->data;
	    parent_replacable->rc=replacable->lc;
	    free(replacable);
	}
