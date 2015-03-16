#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,n=0,sum=0,r=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cin>>n;
            sum=1;
            for(int j=2;j<n;j++)
            {
                    r=0;
                    if(n%j==0)
                    r=1;
                    else
                    for(int k=2;k<=j/2+1;k++)
                    {
                            if(n%k==0&&j%k==0)
                            {
                                r=1;
                                break;
                            }
                    }
                    if(r==0)
                    {
                            //cout<<j<<" ";
                            sum++;
                    }
            }
            cout<<sum<<endl;
    }
    getch();
    return 0;
}
