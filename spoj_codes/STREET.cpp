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
#define MX 505
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
bool ch[MX][MX];
int dp[MX][MX],r[MX],n,k,t,mm;
int fun(int i,int j)
{
	if(ch[i][j]==1)
	return dp[i][j];
	if(j==0||i>n)
	return 0;
	ch[i][j]=1;
	int max=fun(i+1,j),h=INF,sum;
	for(int x=1,y=i;x<=t&&y<=n;x++,y++)
	{
		h=min(h,r[y]);
		sum=h*x+fun(i+x,j-1);
		if(sum>max)
		max=sum;
	}
	dp[i][j]=max;
	if(max>mm)
	mm=max;
	return max;
}

int main()
{
	inp(n);
	inp(k);
	inp(t);
	for(int i=1;i<=n;i++)
	inp(r[i]);
	mm=0;
	CLR(dp);
	CLR(ch);
	fun(1,k);
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	printf("%d\n",mm);
	return 0;
}
