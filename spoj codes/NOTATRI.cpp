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
#define SET(p) memset(p,-1,sizeof(p))
#define ALL(p) p.begin(),p.end()
#define CLR(p) memset(p,0,sizeof(p))
#define FILL(p,v) memset(p,v,sizeof(p))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(p,b) make_pair(p,b)
#define min3(p,b,c) min(p,min(b,c))
#define max3(p,b,c) max(p,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL unsigned
#define MX 2001
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
int p[MX],n;

int search(int start, int end, int val)
{
	int mid, i;
	while(start <= end)
	{
		if(p[start] > val) return start;
		if(p[end] <= val) return end+1;
		mid = (start + end) / 2;
		if(p[mid] > val) end = mid - 1;	
		else if(p[mid] < val) start = mid + 1;
		else if(p[mid] == val)
		{	
			for(i=mid+1; i<n; i++)	
			if(val != p[i])
			return i;
			return i;
		}
	}
	return n;
}
int main()
{
	int t,low,high,cnt,mn,total;
	inp(n);
	while(n)
	{
		cnt=0;
		for(int i=0;i<n;i++)
		inp(p[i]);
		sort(p,p+n);
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				int in=search(j+1,n-1,p[i]+p[j]);
				cnt+=n-in;
			}
		}
		printf("%d\n",cnt);
		inp(n);
	}
	return 0;
}
