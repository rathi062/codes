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
#define MX 100009
#define MOD 1000000007

#define inp(x) scanf("%d",&x)
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
int a[MX],cum[MX],fwd[MX],fp[MX],bck[MX],bp[MX];
int main()
{
	int t,n;
	inp(t);
	while(t--)
	{
		CLR(cum);
		CLR(fwd);
		CLR(bck);
		CLR(fp);
		CLR(bp);
		int max=0,sum=0;
		inp(n);
		bp[n+1]=n+1;
		for(int i=1;i<=n;i++)
		{
			inp(a[i]);
			cum[i]=cum[i-1]+a[i];
			if(fwd[i-1]<cum[i]*(-1))
			{
				fwd[i]=cum[i]*(-1);
				fp[i]=i;
			}
			else
			{
				fwd[i]=fwd[i-1];
				fp[i]=fp[i-1];
			}
		}
		for(int i=n;i>0;i--)
		{
			sum+=a[i];
			if(bck[i+1]<sum*(-1))
			{
				bck[i]=sum*(-1);
				bp[i]=i;
			}
			else
			{
				bck[i]=bck[i+1];
				bp[i]=bp[i+1];
			}
		}
		/*cout<<"\ncum : ";
		for(int i=1;i<=n;i++)
		cout<<cum[i]<<" ";
		
		cout<<"\nfwd : ";
		for(int i=1;i<=n;i++)
		cout<<fwd[i]<<" "<<fp[i]<<endl;
		
		cout<<"\nbck : ";
		for(int i=1;i<=n;i++)
		cout<<bck[i]<<" "<<bp[i]<<endl;*/
		for(int i=1;i<=n;i++)
		{
			
			/*cout<<"\nfwd "<<fwd[i]<<" "<<fp[i];
			cout<<"\nbck "<<bck[i+1]<<" "<<bp[i+1];
			cout<<"\ncum[bck] = "<<cum[bp[i+1]-1];
			cout<<"\ncum[fwd] = "<<cum[fp[i]];*/
			sum=fwd[i]+bck[i+1]+(cum[bp[i+1]-1]-cum[fp[i]]);
			//cout<<"\nsum = "<<sum;
			if(sum>max)
			max=sum;
			//cout<<"\nmax = "<<max<<endl;
		}
		printf("%d\n",max);
	}
	return 0;
}
