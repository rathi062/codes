#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {            
                 float a=0,b=0,c=0;
                 long long x=0,y=0,z=0,count=0,r=0;
                 cin>>x>>y>>z;
                 a=float(x);
                 b=float(y);
                 c=float(z);
                 r=(x*y*z);
                 cout<<"case #"<<(i+1)<<": ";
                 printf("%lld ",(r-1));
                 while(a>1||b>1||c>1)
                 {
                       if(a>1)
                       {
                              a=a/2.0;
                              count++;
                       }
                       if(b>1)
                       {
                              b=b/2.0;
                              count++;
                       }
                       if(c>1)
                       {
                              c=c/2.0;
                              count++;
                       }
                 }
                 cout<<count;
    }
    getch();
    return 0;
}
