#include<stdio.h>
struct node *
{
	int value;
	struct node *next;
	struct node *previous;
};
void insert(struct node *pointer);
{
	int data;

	printf("\nplease enter the value of the node  : ");
	scanf("%d",&data);

	if(pointer==NULL)
	{
		pointer=(struct node *)malloc(sizeof(struct node));
		pointer->next=NULL:
		pointer->previous=NULL;
		poitner->value=data;

		return;
	}
	while(pointer->next!=NULL && pointer->value < data)
		pointer=pointer->next;

	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->value=data;

	if(pointer->value < data)
	{
		temp->next=pointer;
		temp->previous=pointer->previous;
		pointer->previous=temp;
		pointer=temp->previous;
		pointer->next=temp;
	}
	else
	{
		pointer->next=temp;
		temp->next=NULL;
		temp->previous=pointer;
	}

	return;

}
void del(struct node *pointer)
{
	int data;

	printf("\nplease enter the value of the node  : ");
	scanf("%d",&data);



	while(pointer->value!=data && pointer !=NULL)
		pointer=pointer->next;

	if(pointer==NULL)
	{
		printf("there is No element found\n");
		return;
	}

	struct node *temp;
	temp=pointer;

	pointer=pointer->previous;
	pointer->next=temp->next;

	if(temp->next!=NULL)
	{
		pointer=temp->next;
		pointer->previous=temp->previous;
	}

	return;
}
void display_forward(struct node *pointer)
{
}
int main()
{
	struct node *start;

	printf("to insert the element in the list : 1\nto delete the element in the list : 2\nto display the list in fornward order : 3\n");
	printf("to display the list in the backward order : 4\nto exit : 5\n\n\nplease enter the choice : ");

	int choice=0;

	scanf("%d",&choice);

	while(choice)
	{
		switch(choice)
		{
			case 1 : insert(start);
				 break;

			case 2 : del(start);
				 break;

			case 3 : display_forward(start);
				 break;

			case 4 : display_backward(start);
				 break;

			case 5 : insert(start);
				 break;

			default : printf("u have entered the wrong choice please enter again\n");
		}


		printf("%c[2j",27);
		printf("to insert the element in the list : 1\nto delete the element in the list : 2\nto display the list in fornward order");
		printf(" : 3\nto display the list in the backward order : 4\nto exit : 5\n\n\nplease enter the choice : ");

		scanf("%d",&choice);
	}
	printf("%c[2j",27);
	printf("\nu exit the program\n");

	return 0;
}
