#include<stdio.h>
int max(int a, int b) { 
if (a > b) 
return a;
else
return b; 
} 
void knapsack(int m, int wt[], int p[], int n) 
{ 
	int i, w; 
	int tot[n + 1][m + 1]; 
	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= m; w++) { 
			if (i == 0 || w == 0) 
				tot[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				tot[i][w] = max(p[i - 1]+tot[i - 1][w - wt[i - 1]], tot[i - 1][w]); 
			else
				tot[i][w] = tot[i - 1][w]; 
		} 
	} 

	int x[n];
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	int pmax = tot[n][m];	
	printf("\ntotal Max profit : "); 
	printf("%d\n",pmax); 
	
	w = m; 
	for (i = n; i > 0 && pmax> 0; i--) {
		if (pmax== tot[i - 1][w]) 
			continue;		 
		else {
			x[i-1]=1;
			pmax= pmax- p[i - 1]; 
			w = w - wt[i - 1]; 
		} 
	}
	printf("\n vector results:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",x[i]);
	 } 
} 

main() 
{ 
int n,i,knap[n][n];
    printf("enter no of items");
	scanf("%d",&n);
	int m,wt[n],p[n];
	printf("\n enter Weights : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("\n enter Profits : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("\nenter knapsack value ");
	scanf("%d",&m);
	knapsack(m,wt,p,n); 
}
