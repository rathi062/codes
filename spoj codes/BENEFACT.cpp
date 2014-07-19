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
#define MX 50004
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
struct node{
	int d,v;
};
typedef struct node node;
vector<node> v[MX];
bool check[MX];
int ver[MX];
int BFS(int s,int n)
{
	CLR(ver);
	CLR(check);	
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int idx = q.front();
		//cout<<"\nidx = "<<idx;
		q.pop();
		if(check[idx]==1)
		continue;	
		int sz = v[idx].size();
		for(int i=0;i<sz;i++)
		{
			int d =v[idx][i].d;
			int w =v[idx][i].v;
			if(check[d]==0&&ver[d]<ver[idx]+w)
			{
				ver[d]=ver[idx]+w;
				q.push(d);
			}
		}
		check[idx]=1;
	}
	int mx=0,in=1;
	for(int i=1;i<=n;i++)
	{
		if(mx<ver[i])
		{
			mx=ver[i];
			in=i;
		}
	}
	//cout<<"\nv = "<<ver[in];
	return int(max_element(v+1,v+n+1)-v);
}
int main()
{
	int t,n,a,b,l;
	inp(t);
	while(t--)
	{
		CLR(v);
		LL mx=0;
		node temp;
		inp(n);
		for(int i=0;i<n-1;i++)
		{
			inp(a);
			inp(b);
			inp(temp.v);
			temp.d=a;
			v[b].push_back(temp);
			temp.d=b;
			v[a].push_back(temp);
		}
		int fst=BFS(1,n);
		//cout<<"\nfst = "<<fst;
		int scnd=BFS(fst,n);
		printf("%d\n",ver[scnd]);
	}
	return 0;
}
