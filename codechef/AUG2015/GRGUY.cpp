
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
#define MX 200001
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

string a[2];
int dp[2][MX], len;
bool check[2][MX], visited[2][MX];

int getMinNumberOfSteps(int currentLane, int n){
    if(visited[currentLane][n])
        return dp[currentLane][n];
    if(n == len-1){
        visited[currentLane][n] = 1;
        if(a[currentLane][n] =='.')
            dp[currentLane][n] = 0;
        else
            dp[currentLane][n] = INF;
        return dp[currentLane][n];
    }
    if(n == len || a[currentLane][n] =='#' || check[currentLane][n])
        return INF;
    
    check[currentLane][n] = 1;
    int v1,v2,v3;
    v1 = getMinNumberOfSteps(currentLane , n+1);
    v2 = getMinNumberOfSteps(currentLane^1, n) + 1;
    v3 = getMinNumberOfSteps(currentLane^1, n+1) +1;

    dp[currentLane][n] =  min3(v1,v2,v3);
    check[currentLane][n] = 0;
    visited[currentLane][n] = 1;
    return dp[currentLane][n];
}

int  main(){
    int t;
    inp(t);
    while(t--){
        CLR(dp);
        CLR(check);
        CLR(visited);
//        scanf("%s",&a[0]);
//        scanf("%s",&a[1]);
        cin>>a[0]>>a[1];
        len = a[0].size();
        if(a[0][len-1]=='.')
            dp[0][len-1] = 0;
        else
            dp[0][len-1] = INF;
        if(a[1][len-1]=='.')
            dp[1][len-1] = 0;
        else
            dp[1][len-1] = INF;
        
        for(int i=len-2;i>=0;i--){
            for(int j=0;j<2;j++){
                if(a[j][i] =='#')
                    dp[j][i] = INF;
                else{
                    dp[j][i] = min( dp[j][i+1], dp[j^1][i+1]+1);
                }
            }
        }
        
        int ans = min(dp[0][0],dp[1][0]);
        if(ans >= INF)
            printf("No\n");
        else
            printf("Yes\n%d\n",ans);
    }
    return 0;
}