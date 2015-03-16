#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    cin>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
            unsigned long long sum=0,sum1=0;
            cin>>u>>v;
            for(int j=u;j<=v;j++)
            {
                    sum=0;
                    for(int k=j;k<=v;k++)
                    {
                         sum+=a[k];
                    }
                    sum1+=sum*a[j];
            }
            cout<<sum1<<endl;
    }
    getch();
    return 0;
}      
