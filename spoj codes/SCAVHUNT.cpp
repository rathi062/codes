#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,st=0,;
            cin>>n;
            int ch[n-1];
            string a[n-1][2],f;
            for(int j=0;j<n-1;j++)
            {
                    cin>>a[j][0]>>a[j][1];
            }
            for(int j=0;j<n-1;j++)
            {
                    int f=0;
                    for(int k=0;k<n-1;k++)
                    {
                            if(a[j][0]==a[k][1])
                            {
                                f=1;
                                break;
                            }
                    }
                    if(f==0)
                    {
                       st=j;
                       break;
                    }
            }
            cout<<"Scenario #"<<i+1<<endl;
            cout<<a[st][0]<<endl<<a[st][1]<<endl;
            ch[st]=1;
            f=a[st][1];
            for(int j=0;j<n-2;j++)
            {
                    for(int k=0;k<n-1;k++)
                    {
                            if(ch[k]!=1)
                            {
                                if(a[k][0]==f)
                                {
                                    cout<<a[k][1]<<endl;
                                    ch[k]=1;
                                    f=a[k][1];
                                    break;
                                }
                            }
                    }
            }
            cout<<endl;
    }
    getch();
    return 0;
}  
