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
int R,C,line;
char s[MX][MX];
bool check[MX][MX];
int trap[MX][MX];
void DFS(int i,int j)
{
	
	if(i<0||i>=R||j<0||j>=C||check[i][j])
	{
		line=trap[i][j];
		return ;
	}
	//cout<<"\n i = "<<i<<" j = "<<j;
	check[i][j]=1;
	trap[i][j]=line;
	if(s[i][j]=='S')
	DFS(i+1,j);
	else
	if(s[i][j]=='W')
	DFS(i,j-1);
	else
	if(s[i][j]=='E')
	DFS(i,j+1);
	else
	DFS(i-1,j);
	trap[i][j]=line;
}
int main()
{
	inp(R);
	inp(C);
	line=0;
	for(int i=0;i<R;i++)
	scanf("%s",&s[i]);
	
	int cnt=0;
	CLR(check);
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		if(check[i][j]==0)
		{
			line=cnt+1;
			
			//cout<<"\ni = "<<i<<" j = "<<j;
			DFS(i,j);
			if(line>cnt)
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
