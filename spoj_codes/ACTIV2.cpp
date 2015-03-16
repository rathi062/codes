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
#define MOD 100000000

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
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
		
int n,dp[MX],cum[MX];
struct act{
	int st,ed;
}node[MX];

int compare(const act a,const act b)
{
	return ((a.st==b.st)?(a.ed<b.ed):(a.st>b.st));
}
int comp(const act a,const act b)
{
	return a.ed<b.ed;
}
int search(int lim,int j)
{
	int i=0,mid;
	while(i!=j)
	{
		mid=(i+j)>>1;
		if(node[mid].st>=lim)
		i=mid+1;
		else
		j=mid;
	}
	i--;
	return i;
}
int fun(int n)
{
	LL mx;
	int sum=0,j;
	dp[0]=1;
	cum[0]=1;
	for(int i=1;i<n;i++)
	{
		j=search(node[i].ed,i);
		if(j>=0)
		dp[i]=cum[j]+1;
		else
		dp[i]=1;
		cum[i]=cum[i-1]+dp[i];
		if(cum[i]>=MOD)
		cum[i]%=MOD;
	}
	return cum[n-1];
}
int main()
{
    int t=0,w,cnt=1;
    inp(n);
    while(n!=-1)
    {
    	CLR(dp);
    	for(int i=0;i<n;i++)
    	{
    		inp(node[i].st);
    		inp(node[i].ed);
    	}
    	sort(node,node+n,compare);
    	/*for(int i=0;i<n;i++)
    	{
    		cout<<"\nst = "<<node[i].st<<" ed = "<<node[i].ed;
    	}*/
    	printf("%08d\n",fun(n));
    	inp(n);
    }
    return 0;
}
