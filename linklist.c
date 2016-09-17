#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct node *link;
}node;


void insert(struct Node *pointer,int data)
{
	while(pointer->link!=NULL)
	{
		pointer = pointer->link;
	}
	pointer->link=(node *)malloc(sizeof(node));
	pointer=pointer->link;
	pointer->info = data;
	pointer->link=NULL;
}

/* void del(struct Node *pointer,int data)
{
	node *loc;
	loc->link=pointer;
	while(pointer->link !=NULL && (pointer->info !=data)
	{
		loc->link=pointer;
		pointer=pointer->link;
	}
	if(pointer->link==NULL)
	{	printf("the list is not in the list\n");}

	else
	{
		node *temp;
		temp=pointer->link;
		pointer->link=temp->link;
		free(temp); 
	}
}*/

void find(struct Node *pointer,int data)
{
	pointer=pointer->link;
	while(pointer->link != NULL && pointer->info !=data)
	{
		pointer=pointer->link;
	}
	if(pointer->link==NULL)
	{
		printf("the element is not in the list");}

	else
		printf("the element is in the list");
}

void print(struct Node *pointer)
{

	if(pointer->link==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(pointer->link!=NULL)
		{
			pointer=pointer->link;
			printf("%d\n",pointer->info);

		}
	}
}


main()
{
	node *start,*temp;
	start=(node *)malloc(sizeof(node));
	temp=start;
	temp->link=NULL;

	int option=1,data;
	while(option)
	{
		printf("\n\n\nto insert:1\t to delete :2\t to find :3\t to print :4\t to exit : 5 \nenter the option : ");
		scanf("%d",&option);

		switch(option)
		{
			case 1: printf("enter the value of the data : ");
				scanf("%d",&data);
				insert(start,data);
				break;

			case 2: printf("enter the value of the element to be deleted");
				scanf("%d",&data);
//				del(start,data);
				break;

			case 3: printf("enter the element to be find\n");
				scanf("%d",&data);
				find(start,data);
				break;


			case 4 :printf("therefore the link list is:\n");
				print(start);
				break;

			case 5: printf("\n\nu have exit the programm\n\n");
				exit(1);

			default : printf("the programm is under construction and only 1 and 4 option is active\t sorry\n");
				  break;
		}
	}
}

