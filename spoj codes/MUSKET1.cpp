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
#define MX 101
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
bool ch[MX][MX],arr[MX],check[MX][MX][MX];
int dp[MX][MX][MX],n;
char a[MX][MX];
void fun(int p,int q)
{
	//cout<<"\np = "<<p<<" q = "<<q;
	int i,j;
	i=p>n?p%n:p;
	j=q>n?q%n:q;
	if(ch[i][j]==1)
	return ;
	
	ch[i][j]=1;
	if(i==j)
	{
		dp[i][i][0]=1;
		dp[i][i][1]=i;
		return ;	
	}
	int k,l,m,n1,n2,x,y;
	for(k=p;k<q;k++)
	{
		fun(p,k);
		fun(k+1,q);
		l=k>n?k%n:k;
		m=(k+1)>n?(k+1)%n:(k+1);
		//cout<<"\ni = "<<p<<" j = "<<q;
		for(x=1;x<=dp[i][l][0];x++)
		{
				n1=dp[i][l][x];
				for(y=1;y<=dp[m][j][0];y++)
				{
						n2=dp[m][j][y];
						//cout<<"\n  x = "<<x<<" y = "<<y<<" a = "<<a[x-1][y-1]<<" i = "<<i<<" j = "<<j;
						if(a[n1-1][n2-1]=='1')
						{
							if(check[i][j][n1]==0)
							{
								dp[i][j][0]++;
								dp[i][j][dp[i][j][0]]=n1;
								check[i][j][n1]=1;
							}
						}
						else
						{
							if(check[i][j][n2]==0)
							{
								dp[i][j][0]++;
								dp[i][j][dp[i][j][0]]=n2;
								check[i][j][n2]=1;
							}
						}
				}
				
			
		}
	}
	//cout<<"\nw = "<<w<<" h = "<<h<<" dp[w][h] = "<<dp[w][h];
	return ;
}

int main()
{
	int t;
    inp(t);
    while(t--)
    {
    	inp(n);
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	//cout<<"\ninput complete !! ";
    	CLR(dp);
    	CLR(ch);
    	CLR(check);
    	CLR(arr);
    	int l,m,cnt=0;
    	for(int i=0;i<n;i++)
    	{
    		fun(1+i,n+i);
    		l=1+i;
    		m=i==0?n:i;
    		//cout<<"\n\nst = "<<i+1<<" ed = "<<n+i<<endl;
    		for(int j=1;j<=n;j++)
    		{
    			//cout<<"\nj = "<<j<<dp[l][m][j];
    			if(check[l][m][j]==1)
    			arr[j]=1;
    		}
    	}
    	for(int i=1;i<=n;i++)
    	if(arr[i]==1)
    	cnt++;
    	cout<<cnt<<endl;
    	for(int i=1;i<=n;i++)
    	if(arr[i]==1)
    	cout<<i<<endl;
    }
	return 0;
}
