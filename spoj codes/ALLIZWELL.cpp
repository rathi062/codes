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

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
char line[]={"ALLIZZWELL"},grf[MX][MX];
bool check[MX][MX];
int n,m;
bool DFS(int x,int y,int in)
{
	//cout<<"\nx = "<<x<<" y = "<<y;
	int u,v;
	if(in==9)
	return true;
	check[x][y]=1;
	for(int i=0;i<8;i++)
	{
			u=x+dx[i];
			v=y+dy[i];
			if(u<0 || u>n || v<0 || v>m || check[u][v] || grf[u][v]!=line[in+1])
			continue ;
			if(DFS(u,v,in+1))
			return true;
	}	
	check[x][y]=0;			
	return  false;
}

int main()
{
	int t,b;
	inp(t);
	while(t--)
	{
		b=0;
		inp(n);
		inp(m);
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		check[i][j]=0;
		for(int i=0;i<n;i++)
		scanf("%s",&grf[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(grf[i][j]=='A')
				{
					if(DFS(i,j,0))
					{
						printf("YES\n");
						b=1;
						break;
					}
				}
			}
			if(b)
			break;
		}
		if(!b)
		printf("NO\n");
	}
}
