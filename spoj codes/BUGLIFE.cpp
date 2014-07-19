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
#define MX 2003
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
vector<int> wgt[MX];
int  color[MX];

bool BFS(int s,int n)
{
	color[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int idx = q.front();
		q.pop();
		int sz=wgt[idx].size();
		for(int i=0;i<sz;i++)
		{
			if(color[wgt[idx][i]]==color[idx])
			return false;
			if(!color[wgt[idx][i]])
			{
				color[wgt[idx][i]]=3-color[idx];
				q.push(wgt[idx][i]);
			}
		}
	}
	return true;
}
int main()
{
	int t,cnt=1;
	inp(t);
	while(t--)
	{
		CLR(wgt);
		int v,e,s,d;
		inp(v);
		inp(e);
		for(int i=0;i<e;i++)
		{
			inp(s);
			inp(d);
			wgt[s].push_back(d);
			wgt[d].push_back(s);
		}
		int i;
		for( i=1;i<=v;i++)
		{
			if(!color[i])
			{
				if(BFS(i,v)) continue;
				else break;
			}
		}
		
		printf("Scenario #%d:\n",cnt++);
		if(i>v)printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");
	}
	return 0;
}
