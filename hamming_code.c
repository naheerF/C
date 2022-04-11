#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
main()
{
	int n,r=0,l,m,h=0,i,g,j,o=0,t;
	printf("enter the length of bits :");
	scanf("%d",&n);
	char *s,*s1,ch;
	s=(char*)calloc(n,sizeof(char));
	printf("\n enter the data :");
	scanf("%s",s);
	while(pow(2,r) <= (n + r + 1))
	{
		r++;
	}
	m=n+r;
	int *a;
	a=(int*)calloc(r,sizeof(int));
	printf("number of redundant bits =%d\n",r);
	s1=(char*)calloc(m,sizeof(char));
	h=r-1;
	while(h >= 0)
	{
		g=pow(2,h);
		s1[m-g]='$';
		h--;
	}
	i=n-1;
	l=m-1;
	while(i >= 0)
	{
		if(s1[l]!='$')
		{
			s1[l]=s[i];
			l--;
			i--;
		}
		else
		l--;
	}
	int k;
	for(i=m-1;i>=0;i--)
	{
		t=pow(2,r-1);
		k=r-1;
		while(t > 0)
		{
			if(t & (m-i))
			{
				g = s1[i]-'0';
				if(g == 1)
				{
					a[k]++;
				}
	        }
			t=t/2; 
			k--;
		}
		
	}
	printf("data before performing operation : %s\n",s1);
	printf("parity bits are : ");
	for(i=0;i<r;i++)
	printf("%d ",a[i]);
	printf("\n");
	t=r-1;
	for(i=r-1;i>=0;i--,t--)
	{
		if(a[i] & 1)
		{
			g = pow(2,t);
			s1[m-g] = '1';
		}
		else
		{
			g = pow(2,t);
			s1[m-g] ='0';
		}
	}
	printf("data after performing operations : %s",s1);
	int *b;
	b=(int*)calloc(r,sizeof(int));
	for(i=0;i<r;i++)
	b[i]=a[i];
	printf("\ndo you want to corrupt the data : enter yes or no\n");
	char *s2;
	s2=(char*)calloc(3,sizeof(char));
	scanf("%s",s2);
	if(strcmp(s2,"yes")==0)
	{
		printf("\nenter the position of the bit to be corrupted : ");
		int pos;
		scanf("%d",&pos);
		printf("\n the initial bit is : %c",s1[pos-1]);
		scanf(" %c",&ch);
		s1[pos-1] = '0' + ch;
		t=pow(2,r-1);
		k=r-1;
		while(t > 0)
		{
			if(t & (pos))
			{
				g = s1[pos-1] - '0';
				if(g)
				a[k]++;
				else if(a[k])
				a[k]--;
			}
			t=t/2;
			k--;
		}
		
	int sum=0,p=0,temp;
	for(i=0;i<r;i++)
	a[i] = abs(a[i] - b[i]);
	p=0;
	for(i=0;i<r;i++)
	printf("%d ",a[i]);
	printf("\n");
	for(i=0,j=r-1;i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	printf("\n");
    for(i=0;i<r;i++)
	printf("%d ",a[i]);
	printf("\n");
	for(i=r-1;i>=0;i--,p++)
	{
		if(a[i] & 1)
		sum = sum + pow(2,p);
	}
	printf("corrupted bit is : %d",sum);
	}
	
}

