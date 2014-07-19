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
#define MX 105
#define MOD 1000000007
#define pii pair<int,int>
#define pip pair<int,pair<int,int> >
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
bool check[MX];
int dx[8]={-2,-2,-1,1,2,2,-1,1};
int dy[8]={1,-1,2,2,-1,1,-2,-2};
int wgt[MX][MX];
int a,b,c,d,ret,ans;
void initial()
{
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	wgt[i][j]=INF;
}

void BFS()
{
	priority_queue<pip> q;
	int u,v,ct;
	q.push(pip(0,pii(a,b)));
	//wgt[a][b]=0;
	while(!q.empty())
	{
		pip n=q.top();
		q.pop();
		int wt=n.F;
		int x=n.S.F , y=n.S.S;
		
		//cout<<"\nx = "<<x<<" y = "<<y<<" wt = "<<wt;
		if( wt>=wgt[x][y] || wt>wgt[c][d])
		continue;
		wgt[x][y]=wt;
		for(int i=0;i<8;i++)
		{
			//cout<<"\nin loop ";
			u=x+dx[i];
			v=y+dy[i];
			ct=wgt[x][y]+x*u+y*v;
			if(u<0 || u>7 || v<0 || v>7 || wgt[u][v]<ct ||  wgt[c][d]<ct)
			continue ;
			q.push(pip(ct,pii(u,v)));
		}
	}
}
int main()
{
	
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
	{
		initial();
		ans=INF;
		BFS();
		printf("%d\n",wgt[c][d]);
	}
}
