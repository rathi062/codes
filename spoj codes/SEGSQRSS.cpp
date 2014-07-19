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
    int total;
}nod[MX*4];

int lazy_value[4*MX];
bool lazy[4*MX];

void update_node(int idx, int st, int ed, int val,int t)
{
    lazy[idx]=1;
    if(t==0||t==-1)
    
    {  
       lazy_value[idx]=val;
       nod[idx].total=val*val;
    }
    else
    {
        lazy_value[idx]+=val;
        nod[idx].total=lazy_value[idx]*lazy_value[idx];
    }
    //cout<<"\nupdate!!\nin = "<<st<<" val = "<<val;
}

/*void update_lazy(int idx, int st, int ed)
{
    if(st==ed)    return;

    int lft=idx*2, rgt=lft+1;
    int mid=(st+ed)/2;

    update_node(lft, st, mid, lazy_value[idx]);
    update_node(rgt, mid+1, ed, lazy_value[idx]);
    lazy[idx]=lazy_value[idx]=0;
}*/

void insert(int idx, int st, int ed, int s, int e, int val,int t)
{
    if(st==ed&&st>=s&&st<=e)
    {
        update_node(idx, st, ed, val,t);
        return;
        //nod[idx].total=nod[idx].ls=nod[idx].rs=nod[idx].ms=val;
    }

    //if(lazy[idx]) update_lazy(idx, st, ed);

    int lft=idx*2, rgt=lft+1;
    int mid=(st+ed)/2;
    if(e<=mid) insert(lft, st, mid, s, e, val,t);
    else if(s>mid) insert(rgt, mid+1, ed, s, e, val,t);
    else
    {
        insert(lft, st, mid, s, mid, val,t);
        insert(rgt, mid+1, ed, mid+1, e, val,t);
    }
    nod[idx].total = nod[lft].total + nod[rgt].total;
    //mx[idx]=max(mx[lft], mx[rgt]);
    return;
}

Node query(int idx, int st , int ed, int s, int e)
{
    if(st==s && ed==e) return nod[idx];

    //if(lazy[idx]) update_lazy(idx, st, ed);
    int lft=idx*2,rgt=lft+1;
    int mid=(st+ed)/2;
    if(mid>=e)  return query(lft, st, mid, s, e);
    else if(s>mid)  return query(rgt, mid+1, ed, s, e);
    else
    {
         Node l, r, tmp;
         l = query(lft, st, mid, s, mid);
         r = query(rgt, mid+1, ed, mid+1, e);

         tmp.total = l.total + r.total;
         return tmp;
    }
}

int main()
{
    int c, n, i, q, cnt=0, st, ed,val,w,t;
    inp(c);
    while(c--)
    {
    //cin>>n;
      inp(n);
      inp(q);
      for(i=0;i<n;i++)
        {
            //cin>>val;
            inp(val);
            insert(1, 0, n-1, i, i, val,-1);
        }

    //cin>>q;
       cnt++;
       printf("Case %d:\n",cnt);
       while(q--)
       {
        inp(t);
        inp(st);
        inp(ed);
        if(t==2)
        printf("%d\n",query(1, 0, n-1, st-1, ed-1).total);
        else
        {
             inp(val);
             insert(1,0,n-1,st-1,ed-1,val,t);
        }
       }
    }

    return 0;
}


