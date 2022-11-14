#include<stdio.h>
void split();
void alloperations();
void join();
void multiply(int,int [10][10],int [10][10],int [10][10]);
void addition(int,int [10][10],int [10][10],int [10][10]);
void subtract(int,int [10][10],int [10][10],int [10][10]);
void display(int,int,int [10][10]);
int a[10][10],b[10][10],c[10][10],final[10][10]={0};
int a11[10][10],a12[10][10],a21[10][10],a22[10][10]={0};
int b11[10][10],b12[10][10],b21[10][10],b22[10][10]={0};
int c11[10][10],c12[10][10],c21[10][10],c22[10][10]={0};
int m1[10][10],m2[10][10],m3[10][10],m4[10][10],m5[10][10],m6[10][10],m7[10]
[10]={0};
int a1[10][10],b1[10][10],c1[10][10],d1[10][10],e1[10][10],f1[10][10],g1[10]
[10],h1[10][10],i1[10][10],j1[10][10]={0};
int w[10][10],x[10][10],y[10][10],z[10][10],l[10][10]={0};
int n,i,j,s,t;
static int ii=0,jj=0,kk=0;
void main(){
printf("enter n value");
scanf("%d",&n);
printf("enter first matrix values");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);}}
printf("enter second matrix values");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&b[i][j]);}}
split();
alloperations();
join();
printf("final matrix is \n");
display(n,n,final);
}
void split(){
for(i=0;i<n/2;i++){
for( j=0;j<n/2;j++){
a11[i][j]=a[i][j];}}
s=0;
for(i=0; i<n/2;i++,s++){
for(j=n/2,t=0;j<n;j++,t++){
a12[s][t]=a[i][j];}}
s=0;
for(i=n/2;i<n;i++,s++){
for(j=0,t=0;j<n/2;j++,t++){
a21[s][t]=a[i][j];}}
s=0;
for(i=n/2;i<n;i++,s++){
for(j=n/2,t=0;j<n;j++,t++){
a22[s][t]=a[i][j];}}
for(i=0;i<n/2;i++){
for(j=0;j<n/2;j++){
b11[i][j]=b[i][j];}}
s=0;
for(i=0; i<n/2;i++,s++){
for(j=n/2,t=0;j<n;j++,t++){
b12[s][t]=b[i][j];}}
s=0;
for(i=n/2;i<n;i++,s++){
for(j=0,t=0;j<n/2;j++,t++){
b21[s][t]=b[i][j];}}
s=0;
for(i=n/2;i<n;i++,s++){
for(j=n/2,t=0;j<n;j++,t++){
b22[s][t]=b[i][j];}}
}
void alloperations(){
addition(n/2,a11,a22,a1);
addition(n/2,b11,b22,b1);
addition(n/2,a21,a22,c1);
subtract(n/2,b12,b22,d1);
subtract(n/2,b21,b11,e1);
addition(n/2,a11,a12,f1);
subtract(n/2,a21,a11,g1);
addition(n/2,b11,b12,h1);
subtract(n/2,a12,a22,i1);
addition(n/2,b21,b22,j1);
multiply(n/2,a1,b1,m1); ii=jj=kk=0;
multiply(n/2,c1,b11,m2);ii=jj=kk=0;
multiply(n/2,a11,d1,m3);ii=jj=kk=0;
multiply(n/2,a22,e1,m4);ii=jj=kk=0;
multiply(n/2,f1,b22,m5);ii=jj=kk=0;
multiply(n/2,g1,h1,m6);ii=jj=kk=0;
multiply(n/2,i1,j1,m7);ii=jj=kk=0;
addition(n/2,m1,m4,w);
subtract(n/2,w,m5,l);
addition(n/2,m5,m7,x);
subtract(n/2,m1,m2,y);
addition(n/2,m3,m6,z);
addition(n/2,l,m7,c11);
addition(n/2,m3,m5,c12);
addition(n/2,m2,m4,c21);
addition(n/2,y,z,c22);
}
void addition(int n,int a[10][10], int b[10][10],int c[10][10]){
	int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
c[i][j]=a[i][j]+b[i][j];}}
}
void subtract(int n,int a[10][10], int b[10][10],int c[10][10]){
	int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
c[i][j]=a[i][j]-b[i][j];}}
}
void multiply(int n,int a[10][10], int b[10][10],int c[10][10]){
if(ii>=n)
return;
else {
if(jj<n){
if(kk<n){
c[ii][jj]=c[ii][jj]+a[ii][kk]*b[kk][jj];
kk++;
multiply(n,a,b,c);}
kk=0;
jj++;
multiply(n,a,b,c);}
jj=0;
ii++;
multiply(n,a,b,c);}
}
void join(){
for(i=0;i<n/2;i++){
for(j=0;j<n/2;j++){
final[i][j]=c11[i][j];}}
s=0;
for(i=0; i<n/2;i++,s++){
for(t=0, j=n/2;j<n;j++,t++){
final[i][j]=c12[s][t];}}
s=0;
for(i=n/2;i<n;i++,s++){
for(t=0,j=0;j<n/2;j++,t++){
final[i][j]=c21[s][t];}}
s=0;
for(i=n/2;i<n;i++,s++){
for(t=0,j=n/2;j<n;j++,t++){
final[i][j]=c22[s][t];}}
}
void display(int m,int n,int c[10][10]){
	int i,j;
for(i=0;i<m;i++){
for(j=0;j<n;j++){
printf("%d \t",c[i][j]);}
printf("\n");}
}
