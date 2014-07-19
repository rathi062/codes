
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
#define MX 40001
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
int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}
struct node{
	int x,y;
}nod[MX];
int compare(node a,node b)
{
	return a.x<b.x;
}


int xx[MX],yy[MX];

int main()
{
	int ans,f,i,c,mx,t=0,j,cnt,r,tim,x,y,w,h,xdif,ydif;
	int n,k,s;
	inp(t);
	while(t--)
	{
		inp(w);
		inp(h);
		inp(n);
		xx[0]=yy[0]=0;
		xdif=ydif=0;
		for(i=1;i<=n;i++)
		{
			inp(xx[i]);
			inp(yy[i]);
		}
		xx[n+1]=w+1;
		yy[n+1]=h+1;
		
		sort(xx,xx+n+1);
		sort(yy,yy+n+1);
		
		for(i=1;i<=(n+1);i++)
		if((xx[i]-xx[i-1])>xdif)
		xdif=xx[i]-xx[i-1];
		
		for(i=1;i<=(n+1);i++)
		if((yy[i]-yy[i-1])>ydif)
		ydif=yy[i]-yy[i-1];
		
		printf("%d\n",(xdif-1)*(ydif-1));
	}
	return 0;
}

