#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>

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
#define MX 101
#define MOD 1000000007

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
bool ch[MX][MX];
char avl[MX][MX];
int dst[1<<5][101][101];
int ans,R,C,cnt,sx,sy;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void initial()
{
	for(int k=0;k<16;k++)
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
			dst[k][i][j]=INF;
}
int BFS(int x,int y)
{
	int vi,vj,vm,ui,uj,um,mn=INF;
	queue<int> q;
	dst[0][x][y]=0;
	q.push(x);
	q.push(y);
	q.push(0);
	//cout<<"\nx = "<<x<<" y = "<<y;
	while(!q.empty())
	{
		ui=q.front();
		q.pop();
		uj=q.front();
		q.pop();
		um=q.front();
		q.pop();
		//cout<<"\nui = "<<ui<<" uj = "<<uj<<" um = "<<um;
		for(int i=0;i<4;i++)
		{
			vi=ui+dx[i];
			vj=uj+dy[i];
			vm=um;
			if(vi<0||vj<0||vi>=R||vj>=C||avl[vi][vj]=='#')
			continue;
			else
			{
				if(islower(avl[vi][vj]))
				vm|=(1<<(avl[vi][vj]-'a'));
				if(isupper(avl[vi][vj]))
				{
					if(avl[vi][vj]!='X')
					{
						int tmp=vm;
						//cout<<" tmp = "<<tmp;
						vm|=(1<<(avl[vi][vj]-'A'));
						if(vm!=tmp)
						continue;
					}
				}
				if(dst[vm][vi][vj]>dst[um][ui][uj]+1)
				{
					//cout<<" dst ";
					dst[vm][vi][vj]=dst[um][ui][uj]+1;
					if(avl[vi][vj]=='X')
					{
						//cout<<" X ";
						if(dst[vm][vi][vj]<mn)
						mn=dst[vm][vi][vj];
					}
					q.push(vi);
					q.push(vj);
					q.push(vm);
				}
			}
		}
	}
	return mn;
}
int main()
{
	inp(R);
	inp(C);
	while(C!=0&&R!=0)
	{
		CLR(avl);
		for(int i=0;i<R;i++)
		{
			scanf("%s",&avl[i]);
		}
		cnt=0;
		for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			if(avl[i][j]=='*')
			{
				sx=i;
				sy=j;
			}
			else
			if(avl[i][j]=='Y')
			avl[i][j]='A';
			else
			if(avl[i][j]=='R')
			avl[i][j]='C';
			else
			if(avl[i][j]=='G')
			avl[i][j]='D';
			else
			if(avl[i][j]=='y')
			avl[i][j]='a';
			else
			if(avl[i][j]=='r')
			avl[i][j]='c';
			else
			if(avl[i][j]=='g')
			avl[i][j]='d';
		}
		initial();
		//cout<<"\nx1 = "<<x1<<" y1 = "<<y1<<"\nx2 = "<<x2<<" y2 = "<<y2;
		ans=BFS(sx,sy);
		//cout<<"\ntotal = "<<total<<" ans = "<<ans;
		if(ans==INF)
		printf("The poor student is trapped!\n");
		else
		printf("Escape possible in %d steps.\n",ans);
		inp(R);
		inp(C);
	}
	return 0;
}
