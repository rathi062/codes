#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n],c[n],d[n],i,j,k,l,sum=0,r=0;
    for(i=0;i<n;i++)
    {
                    cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             for(k=0;k<n;k++)
             {
                  for(l=0;l<n;l++)
                  {
                       sum=10;
                       sum=a[i]+b[j]+c[k]+d[l];
                       if(sum==0)
                       r++;
                  }
             }
        }
    }
    cout<<r;
    getch();
    return 0;
}
