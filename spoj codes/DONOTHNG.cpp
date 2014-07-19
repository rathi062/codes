#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0;
    cin>>n>>m;
    while(n!=-1&&m!=-1)
    {
                       int c[n];
                       unsigned long long sum=0,sm=0;
          for(int i=0;i<n;i++)
          cin>>c[i];
          for(int i=0;i<n;i++)
          {sum=sum+(m*c[i]);
          sm+=sum;
          //cout<<sum<<endl;
          }
          cout<<sm<<endl;
          cin>>n>>m;
    }
    getch();
    return 0;
}
