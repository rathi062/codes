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
#define MX 20
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
bool ch[MX][MX],avl[MX][MX];
int ans,R,C;
int dx[8]={-2,-2,-1,1,2,2,-1,1};
int dy[8]={1,-1,2,2,-1,1,-2,-2};

void DFS(int x,int y,int vst)
{
	//cout<<"\nx = "<<x<<" y = "<<y;
	if(x<0 || y<0 || avl[x][y]==0 || ch[x][y]==1)
	return ;
	//cout<<" ver[x][y] = "<<ver[x][y];
	ch[x][y]=1;
	if(vst>ans)
	ans=vst;
	for(int i=0;i<8;i++)
	DFS(x+dx[i],y+dy[i],vst+1);
	ch[x][y]=0;
}
int main()
{
	int cnt=1;
	inp(R);
	while(R!=0)
	{
		int lv,fl,total=0;
		CLR(ch);
		CLR(avl);
		for(int i=0;i<R;i++)
		{
			inp(lv);
			inp(fl);
			for(int j=0;j<fl;j++)
			{
				avl[i][j+lv]=1;
				total++;
			}
		}
		ans=0;
		//cout<<"\nx1 = "<<x1<<" y1 = "<<y1<<"\nx2 = "<<x2<<" y2 = "<<y2;
		DFS(0,0,1);
		//cout<<"\ntotal = "<<total<<" ans = "<<ans;
		if(total-ans!=1)
		printf("Case %d, %d squares can not be reached.\n",cnt++,total-ans);
		else
		printf("Case %d, %d square can not be reached.\n",cnt++,1);
		
		inp(R);
	}
	return 0;
}
