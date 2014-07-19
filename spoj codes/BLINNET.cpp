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
#define pii pair<int ,int >
#define F first
#define S second

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
vector<pii> grf[MX];
bool check[MX];
void initial(int n)
{
	for(int i=0;i<=n;i++)
	{
		check[i]=0;
		grf[i].clear();
	}
}
int prims(int i)
{
	int sum=0;
	priority_queue <pii, vector<pii> , greater<pii> > q;
	q.push(pii(0,i));
	while(!q.empty())
	{
		
		int idx=q.top().S;
		int wt =q.top().F;
		q.pop();
		//cout<<"\nidx = "<<idx;
		if(check[idx]==1)
		continue;
		sum+=wt;
		check[idx]=1;
		int sz=grf[idx].size();
		for(int i=0;i<sz;i++)
		{
			int d=grf[idx][i].S;
			int w=grf[idx][i].F;
			if(check[d]==0)
			{
				q.push(pii(w,d));
			}
		}
	}
	return sum;
}
int main()
{
	int t;
	char  nm[20];
	inp(t);
	while(t--)
	{
		int v,e,s,d,cnt=0,w;
		inp(v);
		initial(v);
		for(int k=1;k<=v;k++)
		{
			cin>>nm;
			inp(e);
			for(int i=0;i<e;i++)
			{
				inp(d);
				inp(w);
				grf[k].PB(pii(w,d));
			}
		}
		int ans=prims(1);
		printf("%d\n",ans);
	}
	return 0;
}
