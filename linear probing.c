#include<stdio.h>
int i,n,ch,h[100],t;
main()
{
	hash();
	do
	{
	printf("1.insert\n2.display\n3.deleting\n4.search\n");
	printf("enter ur choice");
	scanf("%d",&ch);
	switch(ch)
	   {
		case 1:printf("enter elts");
		       scanf("%d",&n);
		        insert(n);
		        break;
		case 2:display();
		        break;
		case 3:deleting();
		       break;
		case 4:search();
		        break;
		        
	    }
    }
	while(1);
	
}
hash()
{
	printf("enter tablesize");
	scanf("%d",&t);   //t=table size
	for(i=0;i<t;i++)
	h[i]=0;
}

insert(int n)
{
	int p=0,i=0;
	p=((n%t)+i)%t;
	if(h[p]==0)
	h[p]=n;
	else
	{
		while(h[p]!=0)
		{
			i++;
			p=((n%t)+i)%t;
		}
		h[p]=n;
	}
	
}
search()
{
	int e,p=0,i=0;
	printf("enter elt to search");
	scanf("%d",&e);
	p=((e%t)+i)%t;
	if(h[p]==e)
	printf("elt found");
	else
	{
		while(h[p]!=e)
		{
			i++;
			p=((e%t)+i)%t;
			if(p==t-1)
			break;
		}
		if(h[p]==e)
	printf("elt found");
	else
	printf("not found");
    }
	
}
display()
{
	for(i=0;i<t;i++)
	printf("h[%d]->%d\n",i,h[i]);
	
}
deleting()
{ int d,p=0,i=0;
	printf("enter elt to be deleted");
	scanf("%d",&d);
	p=((d%t)+i)%t;
	if(h[p]==d)
	{
		printf("deleted elt is %d",h[p]);
		h[p]=0;
	
	}
	else
	{
		while(h[p]!=d)
		{
			i++;
			p=((d%t)+i)%t;
			if(p==t-1)
			break;
		}
		if(h[p]==d)
	{
		printf("deleted elt is %d",h[p]);
		h[p]=0;
	
    }
	}
	
}
