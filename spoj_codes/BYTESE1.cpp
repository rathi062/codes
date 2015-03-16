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
#define pii pair<int,int>
#define psi pair<string ,int>
#define pip pair<int,pii>

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
bool check[MX][MX];
int ver[MX][MX],grf[MX][MX];

void initial(int m,int n)
{
	for(int i=0;i<=m;i++)
	for(int j=0;j<=n;j++)
	ver[i][j]=INF;
}
int main()
{
	int t,v,e,s,d,dsx,dsy,tym,m,n;
	inp(t);
	while(t--)
	{
		inp(m);
		inp(n);
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		inp(grf[i][j]);
		inp(dsx);
		inp(dsy);
		inp(tym);
		v=grf[1][1];
			CLR(check);
			initial(m,n);
			priority_queue<pip , vector<pip> ,greater<pip> > q;
			q.push(pip(v,pii(1,1)));
			ver[1][1]=grf[1][1];
			while(!q.empty())
			{
				int x=q.top().second.first;
				int y=q.top().second.second;
				int v=q.top().first;
				q.pop();
				//cout<<"\nx = "<<x<<" y = "<<y<<" v = "<<v<<endl;
						
						v=grf[x][y+1];
						if(y<n&&check[x][y+1]==0&&ver[x][y+1]>ver[x][y]+v)
						{
							ver[x][y+1]=ver[x][y]+v;
							q.push(pip(ver[x][y+1],pii(x,y+1)));
						}
						v=grf[x+1][y];
						if(x<m&&check[x+1][y]==0&&ver[x+1][y]>ver[x][y]+v)
						{
							ver[x+1][y]=ver[x][y]+v;
							q.push(pip(ver[x+1][y],pii(x+1,y)));
						}
						v=grf[x][y-1];
						if(y>1&&check[x][y-1]==0&&ver[x][y-1]>ver[x][y]+v)
						{
							ver[x][y-1]=ver[x][y]+v;
							q.push(pip(ver[x][y-1],pii(x,y-1)));
						}
						v=grf[x-1][y];
						if(x>1&&check[x-1][y]==0&&ver[x-1][y]>ver[x][y]+v)
						{
							ver[x-1][y]=ver[x][y]+v;
							q.push(pip(ver[x-1][y],pii(x-1,y)));
						}
				
				check[x][y]=1;
				if(x==dsx&&y==dsy)
				break;
			}
			if(tym>=ver[dsx][dsy])
			printf("YES\n%d\n",tym-ver[dsx][dsy]);
			else
			printf("NO\n");
	}
	return 0;
}
