#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            int k,sum=0;
            cin>>k;
            for(int j=1;j<=k/2;j++)
            {
                    if(k%j==0)
                    sum+=j;
            }
            cout<<endl<<sum;
    }
    getch();
    return 0;
}
