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
#define MX 1001
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
int p[MX],n,sum;
void fun(int i,int j,int cost,int no)
{
	if(i==1&&j==n)
	{
		if(cost<sum)
		sum=cost;
		return ;
	}
	if(cost>=sum)
	return ;
	int f=1000000000,s=1000000000;
	if(i>1)
	{
		int cnt=0;
		/*for(int k=0;k<n;k++)
		{
			if(p[k]<i||p[k]>j)
			cnt++;
			if(p[k]==i-1)
			break;
		}*/
		cnt=dp[i+1][j];
		fun(i-1,j,cost+no*cnt,no+1);
	}
	if(j<n)
	{
		int cnt=0;
		/*for(int k=0;k<n;k++)
		{
			if(p[k]<i||p[k]>j)
			cnt++;
			if(p[k]==j+1)
			break;
		}*/
		cnt=dp[i][j-1];
		fun(i,j+1,cost+no*cnt,no+1);
	}
	//cout<<"\nf = "<<f<<" s = "<<s;
	//cout<<"\ni = "<<i<<" j = "<<j<<" dp = "<<dp[i][j];
}
int main()
{
    int t=0,cnt=1,ans,k;
    inp(t);
    while(t--)
    {
		 sum=1000000000;
         inp(n);
         //cout<<"\nl = "<<n;
         for(int i=0;i<n;i++)
         {
		 	inp(p[i]);
		 }
         CLR(dp);
         CLR(check);
         for(int i=0;i<n;i++)
         {
         	dp[p[i]][p[i]]=i+1;
         	for(int j=i+1;j<n;j++)
         	{
         		dp[j][p[i]]=1;
         	}
         }
         
         for(int i=0;i<n;i++)
         {
         	for(int j=i-2;j>=0;j--)
         	{
         		dp[i][j]=dp[i][j+1]+dp[i][j];
         	}
         	for(int j=i+2;j<n;j++)
         	{
         		dp[i][j]=dp[i][j-1]+dp[i][j];
         	}
         }
         
         
		 for(int i=0;i<n;i++)
		 {
		 	fun(p[i],p[i],i+1,2);
		 	//cout<<"\ni = "<<i+1<<" sum = "<<sum;
		 }
		 printf("%d\n",sum);
    }
    return 0;
}
