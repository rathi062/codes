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
struct rating{
	int order,time;
}rat[MX];
int bit[MX],bnum;
LL ans[MX];
void init(int n)
{
	for(bnum=1;bnum<n;bnum*=2);
}
void add(int idx,int num)
{
	while(idx<=bnum)
	{
		bit[idx]+=num;
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
	return ((a.time==b.time)?(a.order<b.order):(a.time<b.time));
}
int main()
{	
    int t;
    inp(t);
    while(t--)
    {
    	 int m,n,k,idx,tm=0,x=-1,y=-1,val,sub=0,tl,t,rm;
         long long sum=0;
		 CLR(bit);
         inp(n);
         init(n);
         for(int i=0;i<n;i++)
         {
               rat[i].order=i+1;
			   inp(rat[i].time);
			   add(i+1,1);
         }
         /*cout<<"\nbit : ";
         for(int i=0;i<=n;i++)
         cout<<bit[i]<<" ";*/
         sort(rat,rat+n,compare);
         /*cout<<"\nsorted array is : \n";
         for(int i=0;i<n;i++)
         cout<<rat[i].time<<" "<<rat[i].order<<endl;*/
         y=0;
         tm=0;
         rm=0;
         for(int i=0;i<n;i++)
         {
         	x=rat[i].time;
         	if(x==y)
         	{
         		tl=find(rat[i].order);
         		sum+=tl-find(rat[i-1].order);
         		ans[rat[i].order]=sum;
         		rm=bit[bnum]-tl;
				add(rat[i].order,-1);
				y=x;
         	}
         	else
         	{
         		sum+= rm;
         		sum+= bit[bnum]*(x-1-tm);
         		tm+= (x-y);
         		tl= find(rat[i].order);
         		sum+= tl;
         		ans[rat[i].order]=sum;
         		rm=bit[bnum]-tl;
         		add(rat[i].order,-1);
				y=x;
         	}
    	}
        for(int i=1;i<=n;i++)
        printf("%lld\n",ans[i]);	
    }
    return 0;
}
