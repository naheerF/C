#include<stdio.h>
#include<string.h>
main()
{
 int n,a[n],i;
 printf("Enter the length of bits: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 	scanf("%d",&a[i]);
 }
 printf("Before stuffing: ");
 int count=0;
 for(i=0;i<n;i++)
 {
 	printf("%d ",a[i]);
 }
 for(i=0;i<n;i++)
 {
 	if(a[i]==1)
 	{
 		count++;
 	}
 }
 	if(count%2==0)
 	{
 		a[n]=0; //adding 0 to last if even ones
	}
	else
	{
		a[n]=1;
	}
	printf("\nAfter stuffing in the parity: ");
	for(i=0;i<n+1;i++)  //adding extra elt so n+1
	printf("%d ",a[i]);
}
