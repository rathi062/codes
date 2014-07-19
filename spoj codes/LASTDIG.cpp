#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int t=0,a=0;
    cin>>t;
    int b;
    for(int i=0;i<t;i++)
    {
            cin>>a>>b;
            a=a%10;
            if(b==0)
             cout<<1<<endl;
              else
            {
                if(b==1||(b-1)%4==0)
                  cout<<a<<endl;
                 else if(b==2||(b-2)%4==0)
                 cout<<(a*a)%10<<endl;
                  else if(b==3||(b-3)%4==0)
                   cout<<(a*a*a)%10<<endl;
                  else if(b==4||b%4==0)
                   cout<<(a*a*a*a)%10<<endl;
                   }            
    }
   getch();
   return 0;
}
