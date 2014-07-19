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
#define MX 400000
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
//int arr[3003][3003];
struct rating{
	int order,a,h;
}rat[MX];
int bit[MX],bnum,ans[MX];
void add(int idx)
{
	while(idx<=bnum)
	{
		bit[idx]+=1;
		idx+=idx & -idx ;
	}
}
int find(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=bit[idx];
		idx-=idx & -idx;
	}
	return sum;
}
int compare(const rating a,const rating b)
{
	return ((a.a==b.a)?(a.h<b.h):(a.a<b.a));
}
int main()
{
    
         int m,n,k,idx,x=-1,y=-1,val,sub=0;
         bnum=200000;
         CLR(bit);
         inp(n);
         for(int i=0;i<n;i++)
         {
               rat[i].order=i+1;
			   inp(rat[i].a);
               inp(rat[i].h);
         }
         sort(rat,rat+n,compare);
         for(int i=0;i<n;i++)
         {
         	if(x==rat[i].a&&y==rat[i].h)
         	sub++;
         	else
         	sub=0;
         	x=rat[i].a;
         	y=rat[i].h;
			ans[rat[i].order]=find(rat[i].h)-sub;
			add(rat[i].h);
         }
         for(int i=1;i<=n;i++)
         printf("%d\n",ans[i]);
    return 0;
}
