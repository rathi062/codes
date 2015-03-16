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
#define MX 100
#define MOD 1000000007
#define pii pair<int,int>
#define F first 
#define S second 
#define pip pair<int,pii>
#define ppp pair<int,pip>

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

bool check[MX][MX][MX];
char v[MX][MX][MX];
int ver[MX][MX][MX],C,R,K;
pip fst,scnd;
int main()
{
	int t,n,a,b,l,cnt=1;
	inp(C);
	inp(R);	
	inp(K);
	while(C!=0&&R!=0&&K!=0)
	{
		LL mx=0;
		for(int k=0;k<K;k++)
		for(int i=0;i<R;i++)
			scanf("%s",&v[k][i]);
		
		fst.F=0;
		fst.S.F=0;
		fst.S.S=0;
		//cout<<"\nx = "<<fst.F;
		int dsx=R-1;
		int dsy=C-1;
		CLR(check);
		
			priority_queue<ppp , vector<ppp> ,greater<ppp> > q;
			q.push(ppp(0,fst));
			ver[0][0][0]=0;
			int x,y,z,wt,val,zz;
			while(!q.empty())
			{
				ppp idx=q.top();
				q.pop();
				x=idx.S.S.F;
				y=idx.S.S.S;
				z=idx.S.F;
				wt=idx.F;
				//cout<<"\nx = "<<x<<" y = "<<y<<" z = "<<z<<" wt = "<<wt;
				if(check[z][x][y]==1)
				continue;		
				if(x==dsx&&y==dsy)
				break;
				check[z][x][y]=1;
				zz=(z+1)%K;
				fst.F=zz;
						val=v[zz][x][y+1]-48;
						fst.S.F=x;
						fst.S.S=y+1;
						if(y<C-1&&v[zz][x][y+1]!='1'&&check[zz][x][y+1]==0)
						{
							
							ver[zz][x][y+1]=ver[z][x][y]+1;
							q.push(ppp(ver[zz][x][y+1],fst));
						}
						val=v[zz][x+1][y]-48;
						fst.S.F=x+1;
						fst.S.S=y;
						if(x<R-1&&v[zz][x+1][y]!='1'&&check[zz][x+1][y]==0)
						{
							ver[zz][x+1][y]=ver[z][x][y]+1;
							q.push(ppp(ver[zz][x+1][y],fst));
						}
						val=v[zz][x][y-1]-48;
						fst.S.F=x;
						fst.S.S=y-1;
						if(y>0&&v[zz][x][y-1]!='1'&&check[zz][x][y-1]==0)
						{
							ver[zz][x][y-1]=ver[z][x][y]+1;
							q.push(ppp(ver[zz][x][y-1],fst));
						}
						val=v[zz][x-1][y]-48;
						fst.S.F=x-1;
						fst.S.S=y;
						if(x>0&&v[zz][x-1][y]!='1'&&check[zz][x-1][y]==0)
						{
							ver[zz][x-1][y]=ver[z][x][y]+1;
							q.push(ppp(ver[zz][x-1][y],fst));
						}
						
						val=v[zz][x][y]-48;
						fst.S.F=x;
						fst.S.S=y;
						if(x>0&&v[zz][x][y]!='1'&&check[zz][x][y]==0)
						{
							ver[zz][x][y]=ver[z][x][y]+1;
							q.push(ppp(ver[zz][x][y],fst));
						}
									
			}
		if(ver[z][dsx][dsy]>10000000)
		printf("Case %d: Luke and Leia cannot escape.\n",cnt++);
		else
		printf("Case %d: Luke and Leia can escape in %d steps.\n",cnt++,ver[z][dsx][dsy]);
		inp(C);
		inp(R);
		inp(K);
	}
	return 0;
}


