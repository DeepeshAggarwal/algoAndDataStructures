#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};

void create_queue(struct node *front , struct node *rear)
{
	while(front->next!=NULL)
		front=front->next;

	front->next=(struct node *)malloc(sizeof(struct node));

	front=front->next;
	front->next=NULL;
	rear->next=front;


	printf("enter the value of the item : ");
	scanf("%d",&front->value);


	return;
}
void display_queue(struct node *front , struct node *rear)
{
	if(front->next==NULL)
	{
		printf("there is no element in the queue \n");
		return;
	}
	while(front!=rear->next)
	{
		front=front->next;
		printf("%d-->",front->value);
	}
	printf("\n");

	return;
}
void delete_queue(struct node *front , struct node *rear)
{
	if(front->next==NULL)
	{
		printf("the queue is empty\n");
		return;
	}
	else if(front->next==rear->next)
	{
		front->next=NULL;
		rear->next=NULL;
		return;
	}

	rear=front->next;
	front->next=(front->next)->next;
	return;
}
void number_of_elements(struct node *front , struct node *rear)
{
	int n=0;
	front=front->next;
	while(front!=NULL)
	{
		n++;
		front=front->next;
	}
	printf("the number of elements in the queue are  : %d\n",n);
	return;

}

int main()
{
	int choice=1;
	struct node *front , *rear;
	front=(struct node *)malloc(sizeof(struct node));
	front->next=NULL;
	rear=(struct node *)malloc(sizeof(struct node));
	rear->next=NULL;

	while(choice)
	{
		scanf("%d",&choice);

		switch(choice)
		{
			case 0 : exit(0);

			case 1 : create_queue(front , rear);
				 break;

			case 2 : display_queue(front , rear);
				 break;

			case 3 : delete_queue(front , rear);
				 break;

			case 4 : number_of_elements(front , rear);
				 break;

			default : printf("wrong value inserted.please enter again");
		}
	}
	return 0;
}
