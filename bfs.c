#include<stdio.h>
int cost[10][10],que[10],visited[10],printed[10],i,j,k,n,rear=-1,front=-1;
main()
{
	cost[10][10]=1;
	int m,v;
	printf("enter no of vertices and edges");
	scanf("%d%d",&n,&m);
	printf("enter adj vertices of each edges");
	for(k=1;k<=m;k++)
	{
		printf("\n enter adj vertices %d\n",k);
		scanf("%d%d",&i,&j);
		cost[i][j]=cost[j][i]=1;
	}
	printf("enter intial vertex");
	scanf("%d",&v);
	printf("order of visited vertices");
	printf("%5d",v); //for intial to be printed
	printed[v]=1;
	k=1;
	while(k<n)
	{
		for(j=1;j<=n;j++)
		{
			if(cost[v][j]!=0&&printed[j]!=1&&visited[j]!=1)
			{
				visited[j]=1;
				que[rear++]=j;
			}
		}
		v=que[front++];
		printf("%3d",v);
		k++;
		printed[v]=1;
	}
}
