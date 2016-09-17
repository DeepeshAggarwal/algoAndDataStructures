#include<stdio.h>
main()
{
	int item;
	printf("enter the number of the items in the list");
	scanf("%d",&item);

	int list[item],i,temp,j,loc;
	printf("enter the list:\n");
	for(i=0;i<item;i++)
		scanf("%d",&list[i]);


	for(i=1;i<item;i++)
	{
		temp=list[i];
		loc=i-1;

		again:
		while(temp < list[loc] && loc>=0)
		{
			list[loc+1]=list[loc];
			list[loc]=temp;
			loc--;
			goto again;
		}
	}


	printf("the sorted list is");
	for(i=0;i<item;i++)
	{
		printf("%d\t",list[i]);
	}
	printf("\n");
}

