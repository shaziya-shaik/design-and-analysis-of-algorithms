#include<stdio.h>
#include<stdlib.h>
int sfind(int);
void wunion(int,int);
void sunion(int,int);
int cfind(int);
void print();
int a[20],p[20],in[20],n,k=0,m,m1;
void main()
{
	int i,j;
printf("enter the number of elelments :");
scanf("%d",&n);
printf("enter the elements :\n");
for( i=0;i<n;i++)
scanf("%d",&a[i]);
for( i=0;i<n;i++)
{
printf("enter the parent of %d :",a[i]);
scanf("%d",&p[a[i]]);
if(p[a[i]]==a[i])
{
p[a[i]]=-1;
in[k++]=i;
}
}
for(i=0;i<k;i++)
{
for( j=0;j<n;j++)
{
if(a[in[i]]!=a[j]&&a[in[i]]==sfind(a[j]))
p[a[in[i]]]=p[a[in[i]]]-1;
}
}
do
{
printf("========\n1.simple find\n2.simple union\n3.weighted union\n4.collapsing find\n5.printing of elements\n========\nenter the number to perform whatever operation u want :");
scanf("%d",&k);
switch(k)
{case 1://simple find
printf("enter the element to simple find its parent :");
scanf("%d",&m);
printf("the parent of %d is %d\n",m,sfind(m));
break;
case 2://simple union
printf("enter the elements to perform simple union :");
scanf("%d%d",&m,&m1);
sunion(m,m1);
break;
case 3://weighted union
printf("enter the elements to perform weighted union :");
scanf("%d%d",&m,&m1);
wunion(m,m1);
break;
case 4://collapsing find
printf("enter the element to collapsing find :");
scanf("%d",&m);
cfind(m);
break;
case 5://print
print();
break;
default:printf("no more operations\n");
printf("enter 0 to break :");
scanf("%d",&k);
}
}
while(k);
}
//@@@@@@@@@@@@@@@@@@@@
int sfind(int l)
{
if(p[l]<0)
return l;
else
sfind(p[l]);
}
//@@@@@@@@@@@@@@@@@@@@
void wunion(int u,int v)
{
int x=sfind(u),y=sfind(v);
if(p[x]>p[y])
{
int t=p[x];
p[x]=y;
p[y]=p[y]+t;
}
else
{
int t=p[y];
p[y]=x;p[x]=p[x]+t;
}
}
//@@@@@@@@@@@@@@@@@@@@
int cfind(int l)
{
int x=sfind(p[l]),y=l;
if(x!=p[l])
{
p[l]=x;
return sfind(y);
}
else
return sfind(x);
}
//@@@@@@@@@@@@@@@@@@@@
void sunion(int u,int v)
{
int x=sfind(u),y=sfind(v);
if(x!=y)
{
int t=p[x];
p[x]=y;
p[y]=p[y]+t;
}
}
//@@@@@@@@@@@@@@@@@@@@
void print()
{
	int i;
for(i=0;i<n;i++)
printf("element = %d\tparent = %d\n",a[i],p[a[i]]);
}
//@@@@@@@@@@@@@@@@
