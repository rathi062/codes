#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
               cout<<pow(n,n-2)<<endl;
               cin>>n;
    }
    getch();
    return 0;
}
