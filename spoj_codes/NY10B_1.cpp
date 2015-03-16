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
            int ba=0,a=0,b=0,ar1[100],ar2[100],j=-1;
            cin>>ba>>a>>b;
            while(a!=0||b!=0)
            {
                             ++j;
                             ar1[j]=a%ba;
                             ar2[j]=b%ba;
                             a=a/ba;
                             b=b/ba;
                            
            }
            //cout<<endl;
            for(int k=0;k<=j;k++)
            {
                    ar1[k]=(ar1[k]+ar2[k])%ba;
                    //cout<<ar1[k];
            }
            a=0;
            for(int k=0;k<=j;k++)
            a+=ar1[k]*pow(ba,k);
            cout<<a<<endl;   
    }
    getch();
    return 0;
}
                    
