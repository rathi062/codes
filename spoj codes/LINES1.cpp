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
#define MX 202
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
struct slope{
	int dx,dy;
}slp[50000];
int x[MX],y[MX];
int comp(const slope a,const slope b)
{
	return (a.dy*b.dx<b.dy*a.dx);
}

int equal(const slope a,const slope b)
{
	return (a.dy*b.dx==b.dy*a.dx);
}
int main()
{
	int n;
	double dx,dy,sl;
	inp(n);
	while(n)
	{
		int sz=0,cnt=1;
		for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				slp[sz].dx=x[j]-x[i];
				slp[sz].dy=y[j]-y[i];
				if(slp[sz].dy<0)
				{
					slp[sz].dy*=-1;
					slp[sz].dx*=-1;
				}
				if(!slp[sz].dy)
				slp[sz].dx=abs(slp[sz].dx);
				sz++;
			}
		}
		sort(slp,slp+sz,comp);
		for(int i=1;i<sz;i++)
		if(!equal(slp[i-1],slp[i]))
		cnt++;
		printf("%d\n",cnt);
		inp(n);
	}
	return 0;
}
