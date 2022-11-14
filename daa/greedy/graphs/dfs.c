#include <stdio.h>
#include <stdlib.h>
int source,V,time,visited[20],G[20][20];
void DFS(int i);
void main()
{
    int i,j,v1,v2;
   	printf("\t\t\tGraphs\n");
    printf("Enter the no of vertices:");
    scanf("%d",&V);
    printf("Enter the adjacency matrix:");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            scanf("%d",&G[i][j]);
    }
    for(i=0;i<V;i++)
    {
    	visited[i]=0;
	}

    for(i=0;i<V;i++)//print adjecency matrix
    {
        for(j=0;j<V;j++)
            printf(" %d ",G[i][j]);
        printf("\n");
    }
    printf("Enter the source: ");
    scanf("%d",&source);
        DFS(source);
}
void DFS(int i)
{
    int j;
    visited[i]=1;
    printf(" %c\t",i+65);
    for(j=0;j<V;j++)
    {
        if(G[i][j]==1&&visited[j]==0)
            DFS(j);
    }
}
