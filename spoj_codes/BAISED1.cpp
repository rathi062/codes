#include<iostream>
  #include<vector>
  #include<set>
  #include<map>
  #include<queue>
  #include<stack>
  #include<string>
  #include<algorithm>
  #include<functional>
  #include<iomanip>
  #include<cstdio>
  #include<cmath>
  #include<cstring>
  #include<cstdlib>
  #include<cassert>
#define R return
#define FR(i,a,b) for(int i=a;i<b;i++)
#define IN(i,j) a[i][j]
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define inp(x) scanf("%d",&x)
#define getcx getchar_unlocked
using namespace std;
 /*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/
long long gcd(long long a,long long b)
{
   if(b!=0)
   return gcd(b,a%b);
   else
   return a;
}
long long lcm(long long a,long long b)
{
   return (a/gcd(a,b))*b;
}
int main()
{
    int t,n;
    inp(t);
    while(t--)
    {
          inp(n);
          int a[n],r[n+1],rm=0,ex=0,sum=0;
          FR(i,0,n+1)
          r[i]=0;
          string s[n];
          FR(i,0,n)
          {
             cin>>s[i];
             inp(a[i]);
             r[a[i]]++;
          }
          FR(i,1,n+1)
          {
              sum+=rm+ex;
              if(r[i]==1)
              {
                  continue;
              }
              else
              if(r[i]==0)
              {
                   if(ex==0)
                      rm++;
                   else
                       ex--;
              }
              else
              {
                       if(rm>=r[i]-1)
                       {
                           rm-=(r[i]-1);
                           r[i]=1;
                       }
                       else
                       {
                           ex+=r[i]-1-rm;
                           rm=0;
                       }
              }
          }
          printf("%d\n",sum);
    }
    system("pause");
    return 0;
}
