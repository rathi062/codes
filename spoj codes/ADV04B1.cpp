#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int n=0,t=0;
    cin>>t;
    for(int j=0;j<t;j++)
    {
     long long a=1,sm=1,num=1;
      
     cin>>n;
     if(n==1)
     cout<<1<<endl;
     else
     if(n==2)
     cout<<3<<endl;
     else
     {
      for(int i=1;i<=n;i++)
      {
            if(a*2<=(n-1))
            {
                          a=a*2;
            }
            else
            break;
            //sm=(sm*2)%1000003;
      }
      while(1)
      {
              if(n>=30)
              {
                      sm=num*(long (pow(2,30))%1000003);
                      num=(sm%1000003);
                      n=n-30;
              }
              else
              {
                      sm=num*long(pow(2,n));
                      num=(sm%1000003);
                      break;
              }
      }
      cout<<(2*(sm-a)+1)%1000003<<endl;
     }
    }
    getch();
    return 0;
}
    
