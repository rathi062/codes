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
#define MX 1010
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
LL dp[2][MX];
int h[MX],w[MX],n;
int fun(void)
{
	dp[0][0]=w[0];
	dp[1][0]=h[0];
	for(int i=1;i<n;i++)
	{
		dp[0][i]=max(abs(h[i]-h[i-1])+w[i]+dp[0][i-1],abs(h[i]-w[i-1])+w[i]+dp[1][i-1]);
		dp[1][i]=max(abs(w[i]-h[i-1])+h[i]+dp[0][i-1],abs(w[i]-w[i-1])+h[i]+dp[1][i-1]);
	}
	return max(dp[0][n-1],dp[1][n-1]);
}

int main()
{
    inp(n);
    for(int i=0;i<n;i++)
    {
    	inp(h[i]);
    	inp(w[i]);
    }
    int ans=fun();
    printf("%d\n",ans);
    return 0;
}
