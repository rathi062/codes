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
                i=int(sqrt(r));
                if(r==(i*i))
                cout<<"\nyes";
                else
                {
                    n=n/2;
                    r=sqrt(n);
                    if(n==r*r)
                    cout<<"\nYes";
                    else
                    cout<<"\nNO";
                }
            }
    }
   }
    getch();
    return 0;
}
