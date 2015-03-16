#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int a[16],ga=0,gb=0,f=0,c=0,max=0,in=0;
            string s[16],x,b,w;
            for(int j=0;j<16;j++)
            {
                    cin>>x>>b>>ga>>gb;
                    if(ga>gb)
                    w=x;
                    else
                    w=b;
                    f=0;
                    for(int k=0;k<c;k++)
                    {
                            if(s[k]==w)
                            {
                                       a[k]++;
                                       f=1;
                                       if(a[k]>max)
                                       {
                                                in=k;
                                                max=a[k];
                                       }
                                       break;
                            }
                    }
                    if(f==0)
                    {
                            s[c]=w;
                            a[c++]=1;
                    }
            }
            cout<<s[in]<<endl;
    }
    getch();
    return 0;
}
            
