#include<stdio.h>
#include<string.h>
#define d 256
void rabinKrap(char txt[],char pat[],int q);
void main()
{
	char txt[]="woman Should Be Financially Independent Financially";
	char pat[]="Financially";
	int q=11;
	 rabinKrap(txt,pat,q);
}
void rabinKrap(char txt[],char pat[],int q)
{
	int n=strlen(txt);
	int m=strlen(pat);
	printf("n=%d\nm=%d\n",n,m);
	int p=0,t=0,h=1,i,j;
	for(i=0;i<m-1;i++)
		{
		h=(h*d)%q;
	} 
	 for(i=0;i<m;i++)
	 {
	 	p=(d*p+pat[i])%q;
	 	t=(d*t+txt[i])%q;
	 }
	 for(i=0;i<n-m;i++)
	 {
	 	if(p==t)
	 	{
	 		for(j=0;j<m;j++)
	 		{
	 			if(txt[i+j]!=pat[j])
	 			break;
			 }
			 if(j==m)
			 {
			 	printf("\npattern found at:%d\n",i);
			 }
		 }
		 if(i<n-m)
		 {
		 	t=(d*(t-txt[i]*h)+txt[i+m])%q;
		 	if(t<0)
		 	{
		 		t=t+q;
			 }
		 }
		}
}
