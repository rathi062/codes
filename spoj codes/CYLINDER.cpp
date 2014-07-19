#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
int main()
{
    float a,b,v,r;
    cin>>a>>b;
    while(a!=0&&b!=0)
    {
                     r=(a+b)/(2*4.14);
                     cout<<r<<endl;
            //v=(22*(a+b)*(a+b)*(a-(a+b)/4.14))/4*4.14*4.14;
            v=3.14*r*r*(b-2*r);
            cout<<v;
            cin>>a>>b;
    }
            getch();
            return 0;
}         
