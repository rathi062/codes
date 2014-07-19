#include<iostream>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    long long s=0,f=0,d=1000000003,n=0,a[1000001];
    a[0]=0;
    for(long long j=1;j<=1000000;j++)
    {
       a[j]=((a[j-1]+(j*j*j)%d)%d;
    }
    for(int i=0;i<t;i++)
    {
            scanf("%lld",&n);
            printf("%lld\n",a[n]);
    }
    return 0;
}


