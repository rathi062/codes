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
#define MX 30
#define MOD 100000000
#define pii pair<int ,int>
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
int R,C,X,Y;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<pii> chng[8];
char g[MX][MX],ans;
string fn[4];
bool  check[MX][MX],bk;
void initial()
{
	for(int i=0;i<R;i++)
	for(int j=0;j<C;j++)
	{
		check[i][j]=0;
	}
	chng[1].PB(pii(0,1));
	chng[1].PB(pii(1,0));
	chng[2].PB(pii(-1,0));
	chng[2].PB(pii(0,1));
	chng[3].PB(pii(-1,0));
	chng[3].PB(pii(0,-1));
	chng[4].PB(pii(1,0));
	chng[4].PB(pii(0,-1));
	
	chng[5].PB(pii(0,1));
	chng[5].PB(pii(0,-1));
	chng[6].PB(pii(1,0));
	chng[6].PB(pii(-1,0));
	
	chng[7].PB(pii(1,0));
	chng[7].PB(pii(0,-1));
	chng[7].PB(pii(-1,0));
	chng[7].PB(pii(0,1));
	fn[0]="1476MZ";
	fn[1]="1257MZ";
	fn[2]="2367MZ";
	fn[3]="3457MZ";
}
void find(int x,int y)
{
	int u,v;
	bool up,dn,rgt,lft;
	up=dn=rgt=lft=0;
	u=x-1;
	v=y;
	for(int i=0;i<6;i++)
	if(g[u][v]==fn[0][i])
	{
		up=1;
		break;
	}
	u=x;
	v=y-1;
	for(int i=0;i<6;i++)
	if(g[u][v]==fn[1][i])
	{
		lft=1;
		break;
	}
	u=x+1;
	v=y;
	for(int i=0;i<6;i++)
	if(g[u][v]==fn[2][i])
	{
		dn=1;
		break;
	}
	u=x;
	v=y+1;
	for(int i=0;i<6;i++)
	if(g[u][v]==fn[3][i])
	{
		rgt=1;
		break;
	}
	if(up&dn&rgt&lft)
	ans='+';
	else
	if(rgt&dn)
	ans='1';
	else
	if(rgt&up)
	ans='2';
	else
	if(up&lft)
	ans='3';
	else
	if(lft&dn)
	ans='4';
	else
	if(lft&rgt)
	ans='-';
	else
	if(up&dn)
	ans='|';
	return ;
}
void DFS(int x,int y)
{
	if(check[x][y]==1||g[x][y]=='Z')
	return;
	check[x][y]=1;
	int idx=g[x][y]-'0';
	int sz=chng[idx].size();
	for(int i=0;i<sz;i++)
	{
		int u = x+chng[idx][i].first;
		int v = y+chng[idx][i].second;
		if(g[u][v]=='.')
		{
			X=u;
			Y=v;
			bk=1;
			find(u,v);
		}
		if(bk)return;
		DFS(u,v);
	}
}
int main()
{
    int x,y,u,v,xi,yi,b=0;
    inp(R);
    inp(C);
		
	for(int i=0;i<R;i++)
    scanf("%s",&g[i]);
    initial();
    
	for(int i=0;i<R;i++)
	for(int j=0;j<C;j++)
	{
		if(g[i][j]=='M')
		{
			x=i;
			y=j;
		}
		else	
		if(g[i][j]=='-')
		g[i][j]='5';
		else
		if(g[i][j]=='Z'||g[i][j]=='.')
		continue;
		else
		if(g[i][j]=='+')
		g[i][j]='7';
		else
		if(g[i][j]=='|')
		g[i][j]='6';
	}
	check[x][y]=1;
	for(int i=0;i<4;i++)
	{
		u=x+dx[i];
		v=y+dy[i];
		if(u<0||u==R||v<0||v==C||g[u][v]=='.')
		continue;
		int n=g[u][v]-'0';
		int sz=chng[n].size();
		for(int j=0;j<sz;j++)
		{
			int p=u+chng[n][j].first;
			int q=v+chng[n][j].second;
			if(p==x&&q==y)
			{
				xi=u;
				yi=v;
				b=1;
			}
			if(b)
			break;
		}
		if(b)
		break;
	}
	bk=0;
	DFS(xi,yi);
	printf("%d %d %c\n",X+1,Y+1,ans);
	return 0;
}
