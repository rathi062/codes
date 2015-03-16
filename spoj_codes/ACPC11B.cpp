#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,m=0,min=1000000,num=0;
            cin>>n;
            int a[n];
            for(int j=0;j<n;j++)
            cin>>a[j];
            cin>>m;
            for(int j=0;j<m;j++)
            {
                    cin>>num;
                    for(int k=0;k<n;k++)
                    {
                            if(abs(num-a[k])<min)
                            min=abs(num-a[k]);
                    }
            }
            cout<<min<<endl;
    }
    getch();
    return 0;
}
