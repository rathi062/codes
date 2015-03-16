#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>

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
#define MX 100005
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

void DFS(int i)
{
	if(ch[i])
	return ;
	ch[i]=1;
	int sz=G[i].size();
	for(int x=0;x<sz;x++)
	DFS(G[i][x]);
}
int main()
{
	int t,cnt=0,n,e,u,v;
	inp(t);
	while(t--)
	{
		CLR(ch);
		CLR(G);
		inp(n);
		inp(e);
		for(int i=0;i<e;i++)
		{
			inp(u);
			inp(v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cnt=0;
		for(int i=0;i<n;i++)
		{
			if(ch[i]==0)
			{
				DFS(i);
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
