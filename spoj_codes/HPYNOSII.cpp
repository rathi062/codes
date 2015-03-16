#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            long long n=0;
            int r=0,sum=0,a[1000],f=0;
            cin>>n;
            for(int j=0;j<20;j++)
            {
                    sum=0;
                    while(n!=0)
                    {
                        r=n%10;
                        sum+=r*r;
                        n=n/10;
                        //cout<<"\nsum = "<<sum;
                    }
                    if(sum==1)
                    {
                              f=1;
                              cout<<j+1<<endl;
                              break;
                    }
                    else
                    {
                        //cout<<"\na[sum] = "<<a[sum];
                        if(a[sum]!=1)
                        a[sum]=1;
                        else
                        {
                            f=1;
                            cout<<-1<<endl;
                            break;
                        }
                        n=sum;
                    }
            }
            if(f==0)
            cout<<-1<<endl;
    }
    getch();
    return 0;
}
