#include<iostream>
#include<conio.h>
using namespace std;
long long fun(long long n)
{
     if(n/2+n/3+n/4>n)
     return (fun(n/2)+fun(n/3)+fun(n/4));
     else
     return n;
}
int main()
{
    long long n;
    long long k;
    while(scanf("%lld",&n)!=EOF)
    {
          k=fun(n/2)+fun(n/3)+fun(n/4);
          if(k<n)
          cout<<n;
          else
          cout<<k;
    }
    getch();
    return 0;
}
