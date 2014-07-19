#include<iostream>
#include<conio.h>
using namespace std;
int m=0, n=0,mm=10000;
void fun(int *a[],int x,int y,int cost)
{
     int sum=0;
     //cout<<"\nx y m n "<<x<<y<<m<<n;
     sum=cost+a[x][y];
     if(x==(m-1)&&y==(n-1))
     {
         
         if(mm>sum)
         {
                   mm=sum;
                   //cout<<"\nmin is : "<<mm;
         }
     }
     else
     {
         if(sum>mm)
         return ;
         else
         {
             if(x<(m-1))
             fun(a,x+1,y,sum);
             if(y<(n-1))
             fun(a,x,y+1,sum);
         }
     }
}
int main()
{
    int x=0,y=0,f=0;
    cin>>m>>n>>x>>y;
    //cout<<min;
    int *a[m];
    for(int i=0;i<m;i++)
    {
            a[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                    cin>>a[i][j];
            }
    }
    fun(a,x-1,y-1,0);
    f=2*a[x-1][y-1]-mm;
    if(f<0)
    cout<<"N";
    else
    cout<<"Y "<<f;
    getch();
    return 0;
}    
