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
bool check[MX][MX];
int dp[MX][MX];
char s[MX];
int fun(int i,int j)
{
	if(i==j)
	return 0;
	
	if(check[i][j]==1)
	return dp[i][j];
	check[i][j]=1;
	
	if(i+1==j&&s[i]==s[j])
	return (dp[i][j]=0);
	
	if(s[i]==s[j])
	return (dp[i][j]=fun(i+1,j-1));	
	//cout<<"\ni = "<<i<<" j = "<<j<<" dp = "<<max;
	int a,b;
	a=1+fun(i,j-1);
	b=1+fun(i+1,j);
	dp[i][j]=min(a,b);
	return dp[i][j];
}

int main()
{
    int t=0,n,cnt=1,ans;
    inp(t);
    while(t--)
    {
		 int sum=0;
         scanf("%s",&s);
         n=strlen(s);
         //cout<<"\nl = "<<n;
         CLR(dp);
         CLR(check);
		 sum=fun(0,n-1);
		 printf("%d\n",sum);
    }
    return 0;
}
