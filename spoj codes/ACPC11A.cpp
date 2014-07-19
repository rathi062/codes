#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,e=-1;
            cin>>n;
            string s[n];
            for(int j=0;j<n;j++)
            {
                    cin>>s[j];
                    if(int(s[j][0])!=35)
                    e=j;
            }
            if(e==-1)
            for(int j=0;j<n;j++)
            cout<<s[j]<<" ";
            else
            {
                for(int j=e+1;j<n;j++)
                cout<<s[j]<<" ";
                cout<<s[e]<<" ";
                for(int j=0;j<e;j++)
                cout<<s[j]<<" ";
            }
            cout<<endl;
    }
    getch();
    return 0;
}
