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

bool ch[201][101][101];
int dp[201][101][101],w,h,mx;
char path[101][101];

int fun(int step,int i,int j)
{
	if(step==w+h-2)
	{
		if(i==h-1&&step-i==w-1&&i==j) 
		return path[i][step-j]=='*';
		else 
		return -1;
	}
	if(ch[step][i][j]==1)
	return dp[step][i][j];
	ch[step][i][j]=1;
	int c1=step-i,c2=step-j,ans=-1;
	if(c1<w&&c2<w&&path[i][c1]!='#'&&path[j][c2]!='#')
	{
		ans=max(ans,fun(step+1,i,j));
		if(i+1<h) 
		ans=max(ans,fun(step+1,i+1,j));
		if(j+1<h) 
		ans=max(ans,fun(step+1,i,j+1));
		if(i+1<h&&j+1<h) 
		ans=max(ans,fun(step+1,i+1,j+1));
		if(ans!=-1)
		{
			if(path[i][c1]=='*')
			ans++;
			if(i!=j&&path[j][c2]=='*')
			ans++;
		}
		
	}
	dp[step][i][j]=ans;
	return ans;
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
    	CLR(ch);
    	mx=fun(0,0,0);
    	printf("%d\n",mx);
    }
    return 0;
}
