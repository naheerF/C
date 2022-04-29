#include<stdio.h>
#include<stdlib.h>
#define buffersize 3
int in=0,out =2,x,buffer[5],c=0,consumed;
main()
{
	while(1)
	{
	int n;
	printf("1.producer\t2.consumer\n");
	printf("enter choice");
	scanf("%d",&n);
	switch(n)
	{
		case 1:if(c==buffersize)
		printf("full");
		else
		{
			printf("enter elements");
	         scanf("%d",&x);
		buffer[in]=x;
		in=(in+1)%buffersize;
		c++;
		}
		       break;
		case 2:if(c==0)
		printf("empty");
		else
		{
			consumed=buffer[out--];
			printf("%d",consumed);
		c--;
		}
		      break;
	}
}
}
	
