#include<stdio.h>
#include<conio.h>
#include<process.h>

int rear = 0 , front = 0, a[10];

void enqueue(int data)
{

	if(front  == ((rear+1)%10) && (rear!=-1) || front==0 && rear == 9)
	{

		printf("\n\n \t \"Overflow : Queue is FULL\" \n");
	}
       else
	{
		a[rear] = data;
		rear = (rear + 1)%10;

	}
}

void dequeue()
{
	if(front == rear)
	{
		front = 0;
		rear = 0;
		printf("\n\n \t \"Underflow : Queue is EMPTY \" \n");

	}
	else
	{
		front = (front+1)%10;
	}
}

void print()
{
	int i;
	printf("\n\nQ : ");
	for(i = front ; i != rear ; )
	{
		printf("%d\t", a[i]);
		i=(i+1)%10;
	}
}

int main()
{
	int i, choice, data;
	clrscr();
	for(;;)
	{
		printf("\n\nEnter the method you want to do\n");
		printf("Enter 1 to Enqueue\n");
		printf("Enter 2 to Dequeue\n");
		printf("Enter 3 to Print\n");
		printf("Enter 4 to Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : printf("Enter the value to be entered into the Queue\n");
				 scanf("%d", &data);
				 enqueue(data);
				 print();
				 break;
			case 2 : dequeue();
				 print();
				 break;
			case 3 : print();
				 break;
			case 4 : exit(0);
		}
	}
	return 0;
	getch();
}