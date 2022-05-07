#include<stdio.h>
int mat[10][10],visited[10],n,cost=0;
int least (int);
void getval()
{
int i,j;
printf("Enter No. of Cities to be travelled(no of rows)");
scanf("%d",&n);
printf("\nEnter Cost Matrix\n");
for(i=0;i<n;i++)
{
printf("\nEnter Elements of Row: %d\n",i+1);
for( j=0;j<n;j++)
scanf("%d",&mat[i][j]);
visited[i]=0;
}
printf("\n\nThe cost list is:\n\n");
for( i=0;i<n;i++)
{
printf("\n\n");
for(j=0;j < n;j++)
printf("\t%d",mat[i][j]);
}
}

void mincost(int city)
{
int i,city1;
visited[city]=1;
printf("%d -->",city+1);
city1=least(city);
if(city1==999)
{
city1=0;
printf("%d",city1+1);
cost+=mat[city][city1];
return;
}
mincost(city1);
}

int least(int c)
{
int i,nc=999;
int min=999,kmin;
for(i=0;i<n;i++)
{
if((mat[c][i]!=0)&&(visited[i]==0))
if(mat[c][i] < min)
{
min=mat[i][0]+mat[c][i];
kmin=mat[c][i];
nc=i;
}
}
if(min!=999)
cost+=kmin;
return nc;
}

void putval()
{
printf("\n\nMinimum cost:");
printf("%d",cost);
}

main()
{
getval();
printf("\n\nThe Path is:\n\n");
mincost(0);
putval();
}
