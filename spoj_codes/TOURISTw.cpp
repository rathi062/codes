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
#define WRITE freopen("output.txt", "h", stdout)
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

bool ch[101][101],way[101][101];
int dp[101][101],w,h,mx;
char path[101][101];

int fun(int i,int j)
{
	if(i==h-1&&j==w-1)
	{
		if(path[i][j]=='*')
		return 1;
		else
		return 0;
	}
	if(ch[i][j]==1)
	return dp[i][j];
	ch[i][j]=1;
	if(i==h-1)
	{
		if(path[i][j+1]=='#')
		return (dp[i][j+1]=-1000);
		way[i][j]=0;
		dp[i][j]=fun(i,j+1);
		if(path[i][j]=='*')
		dp[i][j]++;
		return dp[i][j];
	}
	if(j==w-1)
	{
		if(path[i+1][j]=='#')
		return (dp[i+1][j]=-1000);
		way[i][j]=1;
		dp[i][j]=fun(i+1,j);
		if(path[i][j]=='*')
		dp[i][j]++;
		return dp[i][j];
	}
	int r,d;
	r=d=-1000;
	if(path[i][j+1]!='#')
	r=fun(i,j+1);
	if(path[i+1][j]!='#')
	d=fun(i+1,j);
	if(r>d)
	{
		way[i][j]=0;
		dp[i][j]=r;
	}
	else
	{
		way[i][j]=1;
		dp[i][j]=d;
	}
	if(path[i][j]=='*')
	dp[i][j]++;
	return dp[i][j];
}
int main()
{
	int t;
    inp(t);
    while(t--)
    {
    	inp(w);
    	inp(h);
    	for(int i=0;i<h;i++)
    	{
    		scanf("%s",&path[i]);
    	}
    	CLR(dp);
    	CLR(way);
    	CLR(ch);
    	mx=fun(0,0);
    	/*for(int i=0;i<w;i++)
    	{
    		for(int j=0;j<h;j++)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}
    	cout<<endl;
    	for(int i=0;i<w;i++)
    	{
    		for(int j=0;j<h;j++)
    		cout<<way[i][j]<<" ";
    		cout<<endl;
    	}*/
    	int i,j;
    	i=j=0;
    	cout<<"\nfst mx = "<<mx;
    	while(i!=h-1||j!=w-1)
    	{
    		if(way[i][j]==0)
    		path[i][j++]='.';
    		else
    		path[i++][j]='.';
    	}
    	for(int i=0;i<h;i++)
    	printf("%s\n",path[i]);
    	CLR(dp);
    	CLR(ch);
    	mx+=fun(0,0);
    	printf("%d\n",mx);
    }
    return 0;
}
