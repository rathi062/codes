#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a=0,b=0;
    cin>>a>>b;
    while(a!=-1&&b!=-1)
    {
                       int min=0,max=0;
                       if(a>b)
                       {
                              min=b;
                              max=a;
                       }
                       else
                       {
                           min=a;
                           max=b;
                       }
                       if(min==0)
                       cout<<max<<endl;
                       else
                       {
                           if(max%(min+1)==0)
                           cout<<max/(min+1)<<endl;
                           else
                           cout<<(max/(min+1))+1<<endl;
                       }
                       cin>>a>>b;
    }
    getch();
    return 0;
}
