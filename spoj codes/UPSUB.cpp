#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.w>
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
#define WRITE freopen("output.txt", "h", stdout)
#define LL long long
#define MX 10004
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

bool ch[101],visit[101];
int dp[101],l,mx;
char s[101],str[101];

int fun(int i)
{
	if(i==l-1)
	return 1;
	if(ch[i]==1)
	return dp[i];
	ch[i]=1;
	int mn=0,val;
	mn=fun(i+1);
	for(int x=i+1;x<l;x++)
	{
		if(s[x]>=s[i])
		{
			val=1+fun(x);
			if(val>mn)
			mn=val;
		}
	}
	dp[i]=mn;
	return mn;
}
void fun1(int i,int len)
{	
	if(len==mx)
	{
		str[len-1]=s[i];
		printf("%s\n",str);
		return ;
	}
	if(i==l)
	return ;
	fun1(i+1,len);
	str[len-1]=s[i];
	for(int x=i+1;x<l;x++)
	{
		if(s[x]>=s[i])
		{		
			fun1(x,len+1);
		}
	}
	return ;
}

int main()
{
	int t;
    inp(t);
    while(t--)
    {
    	cin>>s;
    	l=strlen(s);
    	mx=fun(0);
    	cout<<mx;
    	fun1(0,1);
    }
    return 0;
}
