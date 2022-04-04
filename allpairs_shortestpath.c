#include<stdio.h>
main()
{
 int a[100][100],wt,n,e,u,v,i,j;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 printf("\n Enter the number of edges:\n");
 scanf("%d",&e);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   a[i][j]=9999;
 }
 for(i=1;i<=e;i++)
 {
  printf("\n Enter the edge-edge %d with its weight \n",i);
  scanf("%d%d%d",&u,&v,&wt);
  a[u][v]=wt;
 }
 printf("\n Matrix of input data:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%d \t",a[i][j]);
  printf("\n");
 }
 all_pair(a,n);
 printf("\n Final Matrix\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++){
   printf("%d \t",a[i][j]);
}
  printf("\n");
 }
}
void all_pair(int a[100][100],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++){
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++){
    if(i==j)
     a[i][j]=0;
    else
     a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	 }
 }
}
}
int min(int a,int b)
{
 if(a<b)
  return a;
 else
  return b;
}

