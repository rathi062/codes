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
#define MX 303
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


using namespace std;
bool ch[MX][MX],diff[MX],chre[MX];
int dp[MX][MX],res[MX];
void sum(int p)
{
	int al=0,bl=0,mx=0,i=0,j=0,r=0,cc;
	cout<<endl;
	for(al=0;ch[p][al];al++){cout<<dp[p][al];}
	cout<<endl;
	for(bl=0;chre[bl];bl++){cout<<res[bl];}
	cout<<"\nal = "<<al<<" bl = "<<bl;
	
	while(1)
	{
		if(i==al&&j==bl)
		break;
		cc=res[j];
		//cout<<"\nc = "<<c<<" cc = "<<cc<<" i = "<<i<<" j = "<<j;
		ch[p][mx]=1;
		dp[p][mx]+=cc;
		r=dp[p][mx]/10;
		dp[p][mx]%=10;
		mx++;		
		dp[p][mx]=r;
		if(i<al)
		i++;
		if(j<bl)
		j++;
	}
	if(r!=0)
	ch[p][mx]=1;
	int k;
	cout<<"\nsum end\n";
	for(k=300;!ch[p][k];k--){}
	for(k;k>=0;k--)
	cout<<dp[p][k];
	cout<<endl;
}	
void mul(int x,int y)
{
	int al,bl;
	CLR(res);
	CLR(chre);
	for(al=0;ch[x][al];al++){}
	for(bl=0;ch[y][bl];bl++){}
	cout<<"\nx = "<<x<<" al = "<<al;
	cout<<"\ny = "<<y<<" bl = "<<bl;
	for(int i=0,p=al-1;p>=0;i++,p--)
	{
		int c=dp[x][p];
		for(int j=0,q=bl-1;q>=0;j++,q--)
		{
			int cc=dp[y][q];
			chre[i+j]=1;
			res[i+j]+=c*cc;
			int d=res[i+j]/10,k=1;
			res[i+j]%=10;
			while(d!=0)
			{
				chre[i+j+k]=1;
				res[i+j+k]+=d;
				d=res[i+j+k]/10;
				res[i+j+k]%=10;
				k++;
			}
		}
	}
	int k;
	cout<<"\nmul nend\n";
	for(k=300;!chre[k];k--){}
	for(k;k>=0;k--)
	cout<<res[k];
	cout<<endl;
}
void fun()
{
	dp[0][0]=1;
	ch[0][0]=1;
	dp[2][0]=1;
	ch[2][0]=1;
	dp[4][0]=2;
	ch[4][0]=1;
	for(int i=6;i<=10;i+=2)
	{
		cout<<"\ni = "<<i<<endl;
		for(int j=2;j<=i;j+=2)
		{
			mul(j-2,i-j);
			sum(i);
		}
		cout<<endl<<dp[i][1]<<dp[i][0];
	}
}

int main()
{
	int n;
	fun();
    inp(n);
    while(n!=-1)
    {
    	
    	/*for(int i=1;i<=2*n;i++)
    	{
    		for(int j=1;j<=2*n;j++)
    		cout<<dp[i][j]<<" ";
    		cout<<endl;
    	}*/
    	inp(n);
    }
	return 0;
}
