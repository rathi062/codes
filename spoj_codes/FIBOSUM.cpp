#include<iostream>
#include<conio.h>
using namespace std;
void pwr(long long p[2][2],int in,int md)
{
     long long q[2][2],r[2][2];
     if(in>1)
     {
             pwr(p,in/2,md);
             q[0][0]=((p[0][0]*p[0][0])%md+(p[0][1]*p[1][0])%md)%md;
             q[0][1]=((p[0][0]*p[0][1])%md+(p[0][1]*p[1][1])%md)%md;
             q[1][0]=((p[1][0]*p[0][0])%md+(p[1][1]*p[1][0])%md)%md;
             q[1][1]=((p[1][0]*p[0][1])%md+(p[1][1]*p[1][1])%md)%md;
             if(in%2==1)
             {
                  r[0][0]=((q[0][1]*1)%md)%md;
                  r[0][1]=((q[0][0]*1)%md+(q[0][1]*1)%md)%md;
                  r[1][0]=((q[1][1]*1)%md)%md;
                  r[1][1]=((q[1][0]*1)%md+(q[1][1]*1)%md)%md;
                  p[0][0]=r[0][0];
                  p[0][1]=r[0][1];
                  p[1][0]=r[1][0];
                  p[1][1]=r[1][1];
             }
             else
             {
                p[0][0]=q[0][0];
                p[0][1]=q[0][1];
                p[1][0]=q[1][0];
                p[1][1]=q[1][1];
             }
     }
}
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       long long d=0,p[2][2],n,m,md=1000000007,a,b;
       p[0][0]=0;
       p[0][1]=1;
       p[1][0]=1;
       p[1][1]=1;
       cin>>n>>m;
       pwr(p,n,md);
       a=p[1][1];
       p[0][0]=0;
       p[0][1]=1;
       p[1][0]=1;
       p[1][1]=1;
       pwr(p,m+1,md);
       b=p[1][1];
       d=b-a;
       if(d<0)
       d=d+md;
       cout<<d<<endl;
    }   
    getch();
    return 0;
}
