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
struct node{
	int d,v;
};
typedef struct node node;
bool check[MX][MX];
char v[MX][MX];
int ver[MX][MX],C,R;
pii nxt;
int ans;
void DFS(int i,int j,int d)
{
	if(i<0||i>=R||j<0||j>=C||v[i][j]!='.')return ;
	DFS(i,j+1,d+1);
	DFS(i+1,j,d+1);
	DFS(i,j-1,d+1);
	DFS(i-1,j,d+1);
	if(d>ans)
	{
		ans=d;
		nxt.F=i;
		nxt.S=j;
	}	
}
int call(void)
{
	int mx=0;
	if(v[nxt.F][nxt.S]!='.')
	return 0;
	while(1)
	{
		ans=0;
		DFS(nxt.F,nxt.S,0);
		if(ans<=mx)
		break;
		else
		mx=ans;
	}
	return mx;
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
		inp(C);
		inp(R);
		for(int i=0;i<R;i++)
			scanf("%s",&v[i]);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				if(v[i][j]=='.')
				{
					nxt.F=i;
					nxt.S=j;
					break;
				}
		printf("Maximum rope length is %d.\n",call());
	}
	return 0;
}
