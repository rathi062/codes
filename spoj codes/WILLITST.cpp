#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    long long x=0;
    float r=0.0;
    int q=0;
    cin>>x;
    if(x<=1)
    cout<<"TAK";
    else
    {
    r=log2(x);
    //cout<<r;
    q=int(r);
    if(r>q)
    cout<<"NIE";
    else
    cout<<"TAK";
    }
    getch();
    return 0;
}
