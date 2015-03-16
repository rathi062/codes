#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cout<<endl;
            cin>>n;
            int a[n],sum=0;
            for(int j=0;j<n;j++)
            {
                    cin>>a[i];
                    sum+=a[i];
            }
            if(sum%n==0)
            cout<<"YES\n";
            else
            cout<<"NO\n";
    }
    getch();
    return 0;
}
