/* 
This dfs programme is for n given vertices 0 to n, you have to fill the given matrix graph by considering 1 in a particular index [i][j] if there is a edge in the gaph from i to j otherwise 0.
I assume 0 for white vertices and 1 for grey. 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void dfs(int *,int [],int,int);

int main()
{
	int i,j,k,ver;
	printf("enter the number of graph vertices\n");
	scanf("%d",&ver);
	int *graph,color[ver];
	graph=(int *)malloc(sizeof(int)*ver*ver);
	bzero(color,ver*sizeof(int));
	for(i=0;i<ver;i++)
		for(j=0;j<ver;j++)
			scanf("%d",&graph[i*ver+j]);

	printf("vertices are traversed in the dfs order given below\n");
	for(i=0;i<ver;i++)
		if(color[i]==0)
			dfs(graph,color,ver,i);

	printf("\nsubmitted by:- \n1. Abhishek - 11533\n2. Prakash - 11538\n3. Deepesh - 11547\n4. Abhay - 11558\n5. Abhishek - 11559\n");
}

void dfs(int *graph,int color[],int ver,int l)
{
	int f;
	color[l]=1;
	for(f=0;f<ver;f++)
	{
		if(graph[l*ver+f]==1 && color[f]==0)
			dfs(graph,color,ver,f);
	}
	printf("%d\n",l);
}
