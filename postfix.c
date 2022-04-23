#include<stdio.h>
#include<ctype.h>
#define size 50
char s[size];
int top=-1;


push(char elem)
{
	s[++top]=elem;
}
char pop()
{
	return(s[top--]);
}
int pr(char elem)
{
	switch(elem)
	  {
	  	 case '#':return 0;
	  	 case '(':
	    case ')':
	    	   return 1;
	    case '+':
	    case '-':
	    	 return 2;
	    case '*':
	    case '/':
	    	return 3;
	  }
}
main()
{
	char infix[100],postfix[100],ch,elem;
	int i=0,k=0;
	printf("read the infix expression");
	scanf("%s",infix);
	push('#');
	while((ch=infix[i++])!='\0')
	{
		if(ch=='(')
		  push(ch);
		else if(isalnum(ch))
		postfix[k++]=ch;
		else if(ch==')')
		{
			while(s[top]!='(')
			
			postfix[k++]=pop();
			elem=pop();
		    
		}
		else
		{
			while(pr(s[top])>=pr(ch))
			
			postfix[k++]=pop();
			push(ch);
		    
			
		}
	}
	while(s[top]!='#')
		postfix[k++]=pop();
	postfix[k]='\0';
	printf("the expression of postfix is %s",postfix);
	    
}
