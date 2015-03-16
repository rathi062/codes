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
#define MX 102
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
struct topo_sort{
	int in,fin,str;
}lst[10000];
bool check[MX],inlist[MX];
vector<int> grf[MX],ans;
set<int> q;
int ver[MX], per[MX],st[MX],f[MX],v,e,s,d,tm,idx,r,sr;

void DFS()
{
	int u,v,sz;
	while(!q.empty())
	{
		u=*q.begin();
		q.erase(u);
		printf("%d ",u);
		ans.push_back(u);
		sz=grf[u].size();
		for(int i=0;i<sz;i++)
		{
			ver[grf[u][i]]--;
			if(!ver[grf[u][i]])
			q.insert(grf[u][i]);
		}
	}
}
int comp(const int a,const int b)
{
	return a>b;
}
int main()
{
	inp(v);
	inp(r);
	CLR(ver);
	for(int i=0;i<r;i++)
	{
		inp(sr);
		inp(e);
		for(int i=0;i<e;i++)
		{
			inp(d);
			grf[d].push_back(sr);
		}
		ver[sr]=e;
	}
	for(int i=1;i<=v;i++)
	{
		if(!ver[i])
		q.insert(i);
		sort(grf[i].begin(),grf[i].end());
	}
	s=1;	
	DFS();
	return 0;
}

