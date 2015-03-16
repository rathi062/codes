#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    long n;
    long i,r=0,f=0,m=0,sum=0,max=0;
    cin>>m>>n;
    int a[m];
    for(i=0;i<m;i++)
    {
                       a[i]=0;
                       cin>>a[r];
                       sum+=a[r];
                       r++;
                    if(sum>max&&sum<=n)
                    {
                         max=sum;
                    }
                    if(sum>n)
                    {
                             while(sum>n)
                             {
                                      sum-=a[f];
                                      f++;
                             }
                             if(sum>max&&sum<=n)
                             {
                                  max=sum;
                             }
                    }
    }
    cout<<max;
    getch();
    return 0;
}
