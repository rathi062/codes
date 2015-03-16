#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    while(a!="*")
    {
         int l=0,c=0,s=0;
         l=a.size();
         for(int i=0;i<l;i++)
         {
                 if(a[i]!=b[i])
                 {
                      if(s==0)
                      {
                              c++;
                              s=1;
                      }
                 }
                 else
                 s=0;
         }
         cout<<c<<endl;
         cin>>a>>b;
    }
    getch();
    return 0;
}
                      
