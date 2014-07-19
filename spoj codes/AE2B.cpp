#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0;
    long a,b,x1,y1,x2,y2;
    long long d1,d2;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            cin>>a>>b>>x1>>y1>>x2>>y2;
            if(x1>x2)
            {d1=x1-x2;}
            else
            {d1=x2-x1;}
            if(y1>y2)
            {d2=y1-y2;}
            else
            {d2=y2-y1;}
            cout<<"\nd1="<<d1<<"\nd2 = "<<d2<<"\nd1 + d2 = "<<(d1+d2)<<"\na+b = "<<(a+b);
            if((d1+d2)%(a+b)==0)
            {cout<<"TAK\n";}
            else
            {cout<<"NIE\n";}
    }
    getch();
    return 0;
}
