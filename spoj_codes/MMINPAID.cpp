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
int n,m,a,b,c,cst1,cst2;
vector<pii> canPayFrom[10][10];
vector<int> canGoTo[10];
bool check[10][10][1<<10];
bool visited[10][10][1<<10];
int dp[10][10][1<<10], cost[10][10];

int TSP(int crntCity, int fromCity, int visitedCities){
    if(check[crntCity][fromCity][visitedCities])
        return  dp[crntCity][fromCity][visitedCities];
    int mnCost = cost[fromCity][crntCity];
    for(int i=0; i<canPayFrom[fromCity][crntCity].size();i++){
        int cty = canPayFrom[fromCity][crntCity][i].first;
        if(visitedCities & (1<<cty)){
            int val = canPayFrom[fromCity][crntCity][i].second;
            mnCost = mnCost < val ? mnCost : val;
        }
    }
    
    if(crntCity == n-1)
        return mnCost;
    
    int result = MX;
    for(int i=0;i<canGoTo[crntCity].size();i++){
        int nxtCity = canGoTo[crntCity][i];
        if(visited[crntCity][nxtCity][visitedCities])
            continue;
        visited[crntCity][nxtCity][visitedCities] = 1;
        int val = TSP(nxtCity, crntCity,  visitedCities|(1<<nxtCity) );
        visited[crntCity][nxtCity][visitedCities] = 0;
        if(val < result)
            result = val;
    }
    check[crntCity][fromCity][visitedCities] = 1;
    dp[crntCity][fromCity][visitedCities] = result + mnCost;
    return result + mnCost;
}

int main(){
    inp(n);
    inp(m);
    CLR(cost);
    CLR(check);
    for(int i=0;i<m;i++){
        inp(a);
        inp(b);
        inp(c);
        inp(cst1);
        inp(cst2);
        cost[a-1][b-1] = cst2;
        canGoTo[a-1].PB(b-1);
        canPayFrom[a-1][b-1].PB(MP(c-1,cst1));
    }
    int visitedCities = 1;
    cost[0][0] = 0;
    int ans = TSP(0,0,visitedCities);
    if(ans >=MX)
        cout<<"impossible\n";
    else
        cout<<ans<<endl;
}
