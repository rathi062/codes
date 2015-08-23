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
#define MX 100005

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
long long hurdles[3][MX],drinks[2][MX],dp[3][MX];
int parent[3][MX];
long long line, energy;

int main(){
    int n;
    cin>>line>>energy>>n;
    for(int i=0; i<3;i++){
        for(LL j=0;j<n;j++){
            cin>>hurdles[i][j];
        }
    }
    for(int i=0; i<2;i++){
        for(LL j=0;j<n-1;j++){
            cin>>drinks[i][j];
        }
    }
    CLR(dp);
    CLR(parent);
    dp[0][0]=dp[1][0]=dp[2][0]=energy;
    parent[0][0]=parent[1][0]=parent[2][0]=line-1;
    for(int j=0;j<n-1;j++){
        int cnt=0;
        for(int i=0;i<3;i++){
            if(i==0){
                LL v1 = dp[i][j] - hurdles[i][j];
                if(v1 < 0){
                    dp[i][j] = v1;
                    cnt++;
                    continue;
                }
                if(v1 > dp[i][j+1])
                {
                    parent[i][j+1] = i;
                    dp[i][j+1] = max(v1,dp[i][j+1]);
                }
                
                LL v2 = v1 + drinks[0][j];
                if(v2 >dp[i+1][j+1]){
                    parent[i+1][j+1] = i;
                    dp[i+1][j+1] = max(v2,dp[i+1][j+1]);
                }
                v2 = v1 + drinks[0][j];
                if(v2 >dp[i+2][j+1]){
                    parent[i+2][j+1] = i;
                    dp[i+2][j+1] = max(v2,dp[i+1][j+1]);
                }
            }
            if(i==1){
                LL v1 = dp[i][j] - hurdles[i][j];
                if(v1 < 0){
                    dp[i][j] = v1;
                    cnt++;
                    continue;
                }
                if(v1 > dp[i][j+1]){
                    dp[i][j+1] = max(v1,dp[i][j+1]);
                    parent[i][j+1]=i;
                }
                LL v2 = v1 + drinks[0][j];
                if(v2 > dp[i-1][j+1]){
                    dp[i-1][j+1] = max(v2,dp[i-1][j+1]);
                    parent[i-1][j+1] = i;
                }
                v2 = v1 + drinks[1][j];
                if(v2 > dp[i+1][j+1]){
                    dp[i+1][j+1] = max(v2,dp[i+1][j+1]);
                    parent[i+1][j+1] = i;
                }
                
            }
            if(i==2){
                LL v1 = dp[i][j] - hurdles[i][j];
                if(v1 < 0){
                    dp[i][j] = v1;
                    cnt++;
                    continue;
                }
                if(v1 >dp[i][j+1]){
                    dp[i][j+1] = max(v1,dp[i][j+1]);
                    parent[i][j+1]=i;
                }
                LL v2 = v1 + drinks[1][j];
                if(v2 > dp[i-2][j+1]){
                    dp[i-2][j+1] = max(v2,dp[i-2][j+1]);
                    parent[i-2][j+1] = i;
                }
                v2 = v1 + drinks[1][j];
                if(v2 > dp[i-1][j+1]){
                    dp[i-1][j+1] = max(v2,dp[i-1][j+1]);
                    parent[i-1][j+1] = i;
                }
            }
        }
        if(cnt==3)
        {
            cout<<"GAME OVER!\n";
            return 0;
        }
    }
    LL result = 0,from=0;
    for(int i=0;i<2;i++){
        if(result < (dp[i][n-1]-hurdles[i][n-1])){
            result = max(result, dp[i][n-1]-hurdles[i][n-1]);
            from = i;
        }
    }
    stack<int> q;
    q.push(from);
    for(int i=n-1;i>=0;i--){
        q.push(parent[from][i]);
        from = parent[from][i];
    }
    from = q.top();
    q.pop();
    while (!q.empty()) {
        int to = q.top();
        q.pop();
        if(to>from){
            for(int i=0;i<to-from;i++)
                cout<<"R";
        }
        else
        if(to<from){
            for(int i=0;i<from-to;i++)
                cout<<"L";
        }
        else
        cout<<"U";
        if(!q.empty())
            cout<<"-";
        from = to;
    }
    cout<<endl;
}
