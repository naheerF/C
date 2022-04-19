#include<stdio.h>
int reverse(int);
 main(){

    int n,temp;
	printf("Enter a number: ");
	scanf("%d",&n);
	temp=reverse(n);
	if(temp==1)
	printf("The given number  %d is a palindrome",n);
	else
	printf("The given number  %d is not a palindrome",n);
}

int reverse(int n){
int rem,rev=0;
    if(n!=0){
 rem=n%10;
 rev=rev*10+rem;
 reverse(n/10);
   }
 else if(rev==n)
  return 1;
  else
  return 0;
}
