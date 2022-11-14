#include<stdio.h>
#define maxx 20
int max(int a,int b);
int m,n,w[maxx],p[maxx],a[maxx][maxx],weight[maxx],profit[maxx];
void set(int m,int n,int w[maxx],int p[maxx],int a[maxx][maxx]);
void knap_sack(int m,int n,int w[maxx],int p[maxx],int a[maxx][maxx]);
void main()
{
	int i,j,total=0,k;
	printf("enter total mass:");
	scanf("%d",&m);
	printf("enter no of weight:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter %d weight:",i+1);
		scanf("%d",&w[i]);
		printf("enter %d profit:",i+1);
		scanf("%d",&p[i]);
	}
	for( k=0;k<n;k++)
		{
		weight[k]=w[k];
		profit[k]=p[k];
		}
	knap_sack(m,n,w,p,a);
	set(m,n,w,p,a);
}
void knap_sack(int m,int n,int w[maxx],int p[maxx],int a[maxx][maxx])
{
	int i,j,val=0,s,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(w[i]>w[j])
			{
				t=w[i];
				w[i]=w[j];
				w[j]=t;
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
	printf("\n weight\tprofit\n");
	for(i=0;i<n;i++)
	{
		printf("%d",w[i]);
		printf("\t%d",p[i]);
		printf("\n");
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			a[i][j]=0;	
		}
	}
	for(i=1,s=0;i<n+1,s<n;i++,s++)
	{
		for(j=1;j<m+1;j++)
		{
			if(j<i)
			{
				a[i][j]=a[i-1][j];
			}
			else
			{
			val=max(a[i-1][j],p[s]+a[i-1][j-w[s]]);
			a[i][j]=val;
			}
		}	
	}
	printf("\nmatrix of knap_sack:\n");
	for(i=0;i<n+1;i++)
	{
		printf("\n");
		for(j=0;j<m+1;j++)
		{
			printf("%d\t",a[i][j]);
			val=a[i][j];
		}
	}
	printf("\ntotal_knap_sack%d",val);
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
void set(int m,int n,int w[maxx],int p[maxx],int a[maxx][maxx])
{
	int i,j,solset[n],k,l,c;
	for(l=0;l<n;l++)
		{
		solset[l]=0;
		}
	 i=n;
	 j=m;
	 while(i>0&&j>0)
	 {
	 	if(a[i][j]==a[i-1][j])
	 	{
	 		i--;
		 }
		 else
		 {
		 	i--;
			for( c=0;c<n;c++)
				{
				if(weight[c]==w[i]&&profit[c]==p[i])
						{
						solset[c]=1;
						break;
						}
				}
		 	j=j-w[i];
		 }
	 }
	printf("solution set\n");
	for(k=0;k<n;k++)
		{
		printf("%d,",solset[k]);
		}
}
