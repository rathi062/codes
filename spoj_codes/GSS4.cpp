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
#define MX 100009
#define MOD 1000000007

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
long long bit[MX];
long long a[MX],next[MX];
int n;
void update(int idx,LL val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=idx & -idx;
	}
}
int nxtidx(int idx)
{
	int n=next[idx];
	if(idx==n)
	return idx;
	else
	{
		next[idx]=nxtidx(n);
		return next[idx];
	}
}
void change(int x,int y)
{
	int i=nxtidx(x);
	while(i>=x&&i<=y)
	{
		if(a[i]!=1)
		{
			update(i,-a[i]);
			a[i]=(LL)floor(sqrt(a[i]));
			update(i,a[i]);
			if(a[i]==1) next[i]=i+1;
		}
		i=nxtidx(i+1);
	}
}
LL find(int idx)
{
	LL sum=0;
	while(idx>0)
	{
		sum+=bit[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int main()
{
    int c, i, q, cnt=1, st, ed,w,t;
    long long val=1;
    while(inp(n)==1)
    {
    	CLR(bit);
		for(i=1;i<=n;i++)
    	{
			inpll(a[i]);
    		update(i,a[i]);
    		next[i]=i;
    	}
    	printf("Case #%d:\n",cnt++);
       inp(q);
       while(q--)
       {
        inp(t);
        inp(st);
        inp(ed);
        if(st>ed)
        swap(st,ed);
        if(t==1)
        printf("%lld\n",find(ed)-find(st-1));
        else
        change(st,ed);
       }
       cout<<endl;
    }
    return 0;
}


