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
#define MX 51
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
bool ch[22][51][101][3];
double dp[22][51][101][3],cost[51],prof[51],ans;
int n,day[22],day1[22],da;
double fun(int d,int m,int l,int f)
{
	//cout<<"\nd = "<<d<<" m = "<<m<<" l = "<<l<<" f = "<<f;
	if(d>da)
	return 0;
	if(ch[d][m][l][f]==1)
	return dp[d][m][l][f];
	
	ch[d][m][l][f]=1;
	double sum=0,mx=0.0;
	for(int i=1;i<=n;i++)
	{
		if(m-cost[i]>=0)
		{
			if(i==l)
			{
				if(f==0)
				sum=(prof[i]/2.0)+fun(d+1,m-cost[i],i,1);
				else
				sum=fun(d+1,m-cost[i],i,2);
			}
			else
			sum=prof[i]+fun(d+1,m-cost[i],i,0);
			if(mx<=sum)
			{
				day[d]=i;
				mx=sum;
				if(l==0&&f==0)
				{
					for(int k=1;k<=da;k++)
					day1[k]=day[k];
				}
			}
		}
	}
	return (dp[d][m][l][f]=mx);
}

int main()
{
	int m;
	inp(da);
	inp(n);
	inp(m);
	while(n!=0&&da!=0&&m!=0)
	{
		CLR(dp);
		CLR(ch);
		int min=10000;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&cost[i]);
			if(cost[i]<min)
			min=cost[i];
			scanf("%lf",&prof[i]);
		}
		//cout<<"\nmin = "<<min;
		if(m<min*da)
		printf("\n0.0\n");
		else
		{
			ans=fun(1,m,0,0);
			printf("\n%.1lf\n",ans);
			for(int i=1;i<=da;i++)
			cout<<day[i]<<" ";
			cout<<endl;
		}
		inp(da);
		inp(n);
		inp(m);
	}
	return 0;
}
