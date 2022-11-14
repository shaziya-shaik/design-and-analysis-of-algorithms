#include<stdio.h>
int k[50],f[50],c[50][50],m[50],s[50],sp[50][50],t[50],n,gap=0,v=0;
int w(int x,int y);
int min(int x[100],int y);
void split(int ,int,int);
void main()
{
	int i,j;
printf("Enter no-of objects:");
scanf("%d",&n);
printf("Enter list of keys:");
for(i=1;i<=n;i++)
scanf("%d",&k[i]);
for(i=1;i<=n;i++)
{
printf("Enter frequency of object %d:",k[i]);
scanf("%d",&f[i]);
}
while(gap<=n)
{
for(i=0;i<=n;i++)
{
if(gap==0)
{
c[i][i+gap]=0;
sp[i][i+gap]=0;
}
else
{
int wei=w(i+1,i+gap);
int x=0;
for(j=i+1;j<=i+gap;j++,x++)
{
m[x]=c[i][j-1]+c[j][i+gap]+wei;
s[x]=j;
}
int minm=min(m,gap);
sp[i][i+gap]=s[minm];
c[i][i+gap]=m[minm];
}
}
gap++;
}
printf("c=\n");
for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
printf("%d\t",c[i][j]);
printf("\n");
}
printf("sp=\n");
for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
printf("%d\t",sp[i][j]);
printf("\n");
}
split(0,n,1);printf("v=%d\n",v);
for(i=0;i<=v;i++)
printf("|%d|",t[i]);
printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int w(int x,int y)
{
int wei=0,i;
for(i=x;i<=y;i++)
wei=wei+f[i];
return wei;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int min(int x[100],int y)
{
int z=0,i;
for(i=0;i<y;i++)
{
if(x[z]>x[i])
z=i;
}
return z;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void split(int i,int j,int l)
{
++v;
if(i==j);
else
{
t[l]=sp[i][j];
t[2*l]=sp[i][t[l]-1];split(i,t[l]-1,2*l);
t[2*l+1]=sp[t[l]][j];split(t[l],j,2*l+1);
}
}
