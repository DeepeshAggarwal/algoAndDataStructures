#include<stdio.h>
#include<string.h>

void heapify(int *num , int n ,int *d)
{
        int i,j,s,f;
        for(i=n-1;i>0;i--)
        {
                s=i;
                j=num[s];
                f=(s-1)/2;

                while(s>0 && d[num[f]]>d[j])
                {
                        num[s]=num[f];
                        s=f;
                        f=(s-1)/2;
                }
                num[s]=j;
        }
}
int deque(int *num , int *n , int *d)
{
        int k;
        k=num[0];
        num[0]=num[*n-1];
        (*n)--;
        heapify(num,*n,d);

        return k;
}
int main()
{
	int n,i,j,k,N,min;

	printf("enter the number of nodes in the graph :- ");
	scanf("%d",&n);
	N=n;

	int graph[n][n],d[n],pre[n],q[n];
	int source , destination;

	printf("enter the source and the destination vertex from 1 to %d : \n",n);
	scanf("%d%d",&source,&destination);

	source = source-1;
	destination=destination-1;

	printf("enter the adjacentry matrix of the graph : \n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
		d[i]=10000;						// the distace array between the source and the vertex
		if(i==source)
			d[i]=0;						// the distace between the source and source is 0

		pre[i]=-1;						// the array that idicates the previous of the vertex and initially is -1
		q[i]=i;							// queue cantaining all the vertex
	}
	while(N)
	{
		min=deque(q,&N,d);					// removing elements on the basis of the distance array "d[]"
		for(i=0;i<n;i++)
		{
			if(graph[min][i]!=0)				// this is the condition that there is edge from min to i or not
			{
				if(d[i]>(d[min]+graph[min][i]))
				{
					d[i]=(d[min]+graph[min][i]);
					pre[i]=min;
				}
			}
		}
		heapify(q,N,d);
	}
	printf("\ni\tdistance[i]\tprevious[i]\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t\t%d\n",i+1,d[i],pre[i]+1);
	}
	printf("\n");

	printf("therefore the path from source %d ----> destination %d is\n",source+1,destination+1);

	i=destination;
	printf("%d<--",destination+1);

	while(pre[i]!=source)
	{
		printf("%d<--",pre[i]+1);
		i=pre[i];
	}
	printf("%d\n",source+1);

	printf("\nsubmitted by:- \n1. Abhishek - 11533\n2. Prakash - 11538\n3. Deepesh - 11547\n4. Abhay - 11558\n5. Abhishek - 11559\n");
	return 0;
}

