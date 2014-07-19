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
#define MX 101
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
LL dp[MX][MX];
string s;
LL fun(int i,int j)
{
	if(check[i][j]==1)
	return dp[i][j];
	check[i][j]=1;
	if(i+2==j)
	{
		char ch=s[i+1];
		int f=int(s[i]-48),sc=int(s[j]-48);
		if(ch=='+')
		return (dp[i][j]=f+sc);
		else
		return (dp[i][j]=f*sc);
	}
	if(i==j)
	return (dp[i][j]=(s[i]-48));
	LL f,sc,max=0,ans;
	for(int k=i;k<j;k+=2)
	{
		char ch=s[k+1];
		f=fun(i,k);
		sc=fun(k+2,j);
		ans=(ch=='+')?(f+sc):(f*sc);
		max=(ans>max)?ans:max;
	}	
	//cout<<"\ni = "<<i<<" j = "<<j<<" dp = "<<max;
	dp[i][j]=max;
	return max;
}
LL fun1(int i,int j)
{
	if(check[i][j]==1)
	return dp[i][j];
	check[i][j]=1;
	if(i+2==j)
	{
		char ch=s[i+1];
		int f=int(s[i]-48),sc=int(s[j]-48);
		if(ch=='+')
		return (dp[i][j]=f+sc);
		else
		return (dp[i][j]=f*sc);
	}
	if(i==j)
	return (dp[i][j]=(s[i]-48));
	LL f,sc,min=INF,ans;
	for(int k=i;k<j;k+=2)
	{
		char ch=s[k+1];
		f=fun1(i,k);
		sc=fun1(k+2,j);
		ans=(ch=='+')?(f+sc):(f*sc);
		min=(ans<min)?ans:min;
	}	
	//cout<<"\ni = "<<i<<" j = "<<j<<" dp = "<<min;
	dp[i][j]=min;
	return min;
}
int main()
{
    int t=0,n,cnt=1,ans;
    inp(t);
    while(t--)
    {
		 LL sum=0,sum1=0;
         CLR(dp);
         cin>>s;
         n=s.size();
         //cout<<"\nl = "<<n;
         CLR(dp);
         CLR(check);
		 sum=fun(0,n-1);
		 CLR(dp);
		 CLR(check);
		 sum1=fun1(0,n-1);
		 printf("%lld %lld\n",sum,sum1);
    }
    return 0;
}
