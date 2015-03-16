#include<iostream>
#include<conio.h>
using namespace std;
long long fn(int st,int n)
{
    if(n!=0)
    {
            long long a=0,b=0;
            if(st==1)
            {
                     a=3*fn(2,n-1);
                     b=3*fn(3,n-1);
            }
            if(st==2)
            {
                     a=1*fn(2,n-1);
                     b=1*fn(3,n-1);
            }
            if(st==3)
            {
                     a=2*fn(2,n-1);
                     b=2*fn(4,n-1);
            }
            if(st==4)
            {
                     a=1*fn(2,n-1);
                     b=1*fn(4,n-1);
            }
            return (a+b);
    }
    else
    return 1;
}
int main()
{
    int n=0,t=0;
    long long sum=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cin>>n;
            sum=fn(1,n);
            cout<<sum/2<<endl;
    }
    getch();
    return 0;
}
