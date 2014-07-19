#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0;
    scanf("%d",&n);
    int a[n];
    long sum[n];
    scanf("%d",&a[0]);
    sum[0]=a[0];
    for(int i=1;i<n;i++)
    {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
    }
    scanf("%d",&m);
    int x=0,y=0;
    unsigned long long r=0;
    for(int i=0;i<m;i++)
    {
            r=0;
            scanf("%d%d",&x,&y);
            if(x==0)
            for(int j=x;j<=y;j++)
                  r+=sum[j]*a[j];
            else
            for(int j=x;j<=y;j++)
                  r+=(sum[j]-sum[x-1])*a[j];
            
            printf("%lld\n",r);
    }
    getch();
    return 0;
}  
