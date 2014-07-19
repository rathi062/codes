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

bool flag[MX];
struct Node{
	int p;
	char c;
}pre[MX];

int n,q[MX];

int mod(int f,int s)
{
	if(f<s) return f;
	else return f%s;
}
void BFS(int st)
{
	flag[st]=1;
	int in,out,nw[2],rem;
	in=out=0;
	q[in++]=st;
	pre[st].p=-1;
	pre[st].c='1';
	while(out<in)
	{
		rem=q[out++];
		nw[0]=mod((rem*mod(10,n)),n);
		nw[1]=mod(nw[0]+1,n);
		for(int i=0;i<2;i++)
		{
			if(!flag[nw[i]])
			{
				pre[nw[i]].p=rem;
				pre[nw[i]].c='0'+i;
				if(nw[i]==0)
				return ;
				flag[nw[i]]=1;
				q[in++]=nw[i];
			}
		}
	}
}
void path(int i)
{
	if(i==-1)
	return ;
	path(pre[i].p);
	putchar(pre[i].c);
}
int main()
{
    int t=0,w,cnt=1;
	inp(t);
    while(t--)
    {
    	inp(n);
    	if(n==1)
    	{
    		printf("1\n");
    		continue;
    	}
    	for(int i=0;i<=n;i++)
    	flag[i]=0;
    	BFS(1);
    	path(0);
    	printf("\n");
    }
    return 0;
}
