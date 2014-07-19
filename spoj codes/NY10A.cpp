#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    int p=0,q=0,r=0;
    for(int i=0;i<t;i++)
    {
            int n=0,a[8],in=0;
            cin>>in;
            char ch[40];
            for(int j=0;j<8;j++)
            a[j]=0;
            for(int j=0;j<40;j++)
            {
                    cin>>ch[j];
                    if(j>=2)
                    {
                            if(ch[j]=='H')
                            r=0;
                            else
                            r=1;
                            if(ch[j-1]=='H')
                            q=0;
                            else
                            q=1;
                            if(ch[j-2]=='H')
                            p=0;
                            else
                            p=1;
                            n=4*p+q*2+1*r;
                            a[n]++;
                    }
            }
            cout<<in;
            for(int j=7;j>=0;j--)
            cout<<" "<<a[j];
            cout<<endl;
    }
    getch();
    return 0;
}     
