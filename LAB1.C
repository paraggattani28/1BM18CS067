#include<stdio.h>
#include<conio.h>
#include<process.h>

int a[10],i,top=-1;

void push(int value)  //PUSH FUNCTION
{
	if(top==10)
	printf("Error : Stack is already full\n"); //ERROR SHOWING STACK IS ALREADY FULL
	else
	top++;
	a[top]=value;
}
void pop()  //POP FUNCTION
{
	if(top==-1)
	printf("Error : Stack is already empty\n"); //ERROR SHOWING STACK IS EMPTY
	else
	top--;
}
void print()
{
	printf("\nCurrent Stack is : \t"); //To DISPLAY Stack
	for(i=top;i>=0;i--)
	{
		printf("%d\t",a[i]);
	}
	printf("\n\n\n");
}
void main()
{
int i,choice,data,n;

clrscr();
printf("Program 1 by PARAG GATTANI, USN : 1BM18CS067");  //MADE BY
for(i=0;;i++)  // LOOP to  ask the choices what user wants to continuously.
{
printf("\nPress 1 to Enter the value into the Stack\n"); //Choices
printf("Press 2 to delete the last value\n");
printf("Press 3 to Print the stack\n");
printf("Press 4 to EXIT\n");
scanf("%d",&choice);
switch(choice)   //Switch case to ask for the choice what user wants to do.
	{
		case 1 : printf("\nEnter the value to be entered into the Stack : ");
			 scanf("%d",&data);
			 push(data);
			 print();
			 break;
		case 2 : pop();
			 print();
			 break;
		case 3 : print();
			 break;
		case 4 : exit(0);
			 break;
	}
}
getch();
}