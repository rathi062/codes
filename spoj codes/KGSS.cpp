#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,q=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
            char ch;
            int x,y;
            cin>>ch>>x>>y;
            if(ch=='U')
            {
                       a[x-1]=y;
            }
            else
            {
                int f=0,s=0;
                for(int j=x-1;j<=y-1;j++)
                {
                        if(a[j]>f)
                        {
                                  s=f;
                                  f=a[j];
                        }
                        else
                        {
                            if(s<a[j])
                            s=a[j];
                        }
                }
                cout<<f+s<<endl;
            }
    }
    getch();
    return 0;
}
                                  
