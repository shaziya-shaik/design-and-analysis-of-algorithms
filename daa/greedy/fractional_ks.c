#include<stdio.h>
void main()
{
int n,weight,temp,j;
printf("enter number:");scanf("%d",&n);
printf("enter total weight of bag:");
scanf("%d",&weight);
int item[n],p[n],w[n],i,item_sol[n],count=1,sum=0;
float ratio[n];
for(i=1;i<=n;i++)
{
printf("enter items:");
scanf("%d",&item[i]);
}
for(i=1;i<=n;i++)
{
printf("enter profit:");
scanf("%d",&p[i]);
}
for(i=1;i<=n;i++)
{
printf("enter weight:");
scanf("%d",&w[i]);
}
for(i=1;i<=n;i++)
{
ratio[i]=p[i]/(float)w[i];
}
printf("items\tprofit\tweight\tratio:\n");
for(i=1;i<=n;i++)
{
printf("%d\t%d\t%d\t%f\n",item[i],p[i],w[i],ratio[i]);
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n-i;j++)
{
if(ratio[j]<ratio[j+1])
{
temp=ratio[j];
ratio[j]=ratio[j+1];
ratio[j+1]=temp;
temp=item[j];
item[j]=item[j+1];
item[j+1]=temp;
}
}
}
printf("items and ratios in descending order:\n");
for(i=1;i<=n;i++)
{
printf("%d,%f\n",item[i],ratio[i]);
}
printf("solution set of items and profit:\n");
for(i=1;i<=n;i++)
{if(weight>0)
{
weight=weight-w[item[i]];
if(weight>0)
{
item_sol[i]=item[i];
sum=sum+p[item[i]];
count++;
printf("%d->",item_sol[i]);
}
else
{
item_sol[i]=item[i];
sum=sum+((float)(weight+w[item[i]])/w[item[i]])*p[item[i]];
count++;
printf("%d%s%d %d\n",(weight+w[item[i]]),"/",w[item[i]],item_sol[i]);
}
}
}
printf("\n");
printf("profit=%d\n",sum);
}
