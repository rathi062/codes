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
int a[MX],dp[MX][MX],sc;
int fun(int i,int j)
{
	if(dp[i][j]!=0)
	return dp[i][j];
	if(i+1==j)
	{
		dp[i][j]=max(a[i],a[j]);
		return dp[i][j];
	}
	int r,l;
	if(a[i]<a[j-1])
	r=fun(i,j-2);
	else
	r=fun(i+1,j-1);
	r+=a[j];
	
	if(a[i+1]<a[j])
	l=fun(i+1,j-1);
	else
	l=fun(i+2,j);
	l+=a[i];
	
	dp[i][j]= max(r,l);
	return dp[i][j];
}
int main()
{
    int t=0,cnt=1,ans,n;
    inp(n);
    while(n)
    {
         int m,k,idx,x,y,val,min=0;
		 LL sum=0;
		 sc=0;
         CLR(a);
         CLR(dp);
         for(int i=1;i<=n;i++)
         {
            inp(a[i]);
            sum+=a[i];
		 }
		 ans=fun(1,n);	
		 printf("In game %d, the greedy strategy might lose by as many as %d points.\n",cnt++,2*ans-sum);
		 inp(n);
    }
    return 0;
}
