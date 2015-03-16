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
#define MX 100005
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

map<string,int> m;

void initial(int n)
{
	for(int i=1;i<=n;i++)
	ver[i]=INF;
}

int main()
{
	int t,v,e,s,d,wt,c,sr,q;
	char nm[21];
	inp(t);
	while(t--)
	{
		CLR(wgt);
		m.clear();
		inp(v);
		inp(e);
		inp(sr);
		inp(ds);
		for(int ii=1;ii<=e;ii++)
		{
			inp(s);
			inp(d);
			inp(wt);
			wgt[s].push_back(pair<int,int>(d,wt));
			wgt[d].push_back(pair<int,int>(s,wt));
		}
		
			CLR(check);
			initial(v);
			priority_queue<pii , vector<pii> ,greater<pii> > q;
			q.push(pii(0,sr));
			ver[sr]=0;
			while(!q.empty())
			{
				int idx=q.top().second;
				q.pop();
				if(check[idx]==1)
				continue;		
				int sz = wgt[idx].size();
				for(int i=0;i<sz;i++)
				{
					int d =wgt[idx][i].first;
					int w =wgt[idx][i].second;
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
			if(ver[ds]>500000000)
			printf("NONE\n");
			else
			printf("%d\n",ver[ds]);
		
	}
	return 0;
}
