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
int dp[MX][MX],res[MX];
void sum(int p)
{
	int i=0,j=0,mx=0,c,cc,r=0;
	for(i=0;i<MX;i++)
	{
		dp[p][i]=dp[p][i]+res[i]+r;
		r=dp[p][i]/10;
		dp[p][i]%=10;
	}
}	
void mul(int i,int j)
{
	int al,bl;
	CLR(res);
	for(al=MX-1;!dp[i][al];al--){}
	for(bl=MX-1;!dp[j][bl];bl--){}
	//cout<<"\nal = "<<al<<" bl = "<<bl<<endl;
	for(int p=0;p<=al;p++)
	{
		int c=dp[i][p];
		for(int q=0;q<=bl;q++)
		{
			int cc=dp[j][q];
			res[p+q]+=c*cc;
			int d=res[p+q]/10,k=1;
			res[p+q]%=10;
			while(d!=0)
			{
				res[p+q+k]+=d;
				d=res[p+q+k]/10;
				res[p+q+k]%=10;
				k++;
			}
		}
	}
}
void fun()
{
	dp[0][0]=1;
	dp[2][0]=1;
	dp[4][0]=2;
	for(int i=6;i<=300;i+=2)
	{
		for(int j=2;j<=i;j+=2)
		{
			mul(j-2,i-j);
			sum(i);
		}
		/*cout<<"\ni = "<<i<<" -> ";
		int k;
    	for(k=300;!dp[i][k];k--){}
    	for(k;k>=0;k--)
		cout<<dp[i][k];*/
	}
}

int main()
{
	int n;
	fun();
    inp(n);
    while(n!=-1)
    {
    	
    	/*for(int i=1;i<=2*n;i++)
    	{
    		for(int j=1;j<=2*n;j++)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}*/
    	int k,i=2*n;
    	for(k=MX;!dp[i][k];k--){}
    	for(k;k>=0;k--)
		printf("%d",dp[i][k]);
		printf("\n");
    	inp(n);
    }
	return 0;
}
