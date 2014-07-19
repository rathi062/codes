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
#define MX 606
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
int dp[MX][MX],wdt[MX],hgt[MX],n;
int fun(int w,int h)
{
	
	if(ch[w][h]==1)
	return dp[w][h];
	
	ch[w][h]=1;
	dp[w][h]=w*h;
	//cout<<"\nw = "<<w<<" h = "<<h<<" dp[w][h] = "<<dp[w][h];
	for(int i=0;i<n;i++)
	{
		if(wdt[i]<=w&&hgt[i]<=h)
		{
			dp[w][h]=min3((fun(wdt[i],h-hgt[i])+fun(w-wdt[i],h)),(fun(w-wdt[i],hgt[i])+fun(w,h-hgt[i])),dp[w][h]);
			ch[wdt[i]][h-hgt[i]]=1;
			ch[w-wdt[i]][h]=1;
			ch[w-wdt[i]][hgt[i]]=1;
			ch[w][h-hgt[i]]=1;
		}
	}
	//cout<<"\nw = "<<w<<" h = "<<h<<" dp[w][h] = "<<dp[w][h];
	return dp[w][h];
}

int main()
{
	int t,w,h;
    inp(t);
    while(t--)
    {
    	inp(w);
    	inp(h);
    	inp(n);
    	for(int i=0;i<n;i++)
    	{
    		inp(wdt[i]);
    		inp(hgt[i]);
		}
    	CLR(dp);
    	CLR(ch);
    	int ans=fun(w,h);
    	/*for(int i=0;i<=w;i++)
    	{
    		for(int j=0;j<=h;j++)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}*/
    	printf("%d\n",ans);
    }
	return 0;
}
