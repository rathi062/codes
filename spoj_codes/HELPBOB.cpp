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
int x,y;
int m,p[16],n[16];
double a[16];
vector<pii> offers[16];
bool check[1<<16];
pii dp[1<<16];

double getCostOfPizza(int idx,int state){
    double price = p[idx] * 1.0;
    for(int i=0;i<m;i++){
        if(! (state & (1<<i))){
            for(int j=0;j<offers[i].size();j++){
                if(offers[i][j].first == idx){
                    double discount = (100 - offers[i][j].second)*0.01;
                    price *= discount;
                }
            }
        }
    }
    return price ;
}

pii getMinimumCost(int state){
//    if(check[state])
//        return dp[state];
    pii result = MP(0,0);
    double ratio = MX * 1.0;
    for(int i=0;i<m;i++){
        if(state & (1<<i)){
            
            double cost = getCostOfPizza(i,state) ;
            double area = a[i] ;
            double newRatio = cost/area;
            if( newRatio <= ratio){
                ratio = newRatio;
                result = MP(cost, area);
            }
            int newState = state ^ (1<<i);
            pii res = getMinimumCost(newState);
            
            newRatio = (cost + res.first)/(area + res.second);
            if( newRatio < ratio){
                ratio = newRatio;
                result.first = res.first + cost;
                result.second = res.second + area;
            }
    
        }
    }
    check[state] = 1;
    dp[state] = result;
    return result;
}

//pii getMinimumCost(int state,int num,int den){
//    if(check[state])
//        return dp[state];
//    pii result = MP(num,den);
//    double ratio = MX * 1.0;
//    for(int i=0;i<m;i++){
//        if(state & (1<<i)){
//            
//            double cost = getCostOfPizza(i) + num;
//            double area = a[i] + den;
//            double newRatio = cost/area;
//            if( newRatio <= ratio){
//                ratio = newRatio;
//                result = MP(cost, area);
//            }
//            for(int j=0;j<offers[i].size();j++){
//                discounts[ offers[i][j].first ].PB( offers[i][j].second );
//            }
//            int newState = state ^ (1<<i);
//            pii res = getMinimumCost(newState,cost,a[i]+den);
//            
//            newRatio = (res.first)/(res.second);
//            if( newRatio < ratio){
//                ratio = newRatio;
//                result = res;
//            }
//            
//            for(int j=0;j<offers[i].size();j++){
//                discounts[ offers[i][j].first ].pop_back();
//            }
//        }
//    }
//    check[state] = 1;
//    dp[state] = result;
//    return result;
//}

int main(){
    inp(m);
    while(m){
        CLR(check);
        CLR(dp);
        CLR(offers);
        for(int i=0;i<m;i++){
            inp(p[i]);
            cin>>a[i];
            inp(n[i]);
            for(int j=0;j<n[i];j++){
                inp(x);
                inp(y);
                offers[i].PB(MP(x-1,y));
            }
        }
        pii ans = getMinimumCost((1<<m) -1);
        double num = ans.first;
        double den = ans.second;
        double output = (num/den);
        cout<<output<<endl;
        inp(m);
    }
}
