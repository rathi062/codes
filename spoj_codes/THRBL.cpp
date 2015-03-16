#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0,m=0,k=0,a=0,b=0,min=0,max=0,c=0;   
    cin>>n>>m;
    long long h[n];
    for(int i=0;i<n;i++)
    {
            cin>>h[i];
    }
    for(int i=0;i<m;i++)
    {
                    max=0,min=0,k=0;
                    cin>>a>>b;
                    if(a>b)
                    {min=b;
                     max=a;}
                    else
                    {
                        max=b;
                        min=a;
                    }
                    for(int j=min;j<max-1;j++)
                    {
                           if(h[j]>h[a-1])
                           {
                                          k=1;
                                          break;
                           }
                    }
                    if(k==0)
                    {
                            c++;
                    }
    } 
    cout<<c;
    getch();
    return 0;
}
