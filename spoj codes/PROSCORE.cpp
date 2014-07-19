#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,p=0,c1=1,c2=1,c3=1,sum=0;
            cin>>n>>p;
            int a[n][p],col[p],r[n],count=0;
            for(int j=0;j<n;j++)
            {
                    count=0;
                    for(int k=0;k<p;k++)
                    {
                            cin>>a[j][k];
                            if(a[j][k]==1)
                            count++;
                    }
                    r[j]=count;
                    if(r[j]==0)
                    c2=0;
                    if(r[j]==p)
                    c3=0;
            }
            for(int j=0;j<p;j++)
            {
                    count=0;
                    for(int k=0;k<n;k++)
                    {
                            if(a[k][j]==1)
                            count++;
                    }
                    col[j]=count;
                    if(col[j]==0)
                    {
                        c1=0;
                        break;
                    }
            }
            sum=4*c1+2*c2+1*c3;
            cout<<"Case "<<i+1<<": "<<sum<<endl;
    }
    getch();
    return 0;
}
