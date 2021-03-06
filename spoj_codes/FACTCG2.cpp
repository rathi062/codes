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


using namespace std;
bool c[MX];
vector<int> v,lst[MX];
void seive()
{
	c[0]=1;
	c[1]=1;
	//printf("%lld\n",l);
	for(int i=2;i<MX;i+=2)
	{
		c[i]=1;
		lst[i].PB(2);
	}
	for(int i=3;i<3164;i+=2)
	{
		if(!c[i])
		{
			for(int j=i*2;j<MX;j+=i)
			{
				c[j]=1;
				lst[j].PB(i);
			}
		}
	}
	v.push_back(2);
	for(int i=3;i<1000001;i+=2)
	if(!c[i])
	v.push_back(i);
}

int main()
{
	int n,no;
	seive();
	while(inp(n))
	{
		printf("1");
		if(!c[n])
		printf(" x %d",n);
		else
		{
			no=n;
			int sz=lst[no].size();
			//cout<<"\nsz = "<<sz;
			for(int i=0;i<sz;i++)
			{
					while(n%lst[no][i]==0)
					{
						printf(" x %d",lst[no][i]);
						n/=lst[no][i];
					}
			}
			if(n!=1)
			printf(" x %d",n);
		}
		printf("\n");
	}
	return 0;
}
