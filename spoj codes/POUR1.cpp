#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int t=0,a=0,b=0,c=0,min=0,max=0,sum=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int s=0,s1=100000,s2=100000;
            cin>>a>>b>>c;
            if((c>a&&c>b)||(c<a&&c<b))
            cout<<"-1"<<endl;
            else
            {
              if(a>b)
              {  
                     max=a;
                     min=b;
              }
              else
              {
                  max=b;
                  min=a;
              }
              if(c%min==0)
              {
                          s=1;
                            s1=(c*2)/min;
              }
              if((max-c)%min==0)
              {
                                s=1;
                       s2=(max-c)*2/min;
              }
              if(s==1)
              {
               if(s1>s2)
               cout<<s2<<endl;
               else
               cout<<s1<<endl;
              }
            }
    }
    getch();
    return 0;
}
