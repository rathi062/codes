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
#define MX 10000009
#define pii pair<int,int>

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
int n,m,p,a,b;
int s,e,d;
double horses[8];
vector<int> canGoTo[31];
bool check[31][1<<8];
bool visited[31];
double dp[31][1<<8];
double cost[31][31];

double TSP(int crntCity, int tkts){
    if(check[crntCity][tkts])
        return  dp[crntCity][tkts];

    if(crntCity == b-1)
        return 0.0;

    if(tkts == 0)
        return MX;
    visited[crntCity] = 1;
    
    double result = MX;
    for(int i=0;i<canGoTo[crntCity].size();i++){
        int nxtCity = canGoTo[crntCity][i];
        if(visited[nxtCity])
            continue;
        for(int j=0;j<n;j++){
            if( tkts & (1<<j)){
                double val1 = cost[crntCity][nxtCity]/horses[j];
                double val = TSP(nxtCity, tkts ^ (1<<j));
                val += val1;
                if(val < result)
                    result = val;
            }
        }
    }
    visited[crntCity] = 0;
    check[crntCity][tkts] = 1;
    dp[crntCity][tkts] = result;
    return result;
}

int main(){
    inp(n);
    inp(m);
    inp(p);
    inp(a);
    inp(b);
    while(n||m||p||a||b){
//        CLR(dp);
//        CLR(cost);
        CLR(check);
        CLR(visited);
        CLR(canGoTo);
        for(int i=0;i<n;i++)
            cin>>horses[i];
        for(int i=0;i<p;i++){
            inp(s);
            inp(e);
            inp(d);
            cost[s-1][e-1] = d;
            cost[e-1][s-1] = d;
            canGoTo[s-1].PB(e-1);
            canGoTo[e-1].PB(s-1);
        }

        double ans = TSP(a-1,(1<<n)-1);
        if(ans >=MX)
            cout<<"Impossible\n";
        else
            cout<<ans<<endl;
        inp(n);
        inp(m);
        inp(p);
        inp(a);
        inp(b);
    }
}
