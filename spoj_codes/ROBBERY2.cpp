#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int t=0,k=0;
    long long n=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            long long c=1,r=0;
            cin>>n;
            cin>>k;
            long long a[k],s=0;
            for(int j=0;j<=k;j++)
            {a[j]=0;}
            r=(-1+sqrt(1+8*n))/2;
            c=r/k;
            s=n-(c*k*(c*k+1)/2);
            cout<<s<<endl;
            for(int i=1;i<=k;i++)
            {
                    a[i]=c*i+c*(c-1)*k/2;
                    if(s>(c*k+i))
                    {
                                 a[i]+=c*k+i;
                                 s-=c*k+i;
                    }
                    else
                    {
                        if(s!=0)
                        {
                                a[i]+=s;
                                s=0;
                        }
                    }
            }        
            for(int j=1;j<=k;j++)
            {    cout<<a[j]<<" ";   }
    }
    getch();
    return 0;
}
