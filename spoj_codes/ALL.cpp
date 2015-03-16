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
int n1,n2,d,cnt[MX],cnt1[MX];
vector<int> grf[MX];
queue<int> q1[2],q2[2];
int DFS()
{
	int u,v,sz,idx=0,mn=INF,chng=1;
	while(!(q1[0].empty()&&q1[1].empty()))
	{
		while(!q1[idx].empty())
		{
			u=q1[idx].front();
			q1[idx].pop();
			sz=grf[u].size();
			for(int i=0;i<sz;i++)
			{
				v=grf[u][i];
				cnt[v]--;
				if(!cnt[v])
				{
					if(v<=n1)
					q1[0].push(v);
					else
					q1[1].push(v);
				}
			}
		}
		idx=idx^1;
		chng++;
	}
	if(mn>chng)
	mn=chng;
	
	idx=1;
	chng=1;
	while(!(q2[0].empty()&&q2[1].empty()))
	{
		while(!q2[idx].empty())
		{
			u=q2[idx].front();
			q2[idx].pop();
			sz=grf[u].size();
			for(int i=0;i<sz;i++)
			{
				v=grf[u][i];
				cnt1[v]--;
				if(!cnt[v])
				{
					if(v<=n1)
					q2[0].push(v);
					else
					q2[1].push(v);
				}
			}
		}
		idx=idx^1;
		chng++;
	}
	if(mn>chng)
	mn=chng;
	return mn;
}
void initial(int n)
{
	for(int i=0;i<=n;i++)
	{
		cnt[i]=0;
		grf[i].clear();
	}
}
int main()
{
	inp(n1);
	inp(n2);
	inp(d);
	while(n1|n2|d)
	{
		initial(n1+n2);
		int u,v;
		for(int i=0;i<d;i++)
		{
			inp(u);
			inp(v);
			grf[v].PB(u);
			cnt[u]++;
			cnt1[u]++;
		}
		for(int i=1;i<=n1;i++)
		{
			if(!cnt[i])
			q1[0].push(i);
			q2[0].push(i);
		}
		for(int i=n1+1;i<=n1+n2;i++)
		{
			if(!cnt[i])
			q1[1].push(i);
			q2[1].push(i);
		}
		printf("%d\n",DFS());
		inp(n1);
		inp(n2);
		inp(d);
	}
	return 0;
}

