#include<stdio.h>
#include<string.h>
 main() {
	int i,j,divlen,msglen,c;
	char msg[100],div[100],temp[100],quot[100],rem[100],div1[100],msg1[100];
	printf("Enter Data: ");
	scanf("%s",msg);
	printf("Enter Key: ");
	scanf("%s",div);
	divlen=strlen(div);
	msglen=strlen(msg);
	strcpy(msg1,msg);
	strcpy(div1,div);
	for (i=msglen;i<msglen+divlen-1;i++) {
		msg[i]='0';
	}
	for (i=0;i<divlen;i++)
	 temp[i]=msg[i];
	for (i=0;i<msglen;i++) 
	 {
		quot[i]=temp[0];
		if(quot[i]=='0')
		 {
		 for (j=0;j<divlen;j++)
		 div[j]='0';
		 }
		 else
		 {
		 for (j=0;j<divlen;j++)
		 div[j]=div1[j];
	     }
		for (j=divlen-1;j>0;j--) {
			if(temp[j]==div[j])
			 rem[j-1]='0'; 
			 else
			 rem[j-1]='1';
		}
		rem[divlen-1]=msg[i+divlen];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	printf("\nSENDER SIDE");
	printf("\nRemainder is ");
	for (i=0;i<divlen-1;i++)
	 printf("%c",rem[i]);
	printf("\nFinal data is: ");
	for (i=0;i<msglen;i++)
	 printf("%c",msg[i]);
	for (i=0;i<divlen-1;i++)
	 printf("%c",rem[i]); 
	for(i=msglen;i<msglen+divlen-1;i++) {
	 msg1[i]=rem[i-msglen];
	}
	for (i=0;i<divlen;i++)
	 temp[i]=msg1[i];
	for (i=0;i<msglen;i++) 
	 {
		quot[i]=temp[0];
		if(quot[i]=='0')
		 {
		 for (j=0;j<divlen;j++)
		 div[j]='0';
		 }
		 else
		 {
		 for (j=0;j<divlen;j++)
		 div[j]=div1[j];
	     }
		for (j=divlen-1;j>0;j--) {
			if(temp[j]==div[j])
			 rem[j-1]='0'; 
			 else
			 rem[j-1]='1';
		}
		rem[divlen-1]=msg1[i+divlen];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	printf("\n RECEIVER SIDE ");
	printf("\nRemainder is ");
	for (i=0;i<divlen-1;i++)
	 printf("%c",rem[i]);
	c=0;
	for (i=0;i<divlen-1;i++){
	 if(rem[i]=='1'){
	 	c++;
	 }
	}
	if(c==0){
		printf("\ndata accepted");
	}
	else
	{
		printf("\ndata not accepted");
	}	
}
