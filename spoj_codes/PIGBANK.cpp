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
int dp[501][MX];
int val[501],wt[501],n;
void printDp(int actualWt){
    for(int  i=0;i<=n;i++){
        for(int j=0;j<=actualWt;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        CLR(dp);
        int e,f;
        cin>>e>>f>>n;
        for(int i=0;i<n;i++){
            cin>>val[i]>>wt[i];
        }
        int actualWt = f-e;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=actualWt;j++){
                if(i==0 || j==0)
                    dp[i][j]=26000000;
                else
                if(j == wt[i-1])
                    dp[i][j] = min(val[i-1],dp[i-1][j]);
                else
                if(j > wt[i-1]){
                    dp[i][j] = min((val[i-1]+dp[i][j-wt[i-1]]),dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
//        printDp(actualWt);
        if(dp[n][actualWt]==26000000)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[n][actualWt]<<"."<<endl;
    }
}
