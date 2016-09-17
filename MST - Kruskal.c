#include<stdio.h>
#include<stdlib.h>
struct Edge
{
	int src,dest,weight;
};

struct Graph
{
	int e,v;
	struct Edge *edge;
};

struct Subset
{
	int rank,parent;
};

struct Graph *createGraph(int vertices,int edges)
{
	struct Graph *graph=((struct Graph *)malloc(sizeof(struct Graph)));
	graph->e=edges;
	graph->v=vertices;
	graph->edge=(struct Edge *)malloc(graph->e*(sizeof(struct Edge)));
	return graph;
}

int find(struct Subset subsets[],int i)
{
	if(subsets[i].parent!=i)
	subsets[i].parent=find(subsets,subsets[i].parent);
	return subsets[i].parent;
}

void Union(struct Subset subsets[],int x,int y)
{
	int xset,yset;
	xset=find(subsets,x);
	yset=find(subsets,y);

	if(subsets[xset].rank>subsets[yset].rank)
		subsets[yset].parent=xset;

	else if(subsets[yset].rank>subsets[xset].rank)
		subsets[xset].parent=yset;
	else
	{
		subsets[yset].parent=xset;
		subsets[xset].rank++;
	}
}
int compute(const void *a,const void *b)
{
	struct Edge *a1=(struct Edge *)a;
	struct Edge *b1=(struct Edge *)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph *graph)
{
	int i=0,x,y,e=0,ver;
	int v=graph->v;
	struct Edge result[v];

	qsort(graph->edge,graph->e,sizeof(graph->edge[0]),compute);

	struct Subset *subsets=(struct Subset *)malloc(v*sizeof(struct Subset));
	for(ver=0;ver<v;ver++)
	{
		subsets[ver].parent=ver;
		subsets[ver].rank=0;
	}

	while(e<v-1)
	{

		struct Edge next_edge=graph->edge[i++];
		x=find(subsets,next_edge.src);
		y=find(subsets,next_edge.dest);

		if(x!=y)
		{
			result[e++]=next_edge;
			Union(subsets,x,y);
		}
	}

	printf("These are the edges in constructed MST\n");
	printf("Source\tDestination\tWeight\n");
	for(i=0;i<e;i++)
		printf("%d-------------%d     =     %d\n",result[i].src,result[i].dest,result[i].weight);

return;
}


int main()
{
	int edge,vertices,s,d,w,i;
        printf("Kruskal algorithm in Graph(Rank-Path Compression)\n");
        printf("Enter the number of vertices and edges : ");
        scanf("%d %d",&vertices,&edge);

        struct Graph *graph=createGraph(vertices,edge);

        printf("Enter source and destination of each edge one by one :-\n");
        printf("Source\tDestination\tWeight\n");
        for(i=0;i<edge;i++)
        {
                scanf("%d %d %d",&s,&d,&w);
                graph->edge[i].src=s;
                graph->edge[i].dest=d;
		graph->edge[i].weight=w;
        }

        KruskalMST(graph);

	printf("\nsubmitted by:- \n1. Abhishek - 11533\n2. Prakash - 11538\n3. Deepesh - 11547\n4. Abhay - 11558\n5. Abhishek - 11559\n");
        return 0;
}
