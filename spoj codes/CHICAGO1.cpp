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
double wgt[MX][MX];
double ver[MX][MX];

void initial(int n)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	wgt[i][j]=0.0;
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
				wgt[s][d]=wgt[d][s]=wt/100.0;
		}
		for(int k=1;k<=v;k++)
		{
			for(int i=1;i<=v;i++)
			{
				for(int j=1;j<=v;j++)
				{
					wgt[i][j]=max(wgt[i][j],wgt[i][k]*wgt[k][j]);
				}
			}
		}
		printf("%lf percent\n",wgt[1][v]*100.0);
		inp(v);
	}
	return 0;
}
