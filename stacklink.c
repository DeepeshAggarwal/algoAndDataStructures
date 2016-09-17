#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int value;
	struct node *link; 
}node;

void push(struct Node * pointer,int data)
{
	if(pointer->link==NULL)
	{
		pointer->link=(struct Node *)malloc(sizeof(node));
		pointer=pointer->link;
		pointer->value=data;
		pointer->link=NULL;
	}
	else
	{
		struct Node *temp;
		temp->link=pointer->link;
		pointer->link=(node *)malloc(sizeof(node));
		pointer=pointer->link;
		pointer->value=data;
		pointer->link=temp->link;
	}
}

void pop(struct Node * pointer)
{
	if(pointer->link==NULL)
	{
		printf("the list is empty\n");
		return;
	}
	struct Node *temp;
	temp=pointer;
	temp=temp->link;
	pointer->link=temp->link;
}

void print(struct Node * pointer)
{
	if(pointer->link==NULL)
	{
		printf("the list is empty");
		return;
	}
	while(pointer->link!=NULL)
	{
		pointer=pointer->link;
		printf("%d\n",pointer->value);
	}
}

main()
{
	int option=1,data;
	struct Node *top;
	top =(node *)malloc(sizeof(node));
	top->link=NULL;
	while(option)
	{
		printf("\nto push : 1\tto pop : 2\tto print : 3\tto exit : 0\nenter the value : ");
		scanf("%d",&option);
		if(option==1)
		{
			printf("enter the value of the element of the data to be pushed\n");
			scanf("%d",&data);
			push(top,data);
		}
		if(option==2)
		{
			pop(top);
			printf("the pop operation is successful");
		}
		if(option==3)
		{
			printf("the stack is as follow\n");
			print(top);
		}
	}
}


