#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,k=0;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
          int a[k];
          long long f=1;
          for(int i=0;i<k;i++)
          cin>>a[i];
          for(int i=2;i<=n;i++)
          f*=i;
          //cout<<"f = "<<f;
          for(int i=0;i<k;i++)
          {
                  if(a[k]>1)
                  for(int j=2;j<=a[i];j++)
                  f=f/j;
          }
          cout<<f<<endl;
    }
    getch();
    return 0;
}
