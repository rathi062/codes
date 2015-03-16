#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,k=0,loop=0;
            long long r=1;
            cin>>n>>k;
            if(n<k)
            r=0;
            else
            {
             if(k<(n-k))
             loop=k;
             else
             loop=n-k+1;
             for(int j=1;j<loop;j++)
             {
                    r=r*(n-j);
                    r/=j;
             }
            }
            cout<<r<<endl;
    }
    getch();
    return 0;
}
