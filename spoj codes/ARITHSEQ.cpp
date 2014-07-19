#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
int main()
{
    int d=0,n=0;
    char x;
    long long a=0;
    cin>>a>>d>>n>>x;
    stringstream out,out1;
    out<<a;
    for(int i=0;i<n;i++)
    {
            a=a+d;
            out<<a;
    }
    string s;
    out>>s;
    a=0;
    for(int i=0;i<s.size();i++)
    {
            if(s[i]==x)
            a++;
    }
    cout<<a;
    getch();
    return 0;
}
