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
#define cls(a) memset(a,-1,sizeof(a))
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
#define MX 1000006
#define MOD 1000000007
#define pii pair<int,int>
#define psi pair<string,int>

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
bool check[MX],check1[MX];
vector<pair<int,int> > wgt[MX],wgt1[MX];
int ver[MX], per[MX];
int n,m,k,s,t,sr,ds,wt,ans;
void initial(int n)
{
	for(int i=1;i<=n;i++)
	{
		wgt[i].clear();
		wgt1[i].clear();
		ver[i]=INF;
		per[i]=INF;
		check[i]=0;
		check1[i]=0;
	}
}
void dijkstra(int st,vector<pii> *wgtt,int *fer,bool *checkk)
{
	priority_queue<pii , vector<pii> ,greater<pii> > q;
	q.push(pii(0,st));
	int idx=st;
	fer[st]=0;
	while(!q.empty())
	{
		idx=q.top().second;
		q.pop();
		if(checkk[idx]==1)
		continue;
	
		int sz = wgtt[idx].size();
		for(int i=0;i<sz;i++)
		{
			int d =wgtt[idx][i].first,w=wgtt[idx][i].second;
			{
				if(checkk[d]==0&&fer[d]>fer[idx]+w)
				{
					fer[d]=fer[idx]+w;
					q.push(pii(fer[d],d));
				}
			}
		}
		checkk[idx]=1;
		//idx=next(n);
	}
}
int main()
{
	int tt;
	inp(tt);
	while(tt--)
	{
	
	inp(n);
	inp(m);
	initial(n);
	for(int i=0;i<m;i++)
	{
		inp(sr);
		inp(ds);
		inp(wt);
		wgt1[ds].push_back(pair<int,int>(sr,wt));
		wgt[sr].push_back(pair<int,int>(ds,wt));
	}
	dijkstra(1,wgt,ver,check);
	dijkstra(1,wgt1,per,check1);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=ver[i]+per[i];
	}
	printf("%d\n",ans);
	}
	return 0;
}

