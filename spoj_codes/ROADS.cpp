
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
#define MX 10001
#define MOD 1000000007

#define pipii pair<int, pair<int,int> >
#define F first
#define S second

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
struct edge{
    int src,dst,len,toll;
}node;

int k,n,r;
vector<edge> grf[101];
bool check[101][MX];
priority_queue<pipii, vector<pipii> , greater<pipii> > q;

void visitNode(int i, int money, int len){
    if(check[i][money])
        return;
    check[i][money]=1;
    for(int idx = 0; idx< grf[i].size(); idx++){
        edge e = grf[i][idx];
        if(!check[e.dst][money-e.toll] && e.toll <= money){
            q.push(MP(e.len + len, MP(e.dst, money - e.toll) ));
        }
    }
}

int  main(){
    int t;
    inp(t);
    while(t--){
        inp(k);
        inp(n);
        inp(r);
        CLR(check);
        CLR(grf);
        for(int i=0;i<r;i++){
            inp(node.src);
            inp(node.dst);
            inp(node.len);
            inp(node.toll);
            grf[node.src].PB(node);
        }
        while(!q.empty())
            q.pop();

        bool reached = 0;
        q.push(MP(0, MP(1,k)));
        while(!q.empty()){
            pipii top = q.top();
            q.pop();
            if(top.S.F == n){
                reached = 1;
                cout<<top.F<<endl;
                break;
            }
            visitNode(top.S.F, top.S.S, top.F );
        }
        
        if(!reached)
            cout<<"-1\n";
    }
    return 0;
}