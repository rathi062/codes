#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n=0,i=0;
    cin>>n;
    long long s=1;
    while(n!=0)
    {
               s=1;
               i++;
               for(int j=0;j<n-2;j++)
               s=s*n;
               cout<<"Case "<<i<<", N = "<<n<<", # of different labelings = "<<s<<endl;
               cin>>n;
    }
    getch();
    return 0;
}
