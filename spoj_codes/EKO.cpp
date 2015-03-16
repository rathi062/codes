
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
int a[MX];
int main()
{
    int n,k,h,b=0;
    LL m,safe=0,r,wd,sum=0;
    inp(n);
    inpll(m);
    a[0]=0;
	for(int i=1;i<=n;i++)
    {
		inp(a[i]);
		sum+=a[i];
	}
    sort(a,a+n+1);
    k=n;
    for(int i=1;i<=n;i++)
    {
    	h=a[i];
    	safe+=k*(a[i]-a[i-1]);
    	wd=sum-safe;
    	if(wd==m)
    	{
    		b=1;
    		break;
    	}
    	else
		if(wd<m)
    	{
    		while(1)
    		{
    			h--;
    			wd+=k;
    			if(wd>=m)
    			{
    				b=1;
    				break;
    			}
    		}
    	}
    	if(b==1)
    	break;
    	k--;
    }
    printf("%d\n",h);
	return 0;
}

