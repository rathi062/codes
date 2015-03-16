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
#define MX 105
#define MOD 1000000007

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
char s[5];
bool take[MX];
int k;
struct trn{
	int idx;
	LL val;
}at[MX];

int compare(const trn a,const trn b)
{
	return (a.val==b.val)?(a.idx<b.idx):(a.val>b.val);
}

int fun(int i,LL n)
{
	if(n==0)
	return 1;
	if(i==k+1||n<0)
	return 0;
	take[at[i].idx]=1;
	int ret = fun(i+1,n-at[i].val);
	if(ret) return 1;
	take[at[i].idx]=0;
	ret = fun(i+1,n);
	return ret;
}
int main()
{
    int t=0,w,cnt=1;
    LL n;
    inp(t);
    while(t--)
    {
    	CLR(take);
    	inpll(n);
    	inp(k);
    	for(int i=1;i<=k;i++)
    	{
    		inp(w);
    		at[i].idx=i;
    		at[i].val=2*at[i-1].val+w;
  		}
    	sort(at+1,at+k+1,compare);
    	/*for(int i=1;i<=k;i++)
    	cout<<at[i].idx<<" "<<at[i].val<<endl;
    	cout<<endl;	
    	cnt=fun(1,n);*/
    	cnt=0;
    	for(int i=1;i<=k;i++)
    	{
    		if(at[i].val<=n)
    		{
    			take[at[i].idx]=1;
    			n-=at[i].val;
    		}
    		if(n==0)
    		{
    			cnt=1;
    			break;
    		}
    	}
    	if(cnt)
    	{
    		for(int i=1;i<=k;i++)
    		if(take[i])
    		printf("%d ",i);
    		cout<<endl;
    	}
    	else
    	printf("-1\n");
    }
    return 0;
}
