#include<stdio.h>
main()
{
	int n1,n2,n,i,c=0,s=0;
	printf("enter");
	scanf("%d%d",&n1,&n2);
	for(n=n1;n<=n2;n++)
	{
		c=0;
		for(i=2;i<=n/2;i++)
		{
			if(n%i==0)
			c++;
			
			
			
		}
		if(c==0)
		s=s+n;
	}
		
		
		
		
		
		
	printf("%d\t",s);
}

