#include<iostream>
using namespace std;
int main()
{
    long long a,i,t,n,s=0;
    cin>>t;
    while(t--)
    {
    std::cin>>n;
    while(n--)
    {
       cout<<"\n is : "<<n;
       std::cin>>a;
       if(i%2==0)
       {if(a<0)
        s+=a;}
       else
       if(a<0)
       s+=a;
    }
    if(s<0)
    std::cout<<"Every Girl Lies!\n";
    else
    std::cout<<"Some Mirrors Lie!\n";
    }
    return 0;
}
       
