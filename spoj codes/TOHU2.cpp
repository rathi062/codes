#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int k,c=0;
            char ch,s;
            char a[99];
            for(int j=0;j<99;j++)
            {
                    cin>>k;
                    cin>>ch;
                    a[k]=ch;
            }
            s=a[9];
            for(int j=1;j<=11;j++)
            {
                    if(a[9*j]!=s)
                    {
                          c=1;
                          break;
                    }
            }
            if(c==0)
            {cout<<"YES\n";}
            else
            cout<<"NO\n";
    }
    getch();
    return 0;
}
