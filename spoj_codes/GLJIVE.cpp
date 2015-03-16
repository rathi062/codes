#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n,sum=0,r=0;
    for(int i=0;i<10;i++)
    {
                  cin>>n;
                  if(r==0)
                  {
                  if(sum+n>100)
                  r=n;
                  else
                  sum+=n;
                  }
    }
    
    if((100-sum)==(sum+r-100))
    {cout<<(sum+r);}
    else
    cout<<sum;
    getch();
    return 0;
}
