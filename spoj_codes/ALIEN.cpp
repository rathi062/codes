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
#define MX 100001
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
unsigned p[MX];
int main()
{
	int t,a,b,st,ed,sum,cnt,max,ms;
	inp(t);
	while(t--)
	{
		st=sum=cnt=max=ms=0;
		inp(a);
		inp(b);
		for(int i=0;i<a;i++)
		{
			scanf("%u",&p[i]);
			sum+=p[i];
			cnt++;
			if(sum>b)
			{
				while(sum>b)
				{
					sum-=p[st++];
					cnt--;
				}
				if(cnt>max||(cnt==max&&sum<ms))
				{
					max=cnt;
					ms=sum;
				}
			}
			else
			{
				if(cnt>max||(cnt==max&&sum<ms))
				{
					max=cnt;
					ms=sum;
				}
			}
		}
		printf("%d %d\n",ms,max);
	}
	return 0;
}
