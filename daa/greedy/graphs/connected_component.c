
#include<stdio.h>
void adj(int);
void dfs(int);
int stack[100],topl[100],a[100][100],b[100],flag[100],n,top=-1,t=-1,count;
void main()
{
	int i,j;
printf("enter no of vertices:");
scanf("%d",&n);
printf("enter values of vertices\n");
for(i=0;i<n;i++)
{
printf("enter value:");
scanf("%d",&b[i]);
flag[i]=-1;
}
printf("enter matrix values\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("a[%d][%d]",i,j);
scanf("%d",&a[i][j]);
}
}
printf("matrix is\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
count=0;
t=-1;
for(i=0;i<n;i++)
{
if(flag[i]==-1)
{
top=-1;
stack[++top]=i;
flag[i]=1;
dfs(i);
count++;
}
}
printf("count is %d\n",count);
}
void dfs(int v)
{
if(top==-1)
return;
if(flag[v]==-1)
{
stack[++top]=v;
flag[v]=1;
}
adj(stack[top]);
}
void adj(int m)
{
	int j;
int k=0;
for(j=0;j<n;j++)
{
if(a[m][j]==1&&flag[j]==-1)
{
k=1;
dfs(j);
}
}
if(k==0)
{
topl[++t]=b[stack[top]];
dfs(stack[--top]);
}
}

