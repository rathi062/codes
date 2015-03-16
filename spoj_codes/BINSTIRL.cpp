#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,m=0,s=0;
            cin>>n>>m;
            if(n==m)
            cout<<"1\n";
            else
            {
                if((n==0&&m!=0)||(n!=0&&m==0))
                cout<<"0\n";
                else
                {
                    if(m>n)
                    cout<<"0\n";
                    else
                    {
                        s=((n-m)&(m-1)/2);
                        if(s%2==0)
                        cout<<"1\n";
                        else
                        cout<<"0\n";
                    }
                }
            }
    }
    getch();
    return 0;
}
