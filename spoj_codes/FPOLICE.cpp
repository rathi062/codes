
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
#define MX 1000001
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
int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}
struct node{
	int val,x,y;
}nod;
bool ch[101][251];
int dp[101][251],rsk[101][101],tm[101][101];
int main()
{
	int ans,f,i,c,min,t=0,j,cnt,r,tim,x,y;
	int n,k,s;
	inp(t);
	while(t--)
	{
		inp(n);
		inp(k);
		CLR(ch);
		for(i=1;i<=n;i++)
		for(j=0;j<=k;j++)
		dp[i][j]=1000000000;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		inp(tm[i][j]);
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		inp(rsk[i][j]);
		dp[1][k]=0;
		while(1)
		{
			min=1000000000;
			f=0;
			for(i=1;i<=n;i++)
			{
				for(j=0;j<=k;j++)
				{
					if(ch[i][j]==0&&dp[i][j]<min)
					{
						f=1;
						min=dp[i][j];
						x=i;
						y=j;
					}
				}
			}
			if(f==0)
			break;
			//cout<<"\nx = "<<x<<" y = "<<y<<" min = "<<min;
			ch[x][y]=1;
			for(i=1;i<=n;i++)
			{
				if((y-tm[x][i])>=0&&dp[i][y-tm[x][i]]>dp[x][y]+rsk[x][i])
				{
					dp[i][y-tm[x][i]]=dp[x][y]+rsk[x][i];
					//cout<<"\ndp["<<i<<"]["<<y-tm[x][i]<<"] = "<<dp[i][y-tm[x][i]];
				}
			}
		}
		ans=100000000;
		for(i=0;i<=k;i++)
		{
			if(ans>=dp[n][i])
			{
				ans=dp[n][i];
				tim=i;
			}
		}
		if(ans!=100000000)
		printf("%d %d\n",ans,k-tim);
		else
		printf("-1\n");
	}
	return 0;
}

