#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
int 
void fn(string s,int in,int n,int sum)
{
     int p=0;
     for(int i=in;i<n;i++)
     {
             stringstream out;
             out<<s[i];
             out>>p;
             fn(
int main()
{
    string s;
    cin>>s;
    while(s!="bye")
    {
                   
                   int sum=0,n=0;
                   for(int i=0;i<s.size();i++)
                   {
                           stringstream out;
                           out<<s[i];
                           out>>n;
                           sum+=n;
                   }
                   fn(s,0,n,sum);
                   cout<<sum<<endl;
                   cin>>s;
    }
    getch();
    return 0;
}
