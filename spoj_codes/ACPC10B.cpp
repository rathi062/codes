#include<iostream>
#include<conio.h>
using namespace std;
int fn(int a)
{
    int s1=0,t=0;
     while(a!=0)
     {
         t=a%10;
         s1+=t*t;
         a=a/10;
     }
     return s1;
}
int main()
{
    int a=0,b=0;
    cin>>a>>b;
    while(a!=0&&b!=0)
    {
                     int ar[20],o=0,n=b,i=0,j=0;
                     ar[0]=a;
                     for(int i=1;i<20;i++)
                     {
                             ar[i]=fn(ar[i-1]);
                     }
                     for( i=0;i<20;i++)
                     {
                             for( j=0;j<20;j++)
                             {
                                     if(ar[j]==n)
                                     {
                                         o=1;
                                         break;
                                     }
                             }
                             if(o==0)
                             n=fn(n);
                             else
                             break;
                     }
                     if(o==0)
                     cout<<a<<" "<<b<<" "<<0<<endl;
                     else
                     cout<<a<<" "<<b<<" "<<(i+j+2)<<endl;
                     cin>>a>>b;
    }
    getch();
    return 0;
}
