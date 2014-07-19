#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    while(n!=-1)
    {
                int d=0;
                float r=0;
                if(n==1)
                cout<<"Y\n";
                else
                {
                    n=n-1;
                    d=n/6;
                    if((d*6)!=n)
                    cout<<"N\n";
                    else
                    {
                        n=n/6;
                        r=(-1+sqrt(1+8*n))/2;
                        
                        d=r;
                        if(r!=d)
                        r=int(r+1);
                        //cout<<"\nr = "<<r;
                        if(n==(r*(r+1))/2)
                        cout<<"Y\n";
                        else
                        cout<<"N\n";
                    }
                }
                cin>>n;
    }
    getch();
    return 0;
}
