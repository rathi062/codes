#include<iostream>
#include<conio.h>
using namespace std;
long long i,j,k,l,p,q,r,s,n,m,d,a,c,t,e;
void f(int in,int d)
{
if(in>1)
{
f(in/2,d);
i=((p*p)%d+(q*r)%d)%d;
j=((p*q)%d+(q*s)%d)%d;
k=((r*p)%d+(s*r)%d)%d;
l=((r*q)%d+(s*s)%d)%d;
if(in%2==1)
{
p=j;
q=(i+j)%d;
r=l;
s=(k+l)%d;
}
else
{
p=i;
q=j;
r=k;
s=l;
}
}
}
int main()
{
cin>>t;
for(e=0;e<t;e++)
{
p=0;
q=1;
r=1;
s=1;
cin>>n>>m>>c>>d;
f(c,d);
a=(r*n+s*m)%d-m%d;
if(a<0)
a+=d;
cout<<a<<endl;
}   
getch();
return 0;
}



