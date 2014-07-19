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
#define MX 10001
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
bool ch[MX];
int p[MX][MX],c[MX],a[MX];
int mn=1000000000;
void fun(int c,int sum,int no,int num)
{
	if(sum>mn)
	{
		return ;
	}
	else
	{
		ch[c]=1;
		for(int i=c-1;i>0;i--)
		{
			if(ch[i]==0)
			{
				int s=sum+p[c][i];
				ch[i]=1;
				if(no==num)
				{
					if(mn>s)
					mn=s;
				}
				else
				{
					int k=no*2;
					while(ch[k]!=0)
					k--;
					fun(k,s,no,num+1);
				}
				ch[i]=0;
			}
		}
		ch[c]=0;
	}
}
int main()
{
	int n;
	inp(n);
	for(int i=0;i<n;i++)
	{
		inp(c[i]);
		inp(a[i]);
	}
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<i;j++)
		p[i][j]=c[i-1]+a[j-1];
	}
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<i;j++)
		cout<<p[i][j]<<" ";
		cout<<endl;
	}
	fun(n,0,n/2,1);
	printf("%d\n",mn);
    return 0;
}
