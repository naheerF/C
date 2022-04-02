#include<stdio.h>
int knapsack(int weight[],int profit[],int visited[],int sum,int psum,int n,int x,int m,int a[])
{
	static int max;
	if(x == n+1)
	return max;
	else if((sum == m) && (psum > max))
	{
		max = psum;
		int i;
		for(i=0;i<n;i++)
		a[i] = visited[i];
	}
	else
	{
		visited[x] = 1;
		knapsack(weight,profit,visited,sum + weight[x],psum + profit[x],n,x+1,m,a);
		visited[x] = 0;
		knapsack(weight,profit,visited,sum,psum,n,x+1,m,a);
		return ;
	}
	return max;
}
main()
{
	int n,i,z;
	printf("\n enter the size of the array : ");
	scanf("%d",&n);
	int a[100],weight[100],profit[100],visited[100],m;
	printf("\n enter the weights : ");
	for(i=0;i<n;i++)
	scanf("%d",&weight[i]);
	printf("\n enter the profits : ");
	for(i=0;i<n;i++)
	scanf("%d",&profit[i]);
	printf("\n enter the weight of the knapsack : ");
	scanf("%d",&m);
	z = knapsack(weight,profit,visited,0,0,n,0,m,a);
	printf("\n maximum profit with %d weight is : %d",m,z);
	printf("\n weights included are : ");
	for(i=0;i<n;i++)
	printf(" %d ",a[i]);
}
