
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
#define MX 10
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

struct Node{
	int val,time,n;
}a[MX];
int compare(Node a,Node b)
{
	return (a.time==b.time)?(a.val<b.val):(a.time<b.time);
}
int main()
{
	int t,p,c,in;
	inp(t);
	while(t--)
	{
		inp(p);
		inp(c);
		int min=1000000;
		for(int i =0;i<c;i++)
		{
			inp(a[i].val);
			a[i].time=a[i].val;
			a[i].n=2;
		}
		/*for(int j=0;j<c;j++)
		cout<<a[j].time<<" ";
		cout<<endl;*/
		for(int i=0;i<p-1;i++)
		{
			//cout<<"\ni = "<<i<<" time = "<<a[0].time;
			//sum+=a[0].time;
			min=1000000;
			for(int j=0;j<c;j++)
			{
				if(a[j].time<min)
				{
					in=j;
					min=a[j].time;
				}
			}
			a[in].time+=a[in].val*a[in].n++;
			/*for(int j=0;j<c;j++)
			cout<<a[j].time<<" ";
			cout<<endl;*/
		}
		min=1000000;
		for(int j=0;j<c;j++)
		{
				if(a[j].time<min)
				{
					in=j;
					min=a[j].time;
				}
		}
		printf("%d\n",a[in].time);
	}
}
