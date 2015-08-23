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
#define MX 10000005
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
int currnt[16], lst[16],n;
bool check[16][1<<16];
int dp[16][1<<16], nxt[16][1<<16], cost[16][16];

void createCostMatrix(){
    CLR(cost);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j] = abs(i-j) + abs(currnt[i]-lst[j]);
        }
    }
//    cout<<"cost matrix \n";
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<cost[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    
}

int getMinimumCost(int state, int availableNumbers){
    if(state >= n){
//        cout<<"\navail = "<<availableNumbers;
        return 0;
    }
    if(check[state][availableNumbers])
        return dp[state][availableNumbers];
    int result = MX;
    for(int i=0;i<n;i++){
        if((availableNumbers & (1<<i))){
            int newAvailableNumbers = availableNumbers ^ (1<<i);
            int val = cost[state][i] + getMinimumCost(state+1, newAvailableNumbers);
            if(result > val){
                nxt[state][availableNumbers] = i;
                result = val;
            }
        }
    }
    dp[state][availableNumbers] = result;
    check[state][availableNumbers] = true;
    return result;
}


int main(){
    inp(n);
    while(n){
        
        for(int i=0;i<n;i++) inp(currnt[i]);
        for(int i=0;i<n;i++) inp(lst[i]);
        createCostMatrix();
        int availableNumbers = (1<<(n)) - 1;
        CLR(check);
        CLR(dp);
        cout<<getMinimumCost(0,availableNumbers)<<endl;
        inp(n);
    }
}
