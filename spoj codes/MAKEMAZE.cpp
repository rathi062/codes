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
#define MX 21
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
bool check[MX][MX],eds[MX][MX];
char grf[MX][MX];
int wgt[MX][MX],ver[MX], per[MX],dsx,dsy;

int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
void initial(int n)
{
	for(int i=1;i<=n;i++)
	ver[i]=INF;
}

bool BFS(int xx,int yy,int m,int n)
{
	CLR(check);
	check[xx][yy]=1;
	queue<pii> q;
	q.push(pii(xx,yy));
	while(!q.empty())
	{
		pii idx = q.front();
		int u=idx.first , v=idx.second;
		//cout<<"\nu = "<<u<<" v = "<<v;
		q.pop();
		if(u==dsx&&v==dsy)
		return true;
		for(int i=0;i<4;i++)
		{
			if( u+x[i]>=0&&u+x[i]<m && v+y[i]>=0&&v+y[i]<n && check[u+x[i]][v+y[i]]==0 && grf[u+x[i]][v+y[i]]=='.')
			{
				check[u+x[i]][v+y[i]]=1;
				q.push(pii(u+x[i],v+y[i]));
			}
		}
	}
	return false;
}
int main()
{
	int t,m,n,x,y;
	inp(t);
	while(t--)
	{
		inp(m);
		inp(n);
		CLR(eds);
		CLR(grf);
		queue<pii> pnts;
		int cnt=0;
		for(int i =0;i<m;i++)
		scanf("%s",&grf[i]);
		for(int i=0;i<n;i++)
		if(!eds[0][i]&&grf[0][i]=='.')
		{	
			cnt++;
			pnts.push(pii(0,i));
			eds[0][i]=1;
		}
		for(int i=0;i<n;i++)
		if(!eds[m-1][i]&&grf[m-1][i]=='.')
		{	
			cnt++;
			pnts.push(pii(m-1,i));
			eds[m-1][i]=1;
		}
		for(int i=0;i<m;i++)
		if(!eds[i][0]&&grf[i][0]=='.')
		{	
			pnts.push(pii(i,0));
			cnt++;
			eds[i][0]=1;
		}
		for(int i=0;i<m;i++)
		if(!eds[i][n-1]&&grf[i][n-1]=='.')
		{	
			pnts.push(pii(i,n-1));
			cnt++;
			eds[i][n-1]=1;
		}
		if(cnt!=2)
		printf("invalid\n");
		else
		{
			pii st=pnts.front();
			pnts.pop();
			pii ed=pnts.front();
			pnts.pop();
			dsx=ed.first;
			dsy=ed.second;
			if(BFS(st.first,st.second,m,n))
			printf("valid\n");
			else
			printf("invalid\n");
		}
	}
}
