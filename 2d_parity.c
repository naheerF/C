#include<stdio.h>
#include<string.h>
main()
{
 int i,j,r=4,c=8;
 int a[100][100];
 printf("enter the frame");
 for(i=0;i<r;i++)
 {
 	for(j=0;j<c;j++)
 	{
 	scanf("%d",&a[i][j]);
	 }
 }
 
 for(i=0;i<=r;i++)
 { int count=0;
 	for(j=0;j<=c;j++)
 	{
 		if(a[i][j]==1)
 		 count++;
	 }
	 if(count%2==0)
	 {
	 	a[i][c]=0;
	 }
	else
	a[i][c]=1;
 }
 
 for(j=0;j<=c;j++)
 { int count=0;
 	for(i=0;i<=r;i++)
 	{
 		if(a[i][j]==1)
 		 count++;
	 }
	 if(count%2==0)
	 {
	 	a[r][j]=0;
	 }
	 else
	 a[r][j]=1;
 }
 //a[j][i]='\0';
  for(i=0;i<=r;i++)
  {
  	for(j=0;j<=c;j++)
	  {
  		printf("%d",a[i][j]);
	  }
	  printf("\n");
  }
 
}
