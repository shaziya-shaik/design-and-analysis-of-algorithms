#include<stdio.h>
#include<string.h>
int naive(char txt[],char pat[]);
void main()
{
	int f;
	char txt[]="womanShouldBeFinanciallyIndependentFinancially";
	char pat[]="Financially";
	f=naive(txt,pat);
	printf("pattern matches at:%d",f);
}
	int naive(char txt[],char pat[])
	{
		int i,j;
	int n=strlen(txt);
	int m=strlen(pat);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(txt[i+j]!=pat[j])
		break;	
		}
		if(j==m)
		return i;
	}
}
