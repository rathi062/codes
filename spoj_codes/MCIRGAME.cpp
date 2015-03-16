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
#define MX 303
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
LL dp[MX][MX],ans;
LL fun(int i,int j)
{
	//cout<<"\ni = "<<i<<" j = "<<j;
	if(ch[i][j]==1)
	return dp[i][j];
	if(i>=j)
	return 1;
	ch[i][j]=1;
	if(i+1==j)
	return (dp[i][j]=1);
	LL sum=0;
	for(int k=i+1;k<=j;k+=2)
	{
		sum+=fun(i+1,k-1)*fun(k+1,j);
		
	}
	//cout<<"\ni = "<<i<<" j = "<<j<<" sum = "<<sum;
	dp[i][j]=sum;
	return dp[i][j];
}

int main()
{
	int n;
    inp(n);
    while(n!=-1)
    {
    	ans=fun(1,2*n);
    	/*for(int i=1;i<=2*n;i++)
    	{
    		for(int j=1;j<=2*n;j++)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}*/
    	printf("%lld\n",ans);
    	inp(n);
    }
	return 0;
}
