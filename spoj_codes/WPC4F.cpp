#include<iostream>
#include<conio.h>
using namespace std;
int fun(int a[][3],int in,int num,int n)
{
    if(in==n)
    return 0;
    int x=0,y=0;
    if(num==0)
    {
        x=a[in][1]+fun(a,in+1,1,n);
        y=a[in][2]+fun(a,in+1,2,n);
    }
    else
    if(num==1)
    {
        x=a[in][0]+fun(a,in+1,0,n);
        y=a[in][2]+fun(a,in+1,2,n);
    }
    else
    if(num==2)
    {
        x=a[in][1]+fun(a,in+1,1,n);
        y=a[in][0]+fun(a,in+1,0,n);
    }
    if(x<y)
    return (x);
    else
    return (y);
}
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,a1=0,a2=0,a3=0;
            cin>>n;
            int a[n][3];
            for(int j=0;j<n;j++)
            {
                    cin>>a[j][0]>>a[j][1]>>a[j][2];
            }
            a1=a[0][0]+fun(a,1,0,n);
            a2=a[0][1]+fun(a,1,1,n);
            a3=a[0][2]+fun(a,1,2,n);
            if(a1<a2&&a1<a3)
            cout<<a1;
            else
            if(a2<a1&&a2<a3)
            cout<<a2;
            else
            cout<<a3;
            cout<<endl;
    }
    getch();
    return 0;
}
