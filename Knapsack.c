#include<stdio.h>
#define max(a,b) a>b?a:b

void swap_float(float a,float b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

void swap(int *a,int *b)
{
        *a=*a^*b,*b=*a^*b,*a=*a^*b;
}

void quick_sort(float arr[],int arr1[],int arr2[],int low,int high)
{
        if(low>=high)
                return;
        float pivot=arr[low];
        float pivot1=arr1[low];
        float pivot2=arr2[low];
        int i=low,j=high;
        while(i<j)
        {
                while(arr[j]>pivot)
                        j--;
                while(arr[i]<=pivot)
                        i++;
                if(i<j)
		{
                        swap_float(arr[i],arr[j]);
                        swap(&arr1[i],&arr1[j]);
                        swap(&arr2[i],&arr2[j]);
		}
			
        }
        arr[low]=arr[j];
        arr[j]=pivot;
        arr1[low]=arr1[j];
        arr1[j]=pivot1;
        arr2[low]=arr2[j];
        arr2[j]=pivot2;
        quick_sort(arr,arr1,arr2,low,j-1);
        quick_sort(arr,arr1,arr2,j+1,high);
}

int main()
{
	int weight,num_constraints;

	printf("Enter the number of constraints :");
	scanf("%d",&num_constraints);

	printf("Enter the maximum weight possible :");
	scanf("%d",&weight);

	int wt[num_constraints],price[num_constraints],i,j;
	float profit=0;
	float price_per_unit[num_constraints];

	printf("Enter the constraints :\n");
	printf("Weight\tPrice\n");

	for(i=0;i<num_constraints;i++)
	{
		scanf("%d%d",&wt[i],&price[i]);
		price_per_unit[i]=(float)price[i]/(float)wt[i];
	}

	quick_sort(price_per_unit,price,wt,0,num_constraints-1);

	i=num_constraints-1;
	while(weight>0)
	{
		if(weight>wt[i])
		{
			profit+=price[i];
			weight-=wt[i];
		}
		else
		{
			profit+=(float)price[i]*weight/(float)wt[i];
			weight=0;
		}
		i--;
	}
	
	printf("\nMaximum Price = %f\n",profit);
	printf("\nsubmitted by:- \n1. Abhishek - 11533\n2. Prakash - 11538\n3. Deepesh - 11547\n4. Abhay - 11558\n5. Abhishek - 11559\n");
	return 0;
}
