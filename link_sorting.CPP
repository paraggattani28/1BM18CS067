#include<stdio.h>
#include<stdlib.h>

struct node

{
	int data;
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
	return NULL;
}

NODE insert_front(NODE head,int item)

{ NODE p;

	p=getnode();

	p->data=item;

	p->next=head;

	head=p;

	return head;

}


NODE insert_position(NODE head, int item)
{
	int i, pos;

	NODE temp, sec, secnext;
	temp = (NODE)malloc(sizeof(struct node));

	temp->data = item;
	printf("Enter the position at which you want to enter the item\n");
	scanf("%d", &pos);

	sec = head;
	secnext = head;
	for(i=0 ; i<(pos-2); i++)
	{
		sec = sec->next;
	}
	secnext = sec->next;
	sec->next = temp;
	temp->next = secnext;
	return head;
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

NODE sort(NODE head, int item)
{
	NODE p, temp, sec;
	
	p = (NODE)malloc(sizeof(struct node));
	
	p->data = item;
	p->next = NULL;
	temp = head;
	sec = NULL;
	if(head->next == NULL)
	{
		p->next = NULL;
		return p;
	}
	else
	{
		if(temp->next != NULL && temp->data > item)
		{
			p->next = temp;
			return p;
		}
		while(temp->next != NULL && temp->next->data < item)
		{
			temp = temp->next;
			sec = temp->next;
		}
			if(temp->next == NULL)
			{
				temp->next = p;
			}
			else
			{
				temp->next = p;
				p->next = sec;
			}
	}
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

	printf("%d->",p->data);

	p=p->next;

	}

}
int main()

	{ NODE head=NULL;

	int option,ele,value,pos;
	
	while(1)

	{ printf("\n1. INSERT FRONT\n2. INSERT END\n3. DISPLAY\n4. At Any position\n 5. SORT\n 6. EXIT\n");

	 printf("ENTER OPTION\n");

	scanf("%d",&option);

	switch(option)

	{ case 1:	printf("ENTER ELEMENT TO BE INSERTED\n");
		 		scanf("%d",&ele);
		 		head=insert_front(head,ele);
		 		break;

	  case 2:	printf("ENTER ELEMENT TO BE INSERTED\n");
		 		scanf("%d",&ele);
		 		head=insert_end(head,ele);
		 		break;

	  case 3:	printf("ELEMENTS IN THE LIST\n");
		 		display(head);
		 		printf("\n\n");
				break;

	  case 4 :  printf("Enter the Element to be entered : ");
		  		scanf("%d\n", &ele);
		  		insert_position(head, ele);
		  		break;
		  
	  case 5 :  printf("Enter the element you want to Insert : ");
				scanf("%d", &ele);
				head = sort(head, ele);
	  			break;
	  			
	  case 6 : exit(0);
	}

	}

	return 0;

}
