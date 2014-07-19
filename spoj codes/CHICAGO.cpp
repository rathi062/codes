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
#define MX 10004
#define MOD 1000000007
#define pii pair<int,int>
#define psi pair<string ,int>
#define pdi pair<double,int>
#define pid pair<int,double>

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
bool check[MX];
vector<pid > wgt[MX];
double ver[MX];

void initial(int n)
{
	for(int i=1;i<=n;i++)
	ver[i]=0.0;
}

int main()
{
	int t,v,e,s,d,c,sr,q;
	double wt;
	inp(v);
	while(v!=0)
	{	
		CLR(wgt);
		inp(t);
		for(int ii=1;ii<=t;ii++)
		{
				inp(s);
				inp(d);
				inpd(wt);
				wgt[d].push_back(pid(s,wt));
				wgt[s].push_back(pid(d,wt));
		}
			initial(v);
			CLR(check);
			priority_queue<pdi > q;
			q.push(pdi(100.00,1));
			ver[1]=100.0;
			while(!q.empty())
			{
				int idx=q.top().second;
				double per=q.top().first;
				//printf("\nidx = %d per = %lf",idx,per);
				q.pop();
				if(check[idx]==1)
				continue;
				//cout<<"\ngv";		
				int sz = wgt[idx].size();
				for(int i=0;i<sz;i++)
				{
					int d =wgt[idx][i].first;
					double w =wgt[idx][i].second;
					//cout<<"\nd = "<<d<<" w = "<<w;
					
						if(check[d]==0&&ver[d]<(w*per)/100.0)
						{
							ver[d]=double((w*per)/100.0);
							q.push(pdi(ver[d],d));
						}
				}
				check[idx]=1;
				if(idx==v)
				break;
			}
			printf("%lf percent\n",ver[v]);
			inp(v);
	}
	return 0;
}
