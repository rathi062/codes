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
#define MX 10000000
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
    int total, ls, rs,ms;
}nod[MX*4];

int lazy_value[4*MX];
bool lazy[4*MX];

void update_node(int idx, int st, int ed, int val)
{
    lazy[idx]=1;
    lazy_value[idx]=val;
    nod[idx].total=nod[idx].ls=nod[idx].rs=nod[idx].ms=val;
}

void update_lazy(int idx, int st, int ed)
{
    if(st==ed)    return;

    int lft=idx*2, rgt=lft+1;
    int mid=(st+ed)/2;

    update_node(lft, st, mid, lazy_value[idx]);
    update_node(rgt, mid+1, ed, lazy_value[idx]);
    lazy[idx]=lazy_value[idx]=0;
}

void insert(int idx, int st, int ed, int s, int e, int val)
{
    if(st==s && ed==e)
    {
        update_node(idx, st, ed, val);
        return;
        //nod[idx].total=nod[idx].ls=nod[idx].rs=nod[idx].ms=val;
    }

    //if(lazy[idx]) update_lazy(idx, st, ed);

    int lft=idx*2, rgt=lft+1;
    int mid=(st+ed)/2;
    if(e<=mid) insert(lft, st, mid, s, e, val);
    else insert(rgt, mid+1, ed, s, e, val);
    /*else
    {
        insert(lft, st, mid, s, mid, val);
        insert(rgt, mid+1, ed, mid+1, e, val);
    }*/
    nod[idx].total = nod[lft].total + nod[rgt].total;
    nod[idx].ls = max(nod[lft].ls, nod[lft].total + nod[rgt].ls);
    nod[idx].rs = max(nod[rgt].rs, nod[rgt].total + nod[lft].rs);
    nod[idx].ms = max3(nod[lft].rs + nod[rgt].ls, nod[lft].ms, nod[rgt].ms);
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
         tmp.ls = max(l.ls, l.total + r.ls);
         tmp.rs = max(r.rs, r.total + l.rs);
         tmp.ms = max3(l.rs + r.ls, l.ms, r.ms);
    return tmp;
    }
}

int main()
{
    int n, i, q, cnt, st, ed,val,w;

    //cin>>n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
            //cin>>val;
            inp(val);
            insert(1, 0, n-1, i, i, val);
        }

    //cin>>q;
    inp(q);

    while(q--)
    {
        inp(w);
        inp(st);
        inp(ed);
        //cout<<query(1, 0, n-1, st-1, ed-1).ms<<endl;
        if(w==1)
        printf("%d\n",query(1, 0, n-1, st-1, ed-1).ms);
        else
        insert(1,0,n-1,st-1,st-1,ed);
    }

    return 0;
}


