#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,n=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cin>>n;
            int w=0,l=0,a[n];
            for(int j=0;j<n;j++)
            {cin>>a[j];}
            long long sum=0;
            for(int j=0;j<n;j++)
            {
                    l=a[j];
                    if(j==0&&l<0)
                    {
                         sum+=l*1;
                         w=1;
                         continue;
                    }
                    if(l>=0)
                    sum+=l*(++w);
                    else
                    {
                        sum+=l*(w=2);
                    }
            }
            cout<<sum<<endl;
    }
    getch();
    return 0;
}
