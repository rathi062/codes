#include<iostream>
#include<conio.h>
using namespace std;
int fn(int a[],int b[],int c[])
{
    long x,y,z,x1,y1,z1,x2,y2,z2,x3,y3,z3;
    for(int i=0;i<3;i++)
    {
            x1=a[i];
            y1=b[i];
            z1=c[i];
            cout<<"\nx1 = "<<x1;
            cout<<"\ny1 = "<<y1;
            cout<<"\nz1 = "<<z1;
            for(int j=i+1;j<4;j++)
            {
                    x2=a[j];
                    y2=b[j];
                    z2=c[j];
                    cout<<"\nx2 = "<<x2;
                    cout<<"\ny2 = "<<y2;
                    cout<<"\nz2 = "<<z2;
                    for(int k=j+1;k<5;k++)
                    {
                            x3=a[k];
                            y3=b[k];
                            z3=c[k];
                            cout<<"\nx3 = "<<x3;
                            cout<<"\ny3 = "<<y3;
                            cout<<"\nz3 = "<<z3;
                            for(int l=0;l<5;l++)
                            {
                                    if(l!=i&&l!=j&&l!=k)
                                    {
                                          x=a[l];
                                          y=b[l];
                                          z=c[l];
                                          cout<<"\nx = "<<x;
                                          cout<<"\ny = "<<y;
                                          cout<<"\nz = "<<z;
                                          cout<<"\n(x-x1)*(y-y2)*(z-z3) = "<<(x-x1)*(y-y2)*(z-z3);
                                          cout<<"\n(y-y1)*(z-z2)*(x-x3) = "<<(y-y1)*(z-z2)*(x-x3);
                                          cout<<"\n(z-z1)*(x-x2)*(y-y3) = "<<(z-z1)*(x-x2)*(y-y3);
                                          cout<<"\n(z-z1)*(y-y2)*(x-x3) = "<<(z-z1)*(y-y2)*(x-x3);
                                          cout<<"\n(y-y1)*(z-z3)*(x-x2) = "<<(y-y1)*(z-z3)*(x-x2);
                                          cout<<"\n(x-x1)*(z-z2)*(y-y3) = "<<(x-x1)*(z-z2)*(y-y3);
                                          if((x-x1)*(y-y2)*(z-z3)+
                                             (y-y1)*(z-z2)*(x-x3)+
                                             (z-z1)*(x-x2)*(y-y3)-
                                             (z-z1)*(y-y2)*(x-x3)-
                                             (y-y1)*(z-z3)*(x-x2)-
                                             (x-x1)*(z-z2)*(y-y3)==0)
                                          return (l)+1;
                                    }
                            }
                    }
            }
    }
    return 0;
}
int main()
{
    int t=0,a[5],b[5],c[5];
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int r=0;
            for(int j=0;j<5;j++)
            cin>>a[j]>>b[j]>>c[j];
            r=fn(a,b,c);
            cout<<r<<endl;
    }
    getch();
    return 0;
}
