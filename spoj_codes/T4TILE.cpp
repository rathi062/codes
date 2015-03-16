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
#define MX 220
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
LL dp[MX],ans;
LL fun(int i)
{
	if(check[i]==1)
	return dp[i];
	
	check[i]=1;
	if(i==0)
	{
		dp[i]=1;
		return 1;
	}
	LL sum=0;
	if(i>=1)
	sum+=1*fun(i-1);
	
	if(i>=2)
	sum+=4*fun(i-2);
	
	for(int k=i-3;k>=0;k-=2)
	{
		sum+=2*fun(k);
	}
	for(int k=i-4;k>=0;k-=2)
	{
		sum+=3*fun(k);
	}
	dp[i]=sum;
	return dp[i];
}
int main()
{
    int t=0,cnt=1,n;
    CLR(dp);
        CLR(check);
    inp(t);
    while(t--)
    {
         int m,k,idx,x,y,val,min=0;
		 LL sum=0;
		 inp(n);
         
		 ans=fun(n);
		 /*for(x=0;x<n;x++)
		 {
		 	for(y=0;y<n;y++)
		 	cout<<zero[x][y]<<" ";
		 	cout<<endl;
		 }
		 for(x=0;x<n;x++)
		 {
		 	for(y=0;y<n;y++)
		 	cout<<one[x][y]<<" ";
		 	cout<<endl;
		 }*/	
		 printf("%d %lld\n",cnt++,ans);
    }
    return 0;
}
