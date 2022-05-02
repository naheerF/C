#include<stdio.h>
#include<string.h>
main()
{
	int i,j,n,k;
	char str[100];
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
	{
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j]){
				for(k=j;str[k]!='\0';k++){
					str[k]=str[k+1];
				}
			}
		}
	}
	printf("%s",str);
}

