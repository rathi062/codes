#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    int a[n],f=0,r=n-1,sum=0;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
            if(a[f]>a[r])
            sum+=(i+1)*a[r--];
            else
            sum+=(i+1)*a[f++];
    }
    cout<<sum;
    getch();
    return 0;
}     
