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
#define MX 100000000
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

bool c[MX+1];
vector<int> v;
int cnt;
void sieve()
{
	cnt=2;
	c[2]=0;
	v.PB(-1);
	v.PB(2);
	for(int i=3;i<=10000;i+=2)
	if(!c[i])
	{
		for(int j=i*i,d=i<<1;j<=MX;j+=d)
		{
			c[j]=1;
		}
	}
	for(int i=3;i<=MX;i+=2)
	if(!c[i]){
		v.PB(i);
		cnt++;
	}
}
/*int search(int i,int j,int n)
{
	if(n<v[i]) return (i-1);
	if(n>v[j]) return (j);
	int mid=(i+j)>>1;
	if(i==j||n==v[mid])
	return mid;
	if(n<v[mid])
	return search(i,mid-1,n);
	else return search(mid+1,j,n);
}*/
int BS(int st, int fn, int val)
{
    int mid;
    while(st <= fn)
    {
        if(val < v[st]) return st-1;
        if(val > v[fn]) return fn;
        mid = (st+fn) / 2;
        if(val == v[mid]) return mid;
        else if(val < v[mid]) fn = mid-1;
        else st = mid+1;
    }
    return cnt-1;
}
int main()
{
	int n;
	double res,r,ct;
	sieve();
	inp(n);
	while(n)
    {
    	ct=BS(0,cnt-1,n);
        res=(n/log(n));
        r=abs(ct-res);
        r=r/ct;
        r*=100;
        printf("%.1lf\n",r);
        inp(n);
    }
	return 0;
}
