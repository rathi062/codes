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
#define MX 6200
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
int dp[2][MX],l;
char s[MX];
int fun(void)
{
	for(int i=0;i<=l;i++)
	dp[0][i]=0;
	dp[1][0]=0;
	for(int i=1;i<=l;i++)
	{
		for(int j=1,k=l;k>0;k--,j++)
		{
			if(s[i-1]==s[k-1])
			dp[i&1][j]=1+dp[!(1&i)][j-1];
			else
			dp[i&1][j]=max(dp[(i&1)][j-1],dp[!(i&1)][j]);
		}
	}
	return l-dp[l&1][l];
}

int main()
{
    int t=0,cnt=1,ans;
    inp(t);
    while(t--)
    {
		 int sum=0;
         scanf("%s",&s);
         l=strlen(s);
         //cout<<"\nl = "<<n;
		 sum=fun();
		 printf("%d\n",sum);
    }
    return 0;
}
