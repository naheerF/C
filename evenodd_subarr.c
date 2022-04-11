#include<stdio.h>
main(){
	int a[100],c=0,i,j;
	printf("enter elts");
	for(i=0;i<5;i++)
	scanf("%d",&a[i]);
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if((a[i]%2==0&&a[j]%2!=0)||(a[j]%2==0&&a[i]%2!=0))
			c++;
			else if((a[i]%2==0&&a[j]%2==0)||(a[j]%2==0&&a[i]%2==0))
			c=1;
			else if((a[i]%2!=0&&a[j]%2!=0)||(a[j]%2!=0&&a[i]%2==0))
			c=1;
		}
	}
	printf("the largest subarray %d",c);
}
