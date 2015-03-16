#include<iostream>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    long long s=0,f=883333336,d=0,n=0,m=1000000003;
    for(int i=0;i<t;i++)
    {
            scanf("%lld",&n);
            s=(n*(n+1))%m;
            s=(s*(n+2))%m;
            s=(s*((3*n*n)%m+(6*n)%m+1))%m;
            s=(s*f)%m;
            printf("%lld\n",s);
    }
    system("pause");
    return 0;
}




