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

bool ch[21][21][201],flag;
int dp[21][21][201],n,m,x,y,ans,a[21][21];
int fun(int i,int j,int pwr)
{
	//cout<<"\ni = "<<i<<" j = "<<j<<" pwr = "<<pwr;
	if(pwr<0)
	return 0;
	if(i==m&&j==n)
	{
		if(pwr>=a[i][j])
		{
			flag=1;
			return pwr-a[i][j];
		}
		else
		return 0;
	}
	
	if(ch[i][j][pwr]==1)
	return dp[i][j][pwr];
	//cout<<"\nflag";
	ch[i][j][pwr]=1;
		if(i==m)
		dp[i][j][pwr]=fun(i,j+1,pwr-a[i][j]);
		else
		if(j==n)
		dp[i][j][pwr]=fun(i+1,j,pwr-a[i][j]);
		else
		dp[i][j][pwr]=max(fun(i,j+1,pwr-a[i][j]),fun(i+1,j,pwr-a[i][j]));
		return dp[i][j][pwr];
}

int main()
{
    	inp(m);
    	inp(n);
    	inp(x);
    	inp(y);
    	for(int i=1;i<=m;i++)
    	{
    		for(int j=1;j<=n;j++)
    		inp(a[i][j]);
    	}
    	CLR(dp);
    	CLR(ch);
    	flag=0;
    	ans=fun(x,y,2*a[x][y]);
    	if(flag==0)
    	printf("N\n");
    	else
    	printf("Y %d\n",ans);
    return 0;
}
