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
#define MX 2001
#define MOD 1000000000
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
int m,n,a[100005];
LL nCr[MX+MX][MX+MX];
LL distributionWays[MX][MX];
bool check[MX][MX];

void init(){
    for(int i=0;i<MX;i++)
        nCr[i][0] = 1;
    for(int i=0;i<MX+MX;i++){
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

//LL Solve(int row, int mx){
//    if(row == 0 || mx == 0)
//    return 1;
//    if(check[row][mx])
//    return distributionWays[row][mx];
//    LL result = 0;
//    for(int i=mx;i>=0;i--){
//        result += geTnCr(i+m-1,m-1)*Solve(row-1, i);
//        if(result >= MOD)
//            result %= MOD;
//    }
//    check[row][mx] = 1;
//    distributionWays[row][mx] = result;
//    return result;
//}

LL Solve(int row, int mx){
    LL factors[mx+1];
    for(int i=0;i<=mx;i++){
        factors[i] = geTnCr(i+mx-1, mx-1);
        if(factors[i] >= MOD)
            factors[i] %= MOD;
    }
    LL sum = 0;
    for(int j=2;j<=row;j++){
        sum = 0;
        for(int i=0;i<=mx;i++){
            sum += factors[i];
            if(sum >= MOD)
                sum %= MOD;
            factors[i] = sum * geTnCr(i+mx-1, mx-1);
            if(factors[i] >= MOD)
                factors[i] %= MOD;
        }
    }
    sum = 0;
    for(int i=0;i<=mx;i++){
        sum += factors[i];
        if(sum >= MOD)
        sum %= MOD;
    }
    return sum;
}

int main(){
    int t;
    inp(t);
    init();
    while(t--){
        inp(n);
        inp(m);
        CLR(distributionWays);
        CLR(check);
        LL ans = Solve(n,m);
        cout<<ans<<endl;
    }
}
/*
 20
 1 1
 2
 1 2
 6
 1 3
 20
 1 4
 70
 1 5
 252
 2 1
 3
 2 2
 25
 2 3
 273
 2 4
 3321
 2 5
 42878
 3 1
 4
 3 2
 90
 3 3
 3208
 3 4
 135450
 3 5
 6267504
 4 1
 5
 4 2
 301
 4 3
 35069
 4 4
 5143341
 4 5
 853339755
 */
