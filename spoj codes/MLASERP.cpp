#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>

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
bool ch[MX];
char G[MX][MX];
int x1,x2,y1,y2,ver[MX][MX],ans,R,C;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct node{
	int sum,len;
};
void initial(int x,int y)
{
	for(int i=0;i<x;i++)
	for(int j=0;j<y;j++)
	ver[i][j]=INF;
}
void DFS(int dir,int turn,int x,int y)
{
	//cout<<"\nx = "<<x<<" y = "<<y<<" turn = "<<turn<<" dir = "<<dir;
	if( x<0 || x>R-1 || y<0 || y>C-1 || G[x][y]=='*' || turn>ans )
	return ;
	//cout<<" ver[x][y] = "<<ver[x][y];
	if(x==x2&&y==y2)
	{
		if(turn<ans)
		ans=turn;
		return;
	}
	if(turn>ver[x][y])
	return;
	ver[x][y]=turn;
	int d1,d2;
	d1=(dir+1)%4;
	d2=(dir+3)%4;
	DFS(dir,turn,x+dx[dir],y+dy[dir]);
	DFS(d1,turn+1,x+dx[d1],y+dy[d1]);
	DFS(d2,turn+1,x+dx[d2],y+dy[d2]);
}
int main()
{
	
		int cnt=0;
		inp(C);
		inp(R);
		CLR(ch);
		CLR(G);
		for(int i=0;i<R;i++)
		{
			scanf("%s",&G[i]);
		}
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(G[i][j]=='C')
				{
					if(cnt==0)
					{
						cnt++;
						x1=i;
						y1=j;
					}
					else
					{
						x2=i;
						y2=j;
						break;
					}
				}
			}
		}
		//cout<<"\nx1 = "<<x1<<" y1 = "<<y1<<"\nx2 = "<<x2<<" y2 = "<<y2;
		initial(R,C);
		ver[x1][y1]=0;
		ans=INF;
		DFS(0,0,x1-1,y1);
		DFS(1,0,x1,y1+1);
		DFS(2,0,x1+1,y1);
		DFS(3,0,x1,y1-1);
		printf("%d\n",ans);
		return 0;
}
