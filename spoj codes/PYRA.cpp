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
#define inpd(x) scanf("%lf",&x)
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
bool ch[MX];
vector<int> G[MX];
struct node{
	int sum,len;
};
node DFS(int u)
{
	int cnt=0,sz,sum=0,v,l=0;
	sz=G[u].size();
	ch[u]=1;
	node ret,cl;
	for(int i=0;i<sz;i++)
	{
		v=G[u][i];
		if(ch[v]==1)
		continue;
		cnt++;
		cl=DFS(v);
		sum+=cl.sum;
		l+=cl.len;
	}
	ret.sum=sum+l+cnt+1;
	ret.len=l+cnt+1;
	//cout<<"\nu = "<<u<<" sum = "<<ret.sum<<" len = "<<ret.len;
	return ret;
}
int main()
{
	int t,n;
	inp(t);
	while(t--)
	{
		int u,v;
		inp(n);
		CLR(ch);
		CLR(G);
		for(int i=0;i<n-1;i++)
		{
			inp(u);
			inp(v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		printf("%d\n",DFS(0));
	}
}
