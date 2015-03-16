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
using namespace std;
 /*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/
  /*inline void inpll( long long &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/

#define MAXN 100000
#define INF 1000000000

struct node{
       int total,ls,rs,ms;
       }nod[4*MAXN];
       
int q,n,i,j,a[4*MAXN];
void update_node(int in,int val)
{
     a[in]=val;
     nod[in].total=nod[in].ls=nod[in].rs=nod[in].ms=val;
}
     
void segment_init(int in,int st,int nd,int i,int j,int val)
{
     
     int mid,l,r;
     if(st==i&&nd==j)
     {
        update_node(in,val);
        return ;
     }
     mid=(st+nd)/2;
     l=in*2;
     r=l+1;
     if(j<=mid)
         segment_init(l,st,mid,i,j,val);
     else    
         segment_init(r,mid+1,nd,i,j,val);
         nod[in].total=nod[l].total+nod[r].total;
         nod[in].ls=max(nod[l].ls,nod[l].total+nod[r].ls);
         nod[in].rs=max(nod[r].rs,nod[l].rs+nod[r].total);
         nod[in].ms=max3(nod[l].ms,nod[r].ms,nod[l].rs+nod[r].ls);
         return ;
}
node query(int in,int st,int nd,int i,int j)
{
    int l,r,mid;
    
    if(st==i&&nd==j)
      return nod[in];
    if(st==nd)
    return nod[in];
    
    mid=(st+nd)/2;
     l=in*2;
     r=l+1;
     if(j<=mid)
         return query(l,st,mid,i,j);
     else
     if(i>mid)   
         return query(r,mid+1,nd,i,j);
     else
     {
         node p1,p2,tmp;
         p1=query(l,st,mid,i,j);
         p2=query(r,mid+1,nd,i,j);
         tmp.total=p1.total+p2.total;
         tmp.ls=max(p1.ls,p1.total+p2.ls);
         tmp.rs=max(p2.rs,p2.total+p1.rs);
         tmp.ms=max3(p1.ms,p1.rs+p2.ls,p2.ms);
         return tmp;
     }
}
int main()
{
    inp(n);
    int val;
    for(i=0;i<n;i++)
    {
        inp(val);
        segment_init(1,0,n-1,i,i,val);
    }
    inp(q);
    while(q--)
    {
       inp(i);
       inp(j);
       printf("%d\n",(query(1,0,n-1,i-1,j-1)).ms);
    }
    system("pause");
    return 0;
}
