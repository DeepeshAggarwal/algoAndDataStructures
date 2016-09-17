#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};


void insert(struct Node *pointer,int data)
{
    while(pointer->link!=NULL)
    {
        pointer = pointer->link;
    }
    pointer->link=(struct Node *)malloc(sizeof(struct Node));
    pointer=pointer->link;
    pointer->info = data;
    pointer->link=NULL;
}

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

void reverse(struct Node *head) {

    if (head->link == NULL)
        return ;    
    struct Node *current = head->link;
    struct Node *previous = NULL;
    struct Node *next;
    while(current !=NULL) {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head->link = previous;
}

struct Node * reverseInBatch(struct Node *head, int batch) {
    if (head == NULL)
        return ;    
    struct Node *current = head, *previous = NULL, *next;
    int counter = 0;
    while(counter < batch && current != NULL) {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
        counter++;
    }
    if (next != NULL)
        head->link = reverseInBatch(current, batch);
    
    return previous;
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
    /*Pointer of type struct Node */
    struct Node *start;
    /*Variable of Type struct Node */
    struct Node temp;

    temp.info = 5;
    printf("%d\n", temp.info);
    start=(struct Node *)malloc(sizeof(struct Node));
    start->link=NULL;

    int option,data;
    while(1)
    {
        printf("\nto insert:1\t to delete :2\t to find :3\t to print :4\treverse : 5\t to exit : 6 \tReverse In Batch : 7\nenter the option : ");
        scanf("%d",&option);

        switch(option)
        {
            case 1: printf("enter the value of the data : ");
                scanf("%d",&data);
                insert(start,data);
                break;

            case 2: printf("enter the value of the element to be deleted");
                scanf("%d",&data);
//              del(start,data);
                break;

            case 3: printf("enter the element to be find\n");
                scanf("%d",&data);
                find(start,data);
                break;


            case 4 :printf("therefore the link list is:\n");
                print(start);
                break;

            case 5 :reverse(start);
                printf("List Is reversed:\n");
                break;

            case 7 :start->link = reverseInBatch(start->link, 3);
                printf("List Is reversed in batch:\n");
                break;

            case 6: printf("\nyou have exit the programm\n");
                exit(1);

            default : printf("the programm is under construction and only 1 and 4 option is active\t sorry\n");
                  break;
        }
    }
}

