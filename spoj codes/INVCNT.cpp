
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
#define MX 10000001
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
int a[MX],bit[MX],n,mx;

void add(int idx)
{
     while(idx>0)
     {
         bit[idx]++;
         //cout<<"\nidx = "<<idx<<" bit = "<<bit[idx];
         idx-=idx&(-idx);
     }
}

LL before(int idx)
{
    LL res=0;
    while(idx<=mx)
    {
    	res+=bit[idx];
    	idx+=idx&(-idx);
    }
    return res;
}
int main()
{
    int t,idx,p,val,q,x,y;
	LL ans=0;
    inp(t);
    while(t--)
    {
    	ans=0;
    	mx=0;
		CLR(a);
    	CLR(bit);
    	inp(n);
    	for(int i=1;i<=n;i++)
    	{
			inp(a[i]);
			if(a[i]>mx)
			mx=a[i];
            add(a[i]);
            ans+=before(a[i]+1);
            //cout<<"ans = "<<ans<<endl;
		}
    	printf("%lld\n",ans);
	}
    return 0;
}
