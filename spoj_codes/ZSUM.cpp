#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n=0,k=0;
    cin>>n>>k;
    while(n!=0&&k!=0)
    {
           int sum=0;
           sum=(int(pow(n,k))%10000007)+
               (int(pow(n,n))%10000007)+ 
                2*(int(pow((n-1),(n-1)))%10000007+
               (int(pow((n-1),k))%10000007))%10000007;
           cout<<sum<<endl;
           cin>>n>>k;
    }
    getch();
    return 0;
}
