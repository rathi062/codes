
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
int main()
{
	int n,m,k,mx,my,cx,cy,kx,ky,d,cd,kd;
	inp(n);
	inp(m);
	inp(k);
	while(k--)
	{
		inp(mx);
		inp(my);
		inp(cx);
		inp(cy);
		inp(kx);
		inp(ky);
		d=mx-1;
		cd=abs(cx-1)+abs(my-cy);
		kd=abs(kx-1)+abs(my-ky);
		if(d<cd&&d<kd)
		{
			printf("YES\n");
			continue;
		}
		d=n-mx;
		cd=abs(cx-n)+abs(my-cy);
		kd=abs(kx-n)+abs(my-ky);
		if(d<cd&&d<kd)
		{
			printf("YES\n");
			continue;
		}
		d=my-1;
		cd=abs(cx-mx)+abs(1-cy);
		kd=abs(kx-mx)+abs(1-ky);
		if(d<cd&&d<kd)
		{
			printf("YES\n");
			continue;
		}
		d=m-my;
		cd=abs(cx-mx)+abs(m-cy);
		kd=abs(kx-mx)+abs(m-ky);
		if(d<cd&&d<kd)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
