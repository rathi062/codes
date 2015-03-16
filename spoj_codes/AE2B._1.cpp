
#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<math.h>
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
#define MOD 1000003

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
    int t,x1,x2,y1,y2,n,k,nn,kk,d,dx,dy,b,a,f;
    inp(t);
    while(t--)
    {
    	inp(kk);
    	inp(nn);
		inp(x1);
    	inp(y1);
    	inp(x2);
    	inp(y2);
    	if(nn==0&&kk==0)
    	{
			printf("NIE\n");
			continue;
		}
    	else
    	if(nn==0||kk==0)
    	{
			printf("TAK\n");
			continue;
		}
    	dx=x1-x2;
    	if(dx<0)
    	dx*=-1;
    	dy=y1-y2;
    	if(dy<0)
    	dy*=-1;
    	k=max(kk,nn);
    	n=min(kk,nn);
    	a=b=f=0;
    	while(1)
    	{
    		d=(dx-a*k);
    		if(d<0)
    		break;
    		if(d%n==0)
    		{
				b=d/n;
				if(a*n+b*k==dy)
				{
					f=1;
					printf("TAK\n");
					break;
				}
			}
			a++;
    	}
    	if(f==0)
    	printf("NIE\n");
    }
	return 0;
}

