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
#define MX 1003
#define MOD 100000000
#define pii pair<int ,int>
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
vector<int> G[MX];		
int n,flr;
LL ans,ver[MX];
bool  check[MX];
void initial(int n)
{
	for(int i=0;i<=n;i++)
	{
		ver[i]=INF;
		check[i]=0;
	}
}
int dijkstra(int s)
{
	priority_queue<pii , vector<pii> ,greater<pii> > q;
	q.push(pii(0,s));
	int idx=s;
	ver[s]=0;
	while(!q.empty())
	{
		idx=q.top().second;
		int wt=q.top().first;
		//cout<<"\nidx = "<<idx<<" wt = "<<wt;
		q.pop();
		if(idx==flr)
		return ver[flr];
		if(check[idx]==1)
		continue;
		check[idx]=1;
		int sz = G[idx].size(),cur,pos,tm;
		//cout<<"\n sz = "<<sz;
		for(int i=0;i<sz;i++)
		{
			cur=0;
			int d =G[idx][i];
			if(check[d]==0)
			{
				int diff=d-idx;
				if(diff<0)
				{	
					cur=1;
					diff*=-1;
				}
				int round=wt/diff;
				int xtra = wt%diff;
				if(xtra==0)	
				{
					if(round%2==1)
					pos=1;
					else
					pos=0;
					tm=wt;
				}
				else
				{
					if(round%2==1)
					pos=0;
					else
					pos=1;
					tm=round*diff+diff;
				}
				if(cur!=pos)
				tm+=diff;
				//cout<<"\n d = "<<d<<" tm = "<<tm<<" cur = "<<cur<<" pos = "<<pos;
				
				if(ver[d]>tm+diff)
				{
					ver[d]=tm+diff;
					q.push(pii(ver[d],d));
				}
			}
		}
	}
	return INF;
}
int main()
{
    int sr,ds;
    inp(flr);
    inp(n);
		for(int i=0;i<n;i++)
    	{
    		inp(sr);
    		inp(ds);
    		G[sr].push_back(ds);
    		G[ds].push_back(sr);
    	}
    	initial(flr);
    	ans=dijkstra(1);
		printf("%lld\n",ans*5);
    	
    return 0;
}
