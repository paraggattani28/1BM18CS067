#include<stdio.h>
#include<conio.h>
#include<string.h>

int top=-1;
char stack[30], exp[30], res[30];
void push(char data)
{
	stack[top] = data;
	top++;
}
void pop()
{
	top--;
}
int prec(char data)
{
	if(top == -1)
	{
		return 1;
	}
	else if(stack[top] == '+' && data == '*' || stack[top] == '+' && data == '/')
	{
		return 1;
	}
	else if(stack[top] == '+' && data == '+' || stack[top] == '+' && data == '-')
	{
		return 0;
	}
	else if(stack[top] == '-' && data == '*' || stack[top] == '-' && data == '/')
	{
		return 1;
	}
	else if(stack[top] == '-' && data == '+' || stack[top] == '-' && data == '-')
	{
		return 0;
	}
	else if(stack[top] == '*' && data == '*' || stack[top] == '*' && data == '/' || stack[top] == '*' && data == '+'|| stack[top] == '*'|| data == '-')
	{
		return 0;
	}
	else if(stack[top] == '/' && data == '*' || stack[top] == '/' && data == '/' || stack[top] == '/' && data == '+'|| stack[top] == '/'|| data == '-')
	{
		return 0;
	}
	return 0;
}




void pref()
{       int j=0,i;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]>='a' && exp[i]<='z'|| exp[i]>='A' && exp[i]<='Z')
		{
			res[j] = exp[i];
			j++;
		}
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if(prec(exp[i])==1)
			{
				push(exp[i]);
			}
			else
			{
				res[j] = stack[top];
				j++;
				pop();
				push(exp[i]);
			}
		}
		else if(exp[i] == '(')
			push(exp[i]);
		else if(exp[i] == '}')
		{
			while(stack[top] != '(')
			{
				res[j] = stack[top];
				j++;
				pop();
			}
			pop();
		}
	}
	res[j]='\0';
}

void main()
{
	printf("Enter the Expression to find the postfix\n ");
	scanf("%s", exp);
	pref();
	printf("%s\n",res);
	printf("%d\n",strlen(res));
	getch();

}


