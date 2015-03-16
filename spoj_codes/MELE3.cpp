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
#define MX 50004
#define MOD 100000000

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
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
		
int n,flr;
LL ans;
struct act{
	int st,ed;
}node[MX];

int compare(const act a,const act b)
{
	return ((a.st==b.st)?(a.ed>b.ed):(a.st<b.st));
}
void fun(int i,LL tym)
{
	//cout<<"\ni = "<<i<<" tym = "<<tym;
	//system("pause");
	if(i==flr)
	{
		ans=tym;
		return ;
	}
	int in;
	LL tm,mn=INF;
	for(int k=0;k<n;k++)
	{
		if(node[k].st>i)
		break;
		if(node[k].ed<=i)
		continue;
		LL cycle = 2*(node[k].ed-node[k].st);
		LL offset = i - node[k].st;
		LL round = tym/cycle;
		LL rem = tym%cycle;
		//cout<<"\n cycle = "<<cycle<<" offset = "<<offset<<" round = "<<round<<" rem = "<<rem;
		if(rem>offset)
		tm=tym+cycle-rem+offset;
		else
		tm=cycle*round+offset;
		if(tm<mn)
		{
			//cout<<"\n k = "<<k<<" tm = "<<tm;
			mn=tm;
			in=k;
		}
	}
	fun(node[in].ed,mn+node[in].ed-i);
}
int main()
{
    int t=0,w,cnt=1;
    inp(flr);
    inp(n);
		for(int i=0;i<n;i++)
    	{
    		inp(node[i].st);
    		inp(node[i].ed);
    	}
    	sort(node,node+n,compare);
    	/*for(int i=0;i<n;i++)
    	{
    		cout<<"\nst = "<<node[i].st<<" ed = "<<node[i].ed;
    	}*/
    	fun(1,0);
    	printf("%lld\n",ans*5);
    	
    return 0;
}
