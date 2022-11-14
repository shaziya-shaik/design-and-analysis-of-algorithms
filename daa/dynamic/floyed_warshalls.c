#include<stdio.h>
#define max 200
int n,G[max][max];
void floyds(int G[max][max],int n);
int min(int a,int b);
void main()
{
	int u,v,i,j,w,e;
	printf("enter no of vertices:\n");
	scanf("%d",&n);
	printf("enter no of edges:\n");
	scanf("%d",&e);
	for (i=1;i<=n;i++)
	 {
		for (j=1;j<=n;j++)
		{
		   G[i][j]=999;
		}
	}
	for(i=1;i<=e;i++)
	{
		printf("enter directed graph of %d edge:\n",i);
			scanf("%d%d%d",&u,&v,&w);
				G[u][v]=w;
	}
		printf("\n Matrix of input data:\n");
	for (i=1;i<=n;i++)
	 {
	 			printf("\n");
		for (j=1;j<=n;j++)
		{
		   printf("%d \t",G[i][j]);
		}
	}
	floyds(G,n);
	printf("\n Transitive closure:\n");
	for (i=1;i<=n;i++) 
	{
					printf("\n");
		for (j=1;j<=n;j++)
		{
		   printf("%d \t",G[i][j]);
		}
	}
	printf("\n The shortest paths are:\n");
	for (i=1;i<=n;i++)
	{
	  for (j=1;j<=n;j++) 
	  {
			if(i!=j)
		    printf("\n <%d,%d>=%d",i,j,G[i][j]);
		}
	}
}
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
void floyds(int G[max][max],int n)
{
	int i,j,k,no_of_edges=0;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					G[i][j]=0;
				}
				else
				{
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				}
			}
				
		}
	}
		printf("matrix for %d verix:\n",k);
		for(i=1;i<=n;i++)
		{
		printf("\n");
		for(j=1;j<=n;j++)
		{
			printf("%d",G[i][j]);
		}
	}
}
