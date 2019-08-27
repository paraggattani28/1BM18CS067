#include<stdio.h>
#include<conio.h>
#include<process.h>


void enque(int x, int *rear, int a[10])
{
	if(*rear == 29)
	{
		printf("Stack is FULL\n");
	}
	else
	{
		*rear+=1;
		a[*rear] = x;
	}
}
void deque(int *front, int *rear)
{
	if(*rear == (*front -1))
	{
		printf("Empty\n");
	}
	else if(*front == *rear)
	{
		*front = -1;
		*rear = -1;
	}
	else
	{
		*front+=1;
	}
}
void print(int front, int rear, int a[10])
{
	int i;
	for(i=front;i<=rear;i++)
	printf("%d\t",a[i]);
}
int main()
{
	int choice, value, i;
	int a[30], rear= -1, front=0;

	clrscr();
	for(;;)
	{
		printf("\n\nChoose your choice\n");
		printf("	Press 1 to Insert\n");
		printf("	Press 2 to Delete\n");
		printf("	Press 3 to Display\n");
		printf("	Press 4 to EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Enter the value to be inserted into the queue\n");
				 scanf("%d",&value);
				 enque(value, &rear, a);
				 print();
				 break;
			case 2 : deque(&front, &rear);
				 break;
			case 3 : print(front,rear,a);
				 break;
			case 4 : return 0;
				break;
		}
	}
	getch();
}