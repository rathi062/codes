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
#define MX 1010
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
int dp[MX][MX],l,al,bl,n;
char a[MX],b[MX];
int fun(void)
{
	for(int i=1;i<=al;i++)
	{
		for(int j=1;j<=bl;j++)
		{
			int cnt=1;
			while((i-cnt)>=0&&(j-cnt)>=0&&a[i-cnt]==b[j-cnt])
			{
				if(cnt>=n)
				dp[i][j]=max(dp[i][j],cnt+dp[i-cnt][j-cnt]);
				cnt++;
			}
			dp[i][j]=max3(dp[i][j-1],dp[i-1][j],dp[i][j]);
		}
	}
	return dp[al][bl];
}

int main()
{
    inp(n);
    while(n)
    {
    	scanf("%s",&a);
    	scanf("%s",&b);
    	al=strlen(a);
    	bl=strlen(b);
    	CLR(dp);
		printf("%d\n",fun());
		/*for(int i=1;i<=al;i++)
		{
			for(int j=1;j<=bl;j++)
			cout<<dp[i][j]<<" ";
			cout<<endl;
		}*/
		inp(n); 
    }
    return 0;
}
