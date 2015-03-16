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
#define MX 10004
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
struct road{
	int d,l,t;
}node[101][MX];
bool ch[111][MX],visit[111];
int dp[110][MX],no,n,k,r,s,ans;
int fun(int i,int m)
{
	if(i==n)
	return 0;
	if(ch[i][m]==1)
	return dp[i][m];
	ch[i][m]=1;
	int mn=100000000,val;
	for(int x=1;x<=node[i][0].l;x++)
	{
		if(visit[node[i][x].d]==0)
		{
			if(m>=node[i][x].t)
			{
				visit[node[i][x].d]=1;
				val=fun(node[i][x].d,m-node[i][x].t)+node[i][x].l;
				visit[node[i][x].d]=0;
				if(val<mn)
				mn=val;
			}
		}
	}
	dp[i][m]=mn;
	return mn;
}

int main()
{
	int t;
    inp(t);
    while(t--)
    {
    	inp(k);
    	inp(n);
    	inp(r);
    	CLR(node);
    	for(int i=0;i<r;i++)
    	{
    		inp(s);
    		node[s][0].l++;
    		inp(node[s][node[s][0].l].d);
    		inp(node[s][node[s][0].l].l);
    		inp(node[s][node[s][0].l].t);
    	}
    	CLR(dp);
    	CLR(ch);
    	visit[1]=1;
    	ans=fun(1,k);
    	if(ans==100000000)
    	printf("-1\n");
    	else
    	printf("%d\n",ans);
    }
    return 0;
}
