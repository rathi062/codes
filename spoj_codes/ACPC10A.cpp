#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a=0,b=0,c=0;
    
    while(1)
    {
                   cin>>a>>b>>c;
                   if(a==0&&b==0&&c==0)
                   break;
                   if((b-a)==(c-b))
                   {cout<<"AP "<<(2*c-b);}
                   else
                   {cout<<"GP "<<(c*b)/a;}
                   cout<<endl;
                  
    }
    getch();
    return 0;
}
