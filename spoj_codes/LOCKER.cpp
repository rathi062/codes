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
#define MX 1000006
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
bool check[MX];
queue<LL> q;
LL dp[MX];
LL n;
LL fun(LL n)
{
	if(n==1||n==2||n==3||n==4)
	return n;
	if(n<MX&&check[n]==true)
	return dp[n];
	LL ret,f=n/2,s=n-f;
	if(f!=s)
	ret=(fun(f)*fun(s));
	else
	{
		ret=fun(f);
		ret*=ret;
	}
	if(ret>=MOD)
	ret%=MOD;
	if(n<MX)
	{
		check[n]=1;
		dp[n]=ret;
		return ret;
	}
	else
	return ret;
}
int main()
{
	int t;
    inp(t);
    for(int i=0;i<t;i++)
    {
    	inpll(n);
    	q.push(n);
			
    }
    for(int i=0;i<t;i++)
    {
    	printf("%lld\n",fun(q.front()));
    	q.pop();
    }
	return 0;
}