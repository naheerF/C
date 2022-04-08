#include<stdio.h>
#include<stdlib.h>
main()
{
	int n,i;
	scanf("%d",&n);
	int a[100],b[100];
	printf("enter data");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Before stuffing : ");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
	int c=0,j=0;
	for(i=0;i<n;i++)
	{
		if(a[i])
		{
			c++;
			if(c == 5)
			{
				b[j++]=a[i];
				b[j++]=0;
			}
			else
			b[j++]=a[i];
		}
		else
		{
			c=0;
			b[j++]=a[i];
		}
	}
	printf("After stuffing : ");
	for(i=0;i<j;i++)
	printf("%d ",b[i]);
	printf("\n");
	printf("After destuffing : ");
	c=0;
	for(i=0;i<j;i++)
	{
		if(b[i])
		{
			c++;
			if(c == 5)
			{
				printf("%d ",b[i]);
				i++;
			}
			else
			printf("%d ",b[i]);
		}
		else
		{
			c=0;
			printf("%d ",b[i]);
		}
	}
	
}
