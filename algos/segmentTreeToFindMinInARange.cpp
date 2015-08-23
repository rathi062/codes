#include<iostream>
#include <stdlib.h>
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
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define MX 1000007
#define MOD 1000000007

#define F first
#define S second
#define pii pair<int,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

using namespace std;

LL min(LL a, LL b){
    if(a<b) return a;
    else return b;
}


LL node[2*MX];

void init(int idx, int st, int ed, int s, int e, LL val){
    if(st==s && ed==e){
        node[idx] = val;
        return;
    }
    
    int lft = idx<<1, rgt = lft+1, mid = (st+ed)>>1;
    if(e<=mid) init(lft,st,mid,s,e,val);
    else init(rgt,mid+1,ed,s,e,val);
    
    node[idx] = min(node[lft], node[rgt]);
    return;
}

LL query(int idx, int st, int ed, int s, int e){
    if(st==s && ed==e)
        return node[idx];
    
    int lft = idx<<1, rgt = lft+1, mid = (st+ed)>>1;
    if(mid>=e)  return query(lft, st, mid, s, e);
    else if(s>mid)  return query(rgt, mid+1, ed, s, e);
    else
    {
        LL l, r;
        l = query(lft, st, mid, s, mid);
        r = query(rgt, mid+1, ed, mid+1, e);
        return min(l,r);
    }
}

int main(){
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        init(1,1,n,i,i,a);
    }
    cout<<endl;
    for(int i=1;i<=2*n;i++){
        cout<<node[i]<<" ";
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,h;
        cin>>l>>h;
        cout<<query(1,1,n,l,h);
    }
    return 0;
}