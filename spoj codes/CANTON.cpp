#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int t=0,n=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int r=0,m=0;
            cin>>n;
            r=(-1+sqrt(1+8*n))/2;
            if(r*(r+1)/2==n)
            {
                            if(r%2==0)
                            {
                                      cout<<"TERM "<<n<<" IS "<<r<<"/1"<<endl;
                            }
                            else
                            {
                                cout<<"TERM "<<n<<" IS "<<"1/"<<r<<endl;
                            }
            }
            else
            {
                m=n-(r*(r+1)/2);
                if(r%2==0)
                {
                          cout<<"TERM "<<n<<" IS "<<(r-m+2)<<"/"<<m<<endl;
                }
                else
                {
                    cout<<"TERM "<<n<<" IS "<<m<<"/"<<(r-m+2)<<endl;
                }
            }
    }
    getch();
    return 0;
}
