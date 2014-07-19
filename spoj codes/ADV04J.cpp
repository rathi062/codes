#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n=0,l=0;
            cin>>n;
            while(n>2)
            {
                      if(n%2==0)
                      n=n/2;
                      else
                      n=(n+1)/2;
                      l++;
            }
            cout<<(l+2)<<endl;
    }
    getch();
    return 0;
}
