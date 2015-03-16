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
#define MX 10004
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
bool check[MX];
vector<int> wgt[MX];
int ver[MX], per[MX];
void initial(int n)
{
	for(int i=1;i<=n;i++)
	ver[i]=INF;
}

bool BFS(int s,int n)
{
	ver[s]=0;
	per[s]=0;
	check[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int idx = q.front();
		q.pop();
		int l=wgt[idx].size();
		//cout<<"\nidx = "<<idx<<" l = "<<l;
		for(int i=0;i<l;i++)
		{
			int in=wgt[idx][i];
			//cout<<"\n in = "<<in;
			if(check[in]==0)
			{
				check[in]=1;
				q.push(in);
			}
		}
	}
	for(int i=1;i<=n;i++)
	if(!check[i])
	return 0;
	return 1;
}
int main()
{
	int v,e,s,d;
	inp(v);
	inp(e);
	if(v-1!=e)
	{
		printf("NO\n");
		return 0;
	}
	//initial(v);
	for(int i=0;i<e;i++)
	{
		inp(s);
		inp(d);
		wgt[d].push_back(s);
		wgt[s].push_back(d);
	}
	if(BFS(1,v))
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
