#include<stdio.h>
#include<string.h>
void kmp(char txt[],char pat[]);
int computePrefixFunction(char pat);
void main()
{
	char txt[]="woman Should Be Financially Independent Financially";
	char pat[]="Financially";
	kmp(txt,pat);
}
void kmp(char txt[],char pat[])
{
	int i;
	int n=strlen(txt);
	int m=strlen(pat);
	int N=computePrefixFunction(pat);
	int q=0;
	for(i=1;i<n;i++)
	{
		while(q>0 && pat[q+1]!=txt[i])
		{
			q=q-N[q];
			q=q+1;
		}
		if(q==m)
		{
			printf("pattern occurs with shift: %d\n",i-m);
			q=N[q];
		}
	}
}
int computePrefixFunction(char pat);
{
	int m=strlen(pat);
	N[1]=0;
	k=0;
	for(q=2;q<m;q++)
	{
		while(k>0&pat[k+!]!=pat[q])
		{
			k=N[k];
			if(pat[k+1]==pat[q])
			k=k+1;
		}
		N[q]-k;
	}
	return(N);
}
