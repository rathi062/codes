#include<iostream>
#include<conio.h>
#include<sstream>
using namespace std;
void fun1(string s,char a[])
{
     int p=0;
     for(int k=s.size();k>=0;k--)
     {
             if(s[k]=='i')
             {
                  p=6;
                  a[p]='1';
                  continue;
             }
             if(s[k]=='x')
             {
                  p=4;
                  a[p]='1';
                  continue;
             }
             if(s[k]=='c')
             {
                  p=2;
                  a[p]='1';
                  continue;
             }
             if(s[k]=='m')
             {
                  p=0;
                  a[0]='1';
                  continue;
             }
             stringstream out;
             out<<s[k];
             out>>a[p];
     }
}
void fun2(char a[],char b[])
{
     int car=0;
     for(int k=6;k>=0;k=k-2)
     {
             int sum=0;
             stringstream out,out1,out2;
             out1<<a[k];
             out2<<b[k];
             int g=0,h=0;
             out1>>g;
             out2>>h;
             sum=g+h+car;
             //cout<<"\nsum is :"<<sum;
             car=sum/10;
             sum=sum%10;
             out<<(sum);
             out>>a[k];
             //cout<<"\na["<<k<<"] is : "<<a[k];
     }
}
int main()
{
    int n;
    cin>>n;
    for(int l=0;l<n;l++)
    {
            string s;
            cin>>s;
            char a[8]={'0','m','0','c','0','x','0','i'};
            /*for(int o=0;o<8;o++)
            cout<<a[o];*/
            char b[8]={'0','m','0','c','0','x','0','i'};
            fun1(s,a);
            
            //cout<<"a[o] is "<<a[0]<<endl;
            for(int o=0;o<8;o++)
            {b[o]=a[o];
            if(o%2==0)
            a[o]='0';}
             //cout<<b[o];}
            cin>>s;
            fun1(s,a);
            //for(int o=0;o<8;o++)
            //cout<<a[o];
            fun2(a,b);
            cout<<endl;
            for(int o=0;o<8;o++)
            {
               if(a[o]=='0')
               {o++;
               continue;}
               if(a[o]=='1')
               {
               }
               else     
               cout<<a[o];       
            }
    }
    getch();
    return 0;
}
            
            
