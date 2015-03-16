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
struct doll{
	int st,ed;
}rd[MX];

int compare(const doll a,const doll b)
{
	return ((a.st==b.st)?(a.ed<b.ed):(a.st>b.st));
}
int comp(const doll a,const doll b)
{
	return a.ed<b.ed;
}
int main()
{
    int t=0,cnt=1;
    inp(t);
    while(t--)
    {
         int m;
		 inp(m);
         for(int i=0;i<m;i++)
         {
               inp(rd[i].st);
               inp(rd[i].ed);
         }
         sort(rd,rd+m,compare);
         //for(int i=0;i<k;i++)
         //printf("\nst = %d ed = %d",rd[i].st,rd[i].ed);
         int ans=m,lst=0,in,mx;
		 for(int i=0;i<m;i++)
         {
         	 mx=-1;
         	 in=lst;
         	 for(int j=0;j<lst;j++)
         	 {
         	 	 if(rd[j].ed>rd[i].ed )
         	 	 {
         	 	 	if(rd[j].ed>=mx)
         	 	 	{
					   mx=rd[j].ed;
					   in=j;
					}
         	 	 }
         	 }
         	 //in=upper_bound(rd, rd+lst, rd[i], comp) - rd;
         	 //cout<<"\nin = "<<in;
			  if(in==lst)
         	 {
         	 	rd[lst++]=rd[i];
         	 }
         	 else
         	 {
         	 	ans--;
         	 	rd[in]=rd[i];
         	 }
         }
         printf("%d\n",ans);
    }
    return 0;
}
