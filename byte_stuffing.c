#include<stdio.h>
#include<string.h>
main()
{
 char a[100],b[100],c[100];
 int i,j=0;
 printf("Enter data :\n");
 scanf(" %s",a);
 for(i=0;i<strlen(a);i++)
 {
 	if(a[i]=='$' || a[i]=='@')
 	{
 		b[j++]='@';
 	}
	b[j++]=a[i];
 }
 	b[j++]='\0';
	printf("after stuffing: ");
	printf("%s",b);
	j=0,c[0]='\0';
	for(i=0;i<(strlen(b));i++)
        {
                if(b[i]=='@')
                {
                
                    c[j++]=b[i+1];
                    i=i+1;
                }
                else
                c[j++]=b[i];

        }
                c[j]='\0';
        printf("The destuffed frame Is : \n");

                printf("%s ",c);
  }
