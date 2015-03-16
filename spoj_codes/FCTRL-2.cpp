#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    long t,n;
    
    cin>>t;
    for(int i=0;i<t;i++)
    {
            long sum=0;
            cin>>n;
            while(n>=5)
            {
                      n=n/5;
                      sum+=n;
            }
            cout<<sum<<endl;
    }
    getch();
    return 0;
}
