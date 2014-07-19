#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
/*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/


using namespace std;
int a[1025][1025],bit[1025][1025];

void update(int i,int j,int m,int n,int val)
{
     int idx=j;
     while(i<=m)
     {
         idx=j;
         while(idx<=n)
         {
             bit[i][idx]+=val;
             idx+=(idx&(-idx));
         }
         i+=(i&(-i));
     }
}
int find(int i,int j)
{
    int sum=0,idx=j;
    while(i>0)
    {
        idx=j;   
        while(idx>0)
        {
            sum+=bit[i][idx];
            idx-=(idx&(-idx));
        }
        i-=(i&(-i));
    }
    return sum;
}
int main()
{
    int t=0,cnt=1;
    inp(t);
    while(t--)
    {
         int m,n,k,idx,x,y,val;
		 LL sum=0;
         CLR(a);
         CLR(bit);
         inp(m);
         inp(n);
         inp(k);
         for(int i=1;i<=k;i++)
         {
               inp(x);
               inp(y);
               update(x,n-y+1,m,n,1);
               sum+=find(x-1,n-y);
               /*cout<<endl;
               for(int p=1;p<=m;p++)
               {
               	  for(int q=1;q<=n;q++)
               	  cout<<bit[p][q]<<" ";
               	  cout<<endl;
               }
               cout<<"\nsum = "<<sum;*/
         }
         printf("Test case %d: %lld\n",cnt++,sum);
    }
    return 0;
}
