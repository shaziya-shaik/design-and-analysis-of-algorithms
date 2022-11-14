#include<stdio.h>
int n;
int check(int slot[],int p);
void main()
{
	printf("enter no of job sequences:");
	scanf("%d",&n);
	int p[n],d[n],slot[n],i,j;
	for(i=0;i<n;i++)
	{
		printf("\nenter profit of j %d:\n",i+1);
		scanf("%d",&p[i]);
		printf("\nenter deadline of j %d:\n",i+1);
		scanf("%d",&d[i]);
	}
	int t=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i]<p[j])
			{
			t=p[i];
			p[i]=p[j];
			p[j]=t;
			t=d[i];
			d[i]=d[j];
			d[j]=t;	
			}
		}
	}
	printf("after decending order:\n");
	printf("index profit\tdeadline:\n");
	for(i=0;i<n;i++)
	{
		printf("j %d:",i+1);
		printf("\t%d",p[i]);
		printf("\t\t%d\n",d[i]);
	}
	for(i=0;i<n;i++)
	{
		slot[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=d[i];j>0;j--)
		{
			if(check(slot,j)==1)
			{
				slot[i]=j;
				break;
				}	
		}
	}
	int sum=0;
	printf("\nindex	profit\tdeadline\tallocated:\n");
	for(i=0;i<n;i++)
	{
		if(slot[i]>0)
		{
		printf("\nj %d	%d\t%d\t(%d- %d)",i+1,p[i],d[i],slot[i-1],slot[i]);
		sum=sum+p[i];	
		}
		else
		{
			printf("\nj %d	%d\t%d\tREJETED",i+1,p[i],d[i]);
		}
	}
	printf("\n total=%d",sum);
}
int check(int slot[],int p)
{
	int i;
	int ptr=0;
	for(i=0;i<n;i++)
	{
		if(slot[i]==p)
		{
			ptr++;
		}
	}
	if(ptr==0)
	return 1;
	else
	return 0;
}
