#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0;
            unsigned long long sum=0;
            cin>>n;
            if(n%2==0)
            {
                      sum=n*n+(n*(n-1)*(n+1))/6+((n-2)*(n)*(2*n-5))/24;
            }
            else
            sum=n*n+(n*(n-1)*(n+1))/6+((n-3)*(n-1)*(2*n-1))/24;
            cout<<sum<<endl;
    }
    getch();
    return 0;
}
    
