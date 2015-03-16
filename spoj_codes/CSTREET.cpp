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
#define MX 105
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
struct kru{
	int s,d,wt;
}node[MX];
bool check[MX];
int cls[MX];
vector<int> subset[MX];

void initial(int n)
{
	for(int i=1;i<=n;i++)
	{
		cls[i]=i;
		subset[i].push_back(i);
	}
}
int kruskal(int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(cls[node[i].s]!=cls[node[i].d])
		{
			//cout<<"\ns = "<<node[i].s<<" d = "<<node[i].d;
			int ss=cls[node[i].s],ds=cls[node[i].d];
			int sz=subset[ss].size();
			for(int j=0;j<sz;j++)
			{
				cls[subset[ss][j]]= ds;
				subset[ds].push_back(subset[ss][j]);
			}
			subset[ss].clear();
			sum+=node[i].wt;
		}
	}
	return sum;
}
int compare(const kru a,const kru b)
{
	return a.wt<b.wt;
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		CLR(cls);
		CLR(check);
		CLR(subset);
		int p,v,e,s,d;
		inp(p);
		inp(v);
		initial(v);
		inp(e);
		for(int i=0;i<e;i++)
		{
			inp(node[i].s);
			inp(node[i].d);
			inp(node[i].wt);
		}
		sort(node,node+e,compare);
		printf("%d\n",kruskal(e)*p);
	}
}
