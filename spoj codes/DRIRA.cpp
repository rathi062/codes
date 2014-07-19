#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0;
    cin>>n>>m;
    while(n!=0||m!=0)
    {
         int *a[n];
         int x=0,y=0,max=0,d=0,r=0;
         int check[n];
         for(int i=0;i<n;i++)
         {
                 a[i]=NULL;
                 check[i]=0;
         }
         for(int i=0;i<m;i++)
         {
            
            cin>>x>>y>>d;
            check[x]=1;
            check[y]=1;
            if(a[x]==NULL)
            {
                          a[x]=new int[n];
                          for(int j=0;j<n;j++)
                          {
                                  a[x][j]=0;
                          }
            }
            if(a[y]==NULL)
            {
                          a[y]=new int[n];
                          for(int j=0;j<n;j++)
                          {
                                  a[y][j]=0;
                          }
            }
            if(a[x][y]==0||a[y][x]==0)
            {
                 a[y][x]=d;
                 a[x][y]=d;
            }
            else
            {
                if(d<a[x][y])
                {
                   a[x][y]=d;
                   a[y][x]=d;
                }
            }
         }
         for(int i=0;i<n;i++)
         {
                 if(check[i]==0)
                 {
                      r=1;
                      cout<<"IMPOSSIBLE\n";
                      break;
                 }
                 else
                 {
                     for(int j=0;j<m;j++)
                     if(a[i][j]>max)
                     max=a[i][j];
                 }
         }
         if(r!=1)
         cout<<max<<endl;
         cin>>n>>m;
    }
                     
    getch();
    return 0;
}
