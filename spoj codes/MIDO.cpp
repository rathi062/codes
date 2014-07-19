#include<iostream>
#include<sstream>
#include<conio.h>
using namespace std;
void display(int a)
{
           if(((a/60)/10!=0)&&((a%60)/10!=0))
           {
           cout<<(a/60)<<":"<<(a%60)<<endl;
            return ;}
           if((a/60)/10==0&&(a%60)/10==0)
           {cout<<"0"<<(a/60)<<":0"<<(a%60)<<endl;
            return ;}
           else
           {
               if((a/60)/10==0)
               {
                   cout<<"0"<<(a/60)<<":"<<(a%60)<<endl;
               }
               else
               {
                   cout<<(a/60)<<":0"<<(a%60)<<endl;
               }
           }
}
int main()
{
    int n;
    cin>>n;
    int g1=0,g2=0,ls=0,lm=0,min=0,sec=0,a=0,b=0;
    for(int i=0;i<n;i++)
    {
            int t;
            string s;
            stringstream out1,out2;
            cin>>t>>s;
            //cout<<endl<<t<<s;
            out1<<s[0]<<s[1];
            out2<<s[3]<<s[4];
            out1>>min;
            out2>>sec;
            if(t==1)
            {
                    if(g1>g2)
                    {
                             a+=(min-lm)*60+(sec-ls);
                    }
                    if(g2>g1)
                    {
                             b+=(min-lm)*60+(sec-ls);
                    }
                    g1++;
                    lm=min;
                    ls=sec;
            }
            else
            {
                    if(g1>g2)
                    {
                             a+=(min-lm)*60+(sec-ls);
                    }
                    if(g2>g1)
                    {
                             b+=(min-lm)*60+(sec-ls);
                    }
                    g2++;
                    lm=min;
                    ls=sec;
            }
            
    }
           if(g1>g2)
           {
                a+=(48-lm)*60+(0-ls);
           }
           if(g2>g1)
           {
                 b+=(48-lm)*60+(0-ls);
           }
           //cout<<"\na : "<<a<<"\nb : "<<b;
           display(a);
           display(b);
           
           
           
    /*stringstream out1;
    string s;
    min=a/60;
    out1<<min/10;
    out1>>s[0];
    out1<<min%10;
    out1>>s[1];
    s[2]=':';
    sec=a%60;
    out1<<sec/10;
    out1>>s[3];
    out1<<sec%10;
    out1>>s[4];
    cout<<s<<endl;
    
    min=b/60;
    out1<<min/10;
    out1>>s[0];
    out1<<min%10;
    out1>>s[1];
    s[2]=':';
    sec=b%60;
    out1<<sec/10;
    out1>>s[3];
    out1<<sec%10;
    out1>>s[4];
    cout<<s;*/
            
    getch();
    return 0;
}
            
    
