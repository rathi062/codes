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
struct Node{
     vector<int> v;
}nod[MX*4];
int a[MX];
vector<int> vc;
vector<int>::iterator it;
void insert(int idx, int st, int ed)
{
    if(st==ed)
    {
        nod[idx].v.assign(a+st,a+ed);
        return;
    }
    int lft=idx<<1, rgt=lft+1;
    int mid=(st+ed)>>1;
        insert(lft, st, mid);
        insert(rgt, mid+1, ed);
    nod[idx].v.assign(a+st,a+ed+1);
    return;
}

void query(int idx, int st , int ed, int s, int e)
{
    if(st==s && ed==e) 
    {
             vc.insert(vc.end(),a+st,a+ed+1);
             return;
    }
    int lft=idx<<1,rgt=lft+1;
    int mid=(st+ed)>>1;
    if(mid>=e)  query(lft, st, mid, s, e);
    else if(s>mid)  query(rgt, mid+1, ed, s, e);
    else
    {
         query(lft, st, mid, s, mid);
         query(rgt, mid+1, ed, mid+1, e);
         return ;
    }
}

int main()
{
    int c, n, i, q, cnt=0, st, ed,w,t;
      inp(n);
      inp(q);
      for(i=0;i<n;i++)
      inp(a[i]);
      insert(1,0,n-1);
      while(q--)
      {
        inp(st);
        inp(ed);
        inp(i);
        vc.clear();
        query(1,0,n-1,st-1,ed-1);
        sort(vc.begin(),vc.end());
        //cout<<"\nvector is :"; 
        //for(it=vc.begin();it<vc.end();it++)
        //cout<<(*it)<<" ";
        printf("%d\n",vc[i-1]);
      }
    return 0;
}


