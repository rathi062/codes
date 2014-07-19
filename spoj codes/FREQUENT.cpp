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
struct nd{
       int sum,no;
       };
struct Node{
    nd total,l,r;
}nod[MX*4];

int lazy_value[4*MX];
bool lazy[4*MX];

void update_node(int idx, int st, int ed, int val)
{
    lazy[idx]=1;
    lazy_value[idx]=val;
    nod[idx].total.sum=nod[idx].l.sum=nod[idx].r.sum=1;
    nod[idx].total.no=nod[idx].l.no=nod[idx].r.no=val;
    //cout<<"\nval = "<<val;
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
    if(nod[lft].total.no == nod[lft].l.no)
    {
        //cout<<"\ntotal lft.ttl.no = "<<nod[lft].total.no;
        nod[idx].l.sum = nod[lft].total.sum;
        nod[idx].l.no = nod[lft].total.no;
    }
    else
    {
        //cout<<"\nleft";
        nod[idx].l.sum = nod[lft].l.sum;
        nod[idx].l.no = nod[lft].l.no;
    }
    if(nod[rgt].total.no == nod[rgt].r.no)
    {
        nod[idx].r.sum = nod[rgt].total.sum;
        nod[idx].r.no = nod[rgt].total.no;
    }
    else
    {
        nod[idx].r.sum = nod[rgt].r.sum;
        nod[idx].r.no = nod[rgt].r.no;
    }
    if(nod[lft].r.no==nod[rgt].l.no)
    {
        if(nod[idx].total.sum < nod[lft].r.sum+nod[rgt].l.sum)
        {
           nod[idx].total.sum = nod[lft].r.sum+nod[rgt].l.sum;
           nod[idx].total.no = nod[lft].r.no;
        }
    }
    if(nod[lft].r.no==nod[rgt].total.no)
    {
        if(nod[idx].total.sum < nod[lft].r.sum+nod[rgt].total.sum)
        {
           nod[idx].total.sum = nod[lft].r.sum+nod[rgt].total.sum;
           nod[idx].total.no = nod[lft].r.no;
        }
    }
    if(nod[lft].total.no == nod[rgt].l.no)
    {
        if(nod[idx].total.sum < nod[lft].total.sum+nod[rgt].l.sum)
        {
           nod[idx].total.sum = nod[lft].total.sum+nod[rgt].l.sum;
           nod[idx].total.no = nod[lft].total.no;
        }
    }
    if(nod[idx].total.sum<nod[lft].total.sum)
    {
        nod[idx].total.sum = nod[lft].total.sum;
        nod[idx].total.no = nod[lft].total.no;
    }
    if(nod[idx].total.sum<nod[rgt].total.sum)
    {
        nod[idx].total.sum = nod[rgt].total.sum;
        nod[idx].total.no = nod[rgt].total.no;
    }
    //cout<<"\nst = "<<st<<" ed = "<<ed<<" sum = "<<nod[idx].total.sum<<" no = "<<nod[idx].total.no<<" l.no = "<<nod[idx].l.no<<" r.no = "<<nod[idx].r.no; 
    //mx[idx]=max(mx[lft], mx[rgt]);
    return;
}

Node query(int idx, int st , int ed, int s, int e)
{
    if(st==s && ed==e) return nod[idx];

    //if(lazy[idx]) update_lazy(idx, st, ed);
    int l=idx*2;
    int r=l+1;
    int mid=(st+ed)/2;
    if(mid>=e)  return query(l, st, mid, s, e);
    else if(s>mid)  return query(r, mid+1, ed, s, e);
    else
    {
         Node lft, rgt, tmp;
         lft = query(l, st, mid, s, mid);
         rgt = query(r, mid+1, ed, mid+1, e);
    
         if(lft.total.no == lft.l.no)
         {
           tmp.l.sum = lft.total.sum;
           tmp.l.no = lft.total.no;
         }
         else
         {
            tmp.l.sum = lft.l.sum;
            tmp.l.no = lft.l.no;
         }
         if(rgt.total.no == rgt.r.no)
         {
            tmp.r.sum = rgt.total.sum;
            tmp.r.no = rgt.total.no;
         }
         else
         {
            tmp.r.sum = rgt.r.sum;
            tmp.r.no = rgt.r.no;
         }
         if(lft.r.no==rgt.l.no)
         {
            if(tmp.total.sum < lft.r.sum+rgt.l.sum)
            {
               tmp.total.sum = lft.r.sum+rgt.l.sum;
               tmp.total.no = lft.r.no;
            }
         }
         if(lft.r.no==rgt.total.no)
         {
            if(tmp.total.sum < lft.r.sum+rgt.total.sum)
            {
               tmp.total.sum = lft.r.sum+rgt.total.sum;
               tmp.total.no = lft.r.no;
            }
         }
         if(lft.total.no == rgt.l.no)
         {
            if(tmp.total.sum < lft.total.sum+rgt.l.sum)
            {
               tmp.total.sum = lft.total.sum+rgt.l.sum;
               tmp.total.no = lft.total.no;
            }
         }
         if(tmp.total.sum<lft.total.sum)
         {
            tmp.total.sum = lft.total.sum;
            tmp.total.no = lft.total.no;
         }
         if(tmp.total.sum<rgt.total.sum)
         {
            tmp.total.sum = rgt.total.sum;
            tmp.total.no = rgt.total.no;
         }     
         cout<<"\nst = "<<st<<" ed = "<<ed<<" sum = "<<tmp.total.sum<<" no = "<<tmp.total.no<<" l.no = "<<tmp.l.no<<" r.no = "<<tmp.r.no; 
         return tmp;
    }
}

int main()
{
    int n, i, q, cnt, st, ed,val;

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
        //cin>>st>>ed;
        inp(st);
        inp(ed);
        //cout<<query(1, 0, n-1, st-1, ed-1).ms<<endl;
        printf("%d\n",query(1, 0, n-1, st-1, ed-1).total.no);
    }

    return 0;
}


