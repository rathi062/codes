#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<sstream>
using namespace std;
string sub(string s,int n)
{
    int l,a,c=0,i,no=0,j=0;
    l=s.size();
    for(i=l-1;i>=0;i--)
    {
         a=s[i]-48;
         if(j==1)
         {
            if(a==0)
            {
               a=9;
               s[i]=char(a+48);
            }
            else
            {
               a--;
               j=0;
               s[i]=char(a+48);
               break;
            }
         }
         else  
         { 
            if(a>=n)
            {
               a-=n;
               s[i]=char(a+48);
               break;
            }
            else
            {
               a+=10;
               //cout<<"\na= "<<a<<end;;
               a-=n;
               s[i]=char(a+48);
               j=1;
            }
         }
    }
    return s;
}
void display(string s)
{
     int i=0,l=s.size();
     for(;i<l;i++)
     cout<<s[i];
}       
int main()
{
    string s;
    int n;
    while(cin>>s)
    {
       if(s=="1")
       printf("1\n");
       else
       {
         n=1;
         s=sub(s,n);
         //cout<<"\nafter sub = "<<s;
         int l,a,c=0,i;
         l=s.size();
         for(i=l-1;i>=0;i--)
         {
            a=s[i]-48;
            a*=2;
            a+=c;
            s[i]=char(a%10+48);
            c=a/10;
         }
         //cout<<"\nafter mul "<<s;
         if(c!=0)
         cout<<c;
         display(s);
         cout<<endl;
       }
    }
    getch();
    return 0;
}
            
