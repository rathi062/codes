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

#define INF (1<<30)
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
#define MX 505
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
bool check[MX],block[505][505];
vector<pair<int,int> > wgt[MX];
int sr,ds,len,ver[MX],per[MX];
void initial(int n)
{
	for(int i=0;i<n;i++)
	{
		ver[i]=INF;
		check[i]=0;
		per[i]=0;
	}
}
void initial1(int n)
{
	for(int i=0;i<n;i++)
	check[i]=0;
}
int dijkstra(int s,int n)
{
	priority_queue<pii , vector<pii> ,greater<pii> > q;
	q.push(pii(0,s));
	int idx=s;
	ver[s]=0;
	per[s]=-1;
	while(!q.empty())
	{
		idx=q.top().second;
		int wt=q.top().first;
		q.pop();
		if(idx==ds)
		return ver[ds];
		if(check[idx]==1)
		continue;
		check[idx]=1;
		int sz = wgt[idx].size();
		for(int i=0;i<sz;i++)
		{
			int d =wgt[idx][i].first,w=wgt[idx][i].second;
			if(block[idx][d]==0)
			{
				if(check[d]==0&&ver[d]>ver[idx]+w)
				{
					per[d]=idx;
					ver[d]=ver[idx]+w;
					q.push(pii(ver[d],d));
				}
			}
		}
	}
	return INF;
}
int main()
{
	int n,m;
	inp(n);
	inp(m);
	while(n!=0&&m!=0)
	{
		int v,e,s,d,wt;
		
		inp(sr);
		inp(ds);
		for(int i=0;i<n;i++)
		wgt[i].clear();
		for(int i=0;i<m;i++)
		{
			inp(s);
			inp(d);
			inp(wt);
			wgt[s].push_back(pair<int,int>(d,wt));
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		block[i][j]=0;
		initial(n);
		int cnt=1,mn=0;
		while(1)
		{
			len=dijkstra(sr,n);
			if(cnt==1)
			{
				cnt++;
				mn=len;
				if(len==INF)
				break;
			}
			else
			if(len>mn)
			break;
			int in=ds;
			while(1)
			{
				block[per[in]][in]=1;
					in=per[in];
				if(in==sr)
				break;
			}
			initial(n);
		}
		
		if(len==INF)
		printf("-1\n");
		else
		printf("%d\n",len);
		inp(n);
		inp(m);
	}
	return 0;
}