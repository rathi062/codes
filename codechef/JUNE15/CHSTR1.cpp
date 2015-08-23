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
#define MX 5005
#define MOD 1000000009
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
int m,n,k;
string s;
LL nCr[MX][MX];
map<string,int> subStringMap;
LL frequencyCount[MX];
LL dp[MX];
bool check[MX];

void init(){
    for(int i=0;i<MX;i++)
        nCr[i][0] = 1;
    for(int i=0;i<MX;i++){
        for(int j=1;j<=i;j++){
            nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
            if(nCr[i][j] >= MOD)
                nCr[i][j] %= MOD;
        }
    }
}

LL geTnCr(int n, int r){
    r = (n-r) < r ? (n-r) : r;
    return nCr[n][r];
}

void process(){
    subStringMap.clear();
    CLR(frequencyCount);
    CLR(dp);
    CLR(check);
    for(int i=0;i<n;i++){
        string subString = "";
        for(int j=i;j<n;j++){
            subString = subString + s[j];
            int cnt = subStringMap[subString];
            if(cnt){
                frequencyCount[cnt]--;
                subStringMap[subString] = cnt+1;
                frequencyCount[cnt+1]++;
                
            }
            else{
                frequencyCount[1]++;
                subStringMap[subString] = 1;
            }
        }
    }
}

LL Solve(int k){
    if(check[k])
        return dp[k];
    LL result = 0;
    for(int i=k;i<=n;i++){
        LL toAdd = frequencyCount[i] * geTnCr(i, k);
        if(toAdd >= MOD)
            toAdd %= MOD;
        result += toAdd;
        if (result >= MOD) {
            result %= MOD;
        }
    }
    while(result < 0 )
        result += MOD;
    check[k] = 1;
    dp[k] = result;
    return result;
}

int main(){
    int t;
    inp(t);
    init();
    while(t--){
        inp(n);
        inp(m);
        cin>>s;
        process();
        for(int i=0;i<m;i++){
            inp(k);
            cout<<Solve(k)<<endl;
        }
    }
}
