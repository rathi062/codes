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
		

int main()
{
    int t=0,n,K,c,l,r;
    inp(t);
    for(int p=0;p<t;p++)
    {
	inp(n);
	inp(c);
	inp(K);
	double a[51][51][101];

	for(int i=0;i<51;i++)
	for(int j=0;j<51;j++)
	for(int k=0;k<101;k++)
	a[i][j][k]=0.0;

	for(int i=1;i<=n;i++)
	{
		a[0][i][1]=1.0;
	}	
	for(int i=1;i<=K;i++)
	{
		inp(l);
		inp(r);

		for(int j=1;j<=n;j++)
		{
			if(j<l||j>r)
			for(int k=0;k<c;k++)
			a[i][j][k]+=a[i-1][j][k];
			else
			for(int k=0;k<c;k++)
			{
				a[i][j][k]+=(a[i-1][j][k]*0.5);
				for(int m=0;m<c;m++)
				a[i][j][(m*k)%c]+=(a[i-1][j][k]/(2*c));
					
			}
		}
		
	}

	double ans=0.0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<c;j++)
		ans+= j*a[K][i][j];
	}
	printf(“%lf\n”,ans);
    }
    return 0;
}
