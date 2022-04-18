#include<stdio.h>
  
main()
{
    int a[20],i,x,n,c=0;
    printf("enter size");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     
    printf("nEnter element to search using linear search:");
    scanf("%d",&x);
     
    for(i=0;i<n;i++)
     {
       if(a[i]==x)
          {
          	c++;
          	break;
			}  
			
}
     
    if(c==1)
        printf("Element found at index %d",i);
    else
        printf("Element not found");
  
    
}
