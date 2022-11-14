#include<stdio.h>
int tsp(int,int,int []);
int a[20][20],n,b[20],e[20],r[20];
void main()
{
	int i,j;
printf("enter the size of matrix :");
scanf("%d",&n);
printf("enter the elements of tree :");
for( i=1;i<=n;i++)
b[i]=i;
for(i=1;i<=n;i++)
{
printf("%d row : ",i);
for( j=1;j<=n;j++)
scanf("%d",&a[i][j]);
}
printf("the minimum cost of tree = %d\n",tsp(1,n,b));
}

int tsp(int p,int n,int s[])
{
	int i,j;
int c[20],k=1,l,min,t=2;
for( i=1;i<=n;i++){
if(s[i]!=p&&s[i]!=0)
c[k++]=s[i];
}
c[k]=0;
if(k==2)
min=a[p][c[1]]+a[c[1]][1];
else
{
min=100;
for(i=1;i<k;i++)
{
l=a[p][c[i]]+tsp(c[i],k,c);
if(min>l)
min=l;
}
}
return min;
} 
