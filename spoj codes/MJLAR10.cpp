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
#define MX 1000006
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
bool ch[55];
int main()
{
	int a[3],x[2],cnt[2],mx1,mx2,tmp,ans;
	inp(a[0]);
	inp(a[1]);
	inp(a[2]);
	inp(x[0]);
	inp(x[1]);
	while(a[0])
	{
		CLR(ch);
		cnt[0]=cnt[1]=0;
		for(int i=0;i<2;i++)
		{
			ch[x[i]]=1;
			for(int j=0;j<3;j++)
			{
				ch[a[j]]=1;
				if(a[j]<x[i])
				cnt[i]++;
			}
		}
		sort(a,a+3);
		sort(x,x+2);
		sort(cnt,cnt+2);
		mx1=cnt[1];
		mx2=cnt[0];
		if(mx1<=1||(mx2==1&&mx1==2)||(mx2==0&&mx1==2))
		printf("-1\n");
		else
		if(mx1==3&&(mx2==0||mx2==1))
		{
			tmp=a[2];
			ans=tmp+1;
			while(ch[ans])
			ans++;
			if(ans>52)
			printf("-1\n");
			else
			printf("%d\n",ans);
		}
		else
		if(mx2==2&&(mx1==2||mx1==3))
		{
			tmp=a[1];
			ans=tmp+1;
			while(ch[ans])
			ans++;
			if(ans>52)
			printf("-1\n");
			else
			printf("%d\n",ans);
		}
		else
		if(mx1==3&&mx2==3)
		{
			
			tmp=0;
			ans=tmp+1;
			while(ch[ans])
			ans++;
			if(ans>52)
			printf("-1\n");
			else
			printf("%d\n",ans);
		}
		inp(a[0]);
		inp(a[1]);	
		inp(a[2]);
		inp(x[0]);
		inp(x[1]);
	}
	return 0;
}
