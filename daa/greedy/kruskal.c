#include<stdio.h>
#define max 20
#define infinity 999
int G[max][max],spanning[max][max],n;
int kruskal();
void main()
{
	int total_cost=0,i,j;
	printf("enter no of vertices:");
	scanf("%d",&n);
	printf("enter adjecency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
	scanf("%d",&G[i][j]);
		}
	}
	total_cost=kruskal();
	printf("spanning tree is:\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",spanning[i][j]);
		}
	}
	printf("total_cost=%d\n",total_cost);
}
int kruskal()
{
	int cost[max][max],visited[max],min_distance,no_of_edges,min_cost,u,v,a,b,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
			{
				cost[i][j]=infinity;
			}
			else
			{
				cost[i][j]=G[i][j];
			}
			spanning[i][j]=0;
		}
		visited[i]=0;
	}
	no_of_edges=n-1;
	min_cost=0;
	while(no_of_edges>0)
	{
		min_distance=infinity;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j]<min_distance)
				{
					min_distance=cost[i][j];
					u=a=i;
					v=b=j;
				}
			}
		}
		spanning[u][v]=cost[u][v];
		spanning[v][u]=cost[u][v];
		while(visited[u]!=0)
		{
			u=visited[u];
		}
		while(visited[v]!=0)
		{
			v=visited[v];
		}
		if(u!=v)
		{
			no_of_edges--;
			min_cost=min_cost+min_distance;
			visited[v]=u;
			cost[a][b]=cost[b][a]=infinity;
		}
	printf("\nEdge ( %c , %c ) --> %d\n",u+65,v+65,min_distance);
	}
	return(min_cost);
}
