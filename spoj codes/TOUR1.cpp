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
#define MX 1003
#define MOD 1000000007
#define pii pair<int,int>

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
bool onstack[MX],grpout[MX];
int index[MX],lowlink[MX],idx,grpno[MX],num;
vector<int> G[MX];
vector<pii> edge;
stack<int> s;
void initial(int v)
{
	for(int i=1;i<=v;i++)
	{
		index[i]=-1;
		onstack[i]=1;
		G[i].clear();
		lowlink[i]=0;
		grpout[i]=0;
		grpno[i]=0;
	}
}
void tarjan(int in)
{
	index[in]=idx;
	lowlink[in]=idx;
	onstack[in]=1;
	idx++;
	s.push(in);
	int sz=G[in].size(),n;
	for(int i=0;i<sz;i++)
	{
		n=G[in][i];
		if(index[n]==-1)
		{
			tarjan(n);
			lowlink[in]=min(lowlink[in],lowlink[n]);
		}
		else
		if(onstack[n])
		{
			lowlink[in]=min(lowlink[in],index[n]);
		}
	}
	if(index[in]==lowlink[in])
	{
		num++;
		//cout<<endl;
		do{
			n=s.top();
			//cout<<n<<" ";
			grpno[n]=num;
			s.pop();
			onstack[n]=0;
		}
		while(n!=in);
	}
}
int winner(int v )
{
	//for(int i=1;i<=v;i++)
	//cout<<grpno[i]<<" ";
	for(int i=0;i<edge.size();i++)
	{
		if(grpno[edge[i].first]!=grpno[edge[i].second])
		{
			grpout[grpno[edge[i].second]]=1;
		}
	}
	int cnt=0,grps=num,idx;
	//cout<<"\ngrps = "<<grps;
	for(int i=1;i<=grps;i++)
	{
		if(!grpout[i])
		{
			cnt++;
			if(cnt>1)
			return 0;
			idx=i;
		}
	}
	//cout<<"\ncnt = "<<cnt<<" idx = "<<idx;
	if(cnt!=1)
	return 0;
	cnt=0;
	for(int i=1;i<=v;i++)
	if(grpno[i]==idx)
	cnt++;
	return cnt;
}
int main()
{
	int t=0;
	inp(t);
	while(t--)
	{
		int v,e,s,d;
		inp(v);	
		initial(v);
		edge.clear();
		idx=1;
		for(int i=1;i<=v;i++)
		{
			inp(e);
			for(int j=0;j<e;j++)
			{
				inp(d);
				G[i].PB(d);
				edge.push_back(pii(d,i));
			}
		}
		num=0;
		for(int i=1;i<=v;i++)
		if(index[i]==-1) tarjan(i);
		printf("%d\n",winner(v));
	}
	return 0;
}
