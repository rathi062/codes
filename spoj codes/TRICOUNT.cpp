#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,n=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cin>>n;
            if(n%2==0)
            {
                      cout<<n*n+(n*(n+1)*(2*n+1)/12)-(n*(n+1)/4)+((n-3)*(n-2)*(2*n-5)/3)-((n-3)*(n-2)/2);
            }
            cout<<endl;
    }
    getch();
    return 0;
}
