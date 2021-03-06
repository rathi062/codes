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
    long long z,o,t,ch;
}nod[MX*4];

bool lazy[4*MX];
void initial(int idx,int st,int ed)
{
    nod[idx].z=ed-st+1;
    if(st==ed) 
    {
       return;
    }
    int lft=idx<<1, rgt=lft+1;
    int mid=(st+ed)>>1;
    initial(lft, st, mid);
    initial(rgt, mid+1, ed);
}
    
void insert(int idx, int st, int ed, int s, int e, long long val)
{
    //cout<<"\nst = "<<st<<" ed = "<<ed;
    if(st==ed)
    {
        nod[idx].ch++;
        nod[idx].ch%=3;
        int z,o,t;
        z=nod[idx].z;
        o=nod[idx].o;
        t=nod[idx].t;
        nod[idx].z=t;
        nod[idx].o=z;
        nod[idx].t=o;
        //cout<<"\nequal z = "<<nod[idx].z<<" o = "<<nod[idx].o<<" t = "<<nod[idx].t<<" ch = "<<nod[idx].ch;
        return;
    }
    else
    if(st==s&&ed==e)
    {
        int lft=idx<<1, rgt=lft+1;
        int mid=(st+ed)>>1;
        //cout<<"\nrange z = "<<nod[idx].z<<" o = "<<nod[idx].o<<" t = "<<nod[idx].t<<" ch = "<<nod[idx].ch;
        nod[idx].ch++;
        nod[idx].ch%=3;
        int z,o,t;
        z=nod[idx].z;
        o=nod[idx].o;
        t=nod[idx].t;
        nod[idx].z=t;
        nod[idx].o=z;
        nod[idx].t=o;
        //cout<<"\nrange z = "<<nod[idx].z<<" o = "<<nod[idx].o<<" t = "<<nod[idx].t<<" ch = "<<nod[idx].ch;
        return;
    }  
    int lft=idx<<1, rgt=lft+1;
    int mid=(st+ed)>>1;
    if(e<=mid) insert(lft, st, mid, s, e, val);
    else if(s>mid) insert(rgt, mid+1, ed, s, e, val);
    else
    {
        insert(lft, st, mid, s, mid, val);
        insert(rgt, mid+1, ed, mid+1, e, val);
    }
    nod[idx].z=nod[lft].z + nod[rgt].z;
    nod[idx].o=nod[lft].o + nod[rgt].o;
    nod[idx].t=nod[lft].t + nod[rgt].t;
    //cout<<"\nz = "<<nod[idx].z<<" o = "<<nod[idx].o<<" t = "<<nod[idx].t<<" ch = "<<nod[idx].ch;
    int z,o,t;
    for(int i=0;i<nod[idx].ch;i++)
    {
        z=nod[idx].z;
        o=nod[idx].o;
        t=nod[idx].t;
        nod[idx].z=t;
        nod[idx].o=z;
        nod[idx].t=o;
    }
    //cout<<"\nz = "<<nod[idx].z<<" o = "<<nod[idx].o<<" t = "<<nod[idx].t<<" ans = "<<nod[idx].ans;
    return;
}

long long query(int idx, int st , int ed, int s, int e,long long val)
{
    if(st==s && ed==e)
    {
         val%=3;
         int z,o,t,x,y,w;
         z=nod[idx].z;
         o=nod[idx].o;
         t=nod[idx].t;    
         for(int i=0;i<val;i++)
         {
             w=z;
             x=o;
             y=t;
             z=y;
             o=w;
             t=x;
         }
         return z;
    }
    int lft=idx<<1,rgt=lft+1;
    int mid=(st+ed)>>1;
    if(mid>=e)  return query(lft, st, mid, s, e,val+nod[idx].ch);
    else if(s>mid)  return query(rgt, mid+1, ed, s, e,val+nod[idx].ch);
    else
    {
         long long l, r, tmp;
         l = query(lft, st, mid, s, mid,val+nod[idx].ch);
         r = query(rgt, mid+1, ed, mid+1, e,val+nod[idx].ch);
         tmp = l + r;
         return tmp;
    }
}

int main()
{
    int c, n, i, q, cnt=0, st, ed,w,t;
    long long val;
      inp(n);
      inp(q);
      initial(1,0,n-1);
       while(q--)
       {
        inp(t);
        inp(st);
        inp(ed);
        if(t==1)
        printf("%lld\n",query(1, 0, n-1, st, ed,0));
        else
        {
             insert(1,0,n-1,st,ed,1);
        }
       }
    //system("pause");
    return 0;
}


