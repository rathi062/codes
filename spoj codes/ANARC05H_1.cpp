
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
#define MX 100000
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
int val[26][26],sum[26][26];
bool ch[26][26];
int fun(int l,int line,int s)
{
	int p=0;
	//cout<<"\nline = "<<line<<" s = "<<s;
	if(line>l)
	{
		return 1;
	}
	for(int i=line;i<=l;i++)
	{
		if(ch[line][i]==1)
		{
			if(sum[line][i]>=s)
			p+=val[line][i];
		}
		else
		{	
			if(sum[line][i]>=s)
			{
				ch[line][i]=1;
				val[line][i]=fun(l,i+1,sum[line][i]);
				p+=val[line][i];
				//cout<<"\nline = "<<line<<" i = "<<i<<" p = "<<p;
			}
		}
	}
	return p;
}
int main()
{
	int l,n,ans,cnt=1;
	string s;
	while(1)
	{
		cin>>s;
		if(s=="bye")
		break;
		CLR(sum);
		CLR(ch);
		CLR(val);
		l=s.size();
		for(int i=0;i<l;i++)
		{
			n=s[i]-48;
			for(int j=1;j<=i+1;j++)
			sum[j][i+1]=sum[j][i]+n;
		}
		/*for(int i=1;i<=l;i++)
		{
			for(int j=i;j<=l;j++)
			cout<<sum[i][j]<<" ";
			cout<<endl;
		}*/
		ans=fun(l,1,0);
		cout<<cnt++<<". "<<ans<<endl;
	}
	return 0;
}

