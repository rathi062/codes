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


using namespace std;
int sml[MX];
bool c[MX];
void seive()
{
	c[0]=1;
	c[1]=1;
	//printf("%lld\n",l);
	for(int i=2;i<MX;i++)
	{
		if(i&1)
		sml[i]=i;
		else
		{
			c[i]=1;
			sml[i]=2;
		}
	}
	c[2]=0;
	for(int i=3;i<=1000;i+=2)
	if(sml[i]==i)
	{
		for(int j=i*i,d=i<<1;j<MX;j+=d)
		{
			c[j]=1;
			if(sml[j]==j)
			sml[j]=i;
		}
	}
}
int dn(int n)
{
	int val=1,cnt=0,prv=0;
	while(n>1)
	{
		if(sml[n]!=prv)
		{
			val*=(1+cnt);
			prv=sml[n];
			cnt=1;
		}
		else
		cnt++;
		n/=sml[n];
	}
	return val*(cnt+1);
}
int main()
{
	int n,cnt=0;
	seive();
	//for(int i=3;i<100;i+=2)
	//cout<<sml[i]<<" ";
	for(int i=2;i<MX;i++)
	{
		int ret=dn(i);
		int othr=ret/sml[ret];
		if(othr!=sml[ret]&&!c[othr])
		{
			cnt++;
			if(cnt==9)
			{
				printf("%d\n",i);
				cnt=0;
			}
		}
	}
	return 0;
}
