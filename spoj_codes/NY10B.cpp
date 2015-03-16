#include<iostream>
#include<conio.h>
#include<sstream>
#include<math.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            
            string s,d;
            int ba=0,a=0,b=0;
            cin>>ba>>a>>b;
            stringstream out,out1,sz;
            while(a!=0||b!=0)
            {
                             out<<a%ba;
                             out1<<b%ba;
                             cout<<"\nout is : "<<a%ba;
                             cout<<"\nout1 is : "<<b%ba;
                             
                             a=a/ba;
                             b=b/ba;
            }
            out>>s;
            out1>>d;
            cout<<endl;
            cout<<s<<endl<<d;
            /*for(int j=s.size()-1;j>=0;j--)
            cout<<s[j];
            for(int j=d.size()-1;j>=0;j--)
            cout<<d[j];*/
            for(int j=0;j<s.size();j++)
            {
                    stringstream sm,sm1,sm2;
                    int n=0,m=0;
                    
                    sm<<s[j];
                    sm1<<d[j];
                    sm>>n;
                    sm1>>m;
                    sm2<<(m+n)%ba;
                    sm2>>s[j];
            }
            a=0;
            cout<<endl<<s;
            cout<<"\nsize of string is : "<<s.size();
            sz<<ba;
            sz>>d;
            cout<<"\nsize of base is : "<<d.size();
            for(int j=s.size();j>=0;)
            {
                    stringstream sum;
                    //for(int k=0;k<d.size();k++)
                    sum<<s[j--];
                    sum>>b;
                    a+=b*pow(ba,j);
            }
            cout<<a<<endl;
    }    
    getch();
    return 0;
}
