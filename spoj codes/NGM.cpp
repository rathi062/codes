#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    if(n%10==0)
    cout<<2;
    else
    cout<<1<<endl<<(n%10);
    getch();
    return 0;
}
