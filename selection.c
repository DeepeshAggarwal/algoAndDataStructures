#include<stdio.h>
main()
{
	int list;


	printf("enter the number in the list");
	scanf("%d",&list);

	int data[list],i,j,min;


	for(i=0;i<list;i++)
		scanf("%d",&data[i]);


	for(i=0;i<list;i++)
	{
		min=data[i];
		for(j=i;j<list;j++)
		{
			if(min > data[j])
			{
				min=data[j];
				data[j]=data[i];
				data[i]=min;
			}
		}
	}


	printf("the list is\n");

	for(i=0;i<list;i++)
		printf("%d\t",data[i]);

	printf("\n\n\n");
}
