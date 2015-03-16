#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    long m=0,n=0;
    long long sum=0,req=0;
    cin>>m>>n;
    int a[n],set=0,r[n];
    for(int i=0;i<n;i++)
    {
            r[i]=0;
            cin>>a[i];
            sum+=a[i];
    }
    req=sum-m;
    //cout<<"\nreq : "<<req;
    while(set!=1)
    {
                 for(int i=0;i<n;i++)
                 {
                         if(req==0)
                         {
                             set=1;
                             break;
                         }
                         if(a[i]>0)
                         {
                               a[i]--;
                               r[i]++;
                               req--;
                         }
                 }
    }
    sum=0;
    for(int i=0;i<n;i++)
    {
            //cout<<"\nval : "<<r[i];
            sum+=(r[i]*r[i]);
    }
    cout<<sum;
    getch();
    return 0;
}                                  
