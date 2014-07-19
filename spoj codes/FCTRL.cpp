#include<iostream>
#include<conio.h>
using namespace std;
long long int fact(long long int n)
{
    long long int f=1;
    if(n>0)
    f=n*fact(n-1);
    cout<<endl<<f;
    return (f);
}
int main()
{
    long long int n,r,i=0,d=0;
    cout<<"enter the no :";
    cin>>n;
    r=fact(n);
    cout<<"\nfactorial = "<<r;
    while(d==0)
    {
               d=r%10;
               r=r/10;
               if(d==0)
               i++;
    }
    cout<<"\n no of 0 is : "<<i;
    getch();
    return 0;
}
    
