#include<stdio.h>
#include<stdlib.h>
#define MAX 999
main()
{
	int n,a[100][100],i,j,k=0;
	printf("\n enter the number of vertices : ");
	scanf("%d",&n);
	printf("\n enter the adjacency matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	int min = MAX,cost=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j] == MAX)
			{
				for(k=0;k<n;k++)
				{
					if(k != i)
					{
					cost = a[i][k] + a[k][j];
					if(cost < min)
					min = cost;
				    }
				}
				if(min < a[i][j])
				a[i][j]=min;
				min = MAX;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d router is : ",i+1);
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}

}
