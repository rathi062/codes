#include<iostream>
#include<conio.h>
#include<stdout.h>
using namespace std;
void fun(int a,int b )
{
     fflush();
     string s;
     int n;
     n=(a+b)/2;
     cout<<n;
     cin>>s;
     if(s=="LOW")
     fun(a,n);
     if(s=="HIGH")
     fun(n,b);
     if(s=="WIN")
     return ;
}
     
int main()
{
    int a,b;
    cin>>a>>b;
    fun(a,b);
    getch();
    return 0;
}
    
