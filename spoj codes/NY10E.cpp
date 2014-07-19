#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int l=0,n=0;
            unsigned long long sum=1;
            cin>>l>>n;
            for(int j=0;j<n;j++)
            {
                    sum=(sum*(10+j))/(j+1);
            }
            cout<<l<<" "<<sum<<endl;
    }
    getch();
    return 0;
}
