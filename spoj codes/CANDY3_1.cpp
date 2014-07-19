#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            long long  n=0;
            cin>>n;
            long long a=0,r=0,sum=0;
            for(int j=0;j<n;j++)
            {
                    cin>>a;
                    r=a%5;
                    sum+=r;
            }
            if(sum%5==0)
            cout<<"YES\n";
            else
            cout<<"NO\n";
    }
    getch();
    return 0;
}
