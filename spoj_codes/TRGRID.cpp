#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,i=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
          int m=0,n=0;
          cin>>m>>n;
          if(m==n)
          {
                  if(m%2==0)
                  cout<<"L"<<endl;
                  else
                  cout<<"R"<<endl;
          }
          else
          {
              if(m<n)
              {
                     if(m%2==0)
                     cout<<"L"<<endl;
                     else
                     cout<<"R"<<endl;
              }
              else
              {
                     if(n%2==0)
                     cout<<"U"<<endl;
                     else
                     cout<<"D"<<endl;
              }
          }
    }
    getch();
    return 0;
}
