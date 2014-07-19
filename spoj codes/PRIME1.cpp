#include<iostream>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
map <long long ,bool> v;
int main()
{
   int t,ts,n=0;
   cin>>t;
   ts=t;
   int a,b,k=0,max=0;
   
   while(t--)
   {
       cin>>a>>b;
       v[1]=true;
       v[0]=true;
       for(int i=2;i<sqrt(b)+1;i++)
       {
          if(v[i]==false)
          {
            long long strt=0;
            if(i*i<(a/i)*i)
            strt=(a/i)*i;
            else
            strt=i*i;
            for(int j=strt;j<=b;j+=i)
                  v[j]=true;
          }
       }
      for(int i=a;i<=b;i++)
      if(v[i]==false)
      cout<<i<<endl;
      cout<<endl;
    }
    return 0;
}

