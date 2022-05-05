#include<stdio.h>
 main()
{
	int a[100][100],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	single_source(a,n,u);
	
}
 
void single_source(int a[100][100],int n,int startnode)
{
 
	int cost[100][100],dist[100],pred[100];
	int visited[100],c,mindist,nextnode,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==0)
				cost[i][j]=999;
			else
				cost[i][j]=a[i][j];
			}
		}
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		dist[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	dist[startnode]=0;
	visited[startnode]=1;
	c=1;
	
	while(c<n-1)
	{
		mindist=999;
		for(i=0;i<n;i++){
			if(dist[i]<mindist&&!visited[i])
			{
				mindist=dist[i];
				nextnode=i;
			}
		}	
			visited[nextnode]=1;
			for(i=0;i<n;i++){
				if(!visited[i])
					if(mindist+cost[nextnode][i]<dist[i])
					{
						dist[i]=mindist+cost[nextnode][i];
						pred[i]=nextnode;
					}
				}
		c++;
	}
 
	
	for(i=0;i<n;i++){
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,dist[i]);
			printf("\nPath=%d",i);    
			
			j=i;
			while(j!=startnode)
			{
				j=pred[j];
				printf("<-%d",j);
			}
	}
}
}
