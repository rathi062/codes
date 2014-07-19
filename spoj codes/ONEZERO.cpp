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
#define MX 10000007
#define MOD 100000000

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
vector<unsigned long long> s;
unsigned long long a[MX];
void fun()
{
	queue<unsigned LL> st;
	st.push(1);
	s.push_back(1);
	double no,nw;
	for(int i=0;i<10000007;i++)
	{
		no=st.front();
		st.pop();
		nw=no*10;
		st.push(nw);
		st.push(nw+1);
		s.push_back(nw);
		s.push_back(nw+1);
	}
	printf("i = %d num = %lld\n",1000000,s[1000000]);
	for(int i=1;i<=400;i++)
	{
		for(int j=0;j<20000;j++)
		{
			//int d=s[j]/i;
			if(s[j]%i==0)
			{
				a[i]=s[j];
				break;
			}
		}
		printf("i = %d num = %lld\n",i,a[i]);
	}
}
int main()
{
    int t=0,w,cnt=1;
    double n=0;
    fun();
	inp(t);
    while(t--)
    {
    	inp(n);
    	//printf("%lf\n",a[n]);
    }
    return 0;
}
