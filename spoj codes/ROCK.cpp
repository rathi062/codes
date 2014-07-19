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
char s[220];
bool check[MX][MX];
int dp[MX][MX],zero[MX][MX],one[MX][MX];
int fun(int i,int j)
{
	if(check[i][j]==1)
	return dp[i][j];
	
	int ch;
	check[i][j]=1;
	if(i==j)
	{
		ch=s[i]-48;
		if(ch==0)
		{
			zero[i][i]=1;
			one[i][i]=0;
			dp[i][i]=0;
		}
		else
		{
			zero[i][i]=0;
			one[i][i]=1;
			dp[i][i]=1;
		}
		return dp[i][i];
	}
	for(int k=i;k<=j;k++)
	{
		ch=s[k]-48;
		if(ch==0)
		zero[i][j]++;
		else
		one[i][j]++;
	}
	//cout<<"\ni = "<<i<<" j = "<<j<<" zero = "<<zero[i][j]<<" one = "<<one[i][j];
	if(one[i][j]>zero[i][j])
	{
		dp[i][j]=j-i+1;
		return dp[i][j];
	}
	int mx=0,p,q;
	for(int k=i;k<j;k++)
	{
		p=fun(i,k);
		q=fun(k+1,j);
		if(mx<p+q)
		mx=p+q;
	}
	dp[i][j]=mx;
	return mx;
}
int main()
{
    int t=0,cnt=1,n,ans;
    inp(t);
    while(t--)
    {
         int m,k,idx,x,y,val,min=0;
		 LL sum=0;
		 inp(n);
         cin>>s;
         CLR(dp);
         CLR(check);
         CLR(one);
         CLR(zero);
		 ans=fun(0,n-1);
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
		 printf("%d\n",ans);
    }
    return 0;
}
