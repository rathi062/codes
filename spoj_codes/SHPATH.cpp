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
#define MX 10004
#define MOD 1000000007
#define pii pair<int,int>
#define psi pair<string ,int>

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
bool check[MX];
vector<pair<int,int> > wgt[MX];
int ver[MX],ds;
priority_queue<pii , vector<pii> ,greater<pii> > q;
map<string,int> m;
void initial(int n)
{
	for(int i=1;i<=n;i++)
	ver[i]=INF;
}

void dijkstra(int s,int n)
{
	while(!q.empty()) q.pop();
	q.push(pii(0,s));
	ver[s]=0;
	while(!q.empty())
	{
		int idx=q.top().second;
		int wt=q.top().first;
		q.pop();
		if(check[idx]==1)
		continue;		
		int sz = wgt[idx].size();
		for(int i=0;i<sz;i++)
		{
			int d =wgt[idx][i].first,w=wgt[idx][i].second;
			{
				if(check[d]==0&&ver[d]>ver[idx]+w)
				{
					ver[d]=ver[idx]+w;
					q.push(pii(ver[d],d));
				}
			}
		}
		check[idx]=1;
		if(idx==ds)
		break;
	}
}
int main()
{
	int t,v,e,s,d,wt,c,sr,q;
	string nm;
	inp(t);
	while(t--)
	{
		CLR(wgt);
		m.clear();
		inp(v);
		for(int ii=1;ii<=v;ii++)
		{
			cin>>nm;
			m.insert(pair<string,int>(nm,ii));
			inp(e);
			for(int i=0;i<e;i++)
			{
				inp(d);
				inp(wt);
				wgt[ii].push_back(pair<int,int>(d,wt));
			}
		}
		inp(q);
		for(int i=0;i<q;i++)
		{
			cin>>nm;
			sr=m[nm];
			cin>>nm;
			ds=m[nm];
			CLR(check);
			CLR(ver);
			initial(v);
			dijkstra(sr,v);
			printf("%d\n",ver[ds]);
		}
	}
	return 0;
}
