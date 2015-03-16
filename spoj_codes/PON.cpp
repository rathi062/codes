#include<iostream>
#include<list>
#include<string>
#include<cstring>
//#include<sstream>
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
#define MX 1000006
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

LL mulmod(LL a,LL b, LL c)
{
	LL x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		x=(x+y)%c;
		y=(y*2)%c;
		b/=2;
	}
	return x%c;
}
LL modulo(LL a,LL b,LL c)
{
	LL x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
			x=(x*y)%c; //x = mulmod(x,y,c)
		y=(y*y)%c; // y =mulmod(y,y,c);
		b/=2;
	}
	return x%c;
}

bool miller(LL p,int iteration)
{
	if(p<2)
	return false;
	if( p!=2 && p%2==0)
	return false;
	LL s=p-1;
	while(s%2==0)
		s/=2;
	for(int i=0;i<iteration;i++)
	{
		LL a=rand()%(p-1)+1,tmp=s;
		LL mod=modulo(a,tmp,p);
		while( tmp!=p-1 && mod!=1 && mod!=p-1 )
		{
			mod=mulmod(mod,mod,p);
			tmp*=2;
		}
		if(mod!=p-1 && tmp%2==0)
		return false;
	}
	return true;
}

int main()
{
	LL p;
	int t;
	inp(t);
	while(t--)
	{
		inpll(p);
		if(miller(p,20))
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
