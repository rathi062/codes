#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    string s;
    int n=0,h=0,q=0,t=0,p=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>s;
            if(s=="1/2")
            h++;
            else
            if(s=="1/4")
            q++;
            else
            t++;
    }
    p+=(h/2);
    h=h%2;
    if(q<t)
    {p+=q;
    t=t-q;
    q=0;}
    else
    {p+=t;
    q=q-t;
    t=0;}
    float r=0;
    r=(0.5*h)+(0.25*q);
    n=int(r);
    if(r==n)
    p+=r;
    else
    p+=(r+1);
    cout<<(p+1+t);
    getch();
    return 0;
}
