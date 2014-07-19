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
#define MX 33
#define MOD 1000000007
#define pii pair<int,int>
#define F first 
#define S second 


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

bool check[MX][MX];
char v[MX][MX];
int ver[MX][MX],C,R;
pii fst,scnd;
void initial()
{
	for(int i=0;i<R;i++)
	for(int j=0;j<C;j++)
	ver[i][j]=INF;
}
void BFS(pii strt)
{
	initial();
	CLR(check);	
	int val;
	priority_queue<pii , vector<pii> ,greater<pii> > q;
	q.push(strt);
	ver[strt.F][strt.S]=0;
	while(!q.empty())
	{
		pii idx = q.top();
		q.pop();
		int x=idx.first;
		int y=idx.second;
		
		if(check[x][y]==1)
		continue;	
		check[x][y]=1;
		//cout<<"\ni = "<<x<<" j = "<<y;
		
		
		
						val=v[x][y+1]-48;
						if(y<C-1&&v[x][y+1]!='X'&&check[x][y+1]==0&&ver[x][y+1]>ver[x][y]+val)
						{
							
							ver[x][y+1]=ver[x][y]+val;
							q.push(pii(x,y+1));
						}
						val=v[x+1][y]-48;
						if(x<R-1&&v[x+1][y]!='X'&&check[x+1][y]==0&&ver[x+1][y]>ver[x][y]+val)
						{
							ver[x+1][y]=ver[x][y]+val;
							q.push(pii(x+1,y));
						}
						val=v[x][y-1]-48;
						if(y>0&&v[x][y-1]!='X'&&check[x][y-1]==0&&ver[x][y-1]>ver[x][y]+val)
						{
							ver[x][y-1]=ver[x][y]+val;
							q.push(pii(x,y-1));
						}
						val=v[x-1][y]-48;
						if(x>0&&v[x-1][y]!='X'&&check[x-1][y]==0&&ver[x-1][y]>ver[x][y]+val)
						{
							ver[x-1][y]=ver[x][y]+val;
							q.push(pii(x-1,y));
						}
						
						if(x==scnd.F&&y==scnd.S)
						return;				
	}
}
int main()
{
	int t,n,a,b,l;
	inp(C);
	inp(R);	
	while(C!=0&&R!=0)
	{
		LL mx=0;
		for(int i=0;i<R;i++)
			scanf("%s",&v[i]);
		
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				//cout<<v[i][j]-48<<" ";
				if(v[i][j]=='S')
				fst=pii(i,j);
				else
				if(v[i][j]=='D')
				scnd=pii(i,j);
			}
			//cout<<endl;
		}
		BFS(fst);
		printf("%d\n",ver[scnd.first][scnd.second]-20);
		inp(C);
		inp(R);
	}
	return 0;
}


