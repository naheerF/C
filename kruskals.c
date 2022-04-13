#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct edge 
{
	int src,dst,wt;
};
struct edge e[MAX];
int nv,ne;
void read_edge()
{
	int i;
	printf("\nenter no of vertices");
	scanf("%d",&nv);
	printf("enter no of edges");
	scanf("%d",&ne);
	for(i=1;i<=ne;i++)
	{
		printf("\nenter edge %d adjacency vertices details and its weight\n",i);
		scanf("%d%d%d",&e[i].src,&e[i].dst,&e[i].wt);
	}
}
void kruskals()
{
	int i,j,vn[MAX],count=0,total_cost=0,connected[MAX],dcc=0;
	struct edge temp;
	for(i=1;i<=nv;i++)
	{
		vn[i]=0;
		connected[i]=0;
	}
	for(i=1;i<ne;i++)
	{
	   for(j=i+1;j<=ne;j++)
	   {
	      if(e[i].wt>e[j].wt)
	      {
	      	temp=e[i];
	      	e[i]=e[j];
	      	e[j]=temp;
		  }
	}
}
		  for(i=1;i<=ne&&count<nv-1;i++)
		  {
		    if((vn[e[i].src]==1&&vn[e[i].dst]==1&&connected[e[i].src]==connected[e[i].dst])||e[i].src==e[i].dst)
		  	continue;
		  	total_cost+=e[i].wt;
		  	vn[e[i].src]=vn[e[i].dst]=1;
		  	printf("\n%d-%d::%d",e[i].src,e[i].dst,e[i].wt);
		  	count++;
		    if(connected[e[i].src]==0&&connected[e[i].dst]==0)
		  	connected[e[i].src]=connected[e[i].dst]=++dcc;
		  	else if(connected[e[i].src]!=connected[e[i].dst])
		  	{
		  		for(j=1;j<=nv;j++)
		  		{
		  			if(connected[e[i].dst]==connected[j])
		  			connected[j]=connected[e[i].src];
				  }
			  }
		  }
		  printf("\nthe minimum spanning tree of a given graph is %d\n",total_cost);
}
main()
{
	read_edge();
	kruskals();

}
