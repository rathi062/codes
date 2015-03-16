#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            char ch;
            int a=1,b=1,c=0;
            cin>>ch;
            if(ch=='-')
            {
                       stringstream out;
                       out<<ch;
                       cin>>ch;
                       if(ch!='x')
                       {
                            out<<ch;
                            a<<out;
                            cout<<"\na = "<<a;
                            cin>>ch>>ch>>ch>>ch>>ch;
                       }
                       else
                       {
                           a=-1;
                           cin>>ch>>ch>>ch>>ch;
                       }
            }
            else
            {
                if(ch!=x)
                {
                         stringstream out1;
                         out1<<ch;
                         out1>>a;
                         cin>>ch>>ch>>ch>>ch>>ch;
                }
                else
                {
                    a=1;
                    cin>>ch>>ch>>ch;
                }
            }
            if(ch=='-')
            {
                       stringstream out2;
                       out2<<ch;
                       cin>>ch;
                       if(ch!=x)
                       {
                                out2<<ch;
                                out2>>b;
                                cin>>ch>>ch>>ch;
                       }
                       else
                       {
                           b=-1;
                           cin>>ch;
                       }
            }
            else
            {
                       if(ch=='+')
                       {
                                  cin>>ch;
                                  if(ch!=x)
                                  {
                                           stringstream out;
                                           out<<ch;
                                           out>
    }
    getch();
    return 0;
}
