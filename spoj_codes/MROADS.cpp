#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int fun(int *a[],int check[],int n,int x,int y)
{
    check[x]=1;
    int r=0;
    if(a[x][y]==1)
    return 1;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(check[i]!=1)
            {
                 if(a[x][i]==1)
                 {
                      r=fun(a,check,n,i,y);
                      if(r==1)
                      return 1;
                 }
            }
        }
    }
    return 0;
}
int main()
{
    int n=0,m=0,max=0,sum=0;
    cin>>n>>m;
    int min[n],requ[n],from[n][3],need[n];
    min[0]=0;
    requ[0]=0;
    need[0]=0;
    for(int i=1;i<n;i++)
    {
            need[i]=0;
            min[i]=0;
            requ[i]=0;
            int x=0,y=0,c=0,mm=0;
            cin>>x>>y>>c>>mm;
            from[i][0]=x;
            from[i][1]=c;
            from[i][2]=mm;
    }
    for(int i=1;i<n;i++)
    {
            int d=0,f=i+1,mm=0,cu=0;
            while(f!=1)
            {
                cu+=from[f-1][1];
                mm+=from[f-1][2];
                f=from[f-1][0];
            }
            min[i]=mm;
            requ[i]=cu;
            need[i]=requ[i]-min[i];
            sum+=need[i];
            if(max<mm)
            {
                      max=mm;
            }
    }
    for(int i=1;i<n;i++)
    cout<<endl<<i+1<<"   "<<requ[i]<<"   "<<min[i];
    cout<<"\nsum : "<<sum<<" money : "<<m;
    if(sum<=m)
    cout<<max;
    else
    {
        
        while(1)
        {
            max=max+1;
            sum=0;
            for(int i=1;i<n;i++)
            {
                 if(requ[i]>max)
                 {
                      sum+=(requ[i]-max);
                 }
            }
            cout<<"\nsum : "<<sum<<" money : "<<m<<" max : "<<max;
            if(sum<=m)
            {
                cout<<max;
                break;
            }
        }
    }
    getch();
    return 0;
}
