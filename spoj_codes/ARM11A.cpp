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
#define MX 505
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
int a[MX][MX],dp[MX][MX];
int main()
{
    int t=0,cnt=1;
    inp(t);
    while(t--)
    {
         int m,n,k,idx,x,y,val,min=0;
		 LL sum=0;
         CLR(a);
         CLR(dp);
         inp(n);
         inp(m);
         for(int i=1;i<=n;i++)
         {
         	for(int j=1;j<=m;j++)
			   inp(a[i][j]);
			a[i][m+1]=1000000;
		 }
		 for(int i=1;i<m;i++)
		 a[n+1][i]=10000000;
		
		 for(int i=n;i>0;i--)
		 {
		 	for(int j=m;j>0;j--)
		 	{
		 		if(dp[i][j+1]<dp[i+1][j])
		 		dp[i][j]=dp[i][j+1];
		 		else
		 		dp[i][j]=dp[i+1][j];
		 		dp[i][j]+=a[i][j];
		 		if(dp[i][j]<=0)
		 		dp[i][j]=1;
		 	}
		 }	
         /*for(int i=1;i<=n;i++)
         {
         	for(int j=1;j<=m;j++)
         	cout<<dp[i][j]<<" ";
         	cout<<endl;
         }*/
		 printf("%d\n",dp[1][1]);
    }
    return 0;
}
