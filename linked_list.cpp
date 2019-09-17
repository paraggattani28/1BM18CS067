#include<stdio.h>

#include<stdlib.h>

struct node

{ int data;

struct node *next;

};

typedef struct node *NODE;



NODE getnode()

{	 NODE p;	

	 p=(NODE)malloc(sizeof(struct node));

	 if(p!=NULL)

		return p;

	 else 

	{ printf("NO MEMORY ALLOCATION\n");

		exit(0);

	}

}

NODE insert_front(NODE head,int item)

{ NODE p;

	p=getnode();

	p->data=item;

	p->next=head;

	head=p;

	return head;

}

void display(NODE head)

{ 	NODE p;

	if(head==NULL)

	{	 printf("LIST IS EMPTY\n");

		

	}

	p=head;

	while(p!=NULL) 

	{

	printf("%d\t",p->data);

	p=p->next;

	}

}

NODE insert_end(NODE head,int item)

{ 	NODE p,q;

	q=getnode();

	q->data=item;

	q->next=NULL;

	if(head==NULL)

	{ return q;

	}

	p=head;

	while(p->next!=NULL)

	p=p->next;

	p->next=q;

	return head;

}

int main()

	{ NODE head=NULL;

	int option,ele,value,pos;

	while(1)

	{ printf("\n1.INSERT FRONT\n2.INSERT END\n3.DISPLAY\n4.EXIT\n");

	 printf("ENTER OPTION\n");

	scanf("%d",&option);

	switch(option)

	{ case 1:printf("ENTER ELEMENT TO BE INSERTED\n");

		 scanf("%d",&ele);

		 head=insert_front(head,ele);

		 break;

	  case 2:printf("ENTER ELEMENT TO BE INSERTED\n");

		 scanf("%d",&ele);

		 head=insert_end(head,ele);

		 break;

	  case 3:printf("ELEMENTS IN THE LIST\n");

		 display(head);

	         break;

	  case 4:exit(0);

	}

	}

	return 0;

	}
