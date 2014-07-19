#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,c=0;
            cin>>n;
            string a[n],b[n],nxt,pr;
            for(int j=0;j<n;j++)
            {
                    cin>>a[j];
            }
            for(int j=0;j<n;j++)
            {
                    cin>>b[j];
            }
            for(int j=0;j<n;j++)
            {
                    if(a[j]!=b[j])
                    {
                           int f=0;
                           for(int k=n-1;k>=j;k--)
                           {
                                   if(f==0)
                                   {
                                          if(b[j]==a[k])
                                          f=1;
                                   }
                                   else
                                   {
                                       nxt=a[k];
                                       a[k]=a[k+1];
                                       a[k+1]=nxt;
                                       c++;
                                   }
                           }
                    }
            }
            cout<<c<<endl;
    }
    getch();
    return 0;
} 
