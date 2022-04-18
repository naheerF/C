#include <stdio.h>
main() {
    int n,m,a[100],i,j;
    printf("enter the n of n-binoccii");
    scanf("%d",&n);
    printf("enter length ");
    scanf("%d",&m);
    for(i=0;i<n-1;i++)
    a[i]=0;
    a[n-1]=1;  
    for(i=n;i<m;i++) {
    	a[i]=0;
        for(j=i-n;j<i;j++){
            a[i]=a[i]+a[j]; 
        }
    }
    for(i=0;i<m;i++) 
    printf("%d\t",a[i]);
  
}
