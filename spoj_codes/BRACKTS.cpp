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
struct Node{
    int total,min;
}nod[MX*4];
char a[30010];
char lazy_value[4*MX];
bool lazy[4*MX];
void insert(int idx,int st,int ed)
{
     if(st==ed)
     {
          if(a[st]=='(')
          nod[idx].total=nod[idx].min=1;
          else
          nod[idx].total=nod[idx].min=-1;
          return ;
     }
     int l,r,mid=(st+ed)/2;
     l=2*idx;
     r=l+1;
     insert(l,st,mid);
     insert(r,mid+1,ed);
     nod[idx].total=nod[l].total+nod[r].total;
     nod[idx].min=min(nod[l].min,nod[l].total+nod[r].min);
     return ;
}
void update(int idx,int st,int ed,int in)
{
     if(st==ed)
     {
          if(a[st]=='(')
          {
             nod[idx].total=nod[idx].min=-1;
             a[st]=')';
          }
          else
          {
              nod[idx].total=nod[idx].min=1;
              a[st]='(';
          }
          return ;
     }
     int l,r,mid=(st+ed)/2;
     l=2*idx;
     r=l+1;
     if(in<=mid)
     update(l,st,mid,in);
     else
     update(r,mid+1,ed,in);
     nod[idx].total=nod[l].total+nod[r].total;
     nod[idx].min=min(nod[l].min,nod[l].total+nod[r].min);
     return ;
}
int main()
{
   int t=10;
   while(t--)
   {
    int n, i, r,q, cnt, st, ed,w;
    inp(n);
    scanf("%s",a);
    insert(1,0,n-1);
    inp(q);
    while(q--)
    {
       inp(w);
       if(!w)
       if(nod[1].total==0&&nod[1].min==0) printf("YES\n");
       else printf("NO\n");
       else update(1,0,n-1,w-1);
    }
   }
    return 0;
}


