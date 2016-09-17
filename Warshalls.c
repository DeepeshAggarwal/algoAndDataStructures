#include <stdio.h>

#define INF 9999

int main( )
{
    int v;
    printf("enter the number of vertex\n");
    scanf("%d",&v);
	int arr[v][v];
	int cost[v][v]; 
	int i, j, k;
	
	for ( i = 0 ; i < v; i++ )
	{
		for ( j = 0; j < v; j++ )
		{ 
            		printf("src=%d\tdes=%d\tcost=",i,j);  
            		scanf("%d",&cost[i][j]);
		            printf("\n");
		}
	}
	for ( i = 0 ; i < v; i++ )
	{
		for ( j = 0; j < v ; j++ )
		{
			if ( cost[i][j] == 0 )
				arr[i][j] = INF ;
			else
				arr[i][j] = cost[i][j] ;
				
		}
	}

	printf ( "Adjacency matrix of cost of edges:\n" ) ;
	for ( i = 0 ; i < v; i++ )
	{
		for ( j = 0; j < v; j++ )
		{
			printf("src=%d\tdes=%d\tcost=",i,j);  
			printf ( "%d\t", arr[i][j] ) ;
	                printf ( "\n" ) ;
           	}
	}
	for ( k = 0 ; k < v; k++ )
	{
		for ( i = 0 ; i < v ; i++ )
		{
			for ( j = 0 ; j < v ; j++ )
			{
				if ( arr[i][j] > arr[i][k] + arr[k][j] )
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	printf ( "\nAdjacency matrix of lowest cost between the vertices:\n" ) ;
	for ( i = 0 ; i < v; i++ )
	{
		for ( j = 0; j < v ; j++ )
			printf ( "%d\t", arr[i][j] ) ;

		printf ( "\n" ) ;
	}

	printf("\nsubmitted by:- \n1. Abhishek - 11533\n2. Prakash - 11538\n3. Deepesh - 11547\n4. Abhay - 11558\n5. Abhishek - 11559\n");
	return 0;
}
