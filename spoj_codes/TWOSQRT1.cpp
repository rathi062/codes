#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
int main()
{
    int t;
    long r;
    long long n;
    cout<<"\nenter the no of test : ";
    cin>>t;
    if(t<=100)
   {
    for(int j=0;j<t;j++)
    {
            int o=0,p=0,q;
            cout<<"\nenter no : ";
            cin>>n;
            int i=0;
            i=sqrt(n);
            cout<<"\ni = "<<i; 
            r=(n-i*i);
            if(r==0)
            cout<<"\nYes";
            else
            {
                q=int(sqrt(r));
                if(r==(q*q))
                cout<<"\nyes";
                else
                {
                    for(int k=i-1;k>=1;k--)
                    {
                            o++;
                            r=(n-k*k);
                            p=int(sqrt(r));
                            if(r==(p*p))
                            {
                             cout<<"\nyes";
                             o=0;
                             break;
                            }
                    }
                }
                if(o!=0)
                cout<<"\nNo";
            }
    }
   }
    getch();
    return 0;
}
