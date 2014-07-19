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
#define MX 2020
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
int a[MX][3],dp[MX][3],n;
int fun(int l,int w)
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(a[i][0]<l&&a[i][1]<w)
		{
			if(dp[i][0]==0)
			{	
				int r=fun(a[i][0],a[i][1])+a[i][2];
				dp[i][0]=r;
			}
			if(max<dp[i][0])
			max=dp[i][0];
		}
		if(a[i][1]<l&&a[i][0]<w)
		{
			if(dp[i][0]==0)
			{	
				int r=fun(a[i][1],a[i][0])+a[i][2];
				dp[i][0]=r;
			}
			if(max<dp[i][0])
			max=dp[i][0];
		}
		if(a[i][2]<l&&a[i][1]<w)
		{
			if(dp[i][1]==0)
			{	
				int r=fun(a[i][2],a[i][1])+a[i][0];
				dp[i][1]=r;
			}
			if(max<dp[i][1])
			max=dp[i][1];
		}
		if(a[i][1]<l&&a[i][2]<w)
		{
			if(dp[i][1]==0)
			{	
				int r=fun(a[i][1],a[i][2])+a[i][0];
				dp[i][1]=r;
			}
			if(max<dp[i][1])
			max=dp[i][1];
		}
		if(a[i][0]<l&&a[i][2]<w)
		{
			if(dp[i][2]==0)
			{	
				int r=fun(a[i][0],a[i][2])+a[i][1];
				dp[i][2]=r;
			}
			if(max<dp[i][2])
			max=dp[i][2];
		}
		if(a[i][2]<l&&a[i][0]<w)
		{
			if(dp[i][2]==0)
			{	
				int r=fun(a[i][2],a[i][0])+a[i][1];
				dp[i][2]=r;
			}
			if(max<dp[i][2])
			max=dp[i][2];
		}
	}
	return max;
}
int main()
{
    int t=0,cnt=1,ans;
    inp(n);
    while(n)
    {
		 int ans;
         CLR(a);
         CLR(dp);
         for(int i=0;i<n;i++)
         {
            inp(a[i][0]);
            inp(a[i][1]);
            inp(a[i][2]);
		 }
		 ans=fun(100000000,100000000);	
         /*for(int i=1;i<=n;i++)
         {
         	for(int j=1;j<=m;j++)
         	cout<<dp[i][j]<<" ";
         	cout<<endl;
         }*/
		 printf("%d\n",ans);
		 inp(n);
    }
    return 0;
}
