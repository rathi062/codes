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
#define MX 100001
#define MOD 1000000007

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
int a[MX],b[MX],r[MX];
vector<int> vc;
vector<int>::iterator it;
int main()
{
    int c, n, i, q, cnt=0, st, ed,w,t;
      inp(n);
      inp(q);
      for(i=0;i<n;i++)
      {
         inp(a[i]);
         b[i]=a[i];
      }
      sort(b,b+n);
      map<int,int> m;
      for(i=0;i<n;i++)
      m.insert(std::pair<int,int> (b[i],i+1));
      for(i=0;i<n;i++)
      r[i]=m[a[i]];
      while(q--)
      {
        inp(st);
        inp(ed);
        inp(i);
        vc.clear();
        vc.assign(r+st-1,r+ed);
        sort(vc.begin(),vc.end());
        //cout<<"\nvector is :"; 
        //for(it=vc.begin();it<vc.end();it++)
        //cout<<(*it)<<" ";
        printf("%d\n",b[vc[i-1]-1]);
      }
    return 0;
}
   
