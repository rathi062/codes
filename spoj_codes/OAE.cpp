#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n,sum=0;
            cin>>n;
            sum=pow(9,n);
            cout<<endl<<sum;
    }
    getch();
    return 0;
}
