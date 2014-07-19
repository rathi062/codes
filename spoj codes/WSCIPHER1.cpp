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

int main()
{
	int k1,k2,k3;
	char s[101],ans[101];
	inp(k1);
	inp(k2);
	inp(k3);
	while(k1|k2|k3)
	{
		vector<int> v1,v2,v3;
		CLR(s);
		scanf("%s",&s);
		int sz=strlen(s);
		for(int i=0;i<sz;i++)
        {
                if(int(s[i])>=97&&int(s[i])<106)
                {
                        v1.PB(i);
                }
                else
                if(int(s[i])>=106&&int(s[i])<115)
                {
                		v2.PB(i);  	
                }
                else
            	if((int(s[i])>=115&&int(s[i])<123)||int(s[i])==95)
                {
                       	v3.PB(i);
                }
        }
        sz=v1.size();
		for(int i=0;i<sz;i++)
		{
			int in=i+k1;
			if(in>=sz)
			{
				in%=sz;
			}
			ans[v1[in]]=s[v1[i]];	
		}
		
        sz=v2.size();
		for(int i=0;i<sz;i++)
		{
			int in=i+k2;
			if(in>=sz)
			{
				in%=sz;
			}
			ans[v2[in]]=s[v2[i]];	
		}
		sz=v3.size();
		for(int i=0;i<sz;i++)
		{
			int in=i+k3;
			if(in>=sz)
			{
				in%=sz;
			}
			ans[v3[in]]=s[v3[i]];	
		}
		sz=strlen(s);
		for(int i=0;i<sz;i++)
		printf("%c",ans[i]);
		printf("\n");
		inp(k1);
		inp(k2);
		inp(k3);
	}
	return 0;
}
