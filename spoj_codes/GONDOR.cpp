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

#define INF (1<<30)	
#define cls(a) memset(a,-1,sizeof(a))
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
#define MX 1003
#define MOD 1000000007
#define pdi pair<double,int>
#define psi pair<string,int>

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
struct archer{
	int x,y,a;
}node[101];
int aim[101][101];
bool check[MX];
int n;
double ver[MX];
void initial(int n)
{
	for(int i=0;i<=n;i++)
	{
		check[i]=0;
		ver[i]=INF;
	}
}
void dijkstra(double tym,int s)
{
	priority_queue<pdi , vector<pdi> ,greater<pdi> > q;
	q.push(pdi(tym,s));
	int idx;
	ver[s]=0.00000;
	while(!q.empty())
	{
		
		idx=q.top().second;
		//cout<<"\nidx = "<<idx;
		double tm=q.top().first;
		q.pop();
		if(check[idx]==1)
		continue;
		check[idx]=1;
		int xi,yi,ar;
		xi=node[idx].x;
		yi=node[idx].y;
		ar=node[idx].a;
		//cout<<"\nxi = "<<xi<<" yi = "<<yi<<" ar = "<<ar;
		for(int i=0;i<n-1&&ar>0;i++)
		{
			int t=aim[idx][i];
			int xj,yj;
			xj=node[t].x;
			yj=node[t].y;
			//cout<<"\nt = "<<t<<" xj = "<<xj<<" yj = "<<yj;
			double dis=sqrt((xj-xi)*(xj-xi)+(yj-yi)*(yj-yi));
			//cout<<" dis = "<<dis;
			//cout<<"\nver[t] = "<<ver[t]<<" ver[idx] = "<<ver[idx];
				if(check[t]==0&&ver[t]>ver[idx])
				{
					ver[t]=min(ver[t],ver[idx]+dis);
					q.push(pdi(ver[t],t));
					ar--;
				}
		}
	}
}
int main()
{
	inp(n);	
	initial(n);
	for(int i=1;i<=n;i++)
	{
		inp(node[i].x);
		inp(node[i].y);
		inp(node[i].a);
		for(int j=0;j<n-1;j++)
		inp(aim[i][j]);
		
		
	}
	double tym=0.000000;
	dijkstra(tym,1);
	for(int i=1;i<=n;i++)
	printf("%lf\n",ver[i]);
	return 0;
}
