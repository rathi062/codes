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
#define MX 100000
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
struct road{
	int st,ed;
}rd[MX];
LL bit[1025],bnum;
void init(int n)
{
	for(bnum=1;bnum<n;bnum*=2);	
}
void add(int idx)
{
	while(idx>0)
	{
		bit[idx]+=1;
		idx-=idx & -idx ;
	}
}
long long find(int idx)
{
	LL sum=0;
	while(idx<=bnum)
	{
		sum+=bit[idx];
		idx+=idx & -idx;
	}
	return sum;
}
int compare(const road a,const road b)
{
	return ((a.st==b.st)?(a.ed<b.ed):(a.st<b.st));
}
int main()
{
    int t=0,cnt=1;
    inp(t);
    while(t--)
    {
         int m,n,k,idx,x,y,val;
		 LL sum=0;
         CLR(bit);
         inp(m);
         inp(n);
         inp(k);
         init(n);
         for(int i=0;i<k;i++)
         {
               inp(rd[i].st);
               inp(rd[i].ed);
         }
         sort(rd,rd+k,compare);
         //for(int i=0;i<k;i++)
         //printf("\nst = %d ed = %d",rd[i].st,rd[i].ed);
         for(int i=0;i<k;i++)
         {
         	add(rd[i].ed);
         	sum+=find(rd[i].ed+1);
         }
         printf("Test case %d: %lld\n",cnt++,sum);
    }
    return 0;
}
