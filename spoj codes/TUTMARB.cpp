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
#define MX 10000007
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

#define MAX 10000000
int prime[MAX+1];
bool c[MAX+1];
void sieve(){
	prime[1]=1;
	c[1]=0;
	for(long long int i=2;i<=MAX;i+=2)
	{
		c[i]=1;
		prime[i]=2;
	}
	c[2]=0;
	for(long long int i=3;i<=MAX;i+=2){
		if(!prime[i]){
            prime[i]=i;
			for(long long int j=i*i,d=i<<1;j<=MAX;j+=d){
				c[j]=1;
				if(!prime[j])prime[j]=i;
			}
		}
	}
}
int dn(int n)
{
	int no=n;
	printf("%d = ",n);
	while(c[n])
	{
		printf("%d * ",prime[n]);
		n/=prime[n];
	}
	if(n!=1)
	printf("%d\n",n);
	n=no;
	int val=1,cnt=0,prv=0;
	while(n>1)
	{
		if(prime[n]!=prv)
		{
			val*=(1+cnt);
			prv=prime[n];
			cnt=1;
		}
		else
		cnt++;
		n/=prime[n];
	}
	return int((val*(cnt+1)+1)/2);
}
int main()
{
	int n,cnt=0;
	sieve();
	inp(n);
	while(n)
	{
		printf("With %d marbles, %d different rectangles can be constructed.\n",n,dn(n));
		inp(n);
	}
	return 0;
}
