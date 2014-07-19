#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int m=0,n=0,min;
            cin>>m>>n;
            int a[m][n],b[m][n],cost=0;
            long long c[m][n],sum[m],max=0;
            for(int j=0;j<m;j++)
            {
                    sum[j]=0;
                    for(int k=0;k<n;k++)
                    cin>>a[j][k];
            }
            for(int j=0;j<m;j++)
            {
                    for(int k=0;k<n;k++)
                    cin>>b[j][k];
            }
            for(int j=0;j<m;j++)
            {
                    for(int k=0;k<n;k++)
                    cin>>c[j][k];
            }
            for(int j=0;j<m;j++)
            {
                    for(int k=0;k<n;k++)
                    {
                           if(a[j][k]<b[j][k])
                           min=a[j][k];
                           else
                           min=b[j][k];
                           cost=(min*c[j][k]);
                           if(sum[j]<cost)
                           sum[j]=cost;
                    }
                    max+=sum[j];
            }
            cout<<max<<endl;
    }
    getch();
    return 0;
}
            
