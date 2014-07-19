
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
#define MX 20002
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
int a[MX];
queue<int> q;
int main()
{
	int t,n;
	inp(t);
	while(t--)
	{
		inp(n);
		while(!q.empty())
		q.pop();
		int i=1,sz,idx=0,p,l;
		for(int i=0;i<n;i++)
		q.push(i);
		i=1;
		/*p=q.front();
		q.pop();
		q.push(p);
		a[q.front()]=i++;
		q.pop();*/
		while(i<=n)
		{
			sz=q.size();
			l=i%sz;
			for(int j=0;j<l;j++)
			{
				p=q.front();
				q.pop();
				q.push(p);
			}
			//cout<<"\nidx = "<<q.front()<<" val = "<<i;
			a[q.front()]=i++;
			q.pop();
		}
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
