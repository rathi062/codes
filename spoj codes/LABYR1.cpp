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
#define MX 1003
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
struct node{
	int d,v;
};
typedef struct node node;
bool check[MX][MX];
char v[MX][MX];
int ver[MX][MX],C,R;
pii BFS(pii strt)
{
	CLR(ver);
	CLR(check);	
	queue<pii> q;
	q.push(strt);
	ver[strt.F][strt.S]=1;
	while(!q.empty())
	{
		pii idx = q.front();
		
		q.pop();
		int x=idx.first;
		int y=idx.second;
		//cout<<"\ni = "<<x<<" j = "<<y;
		if(check[x][y]==1)
		continue;	
		
						if(y<C&&v[x][y+1]=='.'&&check[x][y+1]==0&&ver[x][y+1]<ver[x][y]+1)
						{
							ver[x][y+1]=ver[x][y]+1;
							q.push(pii(x,y+1));
						}
						if(x<R&&v[x+1][y]=='.'&&check[x+1][y]==0&&ver[x+1][y]<ver[x][y]+1)
						{
							ver[x+1][y]=ver[x][y]+1;
							q.push(pii(x+1,y));
						}
						if(y>0&&v[x][y-1]=='.'&&check[x][y-1]==0&&ver[x][y-1]<ver[x][y]+1)
						{
							ver[x][y-1]=ver[x][y]+1;
							q.push(pii(x,y-1));
						}
						if(x>0&&v[x-1][y]=='.'&&check[x-1][y]==0&&ver[x-1][y]<ver[x][y]+1)
						{
							ver[x-1][y]=ver[x][y]+1;
							q.push(pii(x-1,y));
						}
						check[x][y]=1;
	}
	int mx=0,inx=0,iny=0;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			//cout<<ver[i][j]<<" ";
			if(mx<ver[i][j])
			{
				mx=ver[i][j];
				inx=i;
				iny=j;
			}
		}
		//cout<<endl;
	}
	//cout<<"\nv = "<<ver[in];
	return pii(inx,iny);
}
int main()
{
	int t,n,a,b,l;
	inp(t);
	while(t--)
	{
		CLR(v);
		LL mx=0;
		node temp;
		inp(C);
		inp(R);
		for(int i=0;i<R;i++)
			scanf("%s",&v[i]);
		pii fst,scnd;
		b=0;
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			if(v[i][j]=='.')
			{
				b=1;
				fst=BFS(pii(i,j));
				break;
			}
			if(b) break;
		}
		scnd=BFS(fst);
		printf("Maximum rope length is %d.\n",ver[scnd.first][scnd.second]-1);
	}
	return 0;
}


