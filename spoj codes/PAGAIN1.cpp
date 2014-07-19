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
#define LL unsigned
#define MX 1000001
#define MAX 1000001
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
unsigned c[MX];
unsigned primes[MX],len;
#define ifC(n) (c[n>>6]&(1<<((n>>1)&31)))
#define isC(n) (c[n>>6]|=(1<<((n>>1)&31)))

void sieve() {
unsigned i, j, k;
for(i = 3; i < 1001; i += 2)
if( !ifC(i) )
for(j = i*i, k = (i<<1); j < MAX; j += k)
isC(j);
for(i = 3, j = 0; i<MAX; i += 2)
if( !ifC(i) )
primes[j++] = i;
len=j;
}
bool check(LL n)
{
	for(LL i=0;i<len&&i*i<=n;i++)
	{
		if( n%primes[i]==0)
		return false;
	}
	return true;
}
int main()
{
	LL p;
	int t;
	sieve();
	inp(t);
	while(t--)
	{
		scanf("%u",&p);
		if(p%2)
		p-=2;
		else
		p--;
		if(p<MX)
		{
			for(;;p-=2)
			if(!ifC(p))
			{
				printf("%u\n",p);
				break;
			}
		}
		else
		{
			for(;;p-=2)
			{
				if(check(p))
				{
					printf("%u\n",p);
					break;
				}
			}
		}
	}
	return 0;
}
