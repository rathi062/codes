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
            int ch[n];
            string a[n],b[n],nxt,pr;
            for(int j=0;j<n;j++)
            {
                    cin>>a[j];
            }
            for(int j=0;j<n;j++)
            {
                    cin>>b[j];
                    ch[j]=0;
            }
            c=0;
            for(int j=0;j<n;j++)
            {
                    //cout<<"\nfor "<<j+1;
                         for(int k=0;k<n;k++)
                         {
                                 if(ch[k]==0)
                                 {
                                     if(a[k]==b[j])
                                     {
                                         ch[k]=1;
                                         //cout<<endl<<c<<" "<<k+1;
                                         break;
                                     }
                                     else
                                     c++;
                                 }
                         }
                    
            }
            cout<<c<<endl;
    }
    getch();
    return 0;
} 
