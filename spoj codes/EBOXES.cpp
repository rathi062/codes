#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n,k,t,f;
            cin>>n>>k>>t>>f;
            cout<<((f-n)/(k-1)+f)<<endl;
    }
    getch();
    return 0;
}
