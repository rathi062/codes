#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            string a,b,c,d,f,k="macula";
            cin>>a>>b>>c>>d>>f;
            size_t found;
            int x=0,y=0;
            stringstream out1,out2,out3;
            found=a.find_first_of(k);
            if(found!=string::npos)
            {
               out1<<c;
               out2<<f;
               out1>>x;
               out2>>y;
               out3<<(y-x);
               out3>>a;
               cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<f;
            }
            else
            {
                found=c.find_first_of(k);
                if(found!=string::npos)
                {
                   out1<<a;
                   out2<<f;
                   out1>>x;
                   out2>>y;
                   out3<<(y-x);
                   out3>>c;
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<f;
                }
                else
                {
                    found=f.find_first_of(k);
                    if(found!=string::npos)
                    {
                        out1<<c;
                        out2<<a;
                        out1>>x;
                        out2>>y;
                        out3<<(y+x);
                        out3>>f;
                        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<f;
                    }
                }
            }
    cout<<endl;
    }
    getch();
    return 0;
}
            
