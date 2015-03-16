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
#define MX 100005
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
bool ch[5][MX];
int dp[5][MX],v[5],n;
int fun(int i,int w,int f)
{
	if(i<0)
	return 0;
	if(ch[i][w]==1)
	return dp[i][w];
	
	ch[i][w]=1;
	//cout<<"\nw = "<<w<<" h = "<<h<<" dp[w][h] = "<<dp[w][h];
	int val,r;
	for(int frq=f;;frq++)
	{
		
		val=frq*v[i];
		//cout<<"\ni = "<<i<<" val = "<<val<<" w = "<<w;
		if(w-val<0)
		return 0;
		if(w-val==0&&i==0)
		return 1;
		r=fun(i-1,w-val,frq);
		if(r==1)
		return 1;
	}
	//cout<<"\nw = "<<w<<" h = "<<h<<" dp[w][h] = "<<dp[w][h];
	return dp[i][w];
}

int main()
{
	int t,x,n;
    inp(t);
    while(t--)
    {
    	inp(x);
    	inp(n);
    	for(int i=0;i<n;i++)
    		inp(v[i]);
    	CLR(dp);
    	CLR(ch);
    	int ans=fun(n-1,x,1);
    	/*for(int i=0;i<=w;i++)
    	{
    		for(int j=0;j<=h;j++)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}*/
    	if(ans==1)
    	printf("\nYES");
    	else
    	printf("\nNO");
    }
	return 0;
}
