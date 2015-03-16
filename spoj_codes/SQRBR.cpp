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
#define MX 40
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
bool ch[MX][MX];
int dp[MX][MX],a[MX],n,k;
int fun(int cnt,int idx,int i)
{
	//cout<<"\ncnt = "<<cnt<<" idx = "<<idx<<" i = "<<i;
	if(idx==n+1)
	{
		if(cnt==0)
		return 1;
		else
		return 0;
	}
	if(ch[idx][cnt]==1)
	return dp[idx][cnt];
	ch[idx][cnt]=1;
	if(idx==a[i])
	{
		dp[idx][cnt]=fun(cnt+1,idx+1,i+1);
		return dp[idx][cnt];
	}
	dp[idx][cnt]=fun(cnt+1,idx+1,i);
	if(cnt>=1)
	dp[idx][cnt]+=fun(cnt-1,idx+1,i);
	return dp[idx][cnt];
}

int main()
{
	int t;
    inp(t);
    while(t--)
    {
    	inp(n);
    	inp(k);
    	n=2*n;
    	a[0]=0;
    	for(int i=1;i<=k;i++)
    	inp(a[i]);
    	CLR(dp);
    	CLR(ch);
    	int ans=fun(0,1,1);
    	/*for(int i=0;i<n;i++)
    	{
    		for(int j=1;j<=n;j++)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}*/
    	printf("%d\n",ans);
    }
	return 0;
}
